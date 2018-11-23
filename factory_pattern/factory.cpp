#include <iostream>

//抽象类
class ISplitter {
public:
    ISplitter() = default;
    virtual ~ISplitter() {}
    virtual void split() = 0;
};

//具体类
class BinarySplitter : public ISplitter {
public:
    virtual void split() override {
        std::cout << "binary split" << std::endl;
    }
};
class TxtSplitter : public ISplitter {
public:
    virtual void split() override {
        std::cout << "txt split" << std::endl;
    }
};
class PictureSplitter : public ISplitter {
public:
    virtual void split() override {
        std::cout << "picture split" << std::endl;
    }
};
//....待扩展，修改

//工厂基类
class SplitterFactory {
public:
    virtual ~SplitterFactory() {};
    virtual ISplitter* CreateSplitter() = 0;
};

//具体工厂
class BinarySplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() override {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() override {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory {
public:
    virtual ISplitter* CreateSplitter() override {
        return new PictureSplitter();
    }
};

//假如一个类可能用到split方法，可以用工厂类，避免直接依赖具体类
class MainForm {
public:
    MainForm(SplitterFactory* factory) : factory(factory) {}
    ~MainForm() {}
    void button_click() {
        ISplitter* splitter = factory->CreateSplitter();
        splitter->split();
    }
private:
    SplitterFactory* factory;
};

int main() {
    SplitterFactory* factory = new BinarySplitterFactory();
    MainForm* mainform = new MainForm(factory);
    mainform->button_click();
}
