#define BOOST_TEST_MODULE MyTest
#define  BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include "Transport.h"
BOOST_AUTO_TEST_CASE( my_test )
{
	Transport transport;
	BOOST_CHECK(transport.is_valid());

}

