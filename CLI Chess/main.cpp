#include "Board.hpp"

int main(int argc, char const *argv[])
{
    Board board;

    //board.ReadCell( Position{ 'A', '4' } );
    board.WriteCell( Position{ 'A', '8' }, 'X' );
    board.PrintBoard();

    //printf("%c", board.ReadCell( Position{ 'A', '1' } ));

    return 0;
}
