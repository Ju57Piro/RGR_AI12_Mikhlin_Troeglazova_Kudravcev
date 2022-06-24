#pragma once
#include "matrix.h"
#include "decrypt_matrix.h"
#include "Caesar's_cipher.h"
#include "TablShifr.h"
#include "Simple_Table_rewrite.h"
#include "code_word_encr.h"
#include <fstream>

bool pas();
std::ifstream readfile();
std::ofstream printfile(std::string& file_name2);

int type_selection();
void encr(std::ofstream& out, bool check2, std::string result, std::string text, int user_input, std::string file_name2);
void decr(std::ofstream& out, bool check2, std::string result, std::string text, int user_input, std::string file_name2);