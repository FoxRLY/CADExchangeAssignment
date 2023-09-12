#pragma once
#include <memory>
#include <vector>

class Point3D{
public:
	float x, y, z;
	void print();
};

class Vector3D{
public:
	float x, y, z;
	void print();
};

enum FigureType{
	circle,
	ellipse,
	helix
};

class Figure{
public:
	virtual Point3D get_coords(float t) = 0;
	virtual Vector3D get_derivative(float t) = 0;
	virtual FigureType get_type() = 0;
};

class Circle: public Figure{
private:
	Point3D center;
	float radius;
public:
	Circle(Point3D center, float radius): center(center), radius(radius){}
	float get_radius();
	virtual Point3D get_coords(float t) override;
	virtual Vector3D get_derivative(float t) override;
	virtual FigureType get_type() override;
};

class Ellipse: public Figure{
private:
	Point3D center;
	float radius_a;
	float radius_b;
public:
	Ellipse(Point3D center, float radius_a, float radius_b):center(center), radius_a(radius_a), radius_b(radius_b){}
	virtual Point3D get_coords(float t) override;
	virtual Vector3D get_derivative(float t) override;
	virtual FigureType get_type() override;
};

class Helix: public Figure{
private:
	Point3D center;
	float radius;
	float step;
public:
	Helix(Point3D center, float radius, float step): center(center), radius(radius), step(step){}
	virtual Point3D get_coords(float t) override;
	virtual Vector3D get_derivative(float t) override;
	virtual FigureType get_type() override;
};

float get_random_float(float lower_bound, float upper_bound);

Point3D get_random_point(float lower_bound, float upper_bound);

std::shared_ptr<Figure> create_random_figure();

std::vector<std::shared_ptr<Figure>> create_random_vec(int count);

std::vector<std::shared_ptr<Circle>> get_circles(std::vector<std::shared_ptr<Figure>>& figures);

void sort_by_radii(std::vector<std::shared_ptr<Circle>>& circles);

float total_sum_of_radii(std::vector<std::shared_ptr<Circle>>& circles);
