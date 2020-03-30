#pragma once
#include "Board.h"
#include <string>

class GameManager
{
public:
	std::string move(std::string gui_input);
	void init_board(std::string state);
private:
	Board gameBoard;
};