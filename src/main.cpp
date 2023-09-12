#include <iostream>
#include "../include/figures.h"


int main(){
	// Creating vector of random figures
	auto vec = create_random_vec(10);
	
	int number_of_circles = 0;
	float t = 3.14159 / 4.0;

	// Printing Curve(t) and Curve'(t), also counting circles
	for(auto f: vec){
		if(f->get_type() == FigureType::circle){
			number_of_circles += 1;
		}
		f->get_coords(t).print();
		std::cout << "\n";
		f->get_derivative(t).print();
		std::cout << "\n\n\n";
	}

	// Getting circles from figures
	auto circles = get_circles(vec);
	sort_by_radii(circles);

	// Printing circles' radii and total radius
	std::cout << "Number of circles: " << number_of_circles << std::endl;
	for(auto c: circles){
		std::cout << c->get_radius() << std::endl;
	}
	std::cout << "Total radius: " << total_sum_of_radii(circles) << std::endl;
}
