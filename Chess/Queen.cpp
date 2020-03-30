#include "Queen.h"

#define MAX_LEN 7

Queen::Queen(boardLetters x, int y, colors color) : Piece(x, y, color)
{}
moveResult Queen::check_move(boardLetters new_x, int new_y, Board &board)
{
	int j = 0;
	if (_x < 0 || new_x < 0 || _y < 0 || new_y < 0 || _x > MAX_LEN || new_x > MAX_LEN || _y > MAX_LEN || new_y > MAX_LEN)
	{
		return moveResult::moveInvalidIndex;
	}
	if (_x == new_x && _y == new_y)
	{
		return moveResult::moveInvalidSameSpace;
	}
	if (new_x != _x && new_y != _y && (new_x - _x) != (new_y - _y) && (new_x - _x) != (_y - new_y))
	{
		return moveResult::moveInvalidIllegalMove;
	}
	if (_x == new_x) // Only moving on Y axis
	{
		if (new_y > _y)
		{
			for (int i = _y + 1; i <= new_y; i++)
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
			for (int i = _y - 1; i >= new_y; i--)
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
	else if (_y == new_y) // Only moving on x axis
	{
		if (new_x > _x)
		{
			for (int i = _x + 1; i <= new_x; i++)
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
			for (int i = _x - 1; i >= new_x; i--)
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
	else
	{
		if (new_x > _x && new_y > _y)
		{
			j = _x + 1;
			for (int i = _y + 1; i <= new_y; i++)
			{
				if (i == new_y && board[i][j] != nullptr && board[i][j]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_y && board[i][j] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
				j++;
			}
		}
		else if (new_x < _x && new_y > _y)
		{
			j = _x - 1;
			for (int i = _y + 1; i <= new_y; i++)
			{
				if (i == new_y && board[i][j] != nullptr && board[i][j]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_y && board[i][j] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
				j--;
			}
		}
		else if (new_x > _x && new_y < _y)
		{
			j = _x + 1;
			for (int i = _y - 1; i >= new_y; i--)
			{
				if (i == new_y && board[i][j] != nullptr && board[i][j]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_y && board[i][j] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
				j++;
			}
		}
		else if (new_x < _x && new_y < _y)
		{
			j = _x - 1;
			for (int i = _y - 1; i >= new_y; i--)
			{
				if (i == new_y && board[i][j] != nullptr && board[i][j]->getColor() == _color)
				{
					return moveResult::moveInvalidEndPiece;
				}
				else if (i != new_y && board[i][j] != nullptr)
				{
					return moveResult::moveInvalidIllegalMove;
				}
				j--;
			}
		}
	}

	return moveResult::moveValid;
}