#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11_2_2/Lab11_2_2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			try
			{
				::Print();
				::AutoInput();
				::UserInput();
				::AverageMark();
				::MaxAverageMark();
				::Proc();
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
