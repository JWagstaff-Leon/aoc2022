#ifndef THROW_H
#define THROW_H



enum ThrowType
{
    Invalid  = 0,
    Rock     = 1,
    Paper    = 2,
    Scissors = 3
};



enum ThrowScore
{
    NoScore       = 0,
    RockScore     = 1,
    PaperScore    = 2,
    ScissorsScore = 3
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
};

#endif