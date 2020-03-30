#include "King.h"
#define LEN_OF_LINE 8
#define LEN_OF_COLUMN 8
#define MAX_LEN 7

King::King(boardLetters x, int y, colors color) : Piece(x, y, color)
{};

moveResult King::check_move(boardLetters new_x, int new_y, Board &board)
{
	int i = 0;
	if (_x < 0 || new_x < 0 || _y < 0 || new_y < 0 || _x > MAX_LEN || new_x > MAX_LEN || _y > MAX_LEN || new_y > MAX_LEN)
	{
		return moveResult::moveInvalidIndex;
	}

	if (_x == new_x && _y == new_y)
	{
		return moveResult::moveInvalidSameSpace;
	}

	if ((new_x - _x != 1 && new_x - _x != -1 && new_x - _x != 0) || (new_y - _y != 1 && new_y - _y != -1 && new_y - _y != 0))
	{
		return moveResult::moveInvalidIllegalMove;
	}

	if (board[new_y][new_x] != nullptr && board[new_y][new_x]->getColor() == _color)
	{
		return moveResult::moveInvalidEndPiece;
	}

	return moveResult::moveValid;
}

bool King::check_check(Board &board)
{
	int i = 0, j = 0;
	int isValid = -1;
	for (i = 0; i < LEN_OF_LINE; i++)
	{
		for (j = 0; j < LEN_OF_COLUMN; j++)
		{
			isValid = -1;
			if (board[i][j] != nullptr)
			{
				isValid = board[i][j]->check_move(_x, _y, board);
			}
			if ((isValid == moveResult::moveValid || isValid == moveResult::movePawnUpgrade) && board[i][j]->getColor() != _color)
			{
				return true;
			}
		}
	}

	return false;
}