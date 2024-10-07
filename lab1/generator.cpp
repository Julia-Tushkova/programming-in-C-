#include "iostream"
#include "string"
#include <fstream>
using namespace std;
int main(void) {
	string type1, type2, type3;
	char sign_operation;

	cout << "Input type 1\n";
	cin >> type1;

	cout << "Input type 2\n";
	cin >> type2;

	cout << "Input type 3\n";
	cin >> type3;

	cout << "You have entered:\ntype 1: " << type1 << "\ntype 2: " << type2 << "\ntype 3: " << type3 << endl;

	cout << "enter the sign of the mathematical operation: +, -, *, /" << endl;
	cin >> sign_operation;

	ofstream fout("func_1.cpp");
	fout << "#include <iostream>" << endl;
	fout << "int f(void) {" << endl;
	fout << type1 << " var1 = 1;" << endl;
	fout << type2 << " var2 {3};" << endl;
	fout << type3 << " var3 = 7;" << endl;
	fout << "std::cout << var1 " << sign_operation << " var2 " << sign_operation << " var3 << std::endl; " << endl;
	fout << "return 0;" << endl;
	fout << "}" << endl;
	fout.close();
	return 0;
}
