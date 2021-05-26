#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7_3_3/Lab7_3_3.cpp"

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
				n = 0;
			int** a = new int*[k];

			try
			{
				::Create(a, n, k, Low, High);
				::Print(a, n, k);
				::Change(a, n, k);
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