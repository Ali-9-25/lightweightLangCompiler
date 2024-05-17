#include <string>

#include "quad.h"

Quadruple::Quadruple(std::string op, std::string arg1, std::string arg2, std::string dist) {
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->dist = dist;
}

void Quadruple::setOp(std::string op) {
    this->op = op;
}

void Quadruple::setArg1(std::string arg1) {
    this->arg1 = arg1;
}

void Quadruple::setArg2(std::string arg2) {
    this->arg2 = arg2;
}

void Quadruple::setDist(std::string dist) {
    this->dist = dist;
}

std::string Quadruple::getOp() {
    return this->op;
}

std::string Quadruple::getArg1() {
    return this->arg1;
}

std::string Quadruple::getArg2() {
    return this->arg2;
}

std::string Quadruple::getDist() {
    return this->dist;
}

