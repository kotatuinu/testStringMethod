#include "文字列の置換.h"
#include <iostream>

RESULT 文字列の置換::旧(const char* src, const char* replacesrc, const char* replacedest, char** result)
{
	// 文字列を置換するC言語関数は存在しないので、検索→置き換え文字を追加する
	// 汎用的に作ると、最終的な文字列長が分からないので、動的に領域確保する必要がある＝使い終わったら解放

	if (src == NULL || replacesrc == NULL || replacedest == NULL) {
		// invalid arguments
		return RESULT::ERR;
	}

	if (result == NULL) {
		// invalid arguments
		return RESULT::ERR;
	}

	const char* currentPos = src;

	// 毎回、領域確保すると遅くなるので、大きめに取得してサイズを超えるときに改めて取得し直す
	size_t totalSize = 0;
	size_t allocSize = strlen(src) + ALLOC_SIZE;
	char* buff = (char*)malloc(allocSize);
	buff[0] = '\0';

	size_t rsrcSize = strlen(replacesrc);
	size_t rdestSize = strlen(replacedest);

	// 置き換え元の文字検索→置き換え先の文字列を格納
	do {
		const char* nextPos = strstr(currentPos, replacesrc);
		if (nextPos != NULL) {
			if (totalSize + rdestSize + (nextPos - currentPos) + 1 > allocSize) {
				if (rdestSize > ALLOC_SIZE) {
					// 新たに取得するバッファサイズより文字列長が長い場合、文字列長分＋α取得
					allocSize += (rdestSize + (nextPos - currentPos) + 1);
				}
				allocSize += ALLOC_SIZE;

				char* nextBuff = (char*)malloc(allocSize);
				if (nextBuff == NULL) {
					return RESULT::ERR;
				}

				strcpy_s(nextBuff, allocSize, buff);
				free(buff);
				buff = nextBuff;
			}
			strncat_s(buff, allocSize, currentPos, (nextPos - currentPos));
			strcat_s(buff, allocSize, replacedest);

			totalSize += (nextPos - currentPos) + rdestSize;
			currentPos = nextPos + rsrcSize;
		}
		else {
			size_t len = strlen(currentPos) + 1;
			if (totalSize + len > allocSize) {
				if (len > ALLOC_SIZE) {
					// 新たに取得するバッファサイズより文字列長が長い場合、文字列長分取得
					allocSize += len;
				}

				char* nextBuff = (char*)malloc(allocSize);
				if (nextBuff == NULL) {
					return RESULT::ERR;
				}

				strcpy_s(nextBuff, allocSize, buff);
				free(buff);
				buff = nextBuff;
			}

			strcat_s(buff, allocSize, currentPos);
			totalSize += len;
			currentPos = NULL;
		}
	} while (currentPos != NULL);

	*result = buff;

	return RESULT::SUCCESS;
}

RESULT 文字列の置換::新(const std::string& src, const std::string& replacesrc, const std::string& replacedest, std::string& result)
{
	size_t pos1 = 0;
	do {
		size_t pos2 = src.find(replacesrc, pos1);
		if (pos2 == std::string::npos) {
			result += src.substr(pos1);
			break;
		}
		result += src.substr(pos1, pos2 - pos1);
		result += replacedest;
		pos1 = pos2 + replacesrc.size();
	} while (true);

	return RESULT::SUCCESS;
}

void 文字列の置換::exec()
{
	const char src1[] = "李も桃も桃のうち、桃も李も桃のうち";
	const char replacesrc1[] = "も";
	const char replacedest1[] = "だろうと";
	char* result1 = NULL;
	RESULT result = 旧(src1, replacesrc1, replacedest1, &result1);
	printf("%s\n", result1);
	free(result1);


	const std::string src2 = "李も桃も桃のうち、桃も李も桃のうち";
	const std::string replacesrc2 = "も";
	const std::string replacedest2 = "だろうと";
	std::string result2;
	result = 新(src2, replacesrc2, replacedest2, result2);

	std::cout << result2 << std::endl;
}