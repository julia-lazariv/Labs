#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_4/Lab12_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			Elem *L = NULL;
			Info value = NULL;
			int N;
			int count = 1;

			try
			{
				::Insert(L, value);
				::Remove(L);
				::Count(L);
				::Print(L);
				::insertDupl(L, value);
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