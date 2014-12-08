#ifndef KEYRECORD_H
#define KEYRECORD_H

#include <string>

//#include "string_keystatus.h"
//#include "string_keyvalue.h"

#include "keylocks.h"
#include "keystatus.h"
#include "keytime.h"
#include "keyvalue.h"

namespace keylog {
	class KeyRecord {
		private:
			KeyTime mTime;
			KeyValue mValue;
			KeyStatus mStatus;
			KeyLocks mLocks;
			void init(KeyTime time, KeyValue value, KeyStatus status, KeyLocks locks);

		protected:
			KeyRecord(KeyTime time, KeyValue value, KeyStatus status, KeyLocks locks);
			KeyRecord(KeyTime time, KeyValue value, KeyStatus status);

		public:
			KeyTime getTime();
			KeyValue getValue();
			KeyStatus getStatus();
			KeyLocks getLocks();

			unsigned long getSec();
			unsigned int getUsec();

			bool getNumLock();
			bool getCapsLock();
			bool getScrLock();

			std::string getStatusString();

			std::string getValueString();
	};
}

#endif
