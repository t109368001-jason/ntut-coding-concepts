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

  const VirtualEncoder::Ptr encoder = create(coderType);
  encoder->init(configFile);

  ofstream      ofs("./output.bin", ios::out | ios::binary);
  GroupOfFrames frames;
  encoder->encode(frames, ofs);

  return 0;
}
