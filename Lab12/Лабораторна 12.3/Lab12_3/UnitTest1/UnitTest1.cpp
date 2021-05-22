#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_3/Lab12_3.cpp"

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
			int count = 1;

			try
			{
				::push(top);
				::Count(top, count);
				::Print(top);
				::printList_Rec(top);
				::createList_Rec(N, top);
				::CountRec(top, count);
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