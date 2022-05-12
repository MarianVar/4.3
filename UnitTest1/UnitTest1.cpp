
#include "pch.h"
#include "CppUnitTest.h"
#include "../4.3/4.3.cpp"
#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{

			char fname[100]{ 'U','n','i','t','T','e','s','t' };
			CreateFileToUnit();
			PrintTXT(fname);
		}
	};
}
