#ifndef IO_UTIL_H
#define IO_UTIL_H

#include <string>

int readInt(const std::string& prompt, int lo, int hi);
std::string readLine(const std::string& prompt);
bool readYesNo(const std::string& prompt);

#endif // IO_UTIL_H

