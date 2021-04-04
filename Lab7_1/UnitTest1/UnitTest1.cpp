#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_1/Lab7_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			int Low = -34;
			int High = 26;

			int rowCount = 8;
			int colCount = 6;

			int S = 0;
			int k = 0;

			int **a = new int*[rowCount];

			for (int i = 0; i < rowCount; i++)
			{
				a[i] = new int[colCount];
			}

			try
			{
				::Create(a, rowCount, colCount, Low, High);
				::Sort(a, rowCount, colCount);
				::Calc(a, rowCount, colCount, S, k);
				::Print(a, rowCount, colCount);
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