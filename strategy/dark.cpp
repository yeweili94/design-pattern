#ifndef HEAD_FIRST_DESIGN_PATTERN_STRATEGY
#define HEAD_FIRST_DESIGN_PATTERN_STRATEGY
#include <vector>
#include "flybehavior.h"
#include "quackbehavior.h"

class Duck {
    FlyBehavior _flyBehavior;
    QuackBehavior _quackBehavior;
    Duck() {}
    void performFly() {
        _flyBehavior.fly();
    }
    void performQuack() {
        _quackBehavior.quack();
    }
    void swim() {
        std::cout << "All ducks can fly, include decoys!" << std::endl;
    }
}
#endif 
