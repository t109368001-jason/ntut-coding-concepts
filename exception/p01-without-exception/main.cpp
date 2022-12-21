#include <iostream>

enum ExitCode {
  OK = 0,
  ERROR1,
  ERROR2,
  ERROR3,
};

typedef struct Data {
  int data1;
  int data2;
  int data3;
} Data;

ExitCode f1(Data& data);
ExitCode f2(Data& data);
ExitCode f3(Data& data);

int main() {
  Data data;

  ExitCode exitCode = f1(data);

  if (exitCode == OK) {
    std::cout << "data=Data(";
    std::cout << "data1=" << data.data1 << ", ";
    std::cout << "data2=" << data.data2 << ", ";
    std::cout << "data3=" << data.data3;
    std::cout << ")" << std::endl;
  } else {
    std::cout << "exitCode=";
    switch (exitCode) {
      case ERROR1: std::cout << "ERROR1"; break;
      case ERROR2: std::cout << "ERROR2"; break;
      case ERROR3: std::cout << "ERROR3"; break;
    }
    std::cout << std::endl;
  }

  return 0;
}

ExitCode f1(Data& data) {
  ExitCode exitCode = OK;
  if ((exitCode = f2(data)) != OK) {
    return exitCode;
  } else if ((exitCode = f3(data)) != OK) {
    return exitCode;
  }
  if (true) {
    data.data1 = 1;
  } else {
    return ERROR1;
  }

  return exitCode;
}

ExitCode f2(Data& data) {
  if (true) {
    data.data2 = 2;
    return OK;
  }
  return ERROR2;
}

ExitCode f3(Data& data) {
  if (true) {
    data.data3 = 3;
    return OK;
  }
  return ERROR3;
}