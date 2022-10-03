#include <iostream>
#include <fstream>

using namespace std;

bool zadaniePierwsze = true;

string skrot(string wiadomosc) {
	int S[8] = {'A','L','G','O','R','Y','T','M'};
	while (wiadomosc.length() % 8 != 0) {
		wiadomosc += '.';
	}
	
	if (zadaniePierwsze) cout << wiadomosc.length() << endl; 
	
	int j = 0;
	for (int i = 0; i < wiadomosc.length(); i++) {
		S[j] = (S[j] + wiadomosc[i]) % 128;
		j++;
		if (j == 8) j = 0;
	}
	string wynik = "";
	
	if (zadaniePierwsze) {
		for (int i = 0; i < 8; i++) {
			cout << S[i] << " ";
		}
		cout << endl;
	}
	
	for (int j = 0; j < 8; j++) {
		wynik = wynik + (char) (65 + S[j] % 26);
	}
	return wynik;
}



void z1() {
	cout << "Zadanie 1: " << endl;
	ifstream in("wiadomosci.txt");
	string s;
	getline(in, s);
	cout << skrot(s) << endl << endl;
	zadaniePierwsze = false;
}

string odszyfrujSkrot(int tab[], int d, int n) {
	string ans = "";
	for (int i = 0; i < 8; i++) {
		tab[i] = (tab[i] * 3 % 200);
		ans += (char) tab[i];
	}
	return ans;
}

void z2() {
	cout << "Zadanie 2:" << endl;
	ifstream in("podpisy.txt");
	int tab[8];
	string ans;
	for (int q = 0; q < 11; q++) { 
		for (int i = 0; i < 8; i++) {
			in >> tab[i];
		}
		ans = odszyfrujSkrot(tab, 3, 200);
		cout << ans << endl;
	}
	cout << endl;
}

void z3() {
	cout << "Zadanie 3:" << endl;
	ifstream inWiadomosc("wiadomosci.txt");
	ifstream inPodpis("podpisy.txt");
	string wiadomosc;
	int tab[8];
	for (int i = 0; i < 11; i++) {
		getline(inWiadomosc, wiadomosc);
		for (int j = 0; j < 8; j++) inPodpis >> tab[j];
		if (skrot(wiadomosc) == odszyfrujSkrot(tab, 3, 200)) cout << i + 1 << endl;
	}
	cout << endl;
}

int main() {
	z1();
	z2();
	z3();
}
