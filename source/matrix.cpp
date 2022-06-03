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
	std::cout << matrix[0][0] << matrix[3][3];
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

