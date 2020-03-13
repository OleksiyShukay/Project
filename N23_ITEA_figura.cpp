#include <iostream>
#include <conio.h>
#include "figura.h"

int main(int argc, char**argv) {
  Figura f;
  std::cin >> f;

  Circle c(f);
  std::cout << c.Area() << std::endl;

  Rectangle g(f);
  std::cout << g.Area() << std::endl;

  return 0;
}