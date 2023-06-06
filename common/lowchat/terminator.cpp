#include "terminator.h"

void Terminator::msg(const char* msg)
{
	fprintf(stderr, "%s\n", msg);
}

void Terminator::msg(std::string& msg)
{
	fprintf(stderr, "%s\n", msg);
}

void Terminator::die(const char* msg)
{
	int err = errno;
	fprintf(stderr, "[%i]: %s\n", err, msg);
	abort();
}

void Terminator::die(std::string& msg)
{
	int err = errno;
	fprintf(stderr, "[%i]: %s\n", err, msg);
	abort();
}
