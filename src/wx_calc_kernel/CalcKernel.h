#pragma once

#include "wx_calc_common.h"

KHL_CALC_START

class DllExport Calculator {
public:
    Calculator();
    ~Calculator();
public:
    double add(double a, double b);
};

KHL_CALC_END

