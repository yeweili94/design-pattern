#include "flybehavior.h"
#include "quackbehavior.h"

class Duck {
public:
    Duck() = default;
    virtual ~Duck() {}
    void performFly() {
        _flybehavior->fly();
    }
    void performQuack() {
        _quackbehavior->quack();
    }
    void setflybehavior(FlyBehavior *fb) {
        _flybehavior = fb;
    }
    void setquackbehavior(QuackBehavior *qb) {
        _quackbehavior = qb;
    }
    void swim() {
        std::cout << "all duck can swim..." << std::endl;
    }
    virtual void display() = 0;

protected:
    FlyBehavior* _flybehavior;
    QuackBehavior* _quackbehavior;
};

//MallardDuck
class MallardDuck : public Duck {
public:
    MallardDuck() : Duck() {
        _quackbehavior = new Quack();
        _flybehavior = new FlyWithWings();
    }
    void display() override{
        std::cout << "I am a MallardDuck" << std::endl;
    }
};

//RocketDuck
class RocketDuck : public Duck {
public:
    RocketDuck() : Duck() {
        _quackbehavior = new MuteQuack();
        _flybehavior = new FlyWithRocket();
    }
    void display() override{
        std::cout << "I am a RocketDuck...." << std::endl;
    }
};

//ModuleDuck
class ModuleDuck : public Duck {
public:
    ModuleDuck() : Duck() {
        _quackbehavior = new MuteQuack();
        //玩具鸭flybehavior暂时没有设置
    }
    void display() override{
        std::cout << "I am a ModuleDuck..." << std::endl;
    }
};

static void printline() {
    std::cout << "**********************************" << std::endl;
}

int main() {
    Duck *mallard = new MallardDuck();
    mallard->display();
    mallard->performQuack();
    mallard->performFly();
    printline();
    //////////////////
    Duck *duck = new RocketDuck();
    duck->display();
    duck->performQuack();
    duck->performFly();
    printline();
    /////////////////
    Duck *moduleduck = new ModuleDuck();
    moduleduck->setflybehavior(new FlyWithRocket());
    moduleduck->display();
    moduleduck->performQuack();
    moduleduck->performFly();
}
