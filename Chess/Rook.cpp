#include "Rook.h"

#define MAX_LEN 7

Rook::Rook(boardLetters x, int y, colors color) : Piece(x, y, color)
{};

moveResult Rook::check_move(boardLetters new_x, int new_y, Board &board)
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
	if (_x != new_x && _y != new_y)
	{
		return moveResult::moveInvalidIllegalMove;
	}
	if (new_x == _x)
	{
		if (_y < new_y)
		{
			for (i = _y + 1; i <= new_y; i++)
			{
				if (i == new_y && board[i][_x] != nullptr && board[i][_x]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_y && board[i][_x] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
		}

		else
		{
			for (i = _y - 1; i >= new_y; i--)
			{
				if (i == new_y && board[i][_x] != nullptr && board[i][_x]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_y && board[i][_x] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
		}
	}

	else
	{
		if (_x < new_x)
		{
			for (i = _x + 1; i <= new_x; i++)
			{
				if (i == new_x && board[_y][i] != nullptr && board[_y][i]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_x && board[_y][i] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
		}

		else
		{
			for (i = _x - 1; i >= new_x; i--)
			{
				if (i == new_x && board[_y][i] != nullptr && board[_y][i]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_x && board[_y][i] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
		}
	}

	return moveResult::moveValid;
}