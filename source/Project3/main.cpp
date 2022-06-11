#include "cypher.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    bool check = false;
    while (check == false) {
        std::cout << "введите пароль для доступа к программе: ";
        std::string pas = "1111";
        std::string user_pas;
        std::cin >> user_pas;
        if (user_pas == pas) {
            check = true;
        }
    }
    std::cout << std::endl;
    std::string text, tem_str, file_name1, file_name2, result;
    std::vector<std::string> matr;
    std::ifstream file; //открыли файл для ввода
    std::ofstream out; //для вывода
    int user_input, n;
    bool check2 = false;
    while (check) {
        while (true) {
            do {
                std::cout << "Введите имя файла для чтения: ";
                std::cin >> file_name1;
                std::cout << std::endl;
                file.open(file_name1);
                if (!file.is_open()) { // если файл не открыт
                    std::cout << "Файл не может быть открыт!\n \n";
                }
                else { //если открыт
                    while (true) {
                        getline(file, tem_str);
                        text += tem_str;
                        if (!file == '\0') {
                            text.push_back('\n');
                        }
                        if (file.eof()) {
                            break;
                        }
                    }
                } //считывание файла в строку
            } while (!file.is_open());

            do
            {
                std::cout << "Введите имя файла для записи: ";
                std::cin >> file_name2;
                std::cout << std::endl;
                out.open(file_name2);
                if (!file.is_open()) {// если файл не открыт
                    std::cout << "Файл не может быть открыт!\n \n";
                }
            } while (!file.is_open());
            std::cout << "выберите режим работы: \n 1.шифрование файла \n 2.расшифровывание файла \n 3. завершить работу" << std::endl;
            std::cout << "Ввод: ";
            std::cin >> user_input;
            std::cout << std::endl;
            switch (user_input) {
            case 1:
                std::cout << "выберите тип шифрования: \n";
                std::cout << "1.шифрование методом цезаря \n";
                std::cout << "2.шифрование табличным методом \n";
                std::cout << "3.шифрование матричным методом" << std::endl;
                std::cout << "Ввод: ";
                std::cin >> user_input;
                std::cout << std::endl;
                int size;
                switch (user_input)
                {
                case 1:
                    do {
                        std::cout << "введите сдвиг для шифра цезаря больше 0:";
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
                    size = size_of_matrix(text);
                    result = matrix_to_string(matr, size);
                    out << result;
                    std::cout << "шифрование успешно результат в: " << file_name2 << "\n \n";
                    break;
                default:
                    std::cout << "некорректные данные" << std::endl;
                }
                break;
            case 2:
                std::cout << "выберите тип шифрования: \n";
                std::cout << "1.шифрование методом цезаря \n";
                std::cout << "2.шифрование табличным методом \n";
                std::cout << "3.шифрование матричным методом" << std::endl;
                std::cout << "Ввод: ";
                std::cin >> user_input;
                std::cout << std::endl;
                switch (user_input) {
                case 1:
                    do {
                        std::cout << "введите сдвиг для шифра цезаря больше 0" << std::endl;
                        std::cin >> n;
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
                default:
                    std::cout << "некорректные данные" << std::endl;
                }
                break;
            case 3:
                std::cout << "спасибо за использование нашей программы." << std::endl;
                file.close();
                out.close();
                return 0;
            default:
                std::cout << "некорректные данные" << std::endl;
            }
            text.clear();
            result.clear();
            file.close();
            out.close();
        }
    }
    return 0;
}