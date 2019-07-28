#include <fstream>

int main() {
  const int nx = 200;
  const int ny = 100;
  std::ofstream image("hello.ppm");
  image << "P3\n" << nx << " " << ny << "\n255\n";
  for (int j = ny - 1; j >= 0; j--) {
    for (int i = 0; i < nx; i++) {
      float r = static_cast<float>(i) / static_cast<float>(nx);
      float g = static_cast<float>(j) / static_cast<float>(ny);
      float b = 0.2;
      int ir = static_cast<int>(255.99 * r);
      int ig = static_cast<int>(255.99 * g);
      int ib = static_cast<int>(255.99 * b);
      image << ir << " " << ig << " " << ib << '\n';
    }
  }
  return 0;
}
