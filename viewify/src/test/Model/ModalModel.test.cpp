// Copyright ii887522

#include "ModalModel.test.h"
#include "../../main/Model/ModalModel.h"
#include <cassert>

namespace ii887522::viewify {

static void testShow() {
  {
    ModalModel model{ 125u };
    model.show();
    assert(model.getSceneCoverA() == 0u);
    assert(model.getA() == 0u);
  }
  {
    ModalModel model{ 250u };
    model.show();
    assert(model.getSceneCoverA() == 0u);
    assert(model.getA() == 0u);
  }
}

static void testHide() {
  {
    ModalModel model{ 125u };
    model.hide();
    assert(model.getSceneCoverA() == 0u);
    assert(model.getA() == 0u);
  }
  {
    ModalModel model{ 250u };
    model.hide();
    assert(model.getSceneCoverA() == 0u);
    assert(model.getA() == 0u);
  }
}

static void testStep() {
  {
    ModalModel model{ 125u };
    model.show();
    model.step(15u);
    assert(model.getSceneCoverA() == 15u);
    assert(model.getA() == 30u);
    model.step(20u);
    assert(model.getSceneCoverA() == 35u);
    assert(model.getA() == 71u);
    model.step(25u);
    assert(model.getSceneCoverA() == 61u);
    assert(model.getA() == 122u);
    model.step(30u);
    assert(model.getSceneCoverA() == 92u);
    assert(model.getA() == 183u);
    model.step(35u);
    assert(model.getSceneCoverA() == 128u);
    assert(model.getA() == 255u);
  }
  {
    ModalModel model{ 250u };
    model.show();
    model.step(30u);
    assert(model.getSceneCoverA() == 15u);
    assert(model.getA() == 30u);
    model.step(40u);
    assert(model.getSceneCoverA() == 35u);
    assert(model.getA() == 71u);
    model.step(50u);
    assert(model.getSceneCoverA() == 61u);
    assert(model.getA() == 122u);
    model.step(60u);
    assert(model.getSceneCoverA() == 92u);
    assert(model.getA() == 183u);
    model.step(70u);
    assert(model.getSceneCoverA() == 128u);
    assert(model.getA() == 255u);
  }
}

void testModalModel() {
  testShow();
  testHide();
  testStep();
}

}  // namespace ii887522::viewify
