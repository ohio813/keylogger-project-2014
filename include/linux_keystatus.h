#ifndef LINUX_KEYSTATUS_H
#define LINUX_KEYSTATUS_H

#include <map>
using std::map;

#include "keystatus.h"

namespace keylog_linux {
	static map<int, keylog::KeyStatus> createmap_keystatus() {
		map<int, keylog::KeyStatus> m;
		m[0] = keylog::status_release;
		m[1] = keylog::status_press;
		m[2] = keylog::status_repeat;
		return m;
	}
	static map<int, keylog::KeyStatus> map_keystatus = createmap_keystatus();
}

#endif