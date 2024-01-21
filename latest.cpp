#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

class Interpreter
{
private:
    signed char registers[7] = {};
    signed char memory[64] = {};

public:
    void readFile(fstream &);
    void outputFile(const string &);
    void IN (int);
    void OUT (int);
    void MOV(int, int);
    void ADD(int, int);
    void SUB(int, int);
    void MUL(int, int);
    void DIV(int, int);
    void INC (int);
    void DEC (int);
    void ROL (int, int);
    void ROR (int, int);
    void SHL (int, int);
    void SHR (int, int);
    void LOAD (int, int);
    void STORE (int, int);
};

void Interpreter::readFile(fstream &file)
{
    string line;

    while (getline (file, line))
    {
        int element, element2;
        istringstream iss(line);
        string operation, firstInput, secondInput;
        iss >> operation >> firstInput >> secondInput;

        if (operation == "IN")
        {
            if (firstInput.substr(0, 1) == "R")
            {
                element = stoi(firstInput.substr(1));
                IN(element);
            }

        }
        else if (operation == "OUT")
        {
            if (firstInput.substr(0, 1) == "R")
            {
                element = stoi(firstInput.substr(1));
                OUT(element);
            }
        }
        /*else if (operation == "MOV")
        {
            if (firstInput.substr(0, 1) == "R")
                {
                    int element;
                    iss >> element;
                    MOV(element, value);
                }
        }*/
        else if (operation == "ADD")
        {
            if (secondInput.substr(0, 1) == "R")
            {
                element = stoi(secondInput.substr(1));
                ADD(stoi(firstInput), element);
            }
        }
        else if (operation == "SUB")
        {
            if (secondInput.substr(0, 1) == "R")
            {
                element = stoi(secondInput.substr(1));
                SUB(stoi(firstInput), element);
            }
        }
        else if (operation == "MUL")
        {
            if (secondInput.substr(0, 1) == "R")
            {
                element = stoi(secondInput.substr(1));
                MUL(stoi(firstInput), element);
            }
        }
        else if (operation == "DIV")
        {
            if (secondInput.substr(0, 1) == "R")
            {
                element = stoi(secondInput.substr(1));
                DIV(stoi(firstInput), element);
            }
        }
        else if (operation == "INC")
        {
            if (firstInput.substr(0, 1) == "R")
            {
                element = stoi(firstInput.substr(1));
                INC(element);
            }
        }
        else if (operation == "DEC")
        {
            if (firstInput.substr(0, 1) == "R")
            {
                element = stoi(firstInput.substr(1));
                DEC(element);
            }
        }
        /*else if (operation == "ROL")
        {
            char reg;
            int count;
            file >> reg >> count;

            if (reg == 'R')
                {
                    int element;
                    iss >> element;
                    ROL(element, count);
                }
        }
        else if (operation == "ROR")
        {
            char reg;
            int count;
            file >> reg >> count;

            if (reg == 'R')
                {
                    int element;
                    iss >> element;
                    ROR(element, count);
                }
        }
        else if (operation == "SHL")
        {
            char reg;
            int count;
            file >> reg >> count;

            if (reg == 'R')
                {
                    int element;
                    iss >> element;
                    SHL(element, count);
                }
        }
        else if (operation == "SHR")
        {
            char reg;
            int count;
            file >> reg >> count;

            if (reg == 'R')
                {
                    int element;
                    iss >> element;
                    SHR(element, count);
                }
        }*/
        else if (operation == "STORE")
        {
            if (firstInput.substr(0, 1) == "R")
            {
                element = stoi(firstInput.substr(1));

                if (secondInput.substr(0, 1) != "[")
                {
                    element2 = stoi(secondInput);
                    STORE(element, element2);
                }
                else if(secondInput.substr(1, 1) == "R")
                {
                    int temp;

                    temp = stoi(secondInput.substr(2,1));
                    element2 = registers[temp];

                    STORE(element, element2);
                }
            }
        }
        else if (operation == "LOAD")
        {
            if (firstInput.substr(0, 1) == "R")
            {
                element = stoi(firstInput.substr(1));

                if (secondInput.substr(0, 1) != "[")
                {
                    element2 = stoi(secondInput);
                    LOAD(element, element2);
                }
                else if(secondInput.substr(1, 1) == "R")
                {
                    int temp;

                    temp = stoi(secondInput.substr(2,1));
                    element2 = registers[temp];

                    LOAD(element, element2);
                }
            }
        }
    }
}

void Interpreter::outputFile(const string &fileName)
{
    string txtFile;
    txtFile = fileName + ".txt";

    ofstream outputFile(txtFile);

    outputFile << "Registers: ";
    for (int i = 0; i < 7; i++)
    {
        outputFile << static_cast<int>(registers[i]) << " ";
    }

    outputFile << "#" << endl;

    outputFile << "Memory: " << endl;

    for (int j = 0; j < 64; j++)
    {
        outputFile << static_cast<int>(memory[j]) << " ";

        if ((j + 1) % 8 == 0)
        {
            outputFile << endl;
        }
    }
    outputFile << "#\n";

    outputFile.close();
}

void Interpreter::IN(int destination)
{
    int value;

    cout << "Please enter a value: ";
    cin >> value;
    cout << endl;

    registers[destination] = static_cast<signed char>(value);
}

void Interpreter::OUT(int source)
{
    cout << "R" << source << " is " << static_cast<int>(registers[source]) << endl;
}

void Interpreter::MOV(int source, int destination)
{
    registers[destination] = registers[source];
}

void Interpreter::ADD(int source, int destination)
{
    registers[destination] += static_cast<signed char>(source);
}

void Interpreter::SUB(int source, int destination)
{
    registers[destination] -= static_cast<signed char>(source);
}

void Interpreter::MUL(int source, int destination)
{
    registers[destination] *= static_cast<signed char>(source);
}

void Interpreter::DIV(int source, int destination)
{
    if (source != 0)
        registers[destination] /= static_cast<signed char>(source);
    else
        cerr << "Error: Division by zero." << endl;
}

void Interpreter::INC(int destination)
{
    registers[destination]++;
}

void Interpreter::DEC(int destination)
{
    registers[destination]--;
}

void Interpreter::ROL(int destination, int count)
{
    registers[destination] = (registers[destination] << count) | (registers[destination] >> (8 - count));
}

void Interpreter::ROR(int destination, int count)
{
    registers[destination] = (registers[destination] >> count) | (registers[destination] << (8 - count));
}

void Interpreter::SHL(int destination, int count)
{
    registers[destination] <<= count;
}

void Interpreter::SHR(int destination, int count)
{
    registers[destination] >>= count;
}

void Interpreter::STORE(int source, int destination)
{
    memory[destination] = registers[source]; 
}

void Interpreter::LOAD(int source, int destination)
{
    registers[destination] = memory[source]; 
}

int main()
{
    string fileName, asmFile;
    fstream inputFile;
    Interpreter interpreter;

    cout << "Type in file name: ";
    cin >> fileName;
    asmFile = fileName + ".asm";
    cout << endl;

    inputFile.open(asmFile);

    if (!inputFile)
    {
        cout << "File can't be opened." << endl;
        return 1;
    }

    else
    {
        cout << "File success." << endl;
        
        interpreter.readFile(inputFile);


    inputFile.close();

    interpreter.outputFile(fileName);
    }

    return 0;
}