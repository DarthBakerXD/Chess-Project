#pragma once
#include <string>
#define BOARD_SIZE 8

enum boardLetters {a, b, c, d, e, f, g, h};
enum colors;
class Piece;
class King;

class Board
{
public:
	~Board();
	void init(std::string input);
	Piece** operator[](int index);
	int move(boardLetters start_horizontal, int start_vertical, boardLetters end_horizontal, int end_vertical);
	bool check_checkMate();
private:
	Piece* _board[BOARD_SIZE][BOARD_SIZE];
	colors _currentPlayer;
	King* _whiteKing, *_blackKing;
};