#ifndef WINDOWS_KEYRECORD_H
#define WINDOWS_KEYRECORD_H

#include <time.h>

#include <stdexcept>

#include "keytime.h"
#include "keyvalue.h"
#include "keystatus.h"
#include "keylocks.h"
#include "keyrecord.h"

//#include "windows_keystatus.h"
#include "windows_keyvalue.h"

namespace keylog_windows {
	class KeyRecord: public keylog::KeyRecord {
		private:
			static keylog::KeyTime toKeyTime(time_t windows_time) {
				keylog::KeyTime time;
				time.sec = windows_time;
				time.usec = 0;
				return time;
			}

			static keylog::KeyValue toKeyValue(int value) {
				try {
					return map_keyvalue.at(value);
				} catch(const std::out_of_range& oor) {
					return keylog::value_unknown;
				}
			}

			static keylog::KeyStatus toKeyStatus() {
                return keylog::status_press;
			}
		public:
			KeyRecord(time_t time, int value)
				: keylog::KeyRecord(toKeyTime(time), toKeyValue(value), toKeyStatus()) {
			}
	};
}

#endif
