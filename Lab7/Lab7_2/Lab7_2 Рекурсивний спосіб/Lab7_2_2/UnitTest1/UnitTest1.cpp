#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_2_2/Lab7_2_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			int Low = 1;
			int High = 20;

			int rowCount = 0;
			int colCount = 0;

			int **a = new int*[rowCount];
			int*min = new int[rowCount];

			try
			{
				::Create(a, rowCount, colCount, Low, High, 0, 0);
				::Print(a, rowCount, colCount, 0, 0);
				::s1(a, min, rowCount, colCount, Low, High, 0, 0);
				::sum(min, rowCount, 0, 0);
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