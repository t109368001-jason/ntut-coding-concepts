#include <parser/HEVCEncoderParser.h>

namespace vc {

void HEVCEncoderParser::init(const std::string& filepath) {
  encoder_ = std::make_shared<hevc::HEVCEncoder>();
  hevc::HEVCParameter parameter;
  hevc::loadParameter(filepath, parameter);
  encoder_->init(parameter);
}

void HEVCEncoderParser::encode(const GroupOfFrames& frames, std::ostream& os) {
  if (!encoder_) {
    throw std::logic_error("uninitialized error");
  }
  hevc::HEVCGroupOfFrame hevcFrames = toHEVCFrames(frames);
  encoder_->compress(hevcFrames, os);
}

hevc::HEVCGroupOfFrame HEVCEncoderParser::toHEVCFrames(const GroupOfFrames& frames) {
  return {};
}

}  // namespace vc