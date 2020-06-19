# Implementing-RISC-V-Assembler

Input: 一段RISC-V組語的code

Output: 對應的machine code

測試方法: 執行code，輸入risc-v的code(ex. add x2,x3,x4)，會output對應的machine code。

完成部分: register、SB-type、I-type、S-type、R-type 

code撰寫方式 : main function 中，先將使用者輸入的存為string型態，根據逗號分割input的string，再將分割的四等分存入reg中，reg[0]用來判斷使用者輸入的instruction名稱，reg[1]、reg[2]、reg[3] 用來儲存使用者要input的register位址，接著根據不同的type做if的判斷，並output machine code。

//把input 的risc-v分割

	if (inst[i]== ',' || inst[i]== ')' || inst[i]== '(') )  inst[i] = ' ';
//

	stringstream ss(inst);
	string tempGet;
	while (ss >> tempGet) {
		reg.push_back(tempGet);
	}

//register

		for (int i = 0; i < reg.size(); i++)				
		{
			if (reg[i] == "x0") reg[i] = "00000";
			....
			if (reg[i] == "x31") reg[i] = "11111";
		}

// SB-type

		if (reg[0] == "bne")   machinecode = "*******" + reg[2] + reg[1] + "001" + "*****" + "1100011";
		...
		if (reg[0] == "bgtu")  machinecode = "*******" + reg[2] + reg[1] + "111" + "*****" + "1100011";

// I-type

		if (reg[0] == "lb")     machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "000" + reg[1] + "0000011";
		...
		if (reg[0] == "lhu")    machinecode = TransformToBinary_12bit(stoi(reg[2])) + reg[3] + "101" + reg[1] + "0000011";
		
// I-type

		if (reg[0] == "addi")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "000" + reg[1] + "0010011";
		...
		if (reg[0] == "andi")   machinecode = TransformToBinary_12bit(stoi(reg[3])) + reg[2] + "111" + reg[1] + "0010011";

// S-type

		if (reg[0] == "sd" || reg[0] == "sb" || reg[0] == "sh" || reg[0] == "sw")
		{
			imme = reg[2];
			imme = TransformToBinary_12bit(stoi(imme));
			machinecode = machinecode.append(imme, 0, 7);
			switch (reg[0][1])
			{
			case 'd':
				machinecode = machinecode + reg[1] + reg[3] + "011";
				break;
			case 'b':
				machinecode = machinecode + reg[1] + reg[3] + "000";
				break;
			case 'h':
				machinecode = machinecode + reg[1] + reg[3] + "001";
				break;
			case 'w':
				machinecode = machinecode + reg[1] + reg[3] + "010";
				break;
			}
			machinecode = machinecode.append(imme, 7, 5); //append 添加imme字串的某一段字串
			machinecode = machinecode + "0100011";
		}
//R-type

		if (reg[0] == "slli")  machinecode = "0000000" + TransformToBinary_5bit(stoi(reg[3])) + reg[2] + "001" + reg[1] + "0010011";
		...
		if (reg[0] == "srai")  machinecode = "0100000" + TransformToBinary_5bit(stoi(reg[3])) + reg[2] + "101" + reg[1] + "0010011";
		
		
// R-type

		if (reg[0] == "add")   machinecode = "0000000" + reg[3] + reg[2] + "000" + reg[1] + "0110011";
   		 ...
		if (reg[0] == "and")   machinecode = "0000000" + reg[3] + reg[2] + "111" + reg[1] + "0110011";
