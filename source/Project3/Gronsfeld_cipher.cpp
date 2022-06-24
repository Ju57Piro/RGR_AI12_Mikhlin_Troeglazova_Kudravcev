#include "Gronsfeld_cipher.h"

std::string gronsfeld_encr(std::string text, int n)
{
	setlocale(LC_ALL, "Russian");
	char d1[33] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
	char d2[33] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я' };
	
	size_t length = text.length();
	
	std::string jump;
	jump = std::to_string(n);
	size_t jumpLength = jump.length();
	
	int c = 0;
	int p = length - 1;
	int k = -1;
	int u;
	int f;
	char sym;

	std::string result;
	std::string z;

	while (k < p) {
		k += 1;
		z = jump[c];
		f = stoi(z);

		for (int s = 0; s < 33; s++) {
			sym = text.at(k);
			
			u = s + f;

			while (u >= 33) {
				u = u - 33;
			}

			if (sym == d1[s]) {
				if (c == jumpLength - 1) {
					c = -1;
				}
				c++;
				result.push_back(d1[u]);
				break;
			}

			if (sym == d2[s]) {
				if (c == jumpLength - 1) {
					c = -1;
				}
				c++;
				result.push_back(d2[u]);
				break;
			}
			if ((sym != d1[s] || sym != d2[s]) && s == 32) {
				result.push_back(sym);
				break;
			}
		}

	}
	return result;
}


std::string  gronsfeld_decr(std::string text, int n)
{
	char d1[33] = { 'а', 'б', 'в', 'г', 'д', 'е', 'ё', 'ж', 'з', 'и', 'к', 'л', 'м', 'н', 'о', 'п', 'р', 'с', 'т', 'у', 'ф', 'х', 'ц', 'ч', 'ш', 'щ', 'ъ', 'ы', 'ь', 'э', 'ю', 'я' };
	char d2[33] = { 'А', 'Б', 'В', 'Г', 'Д', 'Е', 'Ё', 'Ж', 'З', 'И', 'К', 'Л', 'М', 'Н', 'О', 'П', 'Р', 'С', 'Т', 'У', 'Ф', 'Х', 'Ц', 'Ч', 'Ш', 'Щ', 'Ъ', 'Ы', 'Ь', 'Э', 'Ю', 'Я' };
	
	size_t length = text.length();
	
	std::string jump;
	jump = std::to_string(n);
	size_t jumpLength = jump.length();

	int c = 0;
	int p = length - 1;
	int k = -1;
	int u;
	int f;
	char sym;

	std::string result;
	std::string z;

	while (k < p) {
		k += 1;
		z = jump[c];
		f = stoi(z);

		for (int s = 0; s < 33; s++) {
			sym = text.at(k);

			u = s - f;

			while (u < 0) {
				u = u + 33;
			}
			if (sym == d1[s]) {
				if (c == jumpLength - 1) {
					c = -1;
				}
				c++;
				result.push_back(d1[u]);
				break;
			}

			if (sym == d2[s]) {
				if (c == jumpLength - 1) {
					c = -1;
				}
				c++;
				result.push_back(d2[u]);
				break;
			}

			if ((sym != d1[s] || sym != d2[s]) && s == 32) {
				result.push_back(sym);
				break;
			}
		}
	}
	return result;
}



