#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <vector>

typedef unsigned long long ull;

std::vector<std::string> tmp = {"1", "1", "1", "1"};

std::vector<std::string> split(const std::string &str, char d);

ull getUlongValueOfIpv4(std::vector<std::string> input) {
    int i = 4;
    unsigned long long result = 0;
    
    for (auto elem = input.begin(); elem != input.end(); ++elem, --i) {
        result += std::stoi(*elem) * pow(255, i);
    }
    return result;
}
