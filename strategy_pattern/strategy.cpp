#include <iostream>

class Context;
class TaxStrategy {
public:
    virtual double Caculate(const Context& context) = 0;
    virtual ~TaxStrategy() {}
};

class ChinaTax : public TaxStrategy {
public:
    virtual double Caculate(const Context& context) override {
        std::cout << "china 17%" << std::endl;
    }
};

class USTax : public TaxStrategy {
public:
    virtual double Caculate(const Context& context) override {
        std::cout << "US 10%" << std::endl;
    }
};

//可灵活扩展
class JapanTax : public TaxStrategy {
public:
    virtual double Caculate(const Context& context) override {
        std::cout << "Japan 15%" << std::endl;
    }
};

class StrategyFactory;
class SalesOrder {
public:
    SalesOrder(StrategyFactory* strategyfactory) {
        this->strategy = strategyfactory->NewStrategy();
    }
    ~SalesOrder() {
        delete this->strategy;
    }
    double CaculateTax() {
        Context context();
        double val = Strategy->Caculate(context);
    }

private:
    TaxStrategy* strategy;
}
