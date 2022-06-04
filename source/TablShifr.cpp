#include "TablShifr.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>
std::pair<bool, int> findInVector(const std::vector<char>& Case, const char& element)
{
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
std::string DecShif(std::string S3)
{
    std::vector<char>Case = { ' ' , 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::vector<char>Symbol = { ' ', '+','!','@','#','$','%','^','&','*','[',']',')','(','=','`',':',';','{','}','.',',','<','>','"','?','/','\'' };
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
std::string Tabl(std::string S1)
{
	std::vector<char>Case = { ' ' , 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	std::vector<char>Symbol = { ' ', '+','!','@','#','$','%','^','&','*','[',']',')','(','=','`',':',';','{','}','.',',','<','>','"','?','/','\'' };
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
