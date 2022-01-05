#pragma once
#include <vector>
#include <string>
#include <vector>
#include "constdefine.h"
#include "CLList.h"

class •¶š—ñ‚Ì•ªŠ„
{
private:
	RESULT ‹Œ(const char* src, size_t srcSize, const char* delim, CLList& result);
	RESULT V(const std::string& src, const std::string& delims, std::vector<std::string>& result);
	std::vector<std::string> split(const std::string& src, const std::string& delim);

public:
	void exec();
};