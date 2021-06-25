// Copyright ii887522

#ifdef CONSOLE_TEST

#include <nitro/nitro.h>
#include <catch.hpp>
#include "../../main/Model/ModalModel.h"

using ii887522::nitro::AnimationController;

namespace ii887522::viewify {

TEST_CASE("test ModalModel::show() function") {
  AnimationController animationController;
  {
    ModalModel model{ &animationController, 125u };
    model.show();
    REQUIRE(model.getSceneCoverA() == 0u);
    REQUIRE(model.getA() == 0u);
  }
  {
    ModalModel model{ &animationController, 250u };
    model.show();
    REQUIRE(model.getSceneCoverA() == 0u);
    REQUIRE(model.getA() == 0u);
  }
}

TEST_CASE("test ModalModel::hide() function") {
  AnimationController animationController;
  {
    ModalModel model{ &animationController, 125u };
    model.hide();
    REQUIRE(model.getSceneCoverA() == 0u);
    REQUIRE(model.getA() == 0u);
  }
  {
    ModalModel model{ &animationController, 250u };
    model.hide();
    REQUIRE(model.getSceneCoverA() == 0u);
    REQUIRE(model.getA() == 0u);
  }
}

TEST_CASE("test ModalModel::step() function") {
  AnimationController animationController;
  {
    ModalModel model{ &animationController, 125u };
    model.show();
    model.step(15u);
    REQUIRE(model.getSceneCoverA() == 15u);
    REQUIRE(model.getA() == 30u);
    model.step(20u);
    REQUIRE(model.getSceneCoverA() == 35u);
    REQUIRE(model.getA() == 71u);
    model.step(25u);
    REQUIRE(model.getSceneCoverA() == 61u);
    REQUIRE(model.getA() == 122u);
    model.step(30u);
    REQUIRE(model.getSceneCoverA() == 92u);
    REQUIRE(model.getA() == 183u);
    model.step(35u);
    REQUIRE(model.getSceneCoverA() == 128u);
    REQUIRE(model.getA() == 255u);
  }
  {
    ModalModel model{ &animationController, 250u };
    model.show();
    model.step(30u);
    REQUIRE(model.getSceneCoverA() == 15u);
    REQUIRE(model.getA() == 30u);
    model.step(40u);
    REQUIRE(model.getSceneCoverA() == 35u);
    REQUIRE(model.getA() == 71u);
    model.step(50u);
    REQUIRE(model.getSceneCoverA() == 61u);
    REQUIRE(model.getA() == 122u);
    model.step(60u);
    REQUIRE(model.getSceneCoverA() == 92u);
    REQUIRE(model.getA() == 183u);
    model.step(70u);
    REQUIRE(model.getSceneCoverA() == 128u);
    REQUIRE(model.getA() == 255u);
  }
}

}  // namespace ii887522::viewify

#endif
