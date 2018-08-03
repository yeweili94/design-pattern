#include "flybehavior.h"
#include "quackbehavior.h"

class Duck {
public:
    Duck() {}
    void performFly() {
        _flybehavior->fly();
    }
    void performQuack() {
        _quackbehavior->quack();
    }
    void swim() {
        std::cout << "all duck can swim..." << std::endl;
    }
    virtual void display() = 0;

protected:
    FlyBehavior* _flybehavior;
    QuackBehavior* _quackbehavior;
};

class MallardDuck : public Duck {
public:
    MallardDuck() : Duck() {
        _quackbehavior = new Quack();
        _flybehavior = new FlyWithWings();
    }
    void display() {
        std::cout << "I am a MallardDuck" << std::endl;
    }
};

class RocketDuck : public Duck {
public:
    RocketDuck() : Duck() {
        _quackbehavior = new MuteQuack();
        _flybehavior = new FlyWithRocket();
    }
    void display() {
        std::cout << "I am a RocketDuck...." << std::endl;
    }
};


int main() {
    Duck *mallard = new MallardDuck();
    mallard->display();
    mallard->performQuack();
    mallard->performFly();
    
    Duck *duck = new RocketDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
}
