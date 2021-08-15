#pragma once
#include <vector>
#include <string>
#include "constdefine.h"

class •¶š—ñ‚Ì•ªŠ„
{
private:
	RESULT ‹Œ(const char* src, size_t srcSize, const char* delim);
	RESULT V(const std::string& src, const std::string& delims);
	std::vector<std::string> split(const std::string& src, const std::string& delim);

public:
	void exec();
};