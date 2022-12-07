#ifndef CRATE_H
#define CRATE_H



class Crate
{
    public:
        inline Crate(char value) : value_(value) {};

        inline char getValue() const { return value_; };

    private:
        char value_;
};

#endif