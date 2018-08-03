#include <iostream>

class FlyBehavior {
public:
    FlyBehavior() {}
    virtual void fly() = 0;
};

class FlyWithWings : public FlyBehavior {
public:
    FlyWithWings() : FlyBehavior() {}
    void fly() override {
        std::cout << "fly with wings...." << std::endl;
    }
};

class FLyNoWay : public FlyBehavior {
public:
    FLyNoWay() : FlyBehavior() {}
    void fly() override {
        std::cout << "fly no way..." << std::endl;
    }
};

class FlyWithRocket : public FlyBehavior {
public:
    FlyWithRocket() : FlyBehavior() {}
    void fly() override {
        std::cout << "fly with rocket..." << std::endl;
    }
};
