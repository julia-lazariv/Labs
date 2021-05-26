#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_3_4/Lab7_3_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			int Low = 0;
			int High = 5;
			int k = 0,
				n = 0,
				S = 0;
			int** a = new int*[k];

			try
			{
				::InputRows(a, n, k, 0);
				::PrintRows(a, n, k, 0);
				::Sum(a, k, n, S, 0, 0, 0);
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