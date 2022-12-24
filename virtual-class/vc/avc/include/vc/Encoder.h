#pragma once

#include <string>
#include <vector>

namespace vc {

struct Parameter {};

struct GroupOfFrame {};

class VideoEncoder {
 protected:
  Parameter parameter_;

 public:
  VideoEncoder(const std::string& filepath);

  void encode(const GroupOfFrame& frames, std::vector<char>& bytes);

 private:
  void loadParameter(const std::string& filepath);
};

}  // namespace vc