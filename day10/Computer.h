#ifndef COMPUTER
#define COMPUTER

#include <string>
#include <vector>



class Computer
{
    public:
        inline Computer(std::vector<std::string> program)
            :program_(program),
             instructionPointer_(0),
             instructionDuration_(0),
             registerX_(1),
             cycle_(1)
        {};
        


        void inline loadProgram(std::vector<std::string> program)
        {
            program_             = program;
            instructionPointer_  = 0;
            instructionDuration_ = 0;
            registerX_           = 1;
            cycle_               = 1;
        };



        int         getSignalStrength() const;
        std::string getVisualOutput()   const;

    private:
        void doCycle() const;
        std::vector<std::string> program_;

        mutable int instructionPointer_;
        mutable int instructionDuration_;
        mutable int cycle_;
        mutable int registerX_;
};

#endif