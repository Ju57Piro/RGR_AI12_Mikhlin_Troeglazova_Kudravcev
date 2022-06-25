#pragma once
#include <iostream>
#include <string>


std::pair<bool, int > findInString(const std::string& Case, const char& element);
std::string get_code_word();
std::string code_word_encr(std::string to_encr);
std::string code_word_decr(std::string to_decr);
std::string input_code(std::string code_word);