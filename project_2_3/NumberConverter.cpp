#include <iostream>
#include <vector>
#include "NumberConverter.h"

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