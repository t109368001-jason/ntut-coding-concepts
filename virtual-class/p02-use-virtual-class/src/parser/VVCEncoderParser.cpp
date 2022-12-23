#include <parser/VVCEncoderParser.h>

namespace vc {

void VVCEncoderParser::init(const std::string& filepath) {
  vvc::VVCParameter parameter;
  vvc::loadParameter(filepath, parameter);
  encoder_ = std::make_shared<vvc::VVCEncoder>(parameter);
}

void VVCEncoderParser::encode(const GroupOfFrames& frames, std::ostream& os) {
  if (!encoder_) {
    throw std::logic_error("uninitialized error");
  }
  vvc::VVCGroupOfFrame vvcFrames = toVVCFrames(frames);
  std::vector<char>    bytes;
  encoder_->encoding(vvcFrames, bytes);
  for (const char& byte : bytes) {
    os << byte;
  }
}

vvc::VVCGroupOfFrame VVCEncoderParser::toVVCFrames(const GroupOfFrames& frames) {
  return {};
}

}  // namespace vc