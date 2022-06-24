#include <iostream>
#include "TarabFunc.h"
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
    std::vector<char>Case = {  'Á', 'Â', 'Ã', 'Ä', 'Æ', 'Ç', 'Ê', 'Ë', 'Ì', 'Í', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ô', 'Õ', 'Ó', '×', 'Ø', 'Ù', 'Ú', 'Ü', 'É', 'À', 'Å', '¨', 'È', 'Î', 'Ó', 'Û', 'Ý', 'Þ', 'ß'};
    std::vector<char>Symbol = {'À', 'Å', '¨', 'È', 'Î', 'Ó', 'Û', 'Ý', 'Þ', 'ß', 'Ù', 'Ø', '×', 'Ö', 'Õ', 'Ô', 'Ò', 'Ñ', 'Ð', 'Ï', 'Á', 'Â', 'Ã', 'Ä', 'Æ', 'Ç', 'Ê', 'Ë', 'Ì', 'Í', 'Ý', 'Þ', 'ß'};
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
    std::vector<char>Case = { 'Á', 'Â', 'Ã', 'Ä', 'Æ', 'Ç', 'Ê', 'Ë', 'Ì', 'Í', 'Ï', 'Ð', 'Ñ', 'Ò', 'Ô', 'Õ', 'Ó', '×', 'Ø', 'Ù', 'Ú', 'Ü', 'É', 'À', 'Å', '¨', 'È', 'Î', 'Ó', 'Û', 'Ý', 'Þ', 'ß' };
    std::vector<char>Symbol = { 'À', 'Å', '¨', 'È', 'Î', 'Ó', 'Û', 'Ý', 'Þ', 'ß', 'Ù', 'Ø', '×', 'Ö', 'Õ', 'Ô', 'Ò', 'Ñ', 'Ð', 'Ï', 'Á', 'Â', 'Ã', 'Ä', 'Æ', 'Ç', 'Ê', 'Ë', 'Ì', 'Í', 'Ý', 'Þ', 'ß' };
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