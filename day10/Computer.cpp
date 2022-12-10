#include "Computer.h"



int Computer::runProgram() const
{
    int answer = 0;
    while (instructionPointer_ < program_.size())
    {
        std::string instruction = program_[instructionPointer_];
        std::string command     = instruction.substr(0, 4);
        
        if (instructionDuration_ <= 0)
        {   
            if (command == "noop")
            {
                instructionDuration_ = 1;
            }
            else if (command == "addx")
            {
                instructionDuration_ = 2;
            }
        }

        instructionDuration_ -= 1;
        if (instructionDuration_ <= 0)
        {
            if (command == "addx")
            {
                int delta = std::stoi(instruction.substr(5, instruction.length() - 5));
                registerX_ += delta;
            }

            instructionPointer_ += 1;
        }

        cycle_++;
        if ((cycle_ - 20) % 40 == 0)
        {
            answer += registerX_ * cycle_;
        }
    }
    return answer;
};