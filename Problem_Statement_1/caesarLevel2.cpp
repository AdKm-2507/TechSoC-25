#include <iostream>
#include <vector>
#include <string>
#include <sstream>

// works if 1st encountered 2 letter word is from { "am", "an", "as", "at", "by", "go", "if", "in", "is", "it", "no", "of", "on", "or", "so", "to", "us", "we" }
// doesn't work if 2 letter word is from { "up", "be", "do", "my", "ok"}

std::string getString;

void getInput()
{
	std::cout << "Enter text: ";
	std::getline(std::cin >> std::ws, getString);
	std::cout << '\n';
}

std::string cleanString() //removes special characters and numbers
{
	std::string cleanString;

	for (char c : getString)
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' ')
			cleanString += c;

	return cleanString;
}

std::vector <std::string> makeInputVector() //returns a vector of words
{
	std::istringstream iss(cleanString());

	std::vector <std::string> listOfStrings;

	std::string w;

	while (iss >> w) listOfStrings.push_back(w);

	return listOfStrings;
}

std::vector <std::string> twoLetWord() //returns a vector of 2 lettered words
{
	std::vector <std::string> tempVector = makeInputVector();
	std::vector <std::string> twoLetterWords;

	for (int i = 0; i < tempVector.size(); i++)
	{
		std::string str = tempVector[i];

		if (str.size() == 2)
		{
			twoLetterWords.push_back(str);
		}
	}

	return twoLetterWords;
}

std::vector <std::string> oneLetWord() //returns a vector of 1 lettered words
{
	std::vector <std::string> listOfStrings = makeInputVector();
	std::vector <std::string> oneLetterWords = {};

	for (int i = 0; i < listOfStrings.size(); i++)
	{
		std::string str = listOfStrings[i];

		if (str.size() == 1)
		{
			oneLetterWords.push_back(str);
		}
	}

	return oneLetterWords;
}

void caesarCipher(int shift) //main caesar cipher function
{
	std::string text = getString;

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

int shiftOne() //in case 1 letter words are encountered
{
	std::vector <std::string> oneLetShift = oneLetWord();

	int shift1{};
	char tempChar{}; //Temporary character (to get char from string)

	for (int i = 0; i < oneLetShift.size(); i++)
	{
		for (char c : oneLetShift[i])
			tempChar = c;

		if (tempChar >= 'a' && tempChar <= 'z')
			shift1 = tempChar - 'a';
		else if (tempChar >= 'A' && tempChar <= 'Z')
			shift1 = tempChar - 'I';
	}
	return shift1;
}

int diffTwo() //returns difference between the two alphabets of 2 lettered words
{
	std::vector <std::string> twoLetShift = twoLetWord();
	std::string twoLetStr;
	int diff{};

	twoLetStr = twoLetShift[0];
	diff = twoLetStr[1] - twoLetStr[0];

	return diff;
}

int shiftTwo(int diff) //in case two lettered words are encountered (only if 1 lettered words are not encountered)
{
	std::vector <std::string> twoLetShift = twoLetWord();
	std::string twoLetStr;

	twoLetStr = twoLetShift[0];

	int shift2{};
	switch (diff)
	{
	case -18:
		shift2 = twoLetStr[0] - 'w';
		break;
	case -9:
		shift2 = twoLetStr[0] - 'o';
		break;
	case -5:
		shift2 = twoLetStr[0] - 't';
		break;
	case -4:
		shift2 = twoLetStr[0] - 's';
		break;
	case -3:
		shift2 = twoLetStr[0] - 'i';
		break;
	case -2:
		shift2 = twoLetStr[0] - 'u';
		break;
	case -1:
		shift2 = twoLetStr[0] - 'o';
		break;
	case 1:
		shift2 = twoLetStr[0] - 'n';
		break;
	case 3:
		shift2 = twoLetStr[0] - 'o';
		break;
	case 5:
		shift2 = twoLetStr[0] - 'i';
		break;
	case 8:
		shift2 = twoLetStr[0] - 'g';
		break;
	case 10:
		shift2 = twoLetStr[0] - 'i';
		break;
	case 11:
		shift2 = twoLetStr[0] - 'i';
		break;
	case 12:
		shift2 = twoLetStr[0] - 'a';
		break;
	case 13:
		shift2 = twoLetStr[0] - 'a';
		break;
	case 18:
		shift2 = twoLetStr[0] - 'a';
		break;
	case 19:
		shift2 = twoLetStr[0] - 'a';
		break;
	case 23:
		shift2 = twoLetStr[0] - 'b';
		break;
	default:
		break;
	}
	return shift2;
}

int inputShift()
{
	int inputShift{};
	std::cout << "Enter the shift: ";
	std::cin >> inputShift;

	return inputShift;
}

void menu()
{
		while (true)
	{
		int i{};
		std::cout << "\nEnter 1 for encode, 2 for decode using shift, 3 for decode without shift, 4 for exiting: ";
		std::cin >> i;

		if (i==1)
		{
			getInput();
			caesarCipher(inputShift());
		}
		else if (i == 2)
		{
			getInput();
			caesarCipher(-inputShift());
		}
		else if (i == 3)
		{
			getInput();

			std::vector <std::string> tempVector = oneLetWord();

			if (tempVector.size() == 0)
			{
				caesarCipher(-shiftTwo(diffTwo()));
				std::cout << "\nShift: " << shiftTwo(diffTwo());
			}
			else
			{
				caesarCipher(-shiftOne());
				std::cout << "\nShift: " << shiftOne();
			}
		}
		else if (i == 4)
		{
			break;
		}
		else
		{
			std::cout << "please input either 1 or 2 \n";
		}
	}
}

int main()
{
	menu();
	return 0;
}
