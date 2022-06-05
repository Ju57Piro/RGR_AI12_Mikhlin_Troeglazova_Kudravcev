#include "decrypt_matrix.h"

std::string decrypt_matrix(std::string text)
{
    std::string res;
    std::string cont_text = text;
    int a = cont_text.length();
    int size = size_of_matrix(text);
    char** matrix = write_to_matrix(text, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            res.push_back(matrix[i][j]);
        }
    }
    return res;
}

char** make_empty_matrix(int size)
{
    char** matrix = new char*[size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new char [size];
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = ' ';
        }
    }
    return matrix;
}

char** write_to_matrix(std::string& text, int size)
{
    int i, j, k, step;
    char** matrix = make_empty_matrix(size);
    i = j = size / 2;
    k = 0;
    step = 1;
    if (size % 2 == 0) { // четная матрица
        while (k < size * size) {
            write_to_matrix_by_dir(text, matrix, 0, step, i, j, k);
            write_to_matrix_by_dir(text, matrix, 1, step, i, j, k);
            write_to_matrix_by_dir(text, matrix, 2, step + 1, i, j, k);
            write_to_matrix_by_dir(text, matrix, 3, step + 1, i, j, k);
            step += 2;
            if (step >= size - 1) {
                write_to_matrix_by_dir(text, matrix, 0, step, i, j, k);
                write_to_matrix_by_dir(text, matrix, 1, step, i, j, k);
                write_to_matrix_by_dir(text, matrix, 2, step+1, i, j, k);
                break;
            }
        }
    }
    else {
        while (k < size * size) {
            write_to_matrix_by_dir(text, matrix, 3, step, i, j, k);
            write_to_matrix_by_dir(text, matrix, 0, step, i, j, k);
            write_to_matrix_by_dir(text, matrix, 1, step + 1, i, j, k);
            write_to_matrix_by_dir(text, matrix, 2, step + 1, i, j, k);
            step += 2;
            if (step >= size - 1) {
                write_to_matrix_by_dir(text, matrix, 3, step + 1, i, j, k);
                break;
            }
        }
    }
    return matrix;
}

