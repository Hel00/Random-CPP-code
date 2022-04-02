#pragma once

#include "Rules.hpp"

class Piece
{
private:
    char model;
    //Position position;
    Rules rules;

public:
    Piece();
    ~Piece();

    void move();
};

Piece::Piece()
{
}

Piece::~Piece()
{
}
