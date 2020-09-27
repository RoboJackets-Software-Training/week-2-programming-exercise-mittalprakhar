#include <iostream>
#include <vector>

#include "convolution.h"

std::vector<double> readInVector(std::string s) {
  	int prev_location = 0;
 	int next_location = 0;
  	std::vector<double> result;
  	while(s.find(',', prev_location) != std::string::npos) {
    	next_location = s.find(',', prev_location);
 	   result.push_back(std::stod(s.substr(prev_location, next_location - prev_location)));
    	next_location++;
    	prev_location = next_location;
  	}
  	result.push_back(std::stod(s.substr(prev_location, std::string::npos)));
  	return result;
}

void printVector(std::vector<double> v) {
	if (v.size() > 0) {
		std::cout << "{" << v[0];
  		for (int i = 1; i < v.size(); i++) {
  			std::cout << ", " << v[i];
  		}
  		std::cout << "}" << std::endl;
	}
}

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeros) {
	int center = (w.size() - 1) / 2;
	std::vector<double> y;

  	for (int i = 0; i < x.size(); i++) {
  		double sum = 0;

  		for (int j = 0; j < w.size(); j++) {
  			int diff = i - center + j;
  		
	  		if (diff < 0 and not pack_with_zeros) {
  				sum += x[0] * w[j];
  			} else if (diff >= 0 and diff < x.size()) {
  				sum += x[diff] * w[j];
	  		} else if (diff >= x.size() and not pack_with_zeros) {
  				sum += x[x.size()-1] * w[j];
  			}
  		}

  		y.push_back(sum);
  	}

  	return y;
}