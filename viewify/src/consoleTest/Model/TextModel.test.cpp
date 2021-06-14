// Copyright ii887522

#ifdef CONSOLE_TEST

#include <stdexcept>
#include <catch.hpp>
#include "../../main/Model/TextModel.h"

using std::runtime_error;

namespace ii887522::viewify {

TEST_CASE("test TextModel::Builder::build() function") {
  REQUIRE(TextModel::Builder{ 0u }.setDuration(125u).build().getA() == 0u);
  REQUIRE(TextModel::Builder{ 1u }.setDuration(125u).build().getA() == 1u);
  REQUIRE(TextModel::Builder{ 1u }.setDuration(250u).build().getA() == 1u);
  REQUIRE_THROWS(TextModel::Builder{ 0u }.build());
  REQUIRE_THROWS(TextModel::Builder{ 1u }.build());
}

TEST_CASE("test TextModel::show() function") {
  {
    TextModel model{ TextModel::Builder{ 0u }.setDuration(125u).build() };
    model.show();
    REQUIRE(model.getA() == 0u);
  }
  {
    TextModel model{ TextModel::Builder{ 0u }.setDuration(250u).build() };
    model.show();
    REQUIRE(model.getA() == 0u);
  }
  {
    TextModel model{ TextModel::Builder{ 1u }.setDuration(250u).build() };
    model.show();
    REQUIRE(model.getA() == 1u);
  }
}

TEST_CASE("test TextModel::hide() function") {
  {
    TextModel model{ TextModel::Builder{ 0u }.setDuration(125u).build() };
    model.hide();
    REQUIRE(model.getA() == 0u);
  }
  {
    TextModel model{ TextModel::Builder{ 0u }.setDuration(250u).build() };
    model.hide();
    REQUIRE(model.getA() == 0u);
  }
  {
    TextModel model{ TextModel::Builder{ 1u }.setDuration(250u).build() };
    model.hide();
    REQUIRE(model.getA() == 0u);
  }
}

TEST_CASE("test TextModel::step() function") {
  {
    TextModel model{ TextModel::Builder{ 0u }.setDuration(125u).build() };
    model.show();
    model.step(15u);
    REQUIRE(model.getA() == 30u);
    model.step(20u);
    REQUIRE(model.getA() == 71u);
    model.step(25u);
    REQUIRE(model.getA() == 122u);
    model.step(30u);
    REQUIRE(model.getA() == 183u);
    model.step(35u);
    REQUIRE(model.getA() == 255u);
  }
  {
    TextModel model{ TextModel::Builder{ 0u }.setDuration(250u).build() };
    model.show();
    model.step(30u);
    REQUIRE(model.getA() == 30u);
    model.step(40u);
    REQUIRE(model.getA() == 71u);
    model.step(50u);
    REQUIRE(model.getA() == 122u);
    model.step(60u);
    REQUIRE(model.getA() == 183u);
    model.step(70u);
    REQUIRE(model.getA() == 255u);
  }
  {
    TextModel model{ TextModel::Builder{ 1u }.setDuration(250u).build() };
    model.show();
    model.step(30u);
    REQUIRE(model.getA() == 31u);
    model.step(40u);
    REQUIRE(model.getA() == 72u);
    model.step(50u);
    REQUIRE(model.getA() == 122u);
    model.step(60u);
    REQUIRE(model.getA() == 183u);
    model.step(70u);
    REQUIRE(model.getA() == 255u);
  }
}

}  // namespace ii887522::viewify

#endif
