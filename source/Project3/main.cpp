#include "cypher.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    bool check = false;
    while (check == false) {
        check = pas();
    }
    std::cout << std::endl;
    std::string text, tem_str, result, file_name2;
    std::vector<std::string> matr;
    std::ifstream file; //открыли файл для ввода
    std::ofstream out; //для вывода
    int user_input, n;
    bool check2 = false;
    while (check) {
        while (true) {
            file = readfile();//открывает файл для чтения
            while (true) {
                getline(file, tem_str);
                text += tem_str;
                if (!file == '\0') {
                    text.push_back('\n');
                }
                if (file.eof()) {
                    break;
                }
            } // файл в строку
            out = printfile(file_name2);//открывает файл для записи
            std::cout << "выберите режим работы: \n 1.шифрование файла \n 2.расшифровывание файла \n 3. завершить работу" << std::endl;
            std::cout << "Ввод: ";
            std::cin >> user_input;
            std::cout << std::endl;
            switch (user_input) {
            case 1:
                user_input = type_selection();
                encr(out, check2, result, text, user_input, file_name2); //передает данные для выбранной шифровки
                break;
            case 2:
                user_input = type_selection();
                decr(out, check2, result, text, user_input, file_name2);
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