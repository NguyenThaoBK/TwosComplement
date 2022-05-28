#include "TwoComplement.h"

void printBinary(bool arrBinary[8])
{
	std::cout << "\n";
	for (int i = 7; i >= 0; i--)
		std::cout << arrBinary[i];
	std::cout << "\n";
}

bool isPositive(uint8_t num)
{
	return !((num >> 7) & 0x01);
}

void revertBits(bool arrBinary[8])
{
	for (int i = 0; i < 8; i++)
		arrBinary[i] = !arrBinary[i];
}

void getBits(uint8_t num, bool arrBinary[8])
{
	for (int i = 0; i < 8; i++)
		arrBinary[i] = (num >> i) & 0x01;
}

void calculate2Complement(uint8_t num, bool arrBinary[8])
{
	getBits(num, arrBinary);
	revertBits(arrBinary);

	bool temp = 1;
	for (int i = 0; i < 8; i++)
	{
		if (arrBinary[i] == 1 && temp == 1)
			arrBinary[i] = 0;
		else if (arrBinary[i] == 0 && temp == 1)
		{
			arrBinary[i] = 1;
			temp = 0;
		}
		else
			break;
	}
}

int getValueSigned(uint8_t num)
{
	bool arrBinary[8] = { 0 };
	int result = 0;
	if (isPositive(num))
		result = num;
	else
	{
		calculate2Complement(num, arrBinary);
		for (int i = 0; i < 8; i++)
			result += arrBinary[i] * pow(2, i);
		result = -result;
	}
	return result;
}

int main()
{
	uint8_t arr[10] = { 0, 1, 2, 15, 30, 127, 128, 130, 254, 255 };
	int8_t arrSigned[10] = { 0 };

	std::cout << "Print array as unsigned:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << (int)arr[i] << "\t";

	std::cout << "\nPrint array as signed:" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		arrSigned[i] = arr[i];
		std::cout << (int)arrSigned[i] << "\t";
	}

	std::cout << "\nPrint array as signed using 2Complement:" << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << (int)getValueSigned(arr[i]) << "\t";
}

