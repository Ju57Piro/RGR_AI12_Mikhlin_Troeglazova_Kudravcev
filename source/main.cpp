#include "cypher.h"

int main() {
    {
        setlocale(LC_ALL, "rus");
        std::string text; 
        std::ifstream file("cppstudio.txt"); //������� ����

        if (!file.is_open()) // ���� ���� �� ������
            std::cout << "���� �� ����� ���� ������!\n"; 
        else { //���� ������
            std::getline(file, text, EOF); //������� �� �����
                
        }
        
        system("pause");
        return 0;
    }
}