#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"

#include <boost/multiprecision/cpp_int.hpp>

int sayHello() {

    using namespace boost::multiprecision;

    cpp_int num1 = 123456789;
    cpp_int num2 = 987654321;
    cpp_int result = num1 + num2;

    std::cout << "Result: " << result << std::endl;

    return 1;
}

TEST_CASE("test_sayHello")
{
    std::cout << "test_sayHello" << std::endl;
    INFO("test_sayHello");
    CHECK(1 == sayHello());
}
