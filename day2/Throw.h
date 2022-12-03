#ifndef THROW_H
#define THROW_H



enum ThrowType
{
    None     = 0,
    Rock     = 1,
    Paper    = 2,
    Scissors = 3
};



enum ThrowScore
{
    None     = 0,
    Rock     = 1,
    Paper    = 2,
    Scissors = 3
};



enum OutcomeScore
{
    Loss = 0,
    Draw = 3,
    Win  = 6
};



class Throw
{
    public:
        virtual ThrowScore   getScore()                                            = 0;
        virtual ThrowType    getType()                                             = 0;
        virtual OutcomeScore getOutcomeScoreAgainst(ThrowType contestingThrowType) = 0;
        virtual              ~Throw();
};

#endif