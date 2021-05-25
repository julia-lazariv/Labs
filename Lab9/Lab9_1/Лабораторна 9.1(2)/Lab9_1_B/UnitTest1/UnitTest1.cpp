#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9_1_B/Lab9_1_B.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			int i = 0,
				N = 1;
			Student *p = new Student[N];

			try
			{
				::Create(p, N);
				::Print(p, N);
				::AverageMark(p, N, i);
				::MaxAverageMark(p, N);
				::Proc(p, N);
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