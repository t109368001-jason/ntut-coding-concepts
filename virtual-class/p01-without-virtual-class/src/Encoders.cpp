#include <Encoders.h>

using namespace std;
using namespace avc;
using namespace hevc;
using namespace vvc;

namespace vc {

void avcInit(const string& configFile, VirtualEncoderPtr& encoder) {
  auto avcEncoder = make_shared<AVCEncoder>(configFile);

  encoder = std::static_pointer_cast<void>(avcEncoder);
}

void hevcInit(const string& configFile, VirtualParameterPtr& parameter, VirtualEncoderPtr& encoder) {
  auto hevcParameter = make_shared<HEVCParameter>();
  auto hevcEncoder   = make_shared<HEVCEncoder>();
  loadParameter(configFile, *hevcParameter);
  hevcEncoder->init(*hevcParameter);

  parameter = std::static_pointer_cast<void>(hevcParameter);
  encoder   = std::static_pointer_cast<void>(hevcEncoder);
}

void vvcInit(const string& configFile, VirtualParameterPtr& parameter, VirtualEncoderPtr& encoder) {
  auto vvcParameter = make_shared<VVCParameter>();
  loadParameter(configFile, *vvcParameter);
  auto vvcEncoder = make_shared<VVCEncoder>(*vvcParameter);

  parameter = std::static_pointer_cast<void>(vvcParameter);
  encoder   = std::static_pointer_cast<void>(vvcEncoder);
}

AVCGroupOfFrame toAVCFrames(const GroupOfFrames& frames) {
  return {};
}

HEVCGroupOfFrame toHEVCFrames(const GroupOfFrames& frames) {
  return {};
}

VVCGroupOfFrame toVVCFrames(const GroupOfFrames& frames) {
  return {};
}

void avcEncode(AVCEncoder& avcEncoder, ostream& os, const GroupOfFrames& frames) {
  vector<char>           bytes;
  const AVCGroupOfFrame& avcFrames = toAVCFrames(frames);
  avcEncoder.encode(avcFrames, bytes);
  for (const char byte : bytes) {
    os << byte;
  }
}

void hevcEncode(HEVCEncoder& hevcEncoder, ostream& os, const GroupOfFrames& frames) {
  const HEVCGroupOfFrame& hevcFrames = toHEVCFrames(frames);
  hevcEncoder.compress(hevcFrames, os);
}

void vvcEncode(VVCEncoder& vvcEncoder, ostream& os, const GroupOfFrames& frames) {
  vector<char>           bytes;
  const VVCGroupOfFrame& vvcFrames = toVVCFrames(frames);
  vvcEncoder.encoding(vvcFrames, bytes);
  for (const char byte : bytes) {
    os << byte;
  }
}

}  // namespace vc