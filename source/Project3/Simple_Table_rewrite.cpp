#include "Simple_Table_rewrite.h"

std::string simple_table_rewrite_enc(std::string to_encr)
{
    std::string encripted;
    int size = size_of_matrix(to_encr);
    std::vector<std::string> matr = matrix(&to_encr); //записывает по строкам
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            encripted.push_back(matr[j].at(i));
        }
    }
    return encripted;
}

std::string simple_table_rewrite_dec(std::string to_decr)
{
    std::string decripted;
    int size = size_of_matrix(to_decr);
    std::vector<std::string> matr = to_matr(to_decr); //записывает по строкам
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            decripted.push_back(matr[j].at(i));
        }
    }
    return decripted;
}

std::vector<std::string> to_matr(std::string text) 
{
    int size = size_of_matrix(text);
    std::vector<std::string> matrix;
    std::string temp_str;
    for (int i = 0, j = 0; i < size; i++) {
        for (int k = 0; k < size; k++, j++) {
            temp_str.push_back(text.at(j));
        }
        matrix.push_back(temp_str);
        temp_str.clear();
    }
    return matrix;
}