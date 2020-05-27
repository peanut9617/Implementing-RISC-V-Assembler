#include<iostream>
#include<string>
#include <vector>
#include <sstream>

#define MAX 32
#pragma warning( disable : 4996 )
using namespace std;

string bit12(const string&str)
{
	if (str == "0")
		return "000000000000";
	else {
		int number, i = 0;
		number = stoi(str);
		int bin[MAX], len = 0;
		do
		{
			bin[i] = number % 2;
			number = number / 2;
			i++;
			len++;
		} 
		while (number != 1);
		bin[len] = number;
		len++;
		string result;

		for (i = len - 1; i >= 0; i--)
			result = result + to_string(bin[i]);

		while (result.size() != 12)
			result = "0" + result;

		return result;
	}
}
string bit5(const string&str)
{
	if (str == "0")
		return "00000";
	else {
		int number, i = 0;
		number = stoi(str);
		int bin[MAX], len = 0;
		do
		{
			bin[i] = number % 2;
			number = number / 2;
			i++;
			len++;
		} 
		while (number != 1);
		bin[len] = number;
		len++;
		string result;

		for (i = len - 1; i >= 0; i--)
			result = result + to_string(bin[i]);

		while (result.size() != 5)
			result = "0" + result;

		return result;
	}
}


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
		
		for (int i = 0; i < reg.size(); i++)				
		{
			if (reg[i] == "x0") reg[i] = "00000";
			if (reg[i] == "x1") reg[i] = "00001";
			if (reg[i] == "x2") reg[i] = "00010";
			if (reg[i] == "x3") reg[i] = "00011";
			if (reg[i] == "x4") reg[i] = "00100";
			if (reg[i] == "x5") reg[i] = "00101";
			if (reg[i] == "x6") reg[i] = "00110";
			if (reg[i] == "x7") reg[i] = "00111";
			if (reg[i] == "x8") reg[i] = "01000";
			if (reg[i] == "x9") reg[i] = "01001";
			if (reg[i] == "x10") reg[i] = "01010";
			if (reg[i] == "x11") reg[i] = "01011";
			if (reg[i] == "x12") reg[i] = "01100";
			if (reg[i] == "x13") reg[i] = "01101";
			if (reg[i] == "x14") reg[i] = "01110";
			if (reg[i] == "x15") reg[i] = "01111";
			if (reg[i] == "x16") reg[i] = "10000";
			if (reg[i] == "x17") reg[i] = "10001";
			if (reg[i] == "x18") reg[i] = "10010";
			if (reg[i] == "x19") reg[i] = "10011";
			if (reg[i] == "x20") reg[i] = "10100";
			if (reg[i] == "x21") reg[i] = "10101";
			if (reg[i] == "x22") reg[i] = "10110";
			if (reg[i] == "x23") reg[i] = "10111";
			if (reg[i] == "x24") reg[i] = "11000";
			if (reg[i] == "x25") reg[i] = "11001";
			if (reg[i] == "x26") reg[i] = "11010";
			if (reg[i] == "x27") reg[i] = "11011";
			if (reg[i] == "x28") reg[i] = "11100";
			if (reg[i] == "x29") reg[i] = "11101";
			if (reg[i] == "x30") reg[i] = "11110";
			if (reg[i] == "x31") reg[i] = "11111";
		}
		
	
	return 0;
} 
