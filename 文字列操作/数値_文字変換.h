#pragma once
#include "constdefine.h"
#include <string>

class ���l_�����ϊ�
{
private:
	RESULT ��(int dec, char* word, size_t bufSize);
	RESULT �V1(int dec, std::string& word);
	RESULT �V2(int dec, std::string& word);

public:
	void exec();
};
