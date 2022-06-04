#include "Size_of_matrix.h"

int size_of_matrix(std::string text)
{
	if (ceil(sqrt(text.length() - 1)) > sqrt(text.length() - 1))
	{
		return sqrt(text.length() - 1) + 1;
	}
return sqrt(text.length() - 1);
}