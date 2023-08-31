#include <iostream>
#include <vector>

using namespace std;

void afficheur7Segment(const vector<vector<string>>& segments) {
	system("cls");
	for (int i = 0; i < segments.size(); i++) {
		cout << '\t';
		for (int j = 0; j < segments[i].size(); j++) {
			cout << segments[i][j];
		}
		cout << endl;
	}
	std::cin.get();
}

vector<bool> HexaToBinaire(int n) {
	vector<bool> binaire;
	while (n > 0) {
		binaire.push_back(n % 2);
		n /= 2;
	}
	while (binaire.size() < 4) {
		binaire.push_back(0);
	}
	return binaire;
}

// Fonction utilitaire pour convertir
// FROM 
// x3.x2.!x0 + x3.!x2.!x1 + !x2.!x0 + x2.x1 + !x3.x1 + !x3.x2.x0
// TO
// x3 && x2 && !x0 || x3 && !x2 && !x1 || !x2 && !x0 || x2 && x1 || !x3 && x1 || !x3 && x2 && x0
void convert(string str) {
	string res = "";
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'x') {
			res += str[i];
			res += str[i + 1];
			i++;
		}
		else if(str[i] == '!') {
			res += "!";
		}
		else if (str[i] == '+') {
			res += " || ";
		}
		else if (str[i] == '.') {
			res += " && ";
		}
	}
	std::cout << res << endl;
}

void main() {
		
	const int iA = 0, jA = 1;
	const int iB = 1, jB = 2;
	const int iC = 3, jC = 2;
	const int iD = 4, jD = 1;
	const int iE = 3, jE = 0;
	const int iF = 1, jF = 0;
	const int iG = 2, jG = 1;

	while (true) {

		vector<vector<string>> segments =
		{
			{ " ", " ", " " },
			{ " ", " ", " " },
			{ " ", " ", " " },
			{ " ", " ", " " },
			{ " ", " ", " " }
		};

		cout << "Saisir un nombre Hexadecimal (0-F) : ";
		int nombre;
		cin >> hex >> nombre;

		auto binaire = HexaToBinaire(nombre);

		bool x0 = binaire[0];
		bool x1 = binaire[1];
		bool x2 = binaire[2];
		bool x3 = binaire[3];

		// Segment A
		if (
			x1 && !x0 || !x3 && x1 || x2 && x1 || !x2 && !x0 || !x3 && x2 && x0 || x3 && !x2 && !x1 || x3 && !x1 && !x0
			) {
			segments[iA][jA] = "-";
		}
		
		// Segment B
		if (
			!x3 && !x2 || !x3 && x1 && x0 || !x2 && !x0 || x3 && !x1 && x0 || !x3 && !x1 && !x0 || !x2 && !x1
			) {
			segments[iB][jB] = "|";
		}

		// Segment C
		if (
			!x3 && x2 || x3 && !x2 || !x1 && x0 || !x3 && !x1 || !x3 && x0
			) {
			segments[iC][jC] = "|";
		}

		// Segment D
		if (
			x3 && !x1 || x2 && !x1 && x0 || x2 && x1 && !x0 || !x3 && !x2 && !x0 || !x2 && x1 && x0
			) {
			segments[iD][jD] = "-";
		}

		// Segment E
		if (
			x3 && x2 || x1 && !x0 || x3 && x1 || !x2 && !x1 && !x0
			) {
			segments[iE][jE] = "|";
		}

		// Segment F
		if (
			x3 && !x2 || !x1 && !x0 || x3 && x1 || x2 && x1 && !x0 || !x3 && x2 && !x1
			) {
			segments[iF][jF] = "|";
		}

		// Segment G
		if (
			x3 && !x2 || x1 && !x0 || x3 && x0 || !x3 && x2 && !x1 || !x3 && !x2 && x1
			) {
			segments[iG][jG] = "-";
		}
		
		afficheur7Segment(segments);
	}
}