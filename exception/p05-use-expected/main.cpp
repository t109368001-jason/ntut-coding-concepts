#include <iostream>
#include <expected>

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

std::expected<void, ExitCode> f1(Data& data);
std::expected<void, ExitCode> f2(Data& data);
std::expected<void, ExitCode> f3(Data& data);

int main() {
  Data data;

  std::expected<void, ExitCode> exitCodeOpt = f1(data);

  if (exitCodeOpt) {
    std::cout << "data=Data(";
    std::cout << "data1=" << data.data1 << ", ";
    std::cout << "data2=" << data.data2 << ", ";
    std::cout << "data3=" << data.data3;
    std::cout << ")" << std::endl;
  } else {
    std::cout << "exitCode=";
    switch (exitCodeOpt.error()) {
      case ERROR1: std::cout << "ERROR1"; break;
      case ERROR2: std::cout << "ERROR2"; break;
      case ERROR3: std::cout << "ERROR3"; break;
    }
    std::cout << std::endl;
  }

  return 0;
}

std::expected<void, ExitCode> f1(Data& data) {
  std::expected<void, ExitCode> exitCodeOpt;
  if (!(exitCodeOpt = f2(data)) || !(exitCodeOpt = f3(data))) {
    return exitCodeOpt;
  }
  if (true) {
    data.data1 = 1;
    return {};
  }
  return std::unexpected<ExitCode>{ERROR1};
}

std::expected<void, ExitCode> f2(Data& data) {
  if (true) {
    data.data2 = 2;
    return {};
  }
  return std::unexpected<ExitCode>{ERROR2};
}

std::expected<void, ExitCode> f3(Data& data) {
  std::expected<void, ExitCode> expected;
  if (true) {
    data.data3 = 3;
    expected.emplace();
    return {};
  }
  return std::unexpected<ExitCode>{ERROR3};
}
