#include <iostream>
#include <memory>

typedef struct Data {
  int data1;
  int data2;
  int data3;
  ~Data() {
    std::cout << "~Data()" << std::endl;
  }
} Data;

void f1(const std::shared_ptr<Data>& data);
void f2(const std::shared_ptr<Data>& data);
void f3(const std::shared_ptr<Data>& data);

int main() {
  auto data = std::make_shared<Data>();

  f1(data);
  f2(data);
  f3(data);

  std::cout << "data=Data(";
  std::cout << "data1=" << data->data1 << ", ";
  std::cout << "data2=" << data->data2 << ", ";
  std::cout << "data3=" << data->data3;
  std::cout << ")" << std::endl;
  return 0;
}

void f1(const std::shared_ptr<Data>& data) {
  data->data1 = 1;
}

void f2(const std::shared_ptr<Data>& data) {
  data->data2 = 2;
}

void f3(const std::shared_ptr<Data>& data) {
  data->data3 = 3;
}
