#include <iostream>
#include <string>
#include <vector>
#include "NumberConverter.h"

int main() {

	std::string input, type, result;

	std::cin >> input;
	std::vector<int> params = readInVector(input);

	NumberConverter converter(params);
	
	std::cin >> type;
	std::cin >> input;

	if (input.at(1) == 'x') {
		input = input.substr(2);
		if (type == "d") {
			result = std::to_string(converter.hexToDecimal(input));
		} else {
			result = converter.hexToBinary(input);
		}
	} else if (input.at(0) == 'b') {
		input = input.substr(1);
		if (type == "h") {
			result = converter.binaryToHex(input);
		} else {
			result = std::to_string(converter.binaryToDecimal(input));
		}
	} else {
		int decimal = std::stoi(input);
		if (type == "b") {
			result = converter.decimalToBinary(decimal);
		} else {
			result = converter.decimalToHex(decimal);
		}
	}

	std::cout << "input: " << input << std::endl;
	std::cout << "output type: " << type << std::endl;
	std::cout << "result: " << result << std::endl;
}
