#include "write_segment.h"

std::string write_segment(std::vector<std::string> matrix, int dir, int step, int& i, int& j)
{
	std::string res;
	switch (dir)
	{
	case 0: //вверх
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			i--;
		}
		break;
	case 1: //влево
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			j--;
		}
		break;
	case 2: //вниз
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			i++;
		}
		break;
	case 3: //вправо
		for (int k = 0; k < step; k++) {
			res.push_back(matrix[i][j]);
			j++;;
		}
		break;
	}
	return res;
}

void write_to_matrix_by_dir(std::string text, char** matr ,int dir, int step, int &i, int& j, int &n)
{
	switch (dir)
	{
	case 0: //вверх
		for (int k = 0; k < step; k++) {
			matr[i][j] = text[n];
			i--;
			n++;
		}
		break;
	case 1: //влево
		for (int k = 0; k < step; k++) {
			matr[i][j] = text[n];
			j--;
			n++;
		}
		break;
	case 2: //вниз
		for (int k = 0; k < step; k++) {
			matr[i][j] = text[n];
			i++;
			n++;
		}
		break;
	case 3: //вправо
		for (int k = 0; k < step; k++) {
			matr[i][j] = text[n];
			j++;
			n++;
		}
		break;
	}
}
