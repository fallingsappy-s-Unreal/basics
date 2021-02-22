#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty)
{
	std::cout << "___.___    ~            _____________\n";
	std::cout << "\\  \\\\  \\   ,, ???      |        '\\\\\\\\\\\\\n";
	std::cout << " \\  \\\\  \\ /<   ?       |        ' ____|_\n";
	std::cout << "  --\\//,- \\_.  /_____  |        '||::::::\n";
	std::cout << "     o- /   \\_/     '\\ |        '||_____|\n";
	std::cout << "     | \\ '   o        '________|_____|\n";
	std::cout << "     |  )-   #      <  ___/____|___\\___\n";
	std::cout << "     `_/'------------|    _    '  <<<:|\n";
	std::cout << "	  /________\| |_________'___o_o|\n";
	std::cout << "\n\nYou are a secret agent breaking into a level " << LevelDifficulty;
	std::cout << " secure server room\n\n You need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int LevelDifficulty)
{
	PrintIntroduction(LevelDifficulty);

	int CodeA = rand() % LevelDifficulty + LevelDifficulty;
	int CodeB = rand() % LevelDifficulty + LevelDifficulty;
	int CodeC = rand() % LevelDifficulty + LevelDifficulty;
	 
	int CodeSum = CodeA + CodeB + CodeC;
	int CodeProduct = CodeA * CodeB * CodeC;

	int GuessA, GuessB, GuessC;

	std::cout << "There are 3 numbers in the code\n";

	std::cout << "\nThe codes add-up to: " << CodeSum;

	std::cout << "\nThe codes multiply to give: " << CodeProduct << std::endl; 

	std::cin >> GuessA >> GuessB >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	std::cout << GuessSum;
	std::cout << GuessProduct;

	if (CodeSum == GuessSum && CodeProduct == CodeProduct)
	{
		std::cout << "\nYou entered correct code! \n";
		std::cout << "\nProceeding further... \n";
		return true;
	}
	else
	{
		std::cout << "\nYou guessed wrond... \n";
		std::cout << "\nTry again!... \n";
		return false;
	}
}

int main()
{
	srand(time(NULL));
	int LevelDifficulty = 1;
	const int MaxDifficulty = 3;
	
	while (LevelDifficulty <= MaxDifficulty)
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		std::cin.clear();
		std::cin.ignore();

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}

	std::cout << "\nYou downloaded the data from mainframe and left the fascility \n";
	std::cout << "\nGood job!\n";
}
