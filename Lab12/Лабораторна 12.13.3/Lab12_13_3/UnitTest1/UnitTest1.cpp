#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_13_3/Lab12_13_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			Node *first = new Node;
			try
			{
				::addNode(first);
				::outNode(first);
				::outNodeNum(first);
				::deleteNode(first);
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