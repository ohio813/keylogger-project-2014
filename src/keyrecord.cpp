#include "keyrecord.h"

#include <stdexcept>
#include <string>

#include "string_keystatus.h"
#include "string_keyvalue.h"

#include "keylocks.h"
#include "keystatus.h"
#include "keytime.h"
#include "keyvalue.h"

namespace keylog {
	void KeyRecord::init(KeyTime time, KeyValue value, KeyStatus status, KeyLocks locks) {
		mTime = time;
		mValue = value;
		mStatus = status;
		mLocks = locks;
	}

	KeyRecord::KeyRecord(KeyTime time, KeyValue value, KeyStatus status, KeyLocks locks) {
		init(time, value, status, locks);
	}

	KeyRecord::KeyRecord(KeyTime time, KeyValue value, KeyStatus status) {
		KeyLocks locks;
		init(time, value, status, locks);
	}

	KeyTime KeyRecord::getTime() {
		return mTime;
	}
	KeyValue KeyRecord::getValue() {
		return mValue;
	}
	KeyStatus KeyRecord::getStatus() {
		return mStatus;
	}
	KeyLocks KeyRecord::getLocks() {
		return mLocks;
	}

	unsigned long KeyRecord::getSec() {
		return mTime.sec;
	}
	unsigned int KeyRecord::getUsec() {
		return mTime.usec;
	}

	bool KeyRecord::getNumLock() {
		return mLocks.num;
	}
	bool KeyRecord::getCapsLock() {
		return mLocks.caps;
	}
	bool KeyRecord::getScrLock() {
		return mLocks.scr;
	}

	std::string KeyRecord::getStatusString() {
		return keylog_string::statusString(this->getStatus());
	}

	std::string KeyRecord::getValueString() {
		return keylog_string::valueString(this->getValue());
	}
}
