#pragma once

#include <exception>

class Exception1 : public std::logic_error {
 public:
  Exception1(const std::string& what) : std::logic_error(what) {  // NOLINT(google-explicit-constructor)
  }
};

class Exception2 : public std::logic_error {
 public:
  Exception2(const std::string& what) : std::logic_error(what) {  // NOLINT(google-explicit-constructor)
  }
};

class Exception3 : public std::logic_error {
 public:
  Exception3(const std::string& what) : std::logic_error(what) {  // NOLINT(google-explicit-constructor)
  }
};