// Test class `raytrace::Vec3`
//
// Reference http://bit.ly/32NXpPg
//
// Yan-Song Chen (c.yansong2@gmail.com)

#include "raytracer_oneweek/include/vec3.h"

#include <iostream>

namespace {

inline bool ValueIsClose(raytrace::Value value1, raytrace::Value value2) {
  return (std::abs(value1 - value2) < 1e-6);
}

int VerifyVec3Equal(const raytrace::Vec3& lhs, const raytrace::Vec3& rhs) {
  if (ValueIsClose(lhs[0], rhs[0]) && ValueIsClose(lhs[1], rhs[1]) &&
      ValueIsClose(lhs[2], rhs[2])) {
    return 0;
  }
  return 1;
}

}  // namespace

int main(int argc, char** argv) {
  int ret = 0;

  raytrace::Vec3 default_vec;
  ret = VerifyVec3Equal(default_vec, {0, 0, 0});
  if (ret) {
    std::cerr << "Default test failed" << std::endl;
    return ret;
  }

  raytrace::Vec3 vector(1., 2., 3.);
  if (vector != raytrace::Vec3{1., 2., 3.}) {
    std::cerr << "operator != is incorrect." << std::endl;
    return 1;
  }

  if (vector == raytrace::Vec3{1., 2., 3.1}) {
    std::cerr << "operator == is incorrect." << std::endl;
    return 1;
  }

  return 0;
}