#include "process.h"
#define BOOST_TEST_MODULE test_main
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

using boost::test_tools::output_test_stream;


BOOST_AUTO_TEST_SUITE(test_suite_main)

BOOST_AUTO_TEST_CASE(base)
{
    std::stringstream iss;
    std::stringstream oss;

    std::string  in_data = 
    "2\n"
    "1054\n"
    "1492\n"
    "4\n"
    "1492\n"
    "65536\n"
    "1492\n"
    "100\n"; 

    std::string out_data ="2\n";

    iss << in_data;
    process(iss, oss);

    BOOST_CHECK_EQUAL( oss.str(), out_data );
}

BOOST_AUTO_TEST_SUITE_END()