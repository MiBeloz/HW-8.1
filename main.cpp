#include "main.h"
#include "bad_length.h"


int main(int argv, char** argc) {
	setlocale(LC_ALL, "ru");
	std::cout << "\tПростое исключение\n\n" << std::endl;

	int forbiddenLength{};
	std::string word;

	std::cout << "Введите запретную длину: ";
	std::cin >> forbiddenLength;

	while (true) {
		SetConsoleCP(1251);
		std::cout << "Введите слово: ";
		std::cin >> word;
		SetConsoleCP(866);

		try {
			std::cout << "Длина слова \"" << word << "\" равна " << function(word, forbiddenLength) << std::endl << std::endl;
		}
		catch (const std::exception &ex) {
			std::cout << ex.what() << std::endl;
			break;
		}
		
	}

	system("pause > nul");

	return 0;
}

int function(const std::string word, const int forbiddenLength) {
	return word.length() == forbiddenLength ? throw bad_length() : static_cast<int>(word.length());
}