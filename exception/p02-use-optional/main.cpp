#include <iostream>
#include <optional>

enum ExitCode {
  ERROR1,
  ERROR2,
  ERROR3,
};

typedef struct Data {
  int data1;
  int data2;
  int data3;
} Data;

std::optional<ExitCode> f1(Data& data);
std::optional<ExitCode> f2(Data& data);
std::optional<ExitCode> f3(Data& data);

int main() {
  Data data;

  std::optional<ExitCode> exitCodeOpt = f1(data);

  if (!exitCodeOpt) {
    std::cout << "data=Data(";
    std::cout << "data1=" << data.data1 << ", ";
    std::cout << "data2=" << data.data2 << ", ";
    std::cout << "data3=" << data.data3;
    std::cout << ")" << std::endl;
  } else {
    std::cout << "exitCode=";
    switch (exitCodeOpt.value()) {
      case ERROR1: std::cout << "ERROR1"; break;
      case ERROR2: std::cout << "ERROR2"; break;
      case ERROR3: std::cout << "ERROR3"; break;
    }
    std::cout << std::endl;
  }

  return 0;
}

std::optional<ExitCode> f1(Data& data) {
  std::optional<ExitCode> exitCodeOpt;
  if ((exitCodeOpt = f2(data)) || (exitCodeOpt = f3(data))) {
    return exitCodeOpt;
  }
  if (true) {
    data.data1 = 1;
    return std::nullopt;
  }
  return {ERROR1};
}

std::optional<ExitCode> f2(Data& data) {
  if (true) {
    data.data2 = 2;
    return std::nullopt;
  }
  return {ERROR2};
}

std::optional<ExitCode> f3(Data& data) {
  if (true) {
    data.data3 = 3;
    return std::nullopt;
  }
  return {ERROR3};
}
