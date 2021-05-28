#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab9_3/Lab9_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			room* rooms = new room[15];
			int size = 15;
			try
			{
				::StartMenu(rooms, size);
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