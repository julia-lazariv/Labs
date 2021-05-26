#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11_1/Lab11_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			string filename = "t.bin";
			try
			{
				::CreateBIN(filename);
				::PrintBIN(filename);
				::ProcessBIN1(filename);
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