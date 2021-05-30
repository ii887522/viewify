// Copyright ii887522

#ifdef CONSOLE_TEST

#include "ImageModel.test.h"
#include <cassert>
#include <stdexcept>
#include "../../main/Model/ImageModel.h"

using std::runtime_error;

namespace ii887522::viewify {

static void testBuild() {
  assert(ImageModel::Builder{ 0u }.setDuration(125u).build().getA() == 0u);
  assert(ImageModel::Builder{ 1u }.setDuration(125u).build().getA() == 1u);
  assert(ImageModel::Builder{ 1u }.setDuration(250u).build().getA() == 1u);
  try {
    ImageModel::Builder{ 0u }.build();
  } catch (const runtime_error&) {
    try {
      ImageModel::Builder{ 1u }.build();
    } catch (const runtime_error&) {
      return;
    }
  }
  assert(false);
}

static void testShow() {
  {
    ImageModel model{ ImageModel::Builder{ 0u }.setDuration(125u).build() };
    model.show();
    assert(model.getA() == 0u);
  }
  {
    ImageModel model{ ImageModel::Builder{ 0u }.setDuration(250u).build() };
    model.show();
    assert(model.getA() == 0u);
  }
  {
    ImageModel model{ ImageModel::Builder{ 1u }.setDuration(250u).build() };
    model.show();
    assert(model.getA() == 1u);
  }
}

static void testHide() {
  {
    ImageModel model{ ImageModel::Builder{ 0u }.setDuration(125u).build() };
    model.hide();
    assert(model.getA() == 0u);
  }
  {
    ImageModel model{ ImageModel::Builder{ 0u }.setDuration(250u).build() };
    model.hide();
    assert(model.getA() == 0u);
  }
  {
    ImageModel model{ ImageModel::Builder{ 1u }.setDuration(250u).build() };
    model.hide();
    assert(model.getA() == 0u);
  }
}

static void testStep() {
  {
    ImageModel model{ ImageModel::Builder{ 0u }.setDuration(125u).build() };
    model.show();
    model.step(15u);
    assert(model.getA() == 30u);
    model.step(20u);
    assert(model.getA() == 71u);
    model.step(25u);
    assert(model.getA() == 122u);
    model.step(30u);
    assert(model.getA() == 183u);
    model.step(35u);
    assert(model.getA() == 255u);
  }
  {
    ImageModel model{ ImageModel::Builder{ 0u }.setDuration(250u).build() };
    model.show();
    model.step(30u);
    assert(model.getA() == 30u);
    model.step(40u);
    assert(model.getA() == 71u);
    model.step(50u);
    assert(model.getA() == 122u);
    model.step(60u);
    assert(model.getA() == 183u);
    model.step(70u);
    assert(model.getA() == 255u);
  }
  {
    ImageModel model{ ImageModel::Builder{ 1u }.setDuration(250u).build() };
    model.show();
    model.step(30u);
    assert(model.getA() == 31u);
    model.step(40u);
    assert(model.getA() == 72u);
    model.step(50u);
    assert(model.getA() == 122u);
    model.step(60u);
    assert(model.getA() == 183u);
    model.step(70u);
    assert(model.getA() == 255u);
  }
}

void testImageModel() {
  testBuild();
  testShow();
  testHide();
  testStep();
}

}  // namespace ii887522::viewify

#endif
