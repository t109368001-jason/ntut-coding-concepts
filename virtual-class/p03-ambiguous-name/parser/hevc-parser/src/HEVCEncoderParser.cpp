#include <HEVCEncoderParser.h>

#include <vc/Encoder.h>

namespace vcs {

vc::GroupOfFrame toHEVCFrames(const GroupOfFrames& frames);

void HEVCEncoderParser::init(const std::string& filepath) {
  encoder_ = std::make_shared<vc::VideoEncoder>();
  vc::Parameter parameter;
  vc::loadParameter(filepath, parameter);
  std::static_pointer_cast<vc::VideoEncoder>(encoder_)->init(parameter);
}

void HEVCEncoderParser::encode(const GroupOfFrames& frames, std::ostream& os) {
  if (!encoder_) {
    throw std::logic_error("uninitialized error");
  }
  vc::GroupOfFrame hevcFrames = toHEVCFrames(frames);
  std::static_pointer_cast<vc::VideoEncoder>(encoder_)->compress(hevcFrames, os);
}

vc::GroupOfFrame toHEVCFrames(const GroupOfFrames& frames) {
  return {};
}

}  // namespace vcs