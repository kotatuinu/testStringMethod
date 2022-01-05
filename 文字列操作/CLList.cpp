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
		// �͈͊O�G���[
		return;
	}
	if (m_itemSize == 1) {
		// ���ڂ�1�����Ȃ��ꍇ
		delete m_itemTop;
		m_itemTop = NULL;
		m_itemEnd = NULL;
	}
	else {
		// ���ڂ�2�ȏ�
		if (index == 0) {
			// �擪���폜
			Item* currentItem = m_itemTop;
			m_itemTop = m_itemTop->itemPtr;
			delete currentItem;
		}
		else {
			// �i�Ō�������j2�Ԗڈȍ~���폜
			Item* beforeItem = getitem(index - 1);

			// �폜���鍀��
			Item* currentItem = beforeItem->itemPtr;

			if (currentItem->itemPtr == NULL) {
				// �Ō�̍��ڂ��폜����ꍇ
				m_itemEnd = beforeItem;
			}
			beforeItem->itemPtr = currentItem->itemPtr;

			// �w�肵�����ڂ̗̈���폜
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
