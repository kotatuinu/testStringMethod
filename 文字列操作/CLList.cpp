#include "CLList.h"

CLList::CLList()
	: m_itemTop(NULL)
	, m_itemEnd(NULL)
	, m_itemSize(0)
{
}

CLList::~CLList()
{
	allclear();
}

void CLList::additem(const void* val, size_t valLen)
{
	Item* item = new Item(val, valLen);
	if (m_itemTop == NULL) {
		m_itemTop = item;
		m_itemEnd = item;
	}
	else {
		m_itemEnd->itemPtr = item;
		m_itemEnd = item;
	}
	m_itemSize++;
}

CLList::Item* CLList::getitem(ULONG index)
{
	if (index >= m_itemSize) {
		return NULL;
	}
	Item* ptr = m_itemTop;
	for (ULONG i = 0; i < index; i++) {
		ptr = ptr->itemPtr;
	}
	return ptr;
}

void CLList::delitem(ULONG index)
{
	if (index >= m_itemSize) {
		// 範囲外エラー
		return;
	}
	if (m_itemSize == 1) {
		// 項目が1つしかない場合
		delete m_itemTop;
		m_itemTop = NULL;
		m_itemEnd = NULL;
	}
	else {
		// 項目が2つ以上
		if (index == 0) {
			// 先頭を削除
			Item* currentItem = m_itemTop;
			m_itemTop = m_itemTop->itemPtr;
			delete currentItem;
		}
		else {
			// （最後を除く）2番目以降を削除
			Item* beforeItem = getitem(index - 1);

			// 削除する項目
			Item* currentItem = beforeItem->itemPtr;

			if (currentItem->itemPtr == NULL) {
				// 最後の項目を削除する場合
				m_itemEnd = beforeItem;
			}
			beforeItem->itemPtr = currentItem->itemPtr;

			// 指定した項目の領域を削除
			delete currentItem;
		}
	}
	m_itemSize--;
}

ULONG CLList::getsize()
{
	return m_itemSize;
}

void CLList::allclear()
{
	Item* tmpPtr = m_itemTop;
	Item* nextPtr = NULL;
	for (ULONG i = 0; i < m_itemSize; i++) {
		nextPtr = tmpPtr->itemPtr;
		delete tmpPtr;
		tmpPtr = nextPtr;
	}
	m_itemTop = NULL;
	m_itemEnd = NULL;
	m_itemSize = 0;
}
