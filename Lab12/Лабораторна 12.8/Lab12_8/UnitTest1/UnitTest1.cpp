#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_8/Lab12_8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:		
		TEST_METHOD(All_methods)
		{
			elem* head = NULL;
			elem* last = NULL;
			try
			{
				::CreateDoubleList(head, last);
				::Print_Double_List(head, head);
				::Search(head, head);
				::Print_Double_List(head, head);
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