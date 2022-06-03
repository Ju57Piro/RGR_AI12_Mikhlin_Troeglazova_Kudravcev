#pragma once
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "write_segment.h"
std::vector<std::string> matrix(std::string *text, int size);

int size_of_matrix(std::string text);

std::string matrix_to_string(std::vector<std::string> matrix, int size);
