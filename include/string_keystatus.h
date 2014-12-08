#ifndef STRING_KEYSTATUS_H
#define STRING_KEYSTATUS_H

#include <map>
#include <string>
#include <stdexcept>

#include "keystatus.h"

namespace keylog_string {
	static std::map<keylog::KeyStatus, std::string> createmap_keystatus() {
		std::map<keylog::KeyStatus, std::string> m;
		m[keylog::status_other] = "other";
		m[keylog::status_release] = "release";
		m[keylog::status_press] = "press";
		m[keylog::status_repeat] = "repeat";
		return m;
	}
	static std::map<keylog::KeyStatus, std::string> map_keystatus = createmap_keystatus();

	static std::string statusString(keylog::KeyStatus status) {
		try {
			return map_keystatus.at(status);
		} catch(const std::out_of_range& oor) {
			return map_keystatus.at(keylog::status_other);
		}
	}
}

#endif
