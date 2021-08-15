#pragma once
#include "constdefine.h"
#include <string>

class •¶š—ñ‚Ì’uŠ·
{
private:
	static const size_t ALLOC_SIZE = 5;

private:
	RESULT ‹Œ(const char* src, const char* replacesrc, const char* replacedest, char** result);
	RESULT V(const std::string& src, const std::string& replacesrc, const std::string& replacedest, std::string& result);

public:
	void exec();
};