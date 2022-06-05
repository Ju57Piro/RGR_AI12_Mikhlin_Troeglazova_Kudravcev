#pragma once
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "write_segment.h"
#include "Size_of_matrix.h"

std::string decrypt_matrix(std::string text);

char** make_empty_matrix(int size);

char** write_to_matrix(std::string &text, int size);