#include <exception>
#include <iostream>

#include "Exceptions.h"

typedef struct Data {
  int data1;
  int data2;
  int data3;
} Data;

void f1(Data& data);
void f2(Data& data);
void f3(Data& data);

int main() {
  Data data;

  try {
    f1(data);
    std::cout << "data=Data(";
    std::cout << "data1=" << data.data1 << ", ";
    std::cout << "data2=" << data.data2 << ", ";
    std::cout << "data3=" << data.data3;
    std::cout << ")" << std::endl;
  } catch (const std::exception& e) {
    std::cout << "error=" << e.what() << std::endl;
  }

  return 0;
}

void f1(Data& data) {
  try {
    f2(data);
    f3(data);
    if (true) {
      data.data1 = 1;
      return;
    }
    throw Exception1("Exception1");
  } catch (Exception3& e) {
    data.data1 = 999;
  }
}

void f2(Data& data) {
  if (true) {
    data.data2 = 2;
    return;
  }
  throw Exception2("ERROR2");
}

void f3(Data& data) {
  if (true) {
    data.data3 = 3;
    return;
  }
  throw Exception3("ERROR3");
}
