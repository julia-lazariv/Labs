#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab12_9/Lab12_9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(All_methods)
		{
			TREE* root = NULL;
			try
			{
				::CreateTree(root);
				::PrintTree(root, 0);
				::BalanceHeight(root);
				::DeleteNodeOfTree(root);
				::DeleteBranchOfTree(root);
				::DisplayTree(root, 0);
				::InsertNode(root);
				::Count(root);
				::DestroyTree(root);
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