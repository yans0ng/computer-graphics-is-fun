// Implement class `raytrace::Vec3`
//
// Reference http://bit.ly/32NXpPg
//
// Yan-Song Chen (c.yansong2@gmail.com)

#include "vec3.h"

#include <cmath>
#include <sstream>
#include <stdexcept>

namespace raytrace {

Value Vec3::length() const {
  return std::sqrt(squared_length());
}
Value Vec3::squared_length() const {
  return data_[0] * data_[0] + data_[1] * data_[1] + data_[2] * data_[2];
}

int Vec3::normalize() {
  Value self_length = length();
  if (self_length <= value_tolerance()) {
    return -1;
  }
  data_[0] /= self_length;
  data_[1] /= self_length;
  data_[2] /= self_length;
  return 0;
}

Value Vec3::at(int index) const {
  if (index < 0 || index > 2) {
    std::stringstream error_message;
    error_message << "Request index " << index << " on raytrace::Vec3 object";
    throw std::out_of_range(error_message.str());
  }
  return data_[index];
}

Value Vec3::dot(const Vec3& rhs) const {
  return Dot(*this, rhs);
}

Vec3 Vec3::cross(const Vec3& rhs) const {
  return Cross(*this, rhs);
}

Vec3 operator+(const Vec3& lhs, const Vec3& rhs) {
  return {lhs[0] + rhs[0], lhs[1] + rhs[1], lhs[2] + rhs[2]};
}

Vec3 operator-(const Vec3& lhs, const Vec3& rhs) {
  return {lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2]};
}

Vec3 operator*(const Vec3& lhs, const Vec3& rhs) {
  return {lhs[0] * rhs[0], lhs[1] * rhs[1], lhs[2] * rhs[2]};
}

Vec3 operator/(const Vec3& lhs, const Vec3& rhs) {
  return {lhs[0] / rhs[0], lhs[1] / rhs[1], lhs[2] / rhs[2]};
}

Value Dot(const Vec3& lhs, const Vec3& rhs) {
  return (lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2]);
}

Vec3 Cross(const Vec3& lhs, const Vec3& rhs) {
  return {
      (lhs[1] * rhs[2] - lhs[2] * rhs[1]),
      (-lhs[0] * rhs[2] + lhs[2] * rhs[0]),
      (lhs[0] * rhs[1] - lhs[1] * rhs[2]),
  };
}

namespace {
bool ValueIsClose(Value value1, Value value2) {
  return std::abs(value1 - value2) < Vec3::value_tolerance();
}
}  // namespace

bool operator==(const Vec3& lhs, const Vec3& rhs) {
  return (ValueIsClose(lhs[0], rhs[0]) && ValueIsClose(lhs[1], rhs[1]) &&
          ValueIsClose(lhs[2], rhs[2]));
}

bool operator!=(const Vec3& lhs, const Vec3& rhs) {
  return !(lhs == rhs);
}

std::istream& operator>>(std::istream& istream, Vec3& vector) {
  istream >> vector[0] >> vector[1] >> vector[2];
  return istream;
}

std::ostream& operator<<(std::ostream& ostream, const Vec3& vector) {
  ostream << vector[0] << ' ' << vector[1] << ' ' << vector[2];
  return ostream;
}

}  // namespace raytrace