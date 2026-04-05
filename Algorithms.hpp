#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include <vector>
#include "Bin.hpp"

std::vector<Bin> onlineFirstFit(const std::vector<float>& items);
std::vector<Bin> onlineNextFit(const std::vector<float>& items);
std::vector<Bin> onlineBestFit(const std::vector<float>& items);

std::vector<Bin> offlineFirstFit(std::vector<float> items);
std::vector<Bin> offlineBestFit(std::vector<float> items);

void evaluatePermutation(int s[], int numElements, const std::vector<float>& originalItems, std::vector<Bin>& bestOptimalBins);
bool perm1(int s[], int numElements);

#endif