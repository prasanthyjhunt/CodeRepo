// IntegerReversal.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Adding initial comment
#include <iostream>

int ReverseDigits(int iNum_r)
{
    bool bIsNegativenumber = false;
    //first check if its negative 
	if( 0 < iNum_r)
    {
		bIsNegativenumber = true;
		iNum_r = -iNum_r;
    }
	
	int iRevNum = 0, iLastRevNumber = 0;
	while (0 != iNum_r)
	{
		int iDigitToAdd = iNum_r % 10;
		iRevNum = (iRevNum*10) + iDigitToAdd;
		//Now that we got the reversed number we need to see
		//if there was any overflow. To do this we will
		//compare the previous reversed number
		if(((iRevNum - iDigitToAdd)/10) != iLastRevNumber)
		{ 
			std::cout << "The reverse of input number has resulted in overflow" << std::endl;
			return 0;
		}
		iLastRevNumber = iRevNum;
		iNum_r /= 10;
	}

	return (true == bIsNegativenumber) ? -iRevNum : iRevNum;
}

int main()
{
	std::cout << "Output for 0 = " << ReverseDigits(0) << std::endl;
	std::cout << "Output for -123 = " << ReverseDigits(-123) << std::endl;
	std::cout << "Output for 123 = " << ReverseDigits(123) << std::endl;
	std::cout << "Output for 2346999999 = " << ReverseDigits(2346999999) << std::endl;
}

