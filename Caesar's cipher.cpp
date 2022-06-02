#include <iostream>
#include "windows.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "Caesar's cipher" << endl;
	cout << "Encryption" << endl;
	cout << "" << endl;
	cout << "Enter password" << endl;
	int password;
	cin >> password;

	if (password == 1111){
		char d1[33] = {(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)240,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159 };
		char d2[33] = {(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)241,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239 };
		
		cout << "" << endl;

		cout << "Enter text" << endl;
		int text;
		cin >> text;
		string text;
		cin >> text;
		size_t length = text.length();

		cout << "Number of jumps per character" << endl;
		int n;
		cin >> n;
		
		

		char d4[length];
		int p = length - 1;
		int k = -1;
		int u;
		char sym;
		

		while (k < p) {
			k += 1;
			
			for (int s = 0; s < 33; s++) {
				sym = text.at(k);
				u = s + n;

				while (u >= 33) {
					u = u - 33;
				}

				if (sym == d1[s]) {

					d4[k] = d1[u];
					break;
				}

				if (sym == d2[s]) {
					d4[k] = d2[u];
					break;
				
				
				}

			}
			
		}
		for (int j; j < length; j++) {
			cout << d4[j];
		}

			cout << "" << endl;
			cout << "Decryption" << endl;
			cout << "" << endl;
			cout << "Enter password" << endl;
			cin >> password;
			if (password == 1111) {
				k = -1;
				while (k < p) {
					k += 1;

					for (int s = 0; s < 33; s++) {
						sym = d4[k];
						u = s - n;

						while (u < 0) {
							u = u + 33;
						}

						if (sym == d1[s]) {

							d4[k] = d1[u];
							break;
						}

						if (sym == d2[s]) {
							d4[k] = d2[u];
							break;



						}

					}
				}
				for (int j=0; j < length; j++) {
					cout << d4[j];
				}
			}

		}
	}
	
	
