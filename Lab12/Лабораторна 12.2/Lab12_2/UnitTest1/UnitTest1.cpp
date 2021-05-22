#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_2/Lab12_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			Elem *top = NULL;
			int N;
			bool r = false;

			try
			{
				::push(top);
				::CheckDuplicates(top, r);
				::Print(top);
				::printList_Rec(top);
				::createList_Rec(N, top);
				::CheckRec(top, r);
				Logger::WriteMessage("All methods tests is succedd!");
			}
			catch (...) { FailTest(); }
		}
	private:
		void FailTest()
		{
			Logger::WriteMessage("Failed test!");
		}
	};
}