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
		/*
		* char *strstr(const char *haystack, const char *needle);
		* strstr() 関数は、部分文字列 needle が文字列 haystack 中 で最初に現れる位置を見つける。 文字列を終端ヌルバイト ('\0') は比較されない。
		* 返り値
		*	これらの関数は、見つかった部分文字列の開始を指すポインターを返し、 もし部分文字列が見つからない場合は NULL を返す。
		*/
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

				/*
				* errno_t strcpy_s( char *dest, rsize_t dest_size, const char *src );
				* src のアドレスの内容を、終端の NULL 文字も含めて、dest で指定された場所にコピーします。 コピー先の文字列には、コピー元の文字列とその終端の NULL 文字を保持できるサイズが必要です。 コピー元とコピー先の文字列が重なり合っている場合の strcpy_s 関数の動作は未定義です。
				* 戻り値
				*	正常に終了した場合は 0 を返し、それ以外の場合はエラーを返します。
				*/
				strcpy_s(nextBuff, allocSize, buff);
				free(buff);
				buff = nextBuff;
			}
			/*
			* errno_t strncat_s( char *strDest, size_t numberOfElements, const char *strSource, size_t count );
			* Strsourceの最初のD文字をstrsourceの末尾に追加しようとします。ここで、 dは、 countの小さい方、およびstrsourceの長さです。 (サイズがNumberofelementsとして指定されている) strdestに収まるようにD文字を追加した後も、null 終端文字のスペースを残す場合は、これらの文字が追加され、 strdestの元の終端の null から開始し、新しい終端の null が追加されます。
			* 戻り値
			*	正常終了した場合は 0 を返します。失敗した場合はエラー コードを返します。
			*/
			strncat_s(buff, allocSize, currentPos, (nextPos - currentPos));
			/*
			* errno_t strcat_s( char *strDestination, size_t numberOfElements, const char *strSource );
			* strSource を strDestination に追加し、結果の文字列の終端に null 文字を付けます。 strSource の先頭の文字は、strDestination の終端の null 文字を上書きします。 コピー元とコピー先の文字列が重なり合っている場合の strcat_s 関数の動作は未定義です。
			* 戻り値
			*	正常終了した場合は 0 を返します。失敗した場合はエラー コードを返します。
			*/
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
	std::cout << "文字列の置換" << std::endl;

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