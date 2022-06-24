#include "find_in_vector.h"


std::pair<bool, int> findInVector(const std::vector<char>& Case, const char& element)
{
    setlocale(LC_ALL, "Russian");
    std::pair<bool, int > result;
    // Find given element in vector
    auto it = std::find(Case.begin(), Case.end(), element);
    if (it != Case.end())
    {
        result.second = distance(Case.begin(), it);
        result.first = true;
    }
    else
    {
        result.first = false;
        result.second = -1;
    }
    return result;
}