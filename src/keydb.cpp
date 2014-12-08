#include "keydb.h"

#include <cstdio>
#include <sqlite3.h>
#include <stdexcept>
#include <string>

#include "string_keystatus.h"
#include "string_keyvalue.h"

#include "keyrecord.h"
#include "keystatus.h"
#include "keyvalue.h"
#include "util.h"

namespace keylog_db {
	int KeyDB::db_exec(std::string sql) {
		if(sqlite3_exec(db, sql.c_str(), db_callback, 0, &errMsg) != SQLITE_OK) {
			//fprintf(stderr, "SQL error: %s\n", errMsg);
			sqlite3_free(errMsg);
			return 1;
		}
		return 0;
	}

	void KeyDB::init_strings() {
		table_keylog = "KEYLOG";
		table_keylog_sec = "SEC";
		table_keylog_usec = "USEC";
		table_keylog_value = "VALUE";
		table_keylog_status = "STATUS";
		table_keylog_locknum = "LOCKNUM";
		table_keylog_lockcaps = "LOCKCAPS";
		table_keylog_lockscr = "LOCKSCR";

		table_keyvalue = "KEYVALUE";
		table_keyvalue_id = "ID";
		table_keyvalue_name = "NAME";

		table_keystatus = "KEYSTATUS";
		table_keystatus_id = "ID";
		table_keystatus_name = "NAME";
	}

	int KeyDB::init_db(std::string filename) {
		return sqlite3_open(filename.c_str(), &db);
	}

	int KeyDB::init_table_keyvalue() {
		std::string sql = "CREATE TABLE IF NOT EXISTS " + table_keyvalue + "(" \
						  ""	+ table_keyvalue_id +	" INT	NOT NULL" \
						  ","	+ table_keyvalue_name +	" TEXT	NOT NULL" \
						  ","	+ "PRIMARY KEY(" + table_keyvalue_id + ")" \
						  ");";
		if(db_exec(sql) == 1) {
			return 1;
		}

		// TODO: make iterator as part of KeyValue
		for(keylog::KeyValue val = keylog::value_first; val < keylog::value_last; val++) {
			insert_table_keyvalue(val);
		}
		return 0;
	}

	int KeyDB::init_table_keystatus() {
		std::string sql = "CREATE TABLE IF NOT EXISTS " + table_keystatus + "(" \
						  "" + table_keystatus_id +	" INT	NOT NULL" \
						  "," + table_keystatus_name + " TEXT	NOT NULL" \
						  "," + "PRIMARY KEY(" + table_keystatus_id + ")" \
						  ");";
		if(db_exec(sql) == 1) {
			return 1;
		}

		// TODO: make iterator part of KeyStatus
		for(keylog::KeyStatus stat = keylog::status_first; stat < keylog::status_last; stat++) {
			insert_table_keystatus(stat);
		}
		return 0;
	}

	int KeyDB::init_table_keylog() {
		std::string sql = "CREATE TABLE IF NOT EXISTS " + table_keylog + "("  \
						  ""	+ table_keylog_sec +		" INT	NOT NULL" \
						  ","	+ table_keylog_usec +		" INT	NOT NULL" \
						  ","	+ table_keylog_value +		" INT	NOT NULL" \
						  ","	+ table_keylog_status +		" INT	NOT NULL" \
						  ","	+ table_keylog_locknum +	" INT	NOT NULL	DEFAULT 0" \
						  ","	+ table_keylog_lockcaps +	" INT	NOT NULL	DEFAULT 0" \
						  ","	+ table_keylog_lockscr +	" INT	NOT NULL	DEFAULT 0" \
						  ","	+ "PRIMARY KEY(" + table_keylog_sec + "," + table_keylog_usec + "," + table_keylog_value + ")" \
						  ","	+ "FOREIGN KEY(" + table_keylog_value + ")	REFERENCES " + table_keyvalue + "(" + table_keyvalue_id + ")" \
						  ","	+ "FOREIGN KEY(" + table_keylog_status + ")	REFERENCES " + table_keystatus + "(" + table_keystatus_id + ")" \
						  ");";
		return db_exec(sql);
	}

	int KeyDB::insert_table_keyvalue(keylog::KeyValue val) {
		try {
			std::string sql = "INSERT INTO " + table_keyvalue + "(" \
							  ""	+ table_keyvalue_id + "" \
							  ","	+ table_keyvalue_name + "" \
							  ") VALUES (" \
							  ""	+ to_string(val) + "" \
							  ","	+ "\"" + keylog_string::valueString(val) + "\"" + "" \
							  ");";
			if(db_exec(sql) == 1) {
				return 1;
			}
		} catch(const std::out_of_range& oor) {
		}
		return 0;
	}

	int KeyDB::insert_table_keystatus(keylog::KeyStatus stat) {
		try {
			std::string sql = "INSERT INTO " + table_keystatus + "(" \
							  ""	+ table_keystatus_id + "" \
							  ","	+ table_keystatus_name + "" \
							  ") VALUES (" \
							  ""	+ to_string(stat) + "" \
							  ","	+ "\"" + keylog_string::statusString(stat) + "\"" + "" \
							  ");";
			if(db_exec(sql) == 1) {
				return 1;
			}
		} catch(const std::out_of_range& oor) {
		}
		return 0;
	}

	int KeyDB::insert_table_keyrecord(keylog::KeyRecord* keyRecord) {
		std::string sql = "INSERT INTO " + table_keylog + "(" \
						  ""	+ table_keylog_sec + "" \
						  ","	+ table_keylog_usec + "" \
						  ","	+ table_keylog_value + "" \
						  ","	+ table_keylog_status + "" \
						  ","	+ table_keylog_locknum + "" \
						  ","	+ table_keylog_lockcaps	+ "" \
						  ","	+ table_keylog_lockscr + "" \
						  ") VALUES (" \
						  ""	+ to_string(keyRecord->getSec()) + "" \
						  ","	+ to_string(keyRecord->getUsec()) + "" \
						  ","	+ to_string(keyRecord->getValue()) + "" \
						  ","	+ to_string(keyRecord->getStatus()) + "" \
						  ","	+ to_string(keyRecord->getNumLock()) + "" \
						  ","	+ to_string(keyRecord->getCapsLock()) + "" \
						  ","	+ to_string(keyRecord->getScrLock()) + "" \
						  ");";
		if(db_exec(sql) == 1) {
			return 1;
		}
		return 0;
	}

	KeyDB::KeyDB(std::string filename) {
		init_strings();
		init_db(filename);
		init_table_keylog();
		init_table_keyvalue();
		init_table_keystatus();
	}

	int KeyDB::insert(keylog::KeyRecord* keyRecord) {
		return insert_table_keyrecord(keyRecord);
	}

	int KeyDB::close() {
		return sqlite3_close(db);
	}
}
