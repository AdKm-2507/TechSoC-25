#include <iostream>
#include <string>

std::string inputText()
{
	std::string inputText;
	std::cout << "Enter the text: ";
	std::getline(std::cin >> std::ws, inputText);

	return inputText;
}

int inputShift()
{
	int inputShift{};
	std::cout << "Enter the shift: ";
	std::cin >> inputShift;

	return inputShift;
}

void caesarCipher(int shift)
{
	std::string text{ inputText() };

	shift = shift % 26;

	for (char c : text)
	{
		if (c >= 'a' && c <= 'z')
		{
			c = (c - 97 + shift % 26 + 26) % 26 + 97;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			c = (c - 65 + shift % 26 + 26) % 26 + 65;
		}
		std::cout << c;
	}
}

int main()
{
	while (true)
	{
		int i{};
		std::cout << "\nEnter 1 for encode, 2 for decode or 3 for exiting: ";
		std::cin >> i;

		if (i == 1)
			caesarCipher(inputShift()); //for encoding
		else if (i == 2)
			caesarCipher(-inputShift()); //for decoding
		else if (i == 3)
			break;
		else
			std::cout << "please input either 1 or 2 or 3. Thanks. \n"; 
	}
	return 0;
}