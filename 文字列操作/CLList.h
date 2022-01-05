#pragma once
#include <windows.h>

// èáï˚å¸ÉäÉXÉg
class CLList
{
public:
	struct Item {
		void* val;
		size_t valLen;
		Item* itemPtr;

		Item(const void* v, size_t len)
			:itemPtr(NULL)
			, valLen(len)
		{
			val = new BYTE[len];
			if (val != NULL) {
				memcpy(val, v, len);
			}
		}
		~Item()
		{
			delete val;
		}
	};

private:
	Item* m_itemTop;
	Item* m_itemEnd;
	ULONG m_itemSize;

public:
	CLList();
	~CLList();
	void additem(const void* val, size_t valLen);
	Item* getitem(ULONG index);
	void delitem(ULONG index);
	ULONG getsize();

	void allclear();
};

