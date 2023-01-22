#include"Header.h"

int main() {
	setlocale(LC_ALL, "ru");
	std::map<int, std::string> myMap1;
	int key = 23;
	myMap1.emplace(key, "Bob");
	DataManager A(myMap1);
	std::map<int, int> myMap2;
	myMap2.emplace(21, 34);
	DataManager B(myMap2);
	A.addMyMap(1, "Bob");
	A.addMyMap(23, "Al");
	A.showMyMapAll();
	B.showMyMapAll();
	A.Mod(24, "Bill");
	std::cout << "====================\n";
	A.Del(1);
	A.showMyMapAll();
	return 0;
}