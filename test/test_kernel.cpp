#include <iostream>
#include <memory>
#include <format>


#include "doctest/doctest.h"
#include "CalcKernel.h"

TEST_CASE("test_kernel")
{
    SUBCASE("test_kernel_001")
    {
        std::cout << "test_kernel_001" << std::endl;
        auto kernel = std::make_unique<khl::calc::Calculator>();
        CHECK(3 == static_cast<int>(kernel->add(1, 2)));
    }
}
