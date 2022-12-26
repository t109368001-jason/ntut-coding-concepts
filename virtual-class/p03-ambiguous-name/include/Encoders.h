#pragma once

#include <CoderType.h>
#include <VirtualEncoder.h>

namespace vcs {

VirtualEncoder::Ptr create(const CoderType& coderType);

}  // namespace vcs