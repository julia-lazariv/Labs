#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab11_3_1/Lab11_3_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			string filename;
			string filenameI;
			Student student;
			string iLastName;

			try
			{
				::Create(filename);
				::Print(filename);
				::SortFiz(filename);
				::BinSearch(filename, iLastName, student.spec);
				::indexSort(filename, filenameI);
				::printIndexSort(filename, filenameI);
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