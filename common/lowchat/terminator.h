#include <iostream>
#include <stdlib.h>
#include <cerrno>
#include <cstdio>

class Terminator
{
public:
	static void die(const char* msg);
	static void die(std::string& msg);
	static void msg(const char* msg);
	static void msg(std::string& msg);
};
