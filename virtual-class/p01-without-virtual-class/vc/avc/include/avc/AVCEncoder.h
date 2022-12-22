#pragma once

#include <string>
#include <vector>

namespace avc {

struct AVCParameter {};

struct AVCGroupOfFrame {};

class AVCEncoder {
 protected:
  AVCParameter parameter_;

 public:
  AVCEncoder(const std::string& filepath);

  void encode(const AVCGroupOfFrame& frames, std::vector<char>& bytes);

 private:
  void loadParameter(const std::string& filepath);
};

}  // namespace avc