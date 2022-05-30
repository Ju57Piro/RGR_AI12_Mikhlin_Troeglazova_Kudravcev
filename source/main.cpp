#include "cypher.h"

int main() {
    {
        setlocale(LC_ALL, "rus");
        std::string text; 
        std::ifstream file("cppstudio.txt"); //открыли файл

        if (!file.is_open()) // если файл не открыт
            std::cout << "Файл не может быть открыт!\n"; 
        else { //если открыт
            std::getline(file, text, '\0'); //считать до конца
                
        }
        
        system("pause");
        return 0;
    }
}