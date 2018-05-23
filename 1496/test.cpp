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
    "11\n"
    "naucoder\n"
    "iceman\n"
    "abikbaev\n"
    "abikbaev\n"
    "petr\n"
    "abikbaev\n"
    "abikbaev\n"
    "x\n"
    "abikbaev\n"
    "acrush\n"
    "x\n";
   
    std::string out_data =
    "abikbaev\n"
    "x\n";

    iss << in_data;
    process(iss, oss);

    BOOST_CHECK_EQUAL( oss.str(), out_data );
}

BOOST_AUTO_TEST_SUITE_END()