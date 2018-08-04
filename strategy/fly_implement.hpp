#ifndef HEAD_FIRST_DESIGN_PATTERN_STRATEGY
#define HEAD_FIRST_DESIGN_PATTERN_STRATEGY

#include <iostream>
#include "flybehavior.h"

class FlyWithWings : public FlyBehavior {
    void fly() {
        std::cout << "ok! i am flying with my swing" << std::endl;
    }
};

class FlyNoWay : public FlyBehavior {
    void fly() {
        std::cout << "unfornatunally! i can not fly" << std::endl;
    }
};

#endif
