#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

#include "NumberConverter.h"

std::vector<int> readInVector(std::string s) {
  int prev_location = 0;
  int next_location = 0;
  std::vector<int> result;
  while(s.find(',', prev_location) != std::string::npos) {
    next_location = s.find(',', prev_location);
    result.push_back(std::stoi(s.substr(prev_location, next_location - prev_location)));
    next_location++;
    prev_location = next_location;
  }
  result.push_back(std::stoi(s.substr(prev_location, std::string::npos)));
  return result;
}

NumberConverter::NumberConverter(std::vector<int> params) {
  decimal_inputs = params[0];
  binary_inputs = params[1];
  hex_inputs = params[2];
  decimal_outputs = params[3];
  binary_outputs = params[4];
  hex_outputs = params[5];
}

int NumberConverter::hexCharToNumber(char input) {
  if(input > 57) {
    return input - (65 - 10);
  } else {
    return input - 48;
  }
}

char NumberConverter::numberToHexChar(int input) {
  if(input < 10) {
    return input + 48;
  } else {
    return (input - 10) + 65;
  }
}

int NumberConverter::binaryToDecimal(std::string input) {
  int binary = std::stoi(input);
  int output = 0, count = 0, remainder = 0;
  while (binary != 0) {
    remainder = binary % 10;
    binary /= 10;
    output += remainder * std::pow(2, count);
    count++;
  }
  binary_inputs++;
  decimal_outputs++;
  return output;
}

int NumberConverter::hexToDecimal(std::string input) {
  std::reverse(input.begin(), input.end());
  int output = 0, count = 0;
  for (char c: input) {
    output += hexCharToNumber(c) * std::pow(16, count);
    count ++;
  }
  hex_inputs++;
  decimal_outputs++;
  return output;
}

std::string NumberConverter::binaryToHex(std::string input) {
  int binary = std::stoi(input), remainder = 0;
  std::string output = "";
  while (binary != 0) {
    remainder = binary % 10000;
    binary /= 10000;
    int number = binaryToDecimal(std::to_string(remainder));
    output += numberToHexChar(number);
  }
  std::reverse(output.begin(), output.end());
  decimal_outputs--;
  hex_outputs++;
  return output;
}

std::string NumberConverter::decimalToHex(int input) {
  std::string output = "";
  int remainder = 0;
  while (input != 0) {
    remainder = input % 16;
    input /= 16;
    output += numberToHexChar(remainder);
  }
  std::reverse(output.begin(), output.end());
  decimal_inputs++;
  hex_outputs++;
  return output;
}

std::string NumberConverter::decimalToBinary(int input) {
  std::string output = "";
  int remainder = 0;
  while (input != 0) {
    remainder = input % 2;
    input /= 2;
    output += std::to_string(remainder);
  }
  std::reverse(output.begin(), output.end());
  decimal_inputs++;
  binary_outputs++;
  return output;
}

std::string NumberConverter::hexToBinary(std::string input) {
  std::string output = "";
  for (char c: input) {
    int decimal = hexCharToNumber(c);
    std::string binary = decimalToBinary(decimal);
    if (binary.length() == 1) { binary = "0" + binary; }
    if (binary.length() == 2) { binary = "0" + binary; }
    if (binary.length() == 3) { binary = "0" + binary; }
    output += binary;
    decimal_inputs--;
    binary_outputs--;
  }
  return output;
}

NumberConverter::~NumberConverter() {
  std::cout << "decimal_inputs: " << decimal_inputs << std::endl;
  std::cout << "binary_inputs: " << binary_inputs << std::endl;
  std::cout << "hex_inputs: " << hex_inputs << std::endl;
  std::cout << "decimal_outputs: " << decimal_outputs << std::endl;
  std::cout << "binary_outputs: " << binary_outputs << std::endl;
  std::cout << "hex_outputs: " << hex_outputs << std::endl;
}