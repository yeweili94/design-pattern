#include <iostream>

class QuackBehavior {
public:
    QuackBehavior() {}
    virtual void quack() = 0;
};

class Quack : public QuackBehavior {
public:
    Quack() : QuackBehavior() {}
    void quack() override {
        std::cout << "quack gua gua gua ..." << std::endl;
    }
};

class Squeak : public QuackBehavior {
public:
    Squeak() : QuackBehavior() {}
    void quack() override {
        std::cout << "quack zi zi zi..." << std::endl;
    }
};

class MuteQuack : public QuackBehavior {
public:
    MuteQuack() : QuackBehavior() {}
    void quack() override {
        std::cout << "can not quack..." << std::endl;
    }
};
