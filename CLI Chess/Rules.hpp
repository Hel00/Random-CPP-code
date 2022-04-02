#pragma once

enum Rule
{
    queen = 0,
    king,
    pawn,
    bishop,
    knight,
    rook
};

class Rules
{
private:
    Rule rule;

public:
    Rules();
    ~Rules();

    Rules(Rule rule);
};

Rules::Rules() {}

Rules::~Rules() {}

Rules::Rules(Rule rule) : rule(rule)
{
}
