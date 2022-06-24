#include <iostream>
#include "FuncAtbash.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>

std::string atbash_decr(std::string S3)
{
    setlocale(LC_ALL, "Russian");
    std::vector<char>Case = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    std::vector<char>Symbol = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', 'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'};
    std::string S2;
    for (int i = 0; i < S3.length(); i++) {
        std::pair<bool, int> result = findInVector(Symbol, S3[i]);
        if (result.first) {
            S2.push_back(Case[result.second]);
        }
        else {
            S2.push_back(S3[i]);
        }

    }

    return S2;

}

std::string atbash_encr(std::string S1)
{
    setlocale(LC_ALL, "Russian");
    std::vector<char>Case = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    std::vector<char>Symbol = { 'z', 'y', 'x', 'w', 'v', 'u', 't', 's', 'r', 'q', 'p', 'o', 'n', 'm', 'l', 'k', 'j', 'i', 'h', 'g', 'f', 'e', 'd', 'c', 'b', 'a', 'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A' };
    std::string S2;
    for (int i = 0; i < S1.length(); i++) {
        std::pair<bool, int> result = findInVector(Case, S1[i]);
        if (result.first) {
            S2.push_back(Symbol[result.second]);
        }
        else {
            S2.push_back(S1[i]);
        }

    }

    return S2;
}

