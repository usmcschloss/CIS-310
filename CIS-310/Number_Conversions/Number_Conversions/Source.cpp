#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*
Program Name: Number Conversions
Programmer Name: Michael Schloss
Date: 1/12/19
Class: CIS 310
*/

void ToBinary(int userNumber)
{
	vector<int> binaryNum;
	int spacer = 0;

	for (int i = 0; userNumber > 0; i++)
	{
		binaryNum.push_back(userNumber % 2);
		userNumber = userNumber / 2;
	}

	while (binaryNum.size() < 8)
	{
		binaryNum.push_back(0);
	}

	for (int i = (binaryNum.size() - 1); i >= 0; i--)
	{
		if (spacer == 4)
		{
			cout << " ";
		}
		cout << binaryNum.at(i);
		spacer++;
	}
}

void ToHexidecimal(double userNumber)
{
	vector<int> hexNumber;
	double answer;
	int remainder = 1, baseNum, placer = 0;
	int digitCount = 1, counter = 0, temp = userNumber;

	if (userNumber == 0)
	{
		cout << "0";
	}
	else
	{
		while (digitCount != 0)
		{
			digitCount = temp / 10;
			counter++;
			temp = digitCount;
		}

		while (counter != 0)
		{
			answer = userNumber / 16;
			baseNum = userNumber / 16;
			remainder = (answer - baseNum) * 16;

			hexNumber.push_back(remainder);

			userNumber = baseNum;
			counter--;
		}

		if (hexNumber.at(hexNumber.size() - 1) == 0)
		{
			hexNumber.pop_back();
		}

		for (int i = hexNumber.size() - 1; i >= 0; i--)
		{
			if (hexNumber.at(i) < 10)
			{
				cout << hexNumber.at(i);
			}
			else
			{
				switch (hexNumber.at(i))
				{
				case 10: cout << "A";
					break;
				case 11: cout << "B";
					break;
				case 12: cout << "C";
					break;
				case 13: cout << "D";
					break;
				case 14: cout << "E";
					break;
				case 15: cout << "F";
					break;
				}
			}
		}
	}	
}

void ToBCD(double userNumber)
{
	vector<int> holder;
	vector<int> binaryNum;
	int baseNum, spacer = 0, currNum;
	double temp = userNumber;
	double temp2;
	int digitCount = 1, counter = 0;
	
	while (digitCount != 0)
	{
		digitCount = temp / 10;
		counter++;
		temp = digitCount;
	}
	
	for (int i = 0; i < counter; i++)
	{
		temp = userNumber / 10;
		baseNum = userNumber / 10;
		userNumber = baseNum;
		temp2 = round((temp - baseNum) * 10);
		holder.push_back(temp2);

	}

	for (int i = (holder.size() - 1); i >= 0; i--)
	{
		currNum = holder.at(i);
		for (int j = 0; currNum > 0; j++)
		{
			binaryNum.push_back(currNum % 2);
			currNum = currNum / 2;
		}
		while (binaryNum.size() < 4)
		{
			binaryNum.push_back(0);
		}
		for (int j = (binaryNum.size() - 1); j >= 0; j--)
		{
			cout << binaryNum.at(j);
		}
		while (!binaryNum.empty())
		{
			binaryNum.pop_back();
		}
		cout << " ";
	}

}



int main()
{
	
	cout << "Number:       " << "Binary:        " << "Hexidecimal:        " << "BCD:" << endl;

	for (int i = 0; i <= 255; i++)
	{
		if (i < 10)
		{
			cout << i << setw(13);
			ToBinary(i);
			cout << setw(13);
			ToHexidecimal(i);
			cout << setw(19) << "0000 0000 ";
			ToBCD(i);
			cout << endl;
		}
		else if(i >= 10 && i <= 15)
		{
			cout << i << setw(12);
			ToBinary(i);
			cout << setw(13);
			ToHexidecimal(i);
			cout << setw(14) << "0000 ";
			ToBCD(i);
			cout << endl;
		}
		else if (i > 15 && i < 100)
		{
			cout << i << setw(12);
			ToBinary(i);
			cout << setw(13);
			ToHexidecimal(i);
			cout << setw(13) << "0000 ";
			ToBCD(i);
			cout << endl;
		}
		else
		{
			cout << i << setw(11);
			ToBinary(i);
			cout << setw(13);
			ToHexidecimal(i);
			cout << setw(9);
			ToBCD(i);
			cout << endl;
		}
	}


	


	return 0;
}