#include "GameManager.h"

std::string GameManager::move(std::string gui_input)
{
	boardLetters startLetter = boardLetters::a, endLetter = boardLetters::a;
	int startNumber = 0, endNumber = 0;
	switch (gui_input[0])
	{
	case 'a':
		break; // letter is initialized as a
	case 'b':
		startLetter = boardLetters::b;
		break;
	case 'c':
		startLetter = boardLetters::c;
		break;
	case 'd':
		startLetter = boardLetters::d;
		break;
	case 'e':
		startLetter = boardLetters::e;
		break;
	case 'f':
		startLetter = boardLetters::f;
		break;
	case 'g':
		startLetter = boardLetters::g;
		break;
	case 'h':
		startLetter = boardLetters::h;
		break;
	default:
		return std::string("5"); // Index out of bounds
	}
	switch (gui_input[2])
	{
	case 'a':
		break; // letter is initialized as a
	case 'b':
		endLetter = boardLetters::b;
		break;
	case 'c':
		endLetter = boardLetters::c;
		break;
	case 'd':
		endLetter = boardLetters::d;
		break;
	case 'e':
		endLetter = boardLetters::e;
		break;
	case 'f':
		endLetter = boardLetters::f;
		break;
	case 'g':
		endLetter = boardLetters::g;
		break;
	case 'h':
		endLetter = boardLetters::h;
		break;
	default:
		return std::string("5"); // Index out of bounds
	}
	switch (gui_input[1])
	{
	case '8':
		break; // number is initialized as 0
	case '7':
		startNumber = 1;
		break;
	case '6':
		startNumber = 2;
		break;
	case '5':
		startNumber = 3;
		break;
	case '4':
		startNumber = 4;
		break;
	case '3':
		startNumber = 5;
		break;
	case '2':
		startNumber = 6;
		break;
	case '1':
		startNumber = 7;
		break;
	default:
		return std::string("5");
	}
	switch (gui_input[3])
	{
	case '8':
		break; // number is initialized as 0
	case '7':
		endNumber = 1;
		break;
	case '6':
		endNumber = 2;
		break;
	case '5':
		endNumber = 3;
		break;
	case '4':
		endNumber = 4;
		break;
	case '3':
		endNumber = 5;
		break;
	case '2':
		endNumber = 6;
		break;
	case '1':
		endNumber = 7;
		break;
	default:
		return std::string("5");
	}
	int result = gameBoard.move(startLetter, startNumber, endLetter, endNumber);
	if (result == 1 && gameBoard.check_checkMate())
	{
		result = 8;
	}
	return std::to_string(result);
}

void GameManager::init_board(std::string state)
{
	gameBoard.init(state);
}
