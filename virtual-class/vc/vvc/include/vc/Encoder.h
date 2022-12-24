#pragma once

#include <string>
#include <vector>

namespace vc {

struct Parameter {};

struct GroupOfFrame {};

void loadParameter(const std::string& filepath, Parameter& parameter);

class VideoEncoder {
 protected:
  Parameter parameter_;

 public:
  VideoEncoder(const Parameter& parameter);

  void encoding(const GroupOfFrame& frames, std::vector<char>& bytes);
};

}  // namespace vc