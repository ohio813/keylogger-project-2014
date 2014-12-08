#ifndef KEYLOCKS_H
#define KEYLOCKS_H

namespace keylog {
	struct KeyLocks {
		bool num;
		bool caps;
		bool scr;

		KeyLocks() {
			num = false;
			caps = false;
			scr = false;
		}
	};
}

#endif