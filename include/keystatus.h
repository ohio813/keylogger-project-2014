#ifndef KEYSTATUS_H
#define KEYSTATUS_H

#include <assert.h>

namespace keylog {
	enum KeyStatus {
		status_first,

		status_other = status_first,
		status_press,
		status_release,
		status_repeat,

		status_last
	};

	inline KeyStatus& operator++(KeyStatus& keyStatus) {
		assert(keyStatus != status_last);
		keyStatus = static_cast<KeyStatus>(keyStatus + 1);
		return keyStatus;
	}
	inline KeyStatus operator++(KeyStatus& keyStatus, int) {
		assert(keyStatus != status_last);
		++keyStatus;
		return static_cast<KeyStatus>(keyStatus - 1);
	}
}

#endif