#pragma once

#include <string>
#include <vector>

namespace vvc {

struct VVCParameter {};

struct VVCGroupOfFrame {};

void loadParameter(const std::string& filepath, VVCParameter& parameter);

class VVCEncoder {
 protected:
  VVCParameter parameter_;

 public:
  VVCEncoder(const VVCParameter& parameter);

  void encoding(const VVCGroupOfFrame& frames, std::vector<char>& bytes);
};

}  // namespace vvc