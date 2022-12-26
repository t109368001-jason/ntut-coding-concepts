#include <VVCEncoderParser.h>

#include <vc/Encoder.h>

namespace vcs {

vc::GroupOfFrame toVVCFrames(const GroupOfFrames& frames);

void VVCEncoderParser::init(const std::string& filepath) {
  vc::Parameter parameter;
  vc::loadParameter(filepath, parameter);
  encoder_ = std::make_shared<vc::VideoEncoder>(parameter);
}

void VVCEncoderParser::encode(const GroupOfFrames& frames, std::ostream& os) {
  if (!encoder_) {
    throw std::logic_error("uninitialized error");
  }
  vc::GroupOfFrame  vvcFrames = toVVCFrames(frames);
  std::vector<char> bytes;
  std::static_pointer_cast<vc::VideoEncoder>(encoder_)->encoding(vvcFrames, bytes);
  for (const char& byte : bytes) {
    os << byte;
  }
}

vc::GroupOfFrame toVVCFrames(const GroupOfFrames& frames) {
  return {};
}

}  // namespace vcs