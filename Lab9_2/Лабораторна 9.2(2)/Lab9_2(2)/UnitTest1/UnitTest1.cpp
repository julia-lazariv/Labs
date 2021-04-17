#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9_2(2)/Lab9_2(2).cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(All_methods)
		{
			int N = 0,
				i = 0;
			Pracivnyk *p = new Pracivnyk[N];

			try
			{
				::Create(p, N);
				::Print(p, N);
				::IndexSort(p, N);
				::PrintIndexSorted(p, IndexSort(p, N), N);
				::serbal1(p, N, i);
				::func(p, N, i);
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