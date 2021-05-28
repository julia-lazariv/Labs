#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_10/Lab12_10.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(All_methods)
		{
			std::string filename;
			std::string str = "";
			Node* node = new Node;;
			try
			{
				::StringFromfile(filename);
				::recurs(str, node);
				::recurs(node);
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