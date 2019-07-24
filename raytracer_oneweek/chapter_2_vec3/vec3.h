
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

  Value length() const;
  Value squared_length() const;
  int normalize();

  Value at(int) const;
  Value operator[](int index) const {
    return data_[index];
  }
  Value& operator[](int index) {
    return data_[index];
  }

  Value dot(const Vec3&) const;
  Vec3 cross(const Vec3&) const;

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

}  // namespace raytrace
