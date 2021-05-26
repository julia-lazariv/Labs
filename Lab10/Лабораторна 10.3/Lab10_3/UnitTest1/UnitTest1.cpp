#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab10_3/Lab10_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			string str = "";
			room* rooms;
			int size = 15;
			string filename = "";

			try
			{
				::parse(str);
				::add();
				::save(rooms, size, filename);
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