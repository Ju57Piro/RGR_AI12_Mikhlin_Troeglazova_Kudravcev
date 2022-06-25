#include "Polybius_square.h"

std::string Polybius_encr(std::string text) {
	size_t length = text.length();

	std::vector<std::string> v(text.length());
	for (int idx = 0; idx < length; idx++) {
		v[idx] = text[idx];
	}

	std::vector<std::string> d1 = { "A", "B", "C","D","E","F","G","H","I","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	std::vector<std::string> d2 = { "11","12","13","14","15","21","22","23","24","25","31","32","33","34","35","41","42","43","44","45","51","52","53","54","55" };
	
	for (int k = 0; k < length; k++) {
		for (int i = 0; i < 25; i++) {
			if (text[k] == 'J') {
				result.push_back("24");
				break;
			}
			if (v.at(k) == d1.at(i)) {
				result.push_back(d2.at(i));
				break;
			}
			if (v.at(k) != d1.at(i) && i == 24) {
				result.push_back(v.at(k));
				break;
			}
		}


	}
	return result;
}

std::string Polybius_decr(std::string text) {
	size_t length = text.length();

	std::vector<std::string> v(text.length());
	for (int idx = 0; idx < length; idx++) {
		v[idx] = text[idx];
	}

	std::vector<std::string> d1 = { "A", "B", "C","D","E","F","G","H","I","K","L","M","N","O","P","Q","R","S","T","U","V","W","X","Y","Z" };
	std::vector<std::string> d2 = { "11","12","13","14","15","21","22","23","24","25","31","32","33","34","35","41","42","43","44","45","51","52","53","54","55" };
	std::vector<std::string> num = { "1","2","3","4","5" };

	for (int k = 0; k < length; k++) {
		for (int i = 0; i < 5; i++) {

			if (k + 1 >= length) {
				result.push_back(v.at(k));
				break;
			}

			if (v.at(k) == num.at(i)) {
				k += 1;

				for (int j = 0; j < 5; j++) {

					if (v.at(k) == num.at(j)) {
						int c = i * 5 + j;
						result.push_back(d1.at(c));
						break;
					}

					if (v.at(k) != num.at(j) && j == 4) {
						result.push_back(v.at(k - 1));
						result.push_back(v.at(k));
						break;
					}

				}
				break;
			}

			if (v.at(k) != num.at(i) && i == 4) {
				result.push_back(v.at(k));
				break;
			}


		}
	}
	return result;
}