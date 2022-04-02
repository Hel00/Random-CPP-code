#pragma once

#define CharToInt( ch ) (int)( ch - '0' )

/*
"   _______________",
"8 |_|#|_|#|_|#|_|#|",
"7 |#|_|#|_|#|_|#|_|",
"6 |_|#|_|#|_|#|_|#|",
"5 |#|_|#|_|#|_|#|_|",
"4 |_|#|_|#|_|#|_|#|",
"3 |#|_|#|_|#|_|#|_|",
"2 |_|#|_|#|_|#|_|#|",
"1 |#|_|#|_|#|_|#|_|",
"   A B C D E F G H"*/

const char* CONST_BOARD[] =
{
" _______________",
"|_|#|_|#|_|#|_|#|",
"|#|_|#|_|#|_|#|_|",
"|_|#|_|#|_|#|_|#|",
"|#|_|#|_|#|_|#|_|",
"|_|#|_|#|_|#|_|#|",
"|#|_|#|_|#|_|#|_|",
"|_|#|_|#|_|#|_|#|",
"|#|_|#|_|#|_|#|_|",
};

#include <string>
#include <vector>
#include <cstdio>

#include "Piece.hpp"
#include "Position.hpp"

class Board
{
private:
    std::vector<std::string> board;
    std::vector<Piece*> pieces;

public:
    static const char boardCharacters[];
    static const char boardNumerals[];

    Board();
    ~Board();

    void PrintBoard();
    Position GetPosition (Position position);
    char ReadCell        (Position position);
    void WriteCell       (Position position, const char value);
};

char const Board::boardCharacters[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' }; // X
char const Board::boardNumerals[]   = { '1', '2', '3', '4', '5', '6', '7', '8' }; // Y

Board::Board()
{
    for ( int i = 0; i <= 8; i++)
    {
        board.push_back( std::string( CONST_BOARD[i] ) );
    }
}

Board::~Board() {}

void Board::PrintBoard()
{
    printf
    (
        "  %s\n8 %s\n7 %s\n6 %s\n5 %s\n4 %s\n3 %s\n2 %s\n1 %s\n   A B C D E F G H\n",
        this->board[0].c_str(),
        this->board[1].c_str(),
        this->board[2].c_str(),
        this->board[3].c_str(),
        this->board[4].c_str(),
        this->board[5].c_str(),
        this->board[6].c_str(),
        this->board[7].c_str(),
        this->board[8].c_str()
    );
}

__inline char getBoardCharIndex(char ch)
{
    for ( int i = 0; i <= sizeof( Board::boardCharacters ); i++)
    {
        if ( Board::boardCharacters[i] == ch ) { return (i + 1) * 2; }
    }
}

Position Board::GetPosition(Position position)
{
    Position result;

    result.x = getBoardCharIndex( position.x ) - 1;
    result.y = 9 - CharToInt( position.y );
 
    return result;
}

char Board::ReadCell(Position position)
{
    Position boardPosition = this->GetPosition( position );

    return this->board[ boardPosition.y ][ boardPosition.x ];
}

void Board::WriteCell(Position position, const char value)
{
    Position boardPosition = this->GetPosition( position );

    this->board[ boardPosition.y ][ boardPosition.x ] = value;
}
