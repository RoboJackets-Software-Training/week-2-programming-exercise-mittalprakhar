#pragma once

#include <vector>

std::vector<int> readInVector(std::string s);

class NumberConverter {
public:
	NumberConverter(std::vector<int> params);
	~NumberConverter();
	
	int hexCharToNumber(char input);
	char numberToHexChar(int input);

	int binaryToDecimal(std::string input);
	int hexToDecimal(std::string input);

	std::string binaryToHex(std::string input);
	std::string decimalToHex(int input);

	std::string decimalToBinary(int input);
	std::string hexToBinary(std::string input);

private:
	int decimal_inputs, binary_inputs, hex_inputs, decimal_outputs, binary_outputs, hex_outputs;
};