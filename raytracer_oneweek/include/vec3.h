// Define class `raytrace::Vect3`
//
// Reference http://bit.ly/32NXpPg
//
// Yan-Song Chen (c.yansong2@gmail.com)

#ifndef VEC3_H
#define VEC3_H

#include <iostream>

namespace raytrace {

using Value = double;

class Vec3 {
 public:
  Vec3() = default;
  Vec3(const Value& v1, const Value& v2, const Value& v3)
      : data_{v1, v2, v3} {};
  ~Vec3() = default;
  Vec3(const Vec3&) = default;
  Vec3& operator=(const Vec3&) = default;

  // Access L2 norm of the vector
  Value length() const;
  // Access sum of square of each element
  Value squared_length() const;
  // Normalize the vector to length 1, the ratio between each pair of elements
  // remains equal.
  int normalize();

  // Access the value of an index number. If index number < 0 or index number >=
  // 0, std::out_of_range exception will be thrown.
  Value at(int) const;
  // Access the value of an index number. If the index number is less than zero
  // or greater than two, the behavior is undefined.
  Value operator[](int index) const {
    return data_[index];
  }
  // Reference access the value of an index number. If the index number is less
  // than zero or greater than two, the behavior is undefined.
  Value& operator[](int index) {
    return data_[index];
  }

  // Inner product with another `Vec3`
  Value dot(const Vec3&) const;
  // Cross product with another `Vec3`
  Vec3 cross(const Vec3&) const;

  // Numerical tolerance
  constexpr static Value value_tolerance() {
    return 1e-6;
  }

 private:
  Value data_[3] = {0};
};

Vec3 operator+(const Vec3&, const Vec3&);
Vec3 operator-(const Vec3&, const Vec3&);
Vec3 operator*(const Vec3&, const Vec3&);
Vec3 operator/(const Vec3&, const Vec3&);
Value Dot(const Vec3&, const Vec3&);
Vec3 Cross(const Vec3&, const Vec3&);

bool operator==(const Vec3&, const Vec3&);
bool operator!=(const Vec3&, const Vec3&);

std::istream& operator>>(std::istream&, Vec3&);
std::ostream& operator<<(std::ostream&, const Vec3&);

}  // namespace raytrace

#endif