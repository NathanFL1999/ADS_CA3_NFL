#include "pch.h"
#include "CppUnitTest.h"
#include "../ADS_CA3_NFL/SalesRecords.h"
#include "../ADS_CA3_NFL/FileInputNode.h"
#include "../ADS_CA3_NFL/Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


/***** To Do *****/
// Test parse method
// Test if report is being generated
// Test Main sort method by specified field

namespace ADSCA3TEST
{
	TEST_CLASS(ADS_CA3_TEST)
	{
	public:
		
		TEST_METHOD_INITIALIZE(setup)
		{
			list<SalesRecords> salesRecords;
		}

		TEST_METHOD(parseSales)
		{
			list<SalesRecords> salesRecords;


		}
	};
}
