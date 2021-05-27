#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_5/Lab12_5.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			Stack st;
			int size;		
			try
			{
				::create(size);
				::userinput();
				::getfromfile();
				::print(st);
				::task(st);
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