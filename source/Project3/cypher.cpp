#include "cypher.h"

bool pas()
{
    bool check = false;
    std::cout << "введите пароль для доступа к программе: ";
    std::string pasw = "1111";
    std::string user_pas;
    std::cin >> user_pas;
    if (user_pas == pasw) {
        check = true;
    }
    return check;
}

std::ifstream readfile()
{
    std::ifstream file;
    std::string file_name1, tem_str;
    do {
        std::cout << "Введите имя файла для чтения: ";
        std::cin >> file_name1;
        std::cout << std::endl;
        file.open(file_name1);
        if (!file.is_open()) { // если файл не открыт
            std::cout << "Файл не может быть открыт!\n \n";
        }
    } while (!file.is_open());
    return file;
}

std::ofstream printfile(std::string& file_name2)
{
    std::ofstream out;
    do
    {
        std::cout << "Введите имя файла для записи: ";
        std::cin >> file_name2;
        std::cout << std::endl;
        out.open(file_name2);
        if (!out.is_open()) {// если файл не открыт
            std::cout << "Файл не может быть открыт!\n \n";
        }
    } while (!out.is_open());
    return out;
}

int type_selection()
{
    int user_input;
    std::cout << "выберите тип шифрования: \n";
    std::cout << "1.шифрование методом цезаря \n";
    std::cout << "2.шифрование табличным методом \n";
    std::cout << "3.шифрование матричным методом \n";
    std::cout << "4.шифрование с использованием кодового слова\n";
    std::cout << "5.шифрование простой табличной перестановкой \n";
    std::cout << "6.шифрование методом Атбаш\n";
    std::cout << "7.шифрование методом <тарабарская грамота>\n";
    std::cout << "8.шифрование с помощью квадрата Полибия \n";
    std::cout << "9.шифрование методом Гронсфельда\n";
    std::cout << "Ввод: ";
    std::cin >> user_input;
    std::cout << std::endl;
    return user_input;
}

void encr(std::ofstream& out, bool check2, std::string result, std::string text, int user_input, std::string file_name2)
{
    int n;
    std::vector<std::string> matr;
    switch (user_input)
    {
    case 1:
        do {
            std::cout << "введите сдвиг для шифра цезаря больше 0: ";
            std::cin >> n;
            std::cout << std::endl;
            if (n >= 0) {
                check2 = true;
            }
        } while (check2 == false);
        result = Encryption(text, n);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 2:
        result = Tabl(text);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 3:
        matr = matrix(&text);
        n = size_of_matrix(text);
        result = matrix_to_string(matr, n);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 4:
        result = code_word_encr(text);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 5:
        result = simple_table_rewrite_enc(text);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 6:
        result = atbash_encr(text);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 7:
        result = tarabar_encr(text);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 8:
        break;
    case 9:
        do {
            std::cout << "введите сдвиг для шифра Гронсфельда больше 0: ";
            std::cin >> n;
            std::cout << std::endl;
            if (n >= 0) {
                check2 = true;
            }
        } while (check2 == false);
        result = gronsfeld_encr(text, n);
        out << result;
        std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    default:
        std::cout << "некорректные данные" << std::endl;
    }
}

void decr(std::ofstream& out, bool check2, std::string result, std::string text, int user_input, std::string file_name2)
{
    int n;
    switch (user_input) {
    case 1:
        do {
            std::cout << "введите сдвиг для шифра цезаря больше 0: ";
            std::cin >> n;
            std::cout << std::endl;
            if (n >= 0) {
                check2 = true;
            }
        } while (check2 == false);
        result = Decryption(text, n);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 2:
        result = DecShif(text);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 3:
        result = decrypt_matrix(text);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 4:
        result = code_word_decr(text);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 5:
        result = simple_table_rewrite_dec(text);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 6:
        result = atbash_decr(text);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 7:
        result = tarabar_decr(text);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    case 8:
        break;
    case 9:
        do {
            std::cout << "введите сдвиг для шифра Гронсфельда больше 0: ";
            std::cin >> n;
            std::cout << std::endl;
            if (n >= 0) {
                check2 = true;
            }
        } while (check2 == false);
        result = gronsfeld_decr(text, n);
        out << result;
        std::cout << "дешифрование успешно результат в: " << file_name2 << "\n \n";
        break;
    default:
        std::cout << "некорректные данные" << std::endl;
    }
}

