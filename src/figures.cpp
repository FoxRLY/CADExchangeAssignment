#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

#include "../include/figures.h"


void Point3D::print(){
	printf("Point: x:%f y:%f z:%f", this->x, this->y, this->z);
}

void Vector3D::print(){
	printf("Derivative: x:%f y:%f z:%f", this->x, this->y, this->z);
}

float Circle::get_radius(){
	return this->radius;
}


Point3D Circle::get_coords(float t){
	Point3D coords = this->center;
	coords.x += this->radius * std::cos(t);
	coords.y += this->radius * std::sin(t);
	return coords;
}


Vector3D Circle::get_derivative(float t){
	Vector3D derivative = Vector3D{0.0, 0.0, 0.0};
	derivative.x = this->radius * (std::sin(t) * -1.0);
	derivative.y = this->radius * std::cos(t);
	derivative.z = 0;
	return derivative;
}


FigureType Circle::get_type(){
	return FigureType::circle;
}


Point3D Ellipse::get_coords(float t){
	Point3D coords = this->center;
	coords.x += this->radius_a * std::cos(t);
	coords.y += this->radius_b * std::sin(t);
	return coords;
}

Vector3D Ellipse::get_derivative(float t){
	Vector3D derivative = Vector3D{0.0, 0.0, 0.0};
	derivative.x = this->radius_a * (std::sin(t) * -1.0);
	derivative.y = this->radius_b * std::cos(t);
	derivative.z = 0;
	return derivative;
}

FigureType Ellipse::get_type(){
	return FigureType::ellipse;
}

Point3D Helix::get_coords(float t){
	Point3D coords = this->center;
	coords.x += this->radius * std::cos(t);
	coords.y += this->radius * std::sin(t);
	coords.z += this->step * t;
	return coords;
}

Vector3D Helix::get_derivative(float t){
	Vector3D derivative = Vector3D{0.0,0.0,0.0};
	derivative.x = this->radius * (std::sin(t) * -1.0);
	derivative.y = this->radius * std::cos(t);
	derivative.z = this->step;
	return derivative;
}

FigureType Helix::get_type(){
	return FigureType::helix;
}



float get_random_float(float lower_bound, float upper_bound){
	return static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/ (upper_bound - lower_bound) ));
}

Point3D get_random_point(float lower_bound, float upper_bound){
	return Point3D{
		get_random_float(lower_bound, upper_bound),
		get_random_float(lower_bound, upper_bound),
		get_random_float(lower_bound, upper_bound)
	};
}

std::shared_ptr<Figure> create_random_figure(){
	int type = std::rand() % 3;
	std::shared_ptr<Figure> figure;
	switch (type) {
		case 0:
			figure = std::make_shared<Circle>(get_random_point(-10.0, 10.0), get_random_float(0.0, 10.0));
			break;
		case 1:
			figure = std::make_shared<Ellipse>(
				get_random_point(-10.0, 10.0),
				get_random_float(0.0, 10.0),
				get_random_float(0.0, 10.0)
			);
			break;
		case 2:
			figure = std::make_shared<Helix>(
				get_random_point(-10.0, 10.0),
				get_random_float(0.0, 10.0),
				get_random_float(-10.0, 10.0)
			);
			break;
	}
	return figure;
}

std::vector<std::shared_ptr<Figure>> create_random_vec(int count){
	std::srand((unsigned) time(NULL));
	std::vector<std::shared_ptr<Figure>> container;
	container.reserve(count);
	for(int i = 0; i < count; i++){
		auto figure = create_random_figure();	
		container.push_back(figure);
	}
	return container;
}

std::vector<std::shared_ptr<Circle>> get_circles(std::vector<std::shared_ptr<Figure>>& figures){
	std::vector<std::shared_ptr<Circle>> circles;
	for(auto f: figures){
		if(f->get_type() == FigureType::circle){
			std::shared_ptr<Circle> circle = std::dynamic_pointer_cast<Circle>(f);
			circles.push_back(circle);
		}
	}
	return circles;
}

void sort_by_radii(std::vector<std::shared_ptr<Circle>>& circles){
	std::sort(circles.begin(), circles.end(),
		[](std::shared_ptr<Circle> a, std::shared_ptr<Circle> b){
			return a->get_radius() < b->get_radius();
		}
	);
}


float total_sum_of_radii(std::vector<std::shared_ptr<Circle>>& circles){
	float total = 0.0;
	for(auto c: circles){
		total += c->get_radius();
	}
	return total;
}

