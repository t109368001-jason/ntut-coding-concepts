#include <iostream>

void f1(int* data);
void f2(int* data);
void f3(int* data);

int main() {
  int* data = new int;

  f1(data);
  f2(data);
  f3(data);

  std::cout << "data=" << *data << std::endl;

  delete data;

  return 0;
}

void f1(int* data) {
  *data = 1;
}

void f2(int* data) {
  *data = 2;
}

void f3(int* data) {
  *data = 3;
}
