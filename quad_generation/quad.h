#pragma once
#include <iostream>

class Quadruple {
    private:
        std::string op;
        std::string arg1;
        std::string arg2;
        std::string dist;
    
    public:
        Quadruple(std::string op, std::string arg1, std::string arg2, std::string dist);
        
        // setters
        void setOp(std::string op);
        void setArg1(std::string arg1);
        void setArg2(std::string arg2);
        void setDist(std::string dist);

        // getters
        std::string getOp();
        std::string getArg1();
        std::string getArg2();
        std::string getDist();
};