#pragma once

#include <vector>

std::vector<double> readInVector(std::string s);

class NumberConverter {
public:
	NumberConverter();
	int hexCharToNumber(char input);
	char numberToHexChar(int input);
}