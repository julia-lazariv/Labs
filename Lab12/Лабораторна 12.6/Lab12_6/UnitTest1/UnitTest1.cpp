#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_6/Lab12_6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			Elem *first = NULL,
				*last = NULL;
			int i = 0;
			try
			{
				::enqueue(first, last, i);
				::dequeue(first, last);
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