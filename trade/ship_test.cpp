/*
 * ship_test.cpp
 *
 *  Created on: 01/09/2013
 *      Author: to
 */

#include "ship.h"
#define BOOST_TEST_MODULE MyTest
#define BOOST_TEST_NO_LIB
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test1 )
{
    Ship ship;

    BOOST_CHECK( ship.is_valid());
}


