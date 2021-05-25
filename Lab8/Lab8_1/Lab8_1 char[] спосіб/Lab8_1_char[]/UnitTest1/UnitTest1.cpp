#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_1_char[]/Lab8_1_char[].cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(All_methods)
		{
			char str[101];

			try
			{
				::Search(str);
				::Change(str);
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