#ifndef KEYDB_H
#define KEYDB_H

#include <sqlite3.h>
#include <string>

#include "keyrecord.h"
#include "keyvalue.h"
#include "keystatus.h"
#include "util.h"

namespace keylog_db {
	class KeyDB {
		private:
			char* errMsg;
			sqlite3* db;

			std::string table_keylog;
			std::string table_keylog_sec;
			std::string table_keylog_usec;
			std::string table_keylog_value;
			std::string table_keylog_status;
			std::string table_keylog_locknum;
			std::string table_keylog_lockcaps;
			std::string table_keylog_lockscr;

			std::string table_keyvalue;
			std::string table_keyvalue_id;
			std::string table_keyvalue_name;

			std::string table_keystatus;
			std::string table_keystatus_id;
			std::string table_keystatus_name;

			int db_exec(std::string sql);

			void init_strings();

			int init_db(std::string filename);

			int init_table_keylog();

			int init_table_keyvalue();

			int init_table_keystatus();

			int insert_table_keyrecord(keylog::KeyRecord* keyRecord);

			int insert_table_keyvalue(keylog::KeyValue val);

			int insert_table_keystatus(keylog::KeyStatus stat);

		public:
			KeyDB(std::string filename);

			int insert(keylog::KeyRecord* keyRecord);

			int close();
	};
}

#endif
