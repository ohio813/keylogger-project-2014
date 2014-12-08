#include "keytxt.h"

#include <cstdio>
#include <iostream>
#include <string>

#include <exception>

#include "string_keystatus.h"
#include "string_keyvalue.h"

#include "keyrecord.h"
#include "keytime.h"
#include "keyvalue.h"
#include "keystatus.h"
#include "keylocks.h"

#include <sstream>

namespace keylog_txt {

    template <class T>
    inline static std::string to_string(const T& t) {
        std::stringstream ss;
        ss << t;
        return ss.str();
    }

    void KeyTXT::init_txt(std::string filename) {
        if (debug) {
            std::cout << filename << std::endl;
        }
        txt =  fopen(filename.c_str(), "w");
    }

    void KeyTXT::insert_keyrecord(keylog::KeyRecord* keyRecord) {
        std::string insert_string = keytime(keyRecord->getTime()) + "\t" + keyvalue(keyRecord->getValue()) + "\t" + keystatus(keyRecord->getStatus()) + "\t" + keylocks(keyRecord->getLocks());
        if (debug) {
            std::cout << insert_string << std::endl;
        }
        fprintf(txt, "%s\n", insert_string.c_str());
    }

    std::string KeyTXT::keytime(keylog::KeyTime time) {
        return to_string(time.sec) + "." + to_string(time.usec);
    }

    std::string KeyTXT::keyvalue(keylog::KeyValue value) {
        return keylog_string::valueString(value);
    }

    std::string KeyTXT::keystatus(keylog::KeyStatus status) {
        return keylog_string::statusString(status);
    }

    std::string KeyTXT::keylocks(keylog::KeyLocks locks) {
        return to_string(locks.num) + "." + to_string(locks.caps)+ "." + to_string(locks.scr);
    }



    KeyTXT::KeyTXT(std::string filename) {
        debug = false;
        init_txt(filename);
    }

    KeyTXT::KeyTXT(std::string filename, bool isDebug) {
        debug = isDebug;
        init_txt(filename);
    }

    void KeyTXT::insert(keylog::KeyRecord* keyRecord) {
        insert_keyrecord(keyRecord);
    }

    int KeyTXT::close() {
        if (debug) {
            std::cout << "==========" << std::endl;
        }
        fclose(txt);
        return 0;
    }
}
