#include "Computer.h"

#include <string>
#include <iostream>



int Computer::getSignalStrength() const
{
    int answer = 0;
    while (instructionPointer_ < program_.size())
    {
        doCycle();
        
        if ((cycle_ - 20) % 40 == 0)
        {
            answer += registerX_ * cycle_;
        }
    }
    return answer;
};



std::string Computer::getVisualOutput() const
{
    std::string answer;
    while (instructionPointer_ < program_.size() && cycle_ < 240)
    {
        if ((cycle_ - 1) % 40 == 0 && cycle_ > 1)
        {
            answer += '\n';
        } 
        int drawingPosition = ((cycle_ - 1) % 40);
        if (drawingPosition >= registerX_ - 1 && drawingPosition <= registerX_ + 1)
        {
            answer += (char)219;
        }
        else
        {
            answer += ' ';
        }

        doCycle();
    }
    return answer;
};



void Computer::doCycle() const
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
};