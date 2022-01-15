#include "input_24.h"

#include <array>
#include <cassert>
#include <iostream>
#include <sstream>
#include <variant>

using Operation = void (*)(long long &, long long);
using Registers = std::array<long long, 4>;
using Operand = std::variant<char, long long, long long (*)()>;

void Disp(long long &reg, long long value)
{
    std::cout << reg << ' ';
}

void Inp(long long &reg, long long value)
{
    reg = value;
}

void Add(long long &reg, long long operand)
{
    reg += operand;
}

void Mul(long long &reg, long long operand)
{
    reg *= operand;
}

void Div(long long &reg, long long operand)
{
    reg /= operand;
}

void Mod(long long &reg, long long operand)
{
    reg %= operand;
}

void Eql(long long &reg, long long operand)
{
    reg = (reg == operand);
}

long long &getReg(char c, Registers &registers)
{
    return registers[c - 'w'];
}

struct InstructionVisitor
{
    Registers &registers;
    long long operator()(char c)
    {
        return getReg(c, registers);
    }
    long long operator()(long long i)
    {
        return i;
    }
    long long operator()(long long (*i)())
    {
        return i();
    }
};

struct Instruction
{
    char reg;
    Operand operand;
    Operation operation;

    void operator()(Registers &registers) const
    {
        operation(getReg(reg, registers), std::visit(InstructionVisitor{registers}, operand));
    }
};

Operand getOperand(const std::string &str)
{
    try
    {
        return std::stoi(str);
    }
    catch (const std::invalid_argument &)
    {
        return str[0];
    }
}

std::array<int, 14> inputDigits = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
// std::array<int, 14> inputDigits = {1, 3, 5, 7, 9, 2, 4, 6, 8, 9, 9, 9, 9, 9};
// std::array<int, 14> inputDigits = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
constexpr std::array<int, 14> A = {13, 11, 11, 10, -14, -4, 11, -3, 12, -12, 13, -12, -15, -12};
constexpr std::array<int, 14> B = {10, 16, 0, 13, 7, 11, 11, 10, 16, 8, 15, 2, 5, 10};
constexpr std::array<int, 14> C = {1, 1, 1, 1, 26, 26, 1, 26, 1, 26, 1, 26, 26, 26};
char nextInputDigit = 0;
long long getInput()
{
    if (inputDigits[nextInputDigit] == 0)
    {
        std::cout << "No solution found" << std::endl;
        throw std::runtime_error("No solution found.");
    }
    return inputDigits[nextInputDigit++];
}

/* std::vector<int> doTheMagic(Registers orgRegs, auto instBegin, auto instEnd)
{
    for (int digit = 9; digit > 0; digit--)
    {
        Registers regs = orgRegs;
        auto inst = instBegin;
        regs[0] = digit;
        for (; inst != instEnd; ++inst)
        {
            if (inst->operation == &Inp)
            {
                std::vector<int> digits = doTheMagic(regs, std::next(inst), instEnd);
                if (!digits.empty())
                {
                    digits.push_back(digit);
                    return digits;
                }
                break;
            }
            else
            {
                (*inst)(regs);
            }
        }
        if (inst == instEnd && regs[3] == 0)
        {
            return {digit};
        }
    }
    return {};
}
 */
std::vector<int> doTheMagic(int level, long long z0)
{
    for (int w = 1; w <= 9; w++)
    {
        int x = ((z0 % 26) + A[level]) != w ? 1 : 0;
        long long z = z0 / C[level];
        if (x)
        {
            z = 26 * z + w + B[level];
        }
        if (level == 13)
        {
            if (z == 0)
            {
                return {w};
            }
        }
        else
        {
            std::vector<int> digits = doTheMagic(level + 1, z);
            if (!digits.empty())
            {
                digits.push_back(w);
                return digits;
            }
        }
    }
    return {};
}

int main(int, char **)
{
    std::vector<Instruction> instructions;
    for (const std::string &line : input)
    {
        std::istringstream str(line);
        std::string operation;
        std::string operandString;
        char reg;
        Operand operand;

        str >> operation >> reg;
        if (operation != "inp")
        {
            str >> operandString;
            operand = getOperand(operandString);
        }
        else
        {
            operand = getInput;
        }

        if (operation == "inp")
        {
            instructions.emplace_back(reg, operand, Inp);
        }
        else if (operation == "add")
        {
            instructions.emplace_back(reg, operand, Add);
        }
        else if (operation == "mul")
        {
            instructions.emplace_back(reg, operand, Mul);
        }
        else if (operation == "div")
        {
            instructions.emplace_back(reg, operand, Div);
        }
        else if (operation == "mod")
        {
            instructions.emplace_back(reg, operand, Mod);
        }
        else if (operation == "eql")
        {
            instructions.emplace_back(reg, operand, Eql);
        }
    }

    Registers regs = {0, 0, 0, 0};
    // std::vector<int> digits = doTheMagic(regs, std::next(std::begin(instructions)), std::end(instructions));
    std::vector<int> digits = doTheMagic(0, 0);

    //
    std::reverse(std::begin(digits), std::end(digits));

    std::cout << "The largest model number is ";
    for (int digit : digits)
    {
        std::cout << digit;
    }
    std::cout << std::endl;
}
