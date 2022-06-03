#include "matrix.h"

std::vector<std::string> matrix(std::string* text, int size)
{

	std::string text_cont = *text;
	std::string temp_str;
	std::vector<std::string> matrix;
	int i, len, j, k;
	j = k = 0;
	len = text->length();
	if (ceil(sqrt(text_cont.length())) == sqrt(text_cont.length()))
	{
		for (i = 0; i <= len; i += size) {
			k = 0;
			while (k < size) {
				if (text_cont[j] != '\0') {
					temp_str.push_back(text_cont[j]);
					j++;
					k++;
				}
				else {
					break;
				}
			}
			if (text_cont[j] != '\0') {
				matrix.push_back(temp_str);
				temp_str.clear();
			}
			else {
				matrix.push_back(temp_str);
				temp_str.clear();
				break;
			}
		}
	}
	else {
		for (i = 0; i <= len; i += size) {
			k = 0;
			while (k < size) {
				if (text_cont[j] != '\0') {
					temp_str.push_back(text_cont[j]);
					j++;
					k++;
				}
				else {
					break;
				}
			}
			if (text_cont[j] != '\0') {
				matrix.push_back(temp_str);
				temp_str.clear();
			}
			else {
				while (j < size * size) {
					while (k < size) {
						temp_str.push_back(' ');
						k++;
						j++;
					}
					matrix.push_back(temp_str);
					temp_str.clear();
					k = 0;
				}
				break;
			}
		}
	}
	return matrix;
}


int size_of_matrix(std::string text)
{
	if (ceil(sqrt(text.length())) > sqrt(text.length()))
	{
		return sqrt(text.length()) + 1;;
	}
	return sqrt(text.length());
}


std::string matrix_to_string(std::vector<std::string> matrix, int size)
{
	int i, j, k, step;
	i = j = size/2;
	k = 0;
	step = 1;
	std::string tem_str;
	std::string res_string;
	if (size % 2 == 0) { // четная матрица
		while (k < size) {
			tem_str += write_segment(matrix, 0, step, i, j);
			tem_str += write_segment(matrix, 1, step, i, j);
			tem_str += write_segment(matrix, 2, step+1, i, j);
			tem_str += write_segment(matrix, 3, step+1, i, j);
			step += 2;
			if (step >= size - 1) {
				tem_str += write_segment(matrix, 0, size - 1, i, j);
				tem_str += write_segment(matrix, 1, step, i, j);
				tem_str += write_segment(matrix, 2, step+1, i, j);
				break;
			}
		}
	}
	else { //нечетная матрица
		while (k < size) {
			tem_str += write_segment(matrix, 3, step, i, j);
			tem_str += write_segment(matrix, 0, step, i, j);
			tem_str += write_segment(matrix, 1, step + 1, i, j);
			tem_str += write_segment(matrix, 2, step + 1, i, j);
			step += 2;
			if (step >= size - 1) {
				tem_str += write_segment(matrix, 3, step+1, i, j);
				break;
			}
		}
	}
	return tem_str;
}

