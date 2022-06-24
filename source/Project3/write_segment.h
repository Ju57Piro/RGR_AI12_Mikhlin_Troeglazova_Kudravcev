#pragma once
#include <string>
#include <vector>

std::string write_segment(std::vector<std::string> matrix, int dir, int step, int& i, int& j);
void write_to_matrix_by_dir(std::string text, char** matr, int dir, int step, int& i, int& j, int& n);
