#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_7/Lab12_7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			slist* lst = NULL;
			try
			{
				::slist_fill(lst);
				::slist_print(std::cout, lst);
				::slist_rev(lst);
				::slist_clear(lst);
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