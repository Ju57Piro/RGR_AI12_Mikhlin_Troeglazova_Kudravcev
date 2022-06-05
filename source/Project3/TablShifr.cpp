#include <iostream>
#include "TablShifr.h"
#include <vector>
#include <algorithm>
#include <math.h>
#include <iterator>



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
std::string DecShif(std::string S3)
{
    setlocale(LC_ALL, "Russian");
    std::vector<char>Case = { 'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ','ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ', ',', '.', '?', '!', ';', ':', '"', ' ', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '0', '1', '2', '3', '4',  '5',  '6',  '7',  '8',  '9'};
    std::vector<char>Symbol = { ' ', '1', '$', '^', '@', '3', '&', '[', '(', '5', '=', '{', '<', '/','7', 'b', 'h', 'e', 'r', '9', 'u', 'c','k',  'j', 'x', 'l','o','p','w','n','s','t', 'd', 'a', 'y', 'v', 'z', 'm', 'i', 'q', 'g', ' ', '_', '%', '2', '~', 'ñ', '*', '4', 'ë', ')', 'ú', '6', 'ï', '>', 'ù', 'ç', '8', 'é',  '¸',  'ã',  '¹', '0', 'ÿ', 'ü', 'ô', 'û', 'à', 'ä', 'æ', '}', ']', 'ý', 'ò', '#', 'þ','ð' };
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
    setlocale(LC_ALL, "Russian");
    std::vector<char>Case = { 'à', 'á', 'â', 'ã', 'ä', 'å', '¸', 'æ','ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ', ',', '.', '?', '!', ';', ':', '"', ' ', 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', '0', '1', '2', '3', '4',  '5',  '6',  '7',  '8',  '9' };
    std::vector<char>Symbol = { ' ', '1', '$', '^', '@', '3', '&', '[', '(', '5', '=', '{', '<', '/','7', 'b', 'h', 'e', 'r', '9', 'u', 'c','k',  'j', 'x', 'l','o','p','w','n','s','t', 'd', 'a', 'y', 'v', 'z', 'm', 'i', 'q', 'g', ' ', '_', '%', '2', '~', 'ñ', '*', '4', 'ë', ')', 'ú', '6', 'ï', '>', 'ù', 'ç', '8', 'é',  '¸',  'ã',  '¹', '0', 'ÿ', 'ü', 'ô', 'û', 'à', 'ä', 'æ', '}', ']', 'ý', 'ò', '#', 'þ','ð' };
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
