#pragma once
#include <valarray>
#include <iostream>

struct Point {
  double x_coord;
  double y_coord;
};

class Figura {
private: 
  Point *ptr_point;
  int num_point;
public:
  //explicit constructor
  Figura(Point *ptr_xy, int xy_size) {
    ptr_point = new Point[xy_size];
	num_point = xy_size;
	for (int i(0); i < num_point; ++i) {
		ptr_point[i] = ptr_xy[i];
	}
  }

  //default constructor
  Figura() {
    ptr_point = nullptr;
	num_point = 0;
  }

  //copy constructor
  Figura(const Figura &figura) {
    ptr_point = new Point[figura.num_point];
	num_point = figura.num_point;
	for (int i(0); i < num_point; ++i) {
	  ptr_point[i] = figura.ptr_point[i];
	}
  }

  //output operation overload
  friend std::ostream& operator << (std::ostream& os, const Figura &figura) {
    for (int i(0); i < figura.num_point; ++i) {
	  os << figura.ptr_point[i].x_coord << " ";
	  os << figura.ptr_point[i].y_coord;
	}
	return os;
  }

  //input operations overload
  friend std::istream& operator >> (std::istream& is, Figura &figura) {
    std::cout << "Display the number of point:";
	is >> figura.num_point;
	figura.ptr_point = new Point[figura.num_point];
	for (int i(0); i < figura.num_point; ++i) {
	  std::cout << "Enter number of point" << i + 1 << "point:\n";
	  std::cout << "x:";
	  is >> figura.ptr_point[i].x_coord;
	  std::cout << "y:";
	  is >> figura.ptr_point[i].y_coord;
	}
	return is;
  }

  double distance(int value_i1, int value_i2) {
	  double pt_x1, pt_y1, pt_x2, pt_y2;
	  pt_x1 = ptr_point[value_i1].x_coord;
	  pt_y1 = ptr_point[value_i1].y_coord;
	  pt_x2 = ptr_point[value_i2].x_coord;
	  pt_y2 = ptr_point[value_i2].y_coord;

	  return sqrt(pow(abs(pt_x1 - pt_x2), 2) + pow(abs(pt_y1 - pt_y2), 2));
  }

  //index operation overload
  Point& operator[](const int index) {
	  return ptr_point[index];
  }

  ~Figura(void) { delete[] ptr_point; };
};

class Circle:public Figura {
private:
  double radius;
public:
  Circle(Point *ptr_xy, double var_rad):Figura(&*ptr_xy, 1), radius(var_rad) {};
  Circle(const Figura &figura) :Figura(figura) {
	  radius = distance(0, 1);
  };
  Circle() :Figura(), radius(0) {};
  double Area() {
	  return radius * radius * 3.1459;
  }
};

class Rectangle:public Figura {
private:
  double a;
  double b;
public:
  Rectangle(Figura &figura):Figura(figura) {
    a = figura.distance(0, 1);
	b = figura.distance(1, 2);
  };
  Rectangle() :Figura(), a(0), b(0) {};
  double Area() {
	  return a * b;
  }
};