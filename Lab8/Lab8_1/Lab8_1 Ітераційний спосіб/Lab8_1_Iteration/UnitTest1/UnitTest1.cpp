#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab8_1_Iteration/Lab8_1_Iteration.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(All_methods)
		{
			char str[101];
			cout << "Enter string:" << endl;
			cout << endl;
			cin.getline(str, 100);

			bool k = false;

			try
			{
				::Search(str, k);
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