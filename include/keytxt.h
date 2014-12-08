#ifndef KEYTXT_H
#define KEYTXT_H

#include <string>
#include <fstream>
#include <iostream>

#include "keyrecord.h"
#include "keyvalue.h"
#include "keystatus.h"

namespace keylog_txt {
	class KeyTXT {
		private:
            FILE* txt;

            bool debug;

			void init_txt(std::string filename);

			void insert_keyrecord(keylog::KeyRecord* keyRecord);

			std::string keytime(keylog::KeyTime time);

			std::string keyvalue(keylog::KeyValue value);

			std::string keystatus(keylog::KeyStatus status);

			std::string keylocks(keylog::KeyLocks locks);

		public:
			KeyTXT(std::string filename);

			KeyTXT(std::string filename, bool isDebug);

			void insert(keylog::KeyRecord* keyRecord);

			int close();
	};
}

#endif
