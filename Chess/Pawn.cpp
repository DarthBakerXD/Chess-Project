#include "Pawn.h"
#define WHITE_PAWN_START 6
#define BLACK_PAWN_START 1
#define PAWN_TWO_SPACES 2
#define END_FOR_BLACK_PAWN 7
#define END_FOR_WHITE_PAWN 0
#define MAX_LEN 7

Pawn::Pawn(boardLetters x, int y, colors color) : Piece(x, y, color)
{
}

moveResult Pawn::check_move(boardLetters new_x, int new_y, Board & board)
{
	if (_x < 0 || new_x < 0 || _y < 0 || new_y < 0 || _x > MAX_LEN || new_x > MAX_LEN || _y > MAX_LEN || new_y > MAX_LEN)
	{
		return moveResult::moveInvalidIndex;
	}
	if (_color == colors::black) // Since pawns can only move in one direction, seperating them based on color makes everything easier
	{
		if (new_x != _x)
		{
			if (new_x == _x + 1 || new_x == _x - 1) // Can only move one space diagonally
			{
				if (new_y != _y) // Trying to eat diagonally
				{
					if (new_y == _y + 1) // Actually moving forward
					{
						Piece* pieceToEat = board[new_y][new_x];
						if (pieceToEat != nullptr && pieceToEat->getColor() != _color)
						{
							if (new_y == END_FOR_BLACK_PAWN)
							{
								return moveResult::movePawnUpgrade;
							}

							return moveResult::moveValid;
						}
						else
						{
							return moveResult::moveInvalidIllegalMove;
						}
					}
					else
					{
						return moveResult::moveInvalidIllegalMove;
					}
				}
				else
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
			else
			{
				return moveResult::moveInvalidIllegalMove;
			}
		}
		else if (new_y != _y)
		{
			if (new_y > _y)
			{
				if ((new_y == _y + PAWN_TWO_SPACES && _y == BLACK_PAWN_START) || new_y == _y + 1)
				{
					Piece* moveTarget = board[new_y][new_x];
					if (moveTarget == nullptr)
					{
						if (new_y == END_FOR_BLACK_PAWN)
						{
							return moveResult::movePawnUpgrade;
						}

						return moveResult::moveValid;
					}
					else
					{
						return moveResult::moveInvalidEndPiece;
					}
				}
				else
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
			else
			{
				return moveResult::moveInvalidIllegalMove;
			}
		}
		else
		{
			return moveResult::moveInvalidSameSpace;
		}
	}
	else
	{
		if (new_x != _x)
		{
			if (new_x == _x + 1 || new_x == _x - 1) // Can only move one space diagonally
			{
				if (new_y != _y) // Trying to eat diagonally
				{
					if (new_y == _y - 1) // Actually moving forward
					{
						Piece* pieceToEat = board[new_y][new_x];
						if (pieceToEat != nullptr && pieceToEat->getColor() != _color)
						{
							if (new_y == END_FOR_WHITE_PAWN)
							{
								return moveResult::movePawnUpgrade;
							}

							return moveResult::moveValid;
						}
						else
						{
							return moveResult::moveInvalidIllegalMove;
						}
					}
					else
					{
						return moveResult::moveInvalidIllegalMove;
					}
				}
				else
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
			else
			{
				return moveResult::moveInvalidIllegalMove;
			}
		}
		else if (new_y != _y)
		{
			if (new_y < _y)
			{
				if ((new_y == _y - PAWN_TWO_SPACES && _y == WHITE_PAWN_START) || new_y == _y - 1)
				{
					Piece* moveTarget = board[new_y][new_x];
					if (moveTarget == nullptr)
					{
						if (new_y == END_FOR_WHITE_PAWN)
						{
							return moveResult::movePawnUpgrade;
						}

						return moveResult::moveValid;
					}
					else
					{
						return moveResult::moveInvalidEndPiece;
					}
				}
				else
				{
					return moveResult::moveInvalidIllegalMove;
				}
			}
			else
			{
				return moveResult::moveInvalidIllegalMove;
			}
		}
		else
		{
			return moveResult::moveInvalidSameSpace;
		}
	}
}
