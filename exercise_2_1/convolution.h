#pragma once

#include <vector>

std::vector<double> readInVector(std::string s);

void printVector(std::vector<double> v);

std::vector<double> applyConvolution(std::vector<double> x, std::vector<double> w, bool pack_with_zeroes);
