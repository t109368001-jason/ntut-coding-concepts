#include <fstream>
#include <iostream>
#include <memory>

#include <CoderType.h>

#include <Encoders.h>

using namespace std;
using namespace vc;

int main() {
  vc::CoderType coderType  = vc::parseCoderType("AVC");
  string        configFile = "/path/to/config";

  VirtualParameterPtr parameter;
  VirtualEncoderPtr   encoder;

  if (coderType == vc::CoderType::AVC) {
    avcInit(configFile, encoder);
  } else if (coderType == vc::CoderType::HEVC) {
    hevcInit(configFile, parameter, encoder);
  } else if (coderType == vc::CoderType::VVC) {
    vvcInit(configFile, parameter, encoder);
  }

  ofstream      ofs("./output.bin", ios::out | ios::binary);
  GroupOfFrames frames;
  if (coderType == vc::CoderType::AVC) {
    vc::avcEncode(*std::static_pointer_cast<avc::AVCEncoder>(encoder), ofs, frames);
  } else if (coderType == vc::CoderType::HEVC) {
    vc::hevcEncode(*std::static_pointer_cast<hevc::HEVCEncoder>(encoder), ofs, frames);
  } else if (coderType == vc::CoderType::VVC) {
    vc::vvcEncode(*std::static_pointer_cast<vvc::VVCEncoder>(encoder), ofs, frames);
  }

  return 0;
}
