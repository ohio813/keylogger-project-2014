#ifndef WINDOWS_KEYVALUE_H
#define WINDOWS_KEYVALUE_H

#include <map>
using std::map;

#include <windows.h>
#include <winuser.h>

#include "keyvalue.h"

namespace keylog_windows {
	static map<unsigned short, keylog::KeyValue> createmap_keyvalue() {
		map<unsigned short, keylog::KeyValue> m;
		m[VK_ESCAPE] = keylog::value_esc;
		m[(int) '1'] = keylog::value_1;
		m[(int) '2'] = keylog::value_2;
		m[(int) '3'] = keylog::value_3;
		m[(int) '4'] = keylog::value_4;
		m[(int) '5'] = keylog::value_5;
		m[(int) '6'] = keylog::value_6;
		m[(int) '7'] = keylog::value_7;
		m[(int) '8'] = keylog::value_8;
		m[(int) '9'] = keylog::value_9;
		m[(int) '0'] = keylog::value_0;
		m[VK_BACK] = keylog::value_backspace;
		m[VK_TAB] = keylog::value_tab;
		m[(int) 'Q'] = keylog::value_q;
		m[(int) 'W'] = keylog::value_w;
		m[(int) 'E'] = keylog::value_e;
		m[(int) 'R'] = keylog::value_r;
		m[(int) 'T'] = keylog::value_t;
		m[(int) 'Y'] = keylog::value_y;
		m[(int) 'U'] = keylog::value_u;
		m[(int) 'I'] = keylog::value_i;
		m[(int) 'O'] = keylog::value_o;
		m[(int) 'P'] = keylog::value_p;
		m[VK_OEM_4] = keylog::value_leftbrace;
		m[VK_OEM_6] = keylog::value_rightbrace;
		m[VK_RETURN] = keylog::value_enter;
		m[VK_LCONTROL] = keylog::value_leftctrl;
		m[(int) 'A'] = keylog::value_a;
		m[(int) 'S'] = keylog::value_s;
		m[(int) 'D'] = keylog::value_d;
		m[(int) 'F'] = keylog::value_f;
		m[(int) 'G'] = keylog::value_g;
		m[(int) 'H'] = keylog::value_h;
		m[(int) 'J'] = keylog::value_j;
		m[(int) 'K'] = keylog::value_k;
		m[(int) 'L'] = keylog::value_l;
		m[VK_OEM_1] = keylog::value_semicolon;
		m[VK_OEM_7] = keylog::value_apostrophe;
		m[VK_OEM_3] = keylog::value_grave;
		m[VK_LSHIFT] = keylog::value_leftshift;
		m[VK_OEM_5] = keylog::value_backslash;
		m[(int) 'Z'] = keylog::value_z;
		m[(int) 'X'] = keylog::value_x;
		m[(int) 'C'] = keylog::value_c;
		m[(int) 'V'] = keylog::value_v;
		m[(int) 'B'] = keylog::value_b;
		m[(int) 'N'] = keylog::value_n;
		m[(int) 'M'] = keylog::value_m;
		m[VK_RSHIFT] = keylog::value_rightshift;
		m[VK_MULTIPLY] = keylog::value_kpasterisk;
		m[VK_LMENU] = keylog::value_leftalt;
		m[VK_SPACE] = keylog::value_space;
		m[VK_CAPITAL] = keylog::value_capslock;
		m[VK_F1] = keylog::value_f1;
		m[VK_F2] = keylog::value_f2;
		m[VK_F3] = keylog::value_f3;
		m[VK_F4] = keylog::value_f4;
		m[VK_F5] = keylog::value_f5;
		m[VK_F6] = keylog::value_f6;
		m[VK_F7] = keylog::value_f7;
		m[VK_F8] = keylog::value_f8;
		m[VK_F9] = keylog::value_f9;
		m[VK_F10] = keylog::value_f10;
		m[VK_NUMLOCK] = keylog::value_numlock;
		m[VK_SCROLL] = keylog::value_scrolllock;
		m[VK_NUMPAD7] = keylog::value_kp7;
		m[VK_NUMPAD8] = keylog::value_kp8;
		m[VK_NUMPAD9] = keylog::value_kp9;
		m[VK_SUBTRACT] = keylog::value_kpminus;
		m[VK_NUMPAD4] = keylog::value_kp4;
		m[VK_NUMPAD5] = keylog::value_kp5;
		m[VK_NUMPAD6] = keylog::value_kp6;
		m[VK_ADD] = keylog::value_kpplus;
		m[VK_NUMPAD1] = keylog::value_kp1;
		m[VK_NUMPAD2] = keylog::value_kp2;
		m[VK_NUMPAD3] = keylog::value_kp3;
		m[VK_NUMPAD0] = keylog::value_kp0;
		m[VK_DECIMAL] = keylog::value_kpdot;
		m[VK_F11] = keylog::value_f11;
		m[VK_F12] = keylog::value_f12;
		m[VK_RCONTROL] = keylog::value_rightctrl;
		m[VK_DIVIDE] = keylog::value_kpslash;
		m[VK_RMENU] = keylog::value_rightalt;
		m[VK_HOME] = keylog::value_home;
		m[VK_UP] = keylog::value_up;
		m[VK_PRIOR] = keylog::value_pageup;
		m[VK_LEFT] = keylog::value_left;
		m[VK_RIGHT] = keylog::value_right;
		m[VK_END] = keylog::value_end;
		m[VK_DOWN] = keylog::value_down;
		m[VK_NEXT] = keylog::value_pagedown;
		m[VK_INSERT] = keylog::value_insert;
		m[VK_DELETE] = keylog::value_delete;
		m[VK_PAUSE] = keylog::value_pause;
		m[VK_NONAME] = keylog::value_unknown;
		return m;
	}
	static map<unsigned short, keylog::KeyValue> map_keyvalue = createmap_keyvalue();
}

#endif
