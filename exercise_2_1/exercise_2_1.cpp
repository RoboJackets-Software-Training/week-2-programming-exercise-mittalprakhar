#include <iostream>
#include <vector>

#include "convolution.h"

int main() {
	std::vector<double> x;
	std::vector<double> w;
	bool pack_with_zeros = true;

	std::string s;

	std::cin >> s;
	if (s == "false") {
		pack_with_zeros = false;
	}

  	std::cin >> s;
  	x = readInVector(s);
  	
  	std::cin >> s;
  	w = readInVector(s);

  	printVector(applyConvolution(x, w, pack_with_zeros));
 	printVector(applyConvolution(x, w, not pack_with_zeros));

  	return 0;
}
