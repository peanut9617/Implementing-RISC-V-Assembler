#include<iostream>
using namespace std;
int main() {
	cout << "Inst = ";
	string inst;
	string imme;
	string machinecode;

	while (getline(cin, inst)) {
		if (inst == "")
			continue;

		vector<string> reg;

		for (int i = 0; i < inst.length(); i++) {
			if (inst[i]== ',' || inst[i]== ')' || inst[i]== '(') {
				inst[i] = ' ';
			}
		}

		stringstream ss(inst);
		string tempGet;
		while (ss >> tempGet) {
			reg.push_back(tempGet);
		}
		
	
	return 0;
} 
