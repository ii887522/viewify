// Copyright ii887522

#include "TextModel.h"
#include <nitro/nitro.h>
#include <stdexcept>

using std::runtime_error;
using ii887522::nitro::AnimatedAny;

namespace ii887522::viewify {

TextModel TextModel::Builder::build() {
  if (hasSetDuration) return TextModel{ *this };
  throw runtime_error{ "ImageModel duration is required!" };
}

TextModel::TextModel(const Builder& builder) : a{ AnimatedAny<int>::Builder{ builder.animationController, static_cast<int>(builder.a) }.setDuration(builder.duration).build() } { }

}  // namespace ii887522::viewify
