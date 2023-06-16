#include <iostream>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest/doctest.h"


int sayHello() {
    return 1;
}

TEST_CASE("test_sayHello")
{
    std::cout << "test_sayHello" << std::endl;
    INFO("test_sayHello");
    CHECK(1 == sayHello());
}
