/*
 * sample.cpp
 *
 *  Created on: Jun 13, 2018
 *      Author: scott
 */

#include <iostream>
#include "database.h"

#if defined(TEST)

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>

#endif

using namespace std;

database db;

//Function-1: add a record for a single call. Takes 2 parameters: calling number and number of minutes.
void addRecord(unsigned long number, unsigned short minutes) {
	db.addRecord(number, minutes);
}

//Function-2: print most busy numbers. Takes single parameter (N) and prints N number of telephone
//numbers along with their total minutes in sorted order.
// Assuming a descending order from highest number of minutes to lowest.
void printTopBusy(unsigned int N) {
	cout << "number" << '\t' << "minutes" << endl;
	db.printTopBusy(N);
}

void addSampleData(void);

int main(int argc, const char * argv[]) {
#if defined(TEST)
	// Create the event manager and test controller
	CPPUNIT_NS::TestResult controller;

	// Add a listener that collects test result
	CPPUNIT_NS::TestResultCollector result;
	controller.addListener( &result );

	// Add a listener that print dots as test run.
	CPPUNIT_NS::BriefTestProgressListener progress;
	controller.addListener( &progress );

	// Add the top suite to the test runner
	CPPUNIT_NS::TestRunner runner;
	runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest() );
	runner.run( controller );
#endif

	addSampleData();
	unsigned int numberToPrint = 10; // defaulting to 10
	if (argc == 2) {
		numberToPrint = atoi(argv[1]);
	}
	printTopBusy(numberToPrint);

#if defined(TEST)
	// Print test in a compiler compatible format.
	CPPUNIT_NS::CompilerOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
	outputter.write();

	return result.wasSuccessful() ? 0 : 1;
#else
	return 0;
#endif
}

// This function just adds 100 records to the database. The numbers and minutes are just
// random bashing on the keyboard to generate some values. Then I copied and pasted the
// first 10 items and bashed some more numbers to have some variety.
void addSampleData(void) {
	// adding some sample data to the database
	addRecord(1234, 12);
	addRecord(1234, 234);
	addRecord(65, 235);
	addRecord(87, 78);
	addRecord(26, 5);
	addRecord(24362346, 2);
	addRecord(26, 890);
	addRecord(78089, 54);
	addRecord(2436, 58);
	addRecord(2436, 58);

	addRecord(23454, 234);
	addRecord(35345, 23);
	addRecord(32345, 5);
	addRecord(34554, 23);
	addRecord(54663, 5);
	addRecord(34354, 2);
	addRecord(12355, 5);
	addRecord(34252, 1234);
	addRecord(23451, 32);
	addRecord(23423, 32);

	addRecord(234532345, 4);
	addRecord(234523455, 78);
	addRecord(1321234512, 9);
	addRecord(1234123423, 35);
	addRecord(345134512, 9);
	addRecord(234123461, 79);
	addRecord(213516431, 80);
	addRecord(123412134, 3);
	addRecord(123123552, 24);
	addRecord(123512355, 5);

	addRecord(1234561436, 64);
	addRecord(1346346436, 24);
	addRecord(1346346346, 13);
	addRecord(1451346134, 12);
	addRecord(1346134663, 3);
	addRecord(1346143646, 35);
	addRecord(1346134664, 35);
	addRecord(1346134646, 64);
	addRecord(1346346431, 5);
	addRecord(1346346436, 46);

	addRecord(7890, 7);
	addRecord(8970, 79);
	addRecord(8900, 688);
	addRecord(7890, 86);
	addRecord(8907, 5);
	addRecord(7890, 57);
	addRecord(7807, 8);
	addRecord(8790, 47);
	addRecord(8900, 84);
	addRecord(7890, 47);

	addRecord(5858, 26);
	addRecord(5888, 6);
	addRecord(5485, 612);
	addRecord(5467, 1);
	addRecord(5468, 62);
	addRecord(7865, 62);
	addRecord(7854, 26);
	addRecord(7896, 62);
	addRecord(7891, 74);
	addRecord(7893, 47);

	addRecord(1234, 47);
	addRecord(1234, 47);
	addRecord(65, 16);
	addRecord(87, 15);
	addRecord(26, 15);
	addRecord(24362346, 62);
	addRecord(26, 74);
	addRecord(78089, 85);
	addRecord(2436, 589);
	addRecord(2436, 95);

	addRecord(1234, 95);
	addRecord(1234, 8);
	addRecord(65, 93);
	addRecord(87, 28);
	addRecord(26, 29);
	addRecord(24362346, 48);
	addRecord(26, 19);
	addRecord(78089, 29);
	addRecord(2436, 237);
	addRecord(2436, 48);

	addRecord(1234, 23);
	addRecord(1234, 4);
	addRecord(65, 921);
	addRecord(87, 32);
	addRecord(26, 42);
	addRecord(24362346, 24);
	addRecord(26, 43);
	addRecord(78089, 53);
	addRecord(2436, 63);
	addRecord(2436, 12);

	addRecord(1234, 3);
	addRecord(1234, 4);
	addRecord(65, 7);
	addRecord(87, 789);
	addRecord(26, 78);
	addRecord(90, 89);
	addRecord(26, 78);
	addRecord(78089, 87);
	addRecord(2436, 78);
	addRecord(2436, 234);
}
