/*
 * database_test.cpp
 *
 *  Created on: Jun 13, 2018
 *      Author: scott
 */

#include "database.h"

#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/config/SourcePrefix.h>

class database_test : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( database_test );
	CPPUNIT_TEST( testAddRecord );
	CPPUNIT_TEST_SUITE_END();

protected:
	void testAddRecord();
};

CPPUNIT_TEST_SUITE_REGISTRATION( database_test );

void database_test::testAddRecord() {
	database db;

	CPPUNIT_ASSERT( true == db.callRecords.empty());
	db.addRecord(12345, 42);
	CPPUNIT_ASSERT( false == db.callRecords.empty());
	CPPUNIT_ASSERT(1 == db.callRecords.size());
	CPPUNIT_ASSERT(12345 == (*db.callRecords.begin()).first.number());
	CPPUNIT_ASSERT(42 == (*db.callRecords.begin()).second);

	// make sure an invalid number is not added
	db.addRecord(0, 34);
	CPPUNIT_ASSERT(1 == db.callRecords.size());
}
