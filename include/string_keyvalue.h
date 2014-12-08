#ifndef STRING_KEYVALUE_H
#define STRING_KEYVALUE_H

#include <map>
#include <string>
#include <stdexcept>

#include "keyvalue.h"

namespace keylog_string {
	static std::map<keylog::KeyValue, std::string> createmap_keyvalue() {
		std::map<keylog::KeyValue, std::string> m;
		m[keylog::value_reserved] = "reserved";
		m[keylog::value_esc] = "esc";
		m[keylog::value_1] = "1";
		m[keylog::value_2] = "2";
		m[keylog::value_3] = "3";
		m[keylog::value_4] = "4";
		m[keylog::value_5] = "5";
		m[keylog::value_6] = "6";
		m[keylog::value_7] = "7";
		m[keylog::value_8] = "8";
		m[keylog::value_9] = "9";
		m[keylog::value_0] = "0";
		m[keylog::value_minus] = "minus";
		m[keylog::value_equal] = "equal";
		m[keylog::value_backspace] = "backspace";
		m[keylog::value_tab] = "tab";
		m[keylog::value_q] = "q";
		m[keylog::value_w] = "w";
		m[keylog::value_e] = "e";
		m[keylog::value_r] = "r";
		m[keylog::value_t] = "t";
		m[keylog::value_y] = "y";
		m[keylog::value_u] = "u";
		m[keylog::value_i] = "i";
		m[keylog::value_o] = "o";
		m[keylog::value_p] = "p";
		m[keylog::value_leftbrace] = "leftbrace";
		m[keylog::value_rightbrace] = "rightbrace";
		m[keylog::value_enter] = "enter";
		m[keylog::value_leftctrl] = "leftctrl";
		m[keylog::value_a] = "a";
		m[keylog::value_s] = "s";
		m[keylog::value_d] = "d";
		m[keylog::value_f] = "f";
		m[keylog::value_g] = "g";
		m[keylog::value_h] = "h";
		m[keylog::value_j] = "j";
		m[keylog::value_k] = "k";
		m[keylog::value_l] = "l";
		m[keylog::value_semicolon] = "semicolon";
		m[keylog::value_apostrophe] = "apostrophe";
		m[keylog::value_grave] = "grave";
		m[keylog::value_leftshift] = "leftshift";
		m[keylog::value_backslash] = "backslash";
		m[keylog::value_z] = "z";
		m[keylog::value_x] = "x";
		m[keylog::value_c] = "c";
		m[keylog::value_v] = "v";
		m[keylog::value_b] = "b";
		m[keylog::value_n] = "n";
		m[keylog::value_m] = "m";
		m[keylog::value_comma] = "comma";
		m[keylog::value_dot] = "dot";
		m[keylog::value_slash] = "slash";
		m[keylog::value_rightshift] = "rightshift";
		m[keylog::value_kpasterisk] = "kpasterisk";
		m[keylog::value_leftalt] = "leftalt";
		m[keylog::value_space] = "space";
		m[keylog::value_capslock] = "capslock";
		m[keylog::value_f1] = "f1";
		m[keylog::value_f2] = "f2";
		m[keylog::value_f3] = "f3";
		m[keylog::value_f4] = "f4";
		m[keylog::value_f5] = "f5";
		m[keylog::value_f6] = "f6";
		m[keylog::value_f7] = "f7";
		m[keylog::value_f8] = "f8";
		m[keylog::value_f9] = "f9";
		m[keylog::value_f10] = "f10";
		m[keylog::value_numlock] = "numlock";
		m[keylog::value_scrolllock] = "scrolllock";
		m[keylog::value_kp7] = "kp7";
		m[keylog::value_kp8] = "kp8";
		m[keylog::value_kp9] = "kp9";
		m[keylog::value_kpminus] = "kpminus";
		m[keylog::value_kp4] = "kp4";
		m[keylog::value_kp5] = "kp5";
		m[keylog::value_kp6] = "kp6";
		m[keylog::value_kpplus] = "kpplus";
		m[keylog::value_kp1] = "kp1";
		m[keylog::value_kp2] = "kp2";
		m[keylog::value_kp3] = "kp3";
		m[keylog::value_kp0] = "kp0";
		m[keylog::value_kpdot] = "kpdot";
		m[keylog::value_zenkakuhankaku] = "zenkakuhankaku";
		m[keylog::value_102nd] = "102nd";
		m[keylog::value_f11] = "f11";
		m[keylog::value_f12] = "f12";
		m[keylog::value_ro] = "ro";
		m[keylog::value_katakana] = "katakana";
		m[keylog::value_hiragana] = "hiragana";
		m[keylog::value_henkan] = "henkan";
		m[keylog::value_katakanahiragana] = "katakanahiragana";
		m[keylog::value_muhenkan] = "muhenkan";
		m[keylog::value_kpjpcomma] = "kpjpcomma";
		m[keylog::value_kpenter] = "kpenter";
		m[keylog::value_rightctrl] = "rightctrl";
		m[keylog::value_kpslash] = "kpslash";
		m[keylog::value_sysrq] = "sysrq";
		m[keylog::value_rightalt] = "rightalt";
		m[keylog::value_linefeed] = "linefeed";
		m[keylog::value_home] = "home";
		m[keylog::value_up] = "up";
		m[keylog::value_pageup] = "pageup";
		m[keylog::value_left] = "left";
		m[keylog::value_right] = "right";
		m[keylog::value_end] = "end";
		m[keylog::value_down] = "down";
		m[keylog::value_pagedown] = "pagedown";
		m[keylog::value_insert] = "insert";
		m[keylog::value_delete] = "delete";
		m[keylog::value_macro] = "macro";
		m[keylog::value_mute] = "mute";
		m[keylog::value_volumedown] = "volumedown";
		m[keylog::value_volumeup] = "volumeup";
		m[keylog::value_power] = "power";
		m[keylog::value_kpequal] = "kpequal";
		m[keylog::value_kpplusminus] = "kpplusminus";
		m[keylog::value_pause] = "pause";
		m[keylog::value_kpcomma] = "kpcomma";
		m[keylog::value_hanguel] = "hanguel";
		m[keylog::value_hanja] = "hanja";
		m[keylog::value_yen] = "yen";
		m[keylog::value_leftmeta] = "leftmeta";
		m[keylog::value_rightmeta] = "rightmeta";
		m[keylog::value_compose] = "compose";
		m[keylog::value_stop] = "stop";
		m[keylog::value_again] = "again";
		m[keylog::value_props] = "props";
		m[keylog::value_undo] = "undo";
		m[keylog::value_front] = "front";
		m[keylog::value_copy] = "copy";
		m[keylog::value_open] = "open";
		m[keylog::value_paste] = "paste";
		m[keylog::value_find] = "find";
		m[keylog::value_cut] = "cut";
		m[keylog::value_help] = "help";
		m[keylog::value_menu] = "menu";
		m[keylog::value_calc] = "calc";
		m[keylog::value_setup] = "setup";
		m[keylog::value_sleep] = "sleep";
		m[keylog::value_wakeup] = "wakeup";
		m[keylog::value_file] = "file";
		m[keylog::value_sendfile] = "sendfile";
		m[keylog::value_deletefile] = "deletefile";
		m[keylog::value_xfer] = "xfer";
		m[keylog::value_prog1] = "prog1";
		m[keylog::value_prog2] = "prog2";
		m[keylog::value_www] = "www";
		m[keylog::value_msdos] = "msdos";
		m[keylog::value_coffee] = "coffee";
		m[keylog::value_direction] = "direction";
		m[keylog::value_cyclewindows] = "cyclewindows";
		m[keylog::value_mail] = "mail";
		m[keylog::value_bookmarks] = "bookmarks";
		m[keylog::value_computer] = "computer";
		m[keylog::value_back] = "back";
		m[keylog::value_forward] = "forward";
		m[keylog::value_closecd] = "closecd";
		m[keylog::value_ejectcd] = "ejectcd";
		m[keylog::value_ejectclosecd] = "ejectclosecd";
		m[keylog::value_nextsong] = "nextsong";
		m[keylog::value_playpause] = "playpause";
		m[keylog::value_previoussong] = "previoussong";
		m[keylog::value_stopcd] = "stopcd";
		m[keylog::value_record] = "record";
		m[keylog::value_rewind] = "rewind";
		m[keylog::value_phone] = "phone";
		m[keylog::value_iso] = "iso";
		m[keylog::value_config] = "config";
		m[keylog::value_homepage] = "homepage";
		m[keylog::value_refresh] = "refresh";
		m[keylog::value_exit] = "exit";
		m[keylog::value_move] = "move";
		m[keylog::value_edit] = "edit";
		m[keylog::value_scrollup] = "scrollup";
		m[keylog::value_scrolldown] = "scrolldown";
		m[keylog::value_kpleftparen] = "kpleftparen";
		m[keylog::value_kprightparen] = "kprightparen";
		m[keylog::value_f13] = "f13";
		m[keylog::value_f14] = "f14";
		m[keylog::value_f15] = "f15";
		m[keylog::value_f16] = "f16";
		m[keylog::value_f17] = "f17";
		m[keylog::value_f18] = "f18";
		m[keylog::value_f19] = "f19";
		m[keylog::value_f20] = "f20";
		m[keylog::value_f21] = "f21";
		m[keylog::value_f22] = "f22";
		m[keylog::value_f23] = "f23";
		m[keylog::value_f24] = "f24";
		m[keylog::value_playcd] = "playcd";
		m[keylog::value_pausecd] = "pausecd";
		m[keylog::value_prog3] = "prog3";
		m[keylog::value_prog4] = "prog4";
		m[keylog::value_suspend] = "suspend";
		m[keylog::value_close] = "close";
		m[keylog::value_play] = "play";
		m[keylog::value_fastforward] = "fastforward";
		m[keylog::value_bassboost] = "bassboost";
		m[keylog::value_print] = "print";
		m[keylog::value_hp] = "hp";
		m[keylog::value_camera] = "camera";
		m[keylog::value_sound] = "sound";
		m[keylog::value_question] = "question";
		m[keylog::value_email] = "email";
		m[keylog::value_chat] = "chat";
		m[keylog::value_search] = "search";
		m[keylog::value_connect] = "connect";
		m[keylog::value_finance] = "finance";
		m[keylog::value_sport] = "sport";
		m[keylog::value_shop] = "shop";
		m[keylog::value_alterase] = "alterase";
		m[keylog::value_cancel] = "cancel";
		m[keylog::value_brightnessdown] = "brightnessdown";
		m[keylog::value_brightnessup] = "brightnessup";
		m[keylog::value_media] = "media";
		m[keylog::value_unknown] = "unknown";
		return m;
	}
	static std::map<keylog::KeyValue, std::string> map_keyvalue = createmap_keyvalue();

	static std::string valueString(keylog::KeyValue value) {
		try {
			return map_keyvalue.at(value);
		} catch(const std::out_of_range& oor) {
			return map_keyvalue.at(keylog::value_unknown);
		}
	}
}

#endif