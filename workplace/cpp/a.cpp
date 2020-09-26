#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;
int main() {
	ifstream fin;
	fin.open("text.txt");
	if (fin.is_open() == false){
		cerr << "Can't open file. Bye.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0; 
	getline(fin, item, ':');
	while (fin) {//while input is good
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done\n"; 
	fin.close();
	cin.get();
	cin.get();
	return 0;
}