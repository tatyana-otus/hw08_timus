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
    "7\n"
    "Isenbaev Oparin Toropov\n"
    "Ayzenshteyn Oparin Samsonov\n"
    "Ayzenshteyn Chevdar Samsonov\n"
    "Fominykh Isenbaev Oparin\n"
    "Dublennykh Fominykh Ivankov\n"
    "Burmistrov Dublennykh Kurpilyanskiy\n"
    "Cormen Leiserson Rivest\n";
   

    std::string out_data =
    "Ayzenshteyn 2\n"
    "Burmistrov 3\n"
    "Chevdar 3\n"
    "Cormen undefined\n"
    "Dublennykh 2\n"
    "Fominykh 1\n"
    "Isenbaev 0\n"
    "Ivankov 2\n"
    "Kurpilyanskiy 3\n"
    "Leiserson undefined\n"
    "Oparin 1\n"
    "Rivest undefined\n"
    "Samsonov 2\n"
    "Toropov 1\n";

    iss << in_data;
    process(iss, oss);

    BOOST_CHECK_EQUAL( oss.str(), out_data );
}

BOOST_AUTO_TEST_SUITE_END()