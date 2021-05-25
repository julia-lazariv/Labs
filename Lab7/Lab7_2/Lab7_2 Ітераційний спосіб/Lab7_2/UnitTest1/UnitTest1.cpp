#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_2/Lab7_2.cpp"

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

			int rowCount = 5;
			int colCount = 4;

			int **a = new int*[rowCount];
			for (int i = 0; i < rowCount; i++)
				a[i] = new int[colCount];

			try
			{
				::Create(a, rowCount, colCount, Low, High);
				::Print(a, rowCount, colCount);
				::swap(a, rowCount, colCount);
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