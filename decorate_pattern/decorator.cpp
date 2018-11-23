#include <iostream>

class Stream {
public:
    virtual ~Stream() {};
    virtual void Read() = 0;
    virtual void Write() = 0;
    virtual void Seek() = 0;
};

class FileStream : public Stream {
public:
    virtual void Read() override {
        std::cout << "file stream read" << std::endl;
    }
    virtual void Write() override {
        std::cout << "file stream write" << std::endl;
    }
    virtual void Seek() override {
        std::cout << "file stream seek" << std::endl;
    }
};

class NetWorkStream : public Stream {
public:
    virtual void Read() override {
        std::cout << "network stream read" << std::endl;
    }
    virtual void Write() override {
        std::cout << "network stream write" << std::endl;
    }
    virtual void Seek() override {
        std::cout << "network stream seek" << std::endl;
    }
};

class DecorateStream : public Stream { //这里的继承是为了完成接口规范
protected:
    Stream* stream;
    DecorateStream(Stream* stm) : stream(stm) {
    }
    virtual ~DecorateStream() {}
};

class CryptoStream : public DecorateStream {
public:
    CryptoStream(Stream* stm) : DecorateStream(stm) {}
    virtual void Read() override {
        std::cout << "Cryptoing....." << std::endl;
        stream->Read();
    }
    virtual void Write() override {
        std::cout << "Cryptoing....." << std::endl;
        stream->Write();
    }
    virtual void Seek() override {
        std::cout << "Cryprotoing......" << std::endl;
        stream->Seek();
    }
};

class BufferStream : public DecorateStream {
public:
    BufferStream(Stream* stm) : DecorateStream(stm) {}
    virtual void Read() override {
        std::cout << "Buffering......" << std::endl;
        stream->Read();
    }
    virtual void Write() override {
        std::cout << "Buffering......" << std::endl;
        stream->Write();
    }
    virtual void Seek() override {
        std::cout << "Buffering......" << std::endl;
        stream->Seek();
    }
};

int main() {
FileStream* s1 = new FileStream();
BufferStream* s2 = new BufferStream(s1);
CryptoStream* s3 = new CryptoStream(s2);
s3->Read();
}
