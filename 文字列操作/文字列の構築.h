#pragma once
#include <vector>
#include <string>
#include "constdefine.h"

class ������̍\�z
{
private:
	const size_t ALLOC_SIZE = 5;

private:
	RESULT ���i�o�͌Œ�T�C�Y�j(const char* src, size_t wordSize, size_t count, char* result, size_t resultSize);
	RESULT ���i�o�͉ϒ��j(const char* src, size_t wordSize, size_t count, char** result);
	RESULT �V(const std::vector<std::string>& src, std::string& result);

public:
	void exec();
};