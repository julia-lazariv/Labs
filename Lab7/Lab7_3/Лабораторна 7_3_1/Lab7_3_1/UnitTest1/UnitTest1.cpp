#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_3_1/Lab7_3_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			int Low = -10;
			int High = 10;
			int k = 0, 
				n = 0;
			int **a = new int *[k];

			try
			{
				::Input(a, k, n);
				::Print(a, n, k);
				::NumberNull(a, k, n);
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