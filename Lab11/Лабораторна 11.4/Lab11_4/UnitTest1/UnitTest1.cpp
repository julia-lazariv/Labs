#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11_4/Lab11_4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			string filename = "t.bin";
			try
			{
				::add();
				::create();
				::autocreate();
				::StartMenu();
				::print(filename);
				::change();
				::remove();
				::find();
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