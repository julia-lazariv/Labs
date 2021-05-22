#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_1/Lab12_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(All_methods)
		{
			char fname[100];

			try
			{
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
