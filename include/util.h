#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <sstream>
#include <stdio.h>

template <class T>
inline static std::string to_string(const T& t) {
	std::stringstream ss;
	ss << t;
	return ss.str();
}

int db_callback(void* NotUsed, int argc, char** argv, char** azColName) {
	int i;
	for(i = 0; i < argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

#endif
