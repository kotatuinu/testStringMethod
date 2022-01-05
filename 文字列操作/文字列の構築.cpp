#include "文字列の構築.h"
#include <iostream>

RESULT 文字列の構築::旧（出力固定サイズ）(const char* src, size_t wordSize, size_t count, char* result, size_t resultSize)
{
	for (size_t i = 0; i < count; i++) {
		// 文字列の結合
		/*
		* errno_t strcat_s( char *strDestination, size_t numberOfElements, const char *strSource );
		* strSource を strDestination に追加し、結果の文字列の終端に null 文字を付けます。 strSource の先頭の文字は、strDestination の終端の null 文字を上書きします。 コピー元とコピー先の文字列が重なり合っている場合の strcat_s 関数の動作は未定義です。
		* 戻り値
		*	正常終了した場合は 0 を返します。失敗した場合はエラー コードを返します。
		*/
		errno_t  err = strcat_s(result, resultSize, src);
		if (err != 0) {
			// エラー
			return RESULT::ERR;
		}
		src += wordSize;
	}

	return RESULT::SUCCESS;
}


RESULT 文字列の構築::旧（出力可変長）(const char* src, size_t wordSize, size_t count, char** result)
{
	if (result == NULL) {
		return RESULT::ERR;
	}

	// 毎回、領域確保すると遅くなるので、大きめに取得してサイズを超えるときに改めて取得し直す
	size_t totalSize = 0;
	size_t allocSize = ALLOC_SIZE;
	char* tmp = (char*)malloc(allocSize);
	if (tmp == NULL) {
		return RESULT::ERR;
	}
	tmp[0] = '\0';

	for (size_t i = 0; i < count; i++) {

		size_t wordLen = strlen(src);
		totalSize += wordLen;
		if (allocSize < totalSize) {
			if (wordLen > ALLOC_SIZE) {
				// 新たに取得するバッファサイズより文字列長が長い場合、文字列長分＋α取得
				allocSize += wordLen;
			}
			allocSize += ALLOC_SIZE;

			char* tmp2 = (char*)malloc(allocSize);
			if (tmp2 == NULL) {
				return RESULT::ERR;
			}
			tmp2[0] = '\0';
			// 文字列を新しい領域にコピーする
			strcpy_s(tmp2, allocSize, tmp);
			free(tmp);
			tmp = tmp2;
		}

		// 文字列の結合
		errno_t err = strcat_s(tmp, allocSize, src);
		if (err != 0) {
			// エラー
			return RESULT::ERR;
		}
		src += wordSize;
	}

	*result = tmp;

	return RESULT::SUCCESS;
}

RESULT 文字列の構築::新(const std::vector<std::string>& src, std::string& result)
{
	for (const auto& word : src) {
		// std::stringは、"+="演算子で追加出来る
		result += word;
	}

	return RESULT::SUCCESS;
}

void 文字列の構築::exec()
{
	std::cout << "文字列の構築" << std::endl;

	const char src1[][9] = {
		"てすと１",
		"てすと２",
		"てすと３",
	};
	char result1[25] = {};
	RESULT rslt = 旧（出力固定サイズ）((const char*)(&src1[0]), sizeof(src1[0]), (sizeof(src1) / sizeof(src1[0])), (char*)result1, sizeof(result1));
	if (rslt != RESULT::SUCCESS) {
		fprintf(stderr, "エラー：文字列の構築::旧（出力固定サイズ）\r\n");
	}
	else {
		printf("%s\r\n", result1);
	}

	char* result2 = NULL;
	rslt = 旧（出力可変長）((const char*)(&src1[0]), sizeof(src1[0]), (sizeof(src1) / sizeof(src1[0])), &result2);
	if (rslt != RESULT::SUCCESS) {
		fprintf(stderr, "エラー：文字列の構築::旧（出力可変長）\r\n");
	}
	else {
		printf("%s\r\n", result2);
	}
	free(result2);

	const std::vector<std::string> src2 = {
		"てすと１",
		"てすと２",
		"てすと３",
	};
	std::string result3 = {};
	rslt = 新(src2, result3);
	if (rslt != RESULT::SUCCESS) {
		fprintf(stderr, "エラー：文字列の構築::新\r\n");
	}
	else {
		std::cout << result3 << std::endl;
		//printf("%s\r\n", result3.c_str());
	}
}

