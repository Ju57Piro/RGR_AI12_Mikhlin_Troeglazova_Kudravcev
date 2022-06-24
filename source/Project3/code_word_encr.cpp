#include "code_word_encr.h"

std::pair<bool, int> findInString(const std::string& Case, const char& element)
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

std::string get_code_word()
{
    std::string code_word;
    bool all_one_size = true;
    int k;
    do {
        k = 0;
        std::cout << "введите кодовое слово из букв малого размера английского алфавита: ";
        std::cin >> code_word;
        std::cout << std::endl;
        for (int i = 0; i < code_word.size(); i++) {
            if (code_word.at(i) >= 'a' && code_word.at(i) <= 'z') {
                k++;
            }
        }
        if (k == code_word.size()) {
            all_one_size = false;
        }
    } while (all_one_size);

    return code_word;
}

std::string code_word_encr(std::string to_encr)
{
    std::string lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string cw_lc_alphabet = input_code(get_code_word());
    std::string encr;
    for (int i = 0; i < to_encr.length(); i++) {
        std::pair<bool, int> result = findInString(lc_alphabet, to_encr[i]);
        if (result.first) {
            encr.push_back(cw_lc_alphabet[result.second]);
        }
        else {
            encr.push_back(to_encr[i]);
        }

    }
    return encr;
}

std::string code_word_decr(std::string to_decr)
{
    std::string lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string cw_lc_alphabet = input_code(get_code_word());
    std::string encr;
    for (int i = 0; i < to_decr.length(); i++) {
        std::pair<bool, int> result = findInString(cw_lc_alphabet, to_decr[i]);
        if (result.first) {
            encr.push_back(lc_alphabet[result.second]);
        }
        else {
            encr.push_back(to_decr[i]);
        }

    }
    return encr;
}

std::string input_code(std::string code_word)
{
    char x;
    std::string lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
    std::string cw_lc_alphabet = code_word;
    cw_lc_alphabet += lc_alphabet;
    for (int i = 0; i < code_word.size(); i++) {
        x = code_word.at(i);
        for (int j = i + 1; j < cw_lc_alphabet.size(); j++) {
            cw_lc_alphabet.erase(std::remove_if(std::next(cw_lc_alphabet.begin(), j), cw_lc_alphabet.end(), [x](char n) {return n == x; }));
        }
    }
    return cw_lc_alphabet;
}
