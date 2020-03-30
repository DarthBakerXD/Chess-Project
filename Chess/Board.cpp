#include "Board.h"
#include "Piece.h"
#include "Rook.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>
#define UNNECESSARY_CHARS 1
#define LEN_OF_LINE 8
#define LEN_OF_COLLUM 8
#define PLAYER_TURN_INDEX 64

Board::~Board()
{
	for (int i = 0; i < LEN_OF_LINE; i++)
	{
		for (int j = 0; j < LEN_OF_COLLUM; j++)
		{
			if (_board[i][j] != nullptr)
			{
				delete _board[i][j];
			}
		}
	}
}

void Board::init(std::string input)
{
	int horizontal = 0, vertical = 0;
	int index = 0;
	for (vertical = 0; vertical < LEN_OF_LINE; vertical++)
	{
		for (horizontal = 0; horizontal < LEN_OF_COLLUM; horizontal++)
		{
			switch (input[index])
			{
			case 'k': // king
				_board[vertical][horizontal] = new King((boardLetters)horizontal, vertical, colors::black);
				_blackKing = (King*)_board[vertical][horizontal];
				break;
			case 'K':
				_board[vertical][horizontal] = new King((boardLetters)horizontal, vertical, colors::white);
				_whiteKing = (King*)_board[vertical][horizontal];
				break;
			case 'q': // queen
				_board[vertical][horizontal] = new Queen((boardLetters)horizontal, vertical, colors::black);
				break;
			case 'Q':
				_board[vertical][horizontal] = new Queen((boardLetters)horizontal, vertical, colors::white);
				break;
			case 'r': // rook
				_board[vertical][horizontal] = new Rook((boardLetters)horizontal, vertical, colors::black);
				break;
			case 'R':
				_board[vertical][horizontal] = new Rook((boardLetters)horizontal, vertical, colors::white);
				break;
			case 'n': // knight
				_board[vertical][horizontal] = new Knight((boardLetters)horizontal, vertical, colors::black);
				break;
			case 'N':
				_board[vertical][horizontal] = new Knight((boardLetters)horizontal, vertical, colors::white);
				break;
			case 'b': // bishop
				_board[vertical][horizontal] = new Bishop((boardLetters)horizontal, vertical, colors::black);
				break;
			case 'B':
				_board[vertical][horizontal] = new Bishop((boardLetters)horizontal, vertical, colors::white);
				break;
			case 'p': // pawn
				_board[vertical][horizontal] = new Pawn((boardLetters)horizontal, vertical, colors::black);
				break;
			case 'P':
				_board[vertical][horizontal] = new Pawn((boardLetters)horizontal, vertical, colors::white);
				break;
			default: // # aka empty
				_board[vertical][horizontal] = nullptr;
				break;
			}
			index++;
		}
		
	}
	int playerNum = (int)input[PLAYER_TURN_INDEX];
	playerNum -= '0';
	_currentPlayer = (colors)playerNum;
}

Piece ** Board::operator[](int index)
{
	return _board[index];
}

int Board::move(boardLetters start_horizontal, int start_vertical, boardLetters end_horizontal, int end_vertical)
{
	Piece* toMove = _board[start_vertical][start_horizontal];
	Piece* temp = nullptr;
	char upgradeForPawn = '0';
	if (toMove == nullptr)
	{
		return moveResult::moveInvalidStartPiece;
	}
	if (toMove->getColor() != _currentPlayer)
	{
		return moveResult::moveInvalidStartPiece;
	}
	moveResult isValid = toMove->check_move(end_horizontal, end_vertical, *this);
	if (isValid == moveResult::moveValid || isValid == moveResult::movePawnUpgrade)
	{
		switch (_currentPlayer)
		{
		case colors::black:

			temp = _board[end_vertical][end_horizontal];
			_board[end_vertical][end_horizontal] = toMove;
			_board[start_vertical][start_horizontal] = nullptr;
			_board[end_vertical][end_horizontal]->setNewX(end_horizontal);
			_board[end_vertical][end_horizontal]->setNewY(end_vertical);
			if (_blackKing->check_check(*this))
			{
				_board[start_vertical][start_horizontal] = toMove;
				_board[end_vertical][end_horizontal] = temp;
				_board[start_vertical][start_horizontal]->setNewX(start_horizontal);
				_board[start_vertical][start_horizontal]->setNewY(start_vertical);
				return moveResult::moveInvalidCauseCheck;
			}
			if (temp != nullptr)
			{
				delete temp;
			}
			if (isValid == moveResult::movePawnUpgrade)
			{
				temp = _board[end_vertical][end_horizontal];
				std::cout << "Choose the upgrade you want for the pawn:" << std::endl;
				std::cout << "Q - Queen" << std::endl;
				std::cout << "R - Rook" << std::endl;
				std::cout << "K - Knight" << std::endl;
				std::cout << "B - Bishop" << std::endl;
				std::cin >> upgradeForPawn;

				while (upgradeForPawn != 'Q' && upgradeForPawn != 'R' && upgradeForPawn != 'K' && upgradeForPawn != 'B')
				{
					std::cout << "Invalid choice! try again:" << std::endl;
					std::cin >> upgradeForPawn;
				}

				switch (upgradeForPawn)
				{
				case 'Q':

					_board[end_vertical][end_horizontal] = new Queen((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;

				case 'R':

					_board[end_vertical][end_horizontal] = new Rook((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;

				case 'K':

					_board[end_vertical][end_horizontal] = new Knight((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;

				case 'B':

					_board[end_vertical][end_horizontal] = new Bishop((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;
				}
				delete temp;
			}
			if (_whiteKing->check_check(*this))
			{
				isValid = moveResult::moveValidCheck;
			}
			_currentPlayer = colors::white;
			break;

		default:

			temp = _board[end_vertical][end_horizontal];
			_board[end_vertical][end_horizontal] = toMove;
			_board[start_vertical][start_horizontal] = nullptr;
			_board[end_vertical][end_horizontal]->setNewX(end_horizontal);
			_board[end_vertical][end_horizontal]->setNewY(end_vertical);
			if (_whiteKing->check_check(*this))
			{
				_board[start_vertical][start_horizontal] = toMove;
				_board[end_vertical][end_horizontal] = temp;
				_board[start_vertical][start_horizontal]->setNewX(start_horizontal);
				_board[start_vertical][start_horizontal]->setNewY(start_vertical);
				return moveResult::moveInvalidCauseCheck;
			}
			if (temp != nullptr)
			{
				delete temp;
			}
			if (isValid == moveResult::movePawnUpgrade)
			{
				temp = _board[end_vertical][end_horizontal];
				std::cout << "Choose the upgrade you want for the pawn:" << std::endl;
				std::cout << "Q - Queen" << std::endl;
				std::cout << "R - Rook" << std::endl;
				std::cout << "K - Knight" << std::endl;
				std::cout << "B - Bishop" << std::endl;
				std::cin >> upgradeForPawn;

				while (upgradeForPawn != 'Q' && upgradeForPawn != 'R' && upgradeForPawn != 'K' && upgradeForPawn != 'B')
				{
					std::cout << "Invalid choice! try again:" << std::endl;
					std::cin >> upgradeForPawn;
				}

				switch (upgradeForPawn)
				{
				case 'Q':

					_board[end_vertical][end_horizontal] = new Queen((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;

				case 'R':

					_board[end_vertical][end_horizontal] = new Rook((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;

				case 'K':

					_board[end_vertical][end_horizontal] = new Knight((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;

				case 'B':

					_board[end_vertical][end_horizontal] = new Bishop((boardLetters)end_horizontal, end_vertical, toMove->getColor());
					break;
				}
				delete temp;
				isValid = moveResult::moveValid;
			}
			if (_blackKing->check_check(*this))
			{
				isValid = moveResult::moveValidCheck;
			}
			_currentPlayer = colors::black;
			break;
		}
	}
	return isValid;
}


bool Board::check_checkMate()
{
	int i = 0, j = 0, k = 0, l = 0;
	int isValid = 0, countOfValidMoves = 0;
	Piece* startPiece = nullptr, *temp = nullptr;
	for (i = 0; i < BOARD_SIZE; i++)
	{
		for (j = 0; j < BOARD_SIZE; j++)
		{
			startPiece = _board[i][j];
			if (_currentPlayer == colors::black && startPiece != nullptr && startPiece->getColor() == colors::black)
			{
				for (k = 0; k < BOARD_SIZE; k++)
				{
					for (l = 0; l < BOARD_SIZE; l++)
					{
						isValid = startPiece->check_move((boardLetters)l, k, *this);
						if (isValid == moveResult::moveValid)
						{
							temp = _board[k][l];
							_board[k][l] = startPiece;
							_board[i][j] = nullptr;
							_board[k][l]->setNewX((boardLetters)l);
							_board[k][l]->setNewY(k);
							if (!_blackKing->check_check(*this))
							{
								countOfValidMoves++;
							}
							_board[i][j] = startPiece;
							_board[k][l] = temp;
							_board[i][j]->setNewX((boardLetters)j);
							_board[i][j]->setNewY(i);
							temp = nullptr;
						}
					}
				}
			}
			else if (_currentPlayer == colors::white && startPiece != nullptr && startPiece->getColor() == colors::white)
			{
				for (k = 0; k < BOARD_SIZE; k++)
				{
					for (l = 0; l < BOARD_SIZE; l++)
					{
						isValid = startPiece->check_move((boardLetters)l, k, *this);
						if (isValid == moveResult::moveValid)
						{
							temp = _board[k][l];
							_board[k][l] = startPiece;
							_board[i][j] = nullptr;
							_board[k][l]->setNewX((boardLetters)l);
							_board[k][l]->setNewY(k);
							if (!_whiteKing->check_check(*this))
							{
								countOfValidMoves++;
							}
							_board[i][j] = startPiece;
							_board[k][l] = temp;
							_board[i][j]->setNewX((boardLetters)j);
							_board[i][j]->setNewY(i);
							temp = nullptr;
						}
					}
				}
			}
		}
	}

	if (countOfValidMoves == 0)
	{
		return true;
	}

	return false;
}
