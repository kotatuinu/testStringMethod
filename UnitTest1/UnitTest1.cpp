//#include "pch.h"
#include "CppUnitTest.h"
#include "CLList.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod_allClear_empty)
		{
			try {
				CLList* obj = new CLList();
				obj->allclear();
				delete obj;
				Assert::IsTrue(true);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(TestMethod_1項目登録)
		{
			try {
				CLList obj;
				char data[] = "テスト１";
				obj.additem((const void*)data, strlen(data)+1);

				Assert::IsTrue(obj.getsize() == 1);
				CLList::Item* item = obj.getitem(0);
				char* itemVal = (char*)item->val;
				Assert::IsTrue(strcmp(data, itemVal) == 0);

				item = obj.getitem(1);
				Assert::IsNull(item);

				obj.allclear();
				Assert::IsTrue(obj.getsize()==0);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(TestMethod_2項目登録)
		{
			try {
				CLList obj;
				char data1[] = "テスト１";
				obj.additem((const void*)data1, strlen(data1) + 1);
				char data2[] = "テスト２";
				obj.additem((const void*)data2, strlen(data2) + 1);
				Assert::IsTrue(obj.getsize() == 2);

				CLList::Item* item = obj.getitem(0);
				char* itemVal = (char*)item->val;
				Assert::IsTrue(strcmp(data1, itemVal) == 0);

				item = obj.getitem(1);
				itemVal = (char*)item->val;
				Assert::IsTrue(strcmp(data2, itemVal) == 0);

				item = obj.getitem(2);
				Assert::IsNull(item);

				obj.allclear();
				Assert::IsTrue(obj.getsize() == 0);
			}
			catch (...) {
				Assert::Fail();
			}
		}

		TEST_METHOD(TestMethod_項目削除)
		{
			try {
				CLList obj;
				char data1[] = "テスト１";
				obj.additem((const void*)data1, strlen(data1) + 1);
				char data2[] = "テスト２";
				obj.additem((const void*)data2, strlen(data2) + 1);
				char data3[] = "テスト３";
				obj.additem((const void*)data3, strlen(data3) + 1);
				Assert::IsTrue(obj.getsize() == 3);
				
				obj.delitem(1);
				obj.delitem(1);
				obj.delitem(0);

				Assert::IsTrue(obj.getsize() == 0);
			}
			catch (...) {
				Assert::Fail();
			}
		}

	};
}
