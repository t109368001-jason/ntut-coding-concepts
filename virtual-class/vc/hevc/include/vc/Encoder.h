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
  void init(const Parameter& parameter);

  void compress(const GroupOfFrame& frames, std::ostream& os);
};

}  // namespace vc