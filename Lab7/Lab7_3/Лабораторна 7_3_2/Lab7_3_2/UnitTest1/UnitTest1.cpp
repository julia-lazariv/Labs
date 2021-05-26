#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_3_2/Lab7_3_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			int Low = -9;
			int High = 9;
			int k = 0, 
				n = 0;
			int **a = new int *[k];
			int S = 0;

			try
			{
				::InputRows(a, k, n, 0);
				::PrintRows(a, n, k, 0);
				::NumberNull(a, k, n, S, 0);
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