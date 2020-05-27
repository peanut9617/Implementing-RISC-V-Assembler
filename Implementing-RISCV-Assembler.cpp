#include<iostream>
#include<string>
#include <vector>
#include <sstream>
#define MAX 32
#pragma warning( disable : 4996 )
using namespace std;

string TransformToBinary_12bit(int HEX){
	if (HEX == 0)
		return "000000000000";
	string reverse="";
	int t = Hex;
	while (t != 0){
		if (t % 2 == 0)
			reverse = reverse + "0";
		else if (t % 2 == 1)
			reverse = reverse + "1";
		t /=  2;
	}

	string a="";
	for (int i = 11 i >= 0; i--){
		if(i > reverse.length()-1)
			a = a + "0";	
		else
			a = a +reverse[i];
	}
	return a;
}

string TransformToBinary_12bit(int HEX){
	if (HEX == 0)
		return "00000";
	string reverse="";
	int t = Hex;
	while (t != 0){
		if (t % 2 == 0)
			reverse = reverse + "0";
		else if (t % 2 == 1)
			reverse = reverse + "1";
		t /=  2;
	}

	string a="";
	for (int i = 4 i >= 0; i--){
		if(i > reverse.length() - 1)
			a = a + "0";	
		else
			a = a +reverse[i];
	}
	return a;
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
		
		if (reg[0] == "bne")   machinecode = "*******" + reg[2] + reg[1] + "001" + "*****" + "1100011";
		if (reg[0] == "beq")   machinecode = "*******" + reg[2] + reg[1] + "000" + "*****" + "1100011";
		if (reg[0] == "blt")   machinecode = "*******" + reg[2] + reg[1] + "100" + "*****" + "1100011";
		if (reg[0] == "bgt")   machinecode = "*******" + reg[2] + reg[1] + "101" + "*****" + "1100011";
		if (reg[0] == "bltu")  machinecode = "*******" + reg[2] + reg[1] + "110" + "*****" + "1100011";
		if (reg[0] == "bgtu")  machinecode = "*******" + reg[2] + reg[1] + "111" + "*****" + "1100011";
		
		if (reg[0] == "addi")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "000" + reg[1] + "0010011";
		if (reg[0] == "slti")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "010" + reg[1] + "0010011";
		if (reg[0] == "sltu")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "011" + reg[1] + "0010011";
		if (reg[0] == "xori")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "100" + reg[1] + "0010011";
		if (reg[0] == "ori")    machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "110" + reg[1] + "0010011";
		if (reg[0] == "andi")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "111" + reg[1] + "0010011";

		if (reg[0] == "lb")     machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "000" + reg[1] + "0000011";
		if (reg[0] == "lh")     machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "001" + reg[1] + "0000011";
		if (reg[0] == "lw")     machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "010" + reg[1] + "0000011";
		if (reg[0] == "lbu")    machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "100" + reg[1] + "0000011";
		if (reg[0] == "lhu")    machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "101" + reg[1] + "0000011";
	return 0;
} 
