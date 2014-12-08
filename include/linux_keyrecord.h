#ifndef LINUX_KEYRECORD_H
#define LINUX_KEYRECORD_H

#include <sys/time.h>

#include <stdexcept>

#include "keytime.h"
#include "keyvalue.h"
#include "keystatus.h"
#include "keylocks.h"
#include "keyrecord.h"

#include "linux_keystatus.h"
#include "linux_keyvalue.h"

namespace keylog_linux {
	class KeyRecord: public keylog::KeyRecord {
		private:
			static keylog::KeyTime toKeyTime(timeval linux_time) {
				keylog::KeyTime time;
				time.sec = linux_time.tv_sec;
				time.usec = linux_time.tv_usec;
				return time;
			}

			static keylog::KeyValue toKeyValue(unsigned short value) {
				try {
					return map_keyvalue.at(value);
				} catch(const std::out_of_range& oor) {
					return keylog::value_unknown;
				}
			}

			static keylog::KeyStatus toKeyStatus(int status) {
				try {
					return map_keystatus.at(status);
				} catch(const std::out_of_range& oor) {
					return keylog::status_other;
				}
			}
		public:
			KeyRecord(input_event event)
				: keylog::KeyRecord(toKeyTime(event.time), toKeyValue(event.code), toKeyStatus(event.value)) {
			}
	};
}

#endif