// *******
// Program: YOUR_FILENAME.cpp
// Course: TCP1101 PROGRAMMING FUNDAMENTALS
// Lecture Class: TC6L
// Tutorial Class: T21L
// Trimester: 2310
// Member_1: 1221309548 | AHMAD ALIFF BIN YUSMAR | aliff.yusmar@gmail.com | 019-595 0408
// Member_2: ID | DANISH ADAM BIN RAZWAN | 1221309446@student.mmu.edu.my | 018-394 5083
// Member_3: 1221309130 | MOHAMAD SYAMEL BIN MOHAMAD KARID | syamelkarid321@gmail.com | 013-345 2616
// Member_4: 1221309435 | MUHAMMAD FAIZ BIN ILYASA | faizzilyasa5@gmail.com | 012-246 2882
// *******
// Task Distribution
// Member_1:
// Member_2:
// Member_3:
// Member_4:
// *******

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <bitset>

using namespace std;

class Interpreter
{
private:
    unsigned char registers[7] = {};
    unsigned char memory[64] = {};
    int counter = 0;
    bool OF = false;
    bool UF = false;
    bool CF = false;
    bool ZF = false;

public:
    void readFile(fstream &);
    void outputFile(const string &);
    void setFlags(int);
    void resetFlags();
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
    void COUT (unsigned char[], unsigned char[], int, bool, bool, bool, bool);
};

void Interpreter::readFile(fstream &file)
{
    string line;

    while (getline (file, line))
    {
        int element, element2, value;
        istringstream iss(line);
        string operation, firstInput, secondInput;
        iss >> operation >> firstInput >> secondInput;

        if (operation == "IN")
        {
            element = stoi(firstInput.substr(1));
            IN(element);
        }

        else if (operation == "OUT")
        {
            element = stoi(firstInput.substr(1));
            OUT(element);
        }

        else if (operation == "MOV")
        {
            if (firstInput.substr(0,1) == "R")
            {
                element = stoi(firstInput.substr(1));
                value = registers[element];
                element2 = stoi(secondInput.substr(1));
            }

            else if (firstInput.substr(0,1) == "[")
            {
                int temp;
                element = stoi(firstInput.substr(2,1));
                temp = registers[element];
                value = memory[temp];
                element2 = stoi(secondInput.substr(1));
            }

            else
            {
                value = stoi(firstInput);
                element2 = stoi(secondInput.substr(1));
            }

            MOV(value, element2);
        }

        else if (operation == "ADD")
        {
            if (firstInput.substr(0,1) == "R")
            {
                element = stoi(firstInput.substr(1));
                value = registers[element];

                element2 = stoi(secondInput.substr(1));
            }

            else if (firstInput.substr(0, 1) != "R")
            {
                element2 = stoi(secondInput.substr(1));
                value = stoi(firstInput);
            }

            ADD(value, element2);
        }

        else if (operation == "SUB")
        {
            if (firstInput.substr(0,1) == "R")
            {
                element = stoi(firstInput.substr(1));
                value = registers[element];

                element2 = stoi(secondInput.substr(1));
            }

            else if (firstInput.substr(0, 1) != "R")
            {
                element2 = stoi(secondInput.substr(1));
                value = stoi(firstInput);
            }

            SUB(value, element2);
        }

        else if (operation == "MUL")
        {
            if (firstInput.substr(0,1) == "R")
            {
                element = stoi(firstInput.substr(1));
                value = registers[element];

                element2 = stoi(secondInput.substr(1));
            }

            else if (firstInput.substr(0, 1) != "R")
            {
                element2 = stoi(secondInput.substr(1));
                value = stoi(firstInput);
            }

            MUL(value, element2);
        }

        else if (operation == "DIV")
        {
            if (firstInput.substr(0,1) == "R")
            {
                element = stoi(firstInput.substr(1));
                value = registers[element];

                element2 = stoi(secondInput.substr(1));
            }

            else if (firstInput.substr(0, 1) != "R")
            {
                element2 = stoi(secondInput.substr(1));
                value = stoi(firstInput);
            }

            DIV(value, element2);
        }

        else if (operation == "INC")
        {
            element = stoi(firstInput.substr(1));
            INC(element);
        }

        else if (operation == "DEC")
        {
            element = stoi(firstInput.substr(1));
            DEC(element);
        }

        else if (operation == "ROL")
        {
            element = stoi(firstInput.substr(1));
            ROL(element, stoi(secondInput));
        }

        else if (operation == "ROR")
        {
            element = stoi(firstInput.substr(1));
            ROR(element, stoi(secondInput));
        }

        else if (operation == "SHL")
        {
            element = stoi(firstInput.substr(1));
            SHL(element, stoi(secondInput));
        }

        else if (operation == "SHR")
        {
            element = stoi(firstInput.substr(1));
            SHR(element, stoi(secondInput));
        }

        else if (operation == "STORE")
        {
            element = stoi(firstInput.substr(1));

            if (secondInput.substr(0, 1) != "[")
            {
                element2 = stoi(secondInput);
            }

            else if(secondInput.substr(0, 1) == "[")
            {
                int temp;

                temp = stoi(secondInput.substr(2,1));
                element2 = registers[temp];

            }

            STORE(element, element2);
        }

        else if (operation == "LOAD")
        {
            element = stoi(firstInput.substr(1));

            if (secondInput.substr(0, 1) != "[")
            {
                element2 = stoi(secondInput);
            }

            else if(secondInput.substr(0, 1) == "[")
            {
                int temp;

                temp = stoi(secondInput.substr(2,1));
                element2 = registers[temp];
            }

            LOAD(element, element2);
        }

        counter++;
        cout << endl << "==============" << endl;
        cout << operation << " " << firstInput << " " << secondInput;
        cout << endl << "==============" << endl;
        COUT(registers, memory, counter, OF, UF, CF, ZF);
        resetFlags();
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
        if (static_cast<int>(registers[i]) == 0)
        {
            outputFile << setw(4) << right << setfill(' ');
            outputFile << setfill('0') << static_cast<int>(registers[i]) << " ";
        }

        else
        {
            outputFile << static_cast<int>(registers[i]) << " ";
        }
    }

    outputFile << "#" << endl;

    outputFile << "Flags    : " << OF << " " << UF << " " << CF << " " << ZF << "#" << endl;

    outputFile << "PC       : " << counter << endl << endl;

    outputFile << "Memory: " << endl;


    for (int j = 0; j < 64; j++)
    {
        outputFile << setw(4) << right << setfill(' ');

        if (static_cast<int>(memory[j]) == 0)
        {
            outputFile << setfill('0') << static_cast<int>(memory[j]) << " ";
        }

        else
        {
            outputFile << static_cast<int>(memory[j]) << " ";
        }

        if ((j + 1) % 8 == 0)
        {
            outputFile << endl;
        }
    }

    outputFile << "#" << endl;

    outputFile.close();
}

void Interpreter::setFlags(int result)
{
    OF = (result > 255);
    UF = (result < 0);
    CF = (result > 255);
    ZF = (result == 0);
}

void Interpreter::resetFlags()
{
    OF = UF = CF = ZF = false;
}

void Interpreter::IN(int destination)
{
    int value;

    cout << "Please enter a value for R" << destination << ": ";
    cin >> value;
    cout << endl;

    setFlags(value);

    registers[destination] = static_cast<unsigned char>(value);

    //resetFlags();
}

void Interpreter::OUT(int source)
{
    cout << "R" << source << " is " << static_cast<int>(registers[source]) << endl;
}

void Interpreter::MOV(int source, int destination)
{
    setFlags(source);

    registers[destination] = source;

    //resetFlags();
}

void Interpreter::ADD(int source, int destination)
{
    int result;
    result = static_cast<int>(registers[destination]) + source;

    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);

    //resetFlags();
}

void Interpreter::SUB(int source, int destination)
{
    int result;
    result = static_cast<int>(registers[destination]) - source;

    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);

    //resetFlags();
}

void Interpreter::MUL(int source, int destination)
{
    int result;
    result = static_cast<int>(registers[destination]) * source;

    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);

    //resetFlags();
}

void Interpreter::DIV(int source, int destination)
{
    if (source != 0)
    {
        int result;
        result = static_cast<int>(registers[destination]) / source;
        setFlags(result);
        registers[destination] = static_cast<unsigned char>(result);
        //resetFlags();
    }
    else
        cout << "Error: Division by zero." << endl;
}

void Interpreter::INC(int destination)
{
    int result;
    result = ++registers[destination];
    setFlags(result);
    registers[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::DEC(int destination)
{
    int result;
    result = --registers[destination];
    setFlags(result);
    registers[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::ROL(int destination, int count)
{
    int result;
    std::bitset<8> binaryValue(registers[destination]);

    binaryValue = (binaryValue << count) | (binaryValue >> (8 - count));

    result = static_cast<int>(binaryValue.to_ulong());
    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::ROR(int destination, int count)
{
    int result;
    std::bitset<8> binaryValue(registers[destination]);

    binaryValue = (binaryValue >> count) | (binaryValue << (8 - count));

    result = static_cast<int>(binaryValue.to_ulong());
    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::SHL(int destination, int count)
{
    int result;
    std::bitset<8> binaryValue(registers[destination]);

    binaryValue <<= count;

    result = static_cast<int>(binaryValue.to_ulong());
    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::SHR(int destination, int count)
{
    int result;
    std::bitset<8> binaryValue(registers[destination]);

    binaryValue >>= count;

    result = static_cast<int>(binaryValue.to_ulong());
    setFlags(result);

    registers[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::STORE(int source, int destination)
{
    int result;
    result = static_cast<int>(registers[source]);
    memory[destination] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::LOAD(int source, int destination)
{
    int result;
    result = static_cast<int>(memory[destination]);
    registers[source] = static_cast<unsigned char>(result);
    //resetFlags();
}

void Interpreter::COUT(unsigned char registers[], unsigned char memory[], int counter, bool OF, bool UF, bool CF, bool ZF)
{
    // line for registers and pc
    cout << "   0     1     2     3     4     5     6";
    cout << endl << "+-----+-----+-----+-----+-----+-----+-----+  PC +-----+" << endl;
    for(int i = 0; i < 7; i++)
    {
        if (registers[i] == 0)
        {
            cout << "|     ";
        }
        else
        {
            cout << "| " << setw(4) << static_cast<int>(registers[i]);
        }
    }
    cout << "|";
    cout << setw(6) << right << "|" << setw(5) << left << counter << "|" << endl;
    cout << "+-----+-----+-----+-----+-----+-----+-----+     +-----+" << endl;

    // flags output
    cout << "  OF    UF    CF    ZF" << endl;
    cout << "+-----+-----+-----+-----+" << endl;

    if(!OF)
    {
        cout << "|     ";
    }
    else
    {
        cout << "| " << OF << "   ";
    }

    if(!UF)
    {
        cout << "|     ";
    }
    else
    {
        cout << "| " << UF << "   ";
    }

    if(!CF)
    {
        cout << "|     ";
    }
    else
    {
        cout << "| " << CF << "   ";
    }

    if(!ZF)
    {
        cout << "|     ";
    }
    else
    {
        cout << "| " << ZF << "   ";
    }
    cout << "|";
    cout << endl << "+-----+-----+-----+-----+" << endl;

    // memory output
    cout << "   0     1     2     3     4     5     6     7";
    for(int i = 0; i < 8; i++)
    {
        cout << endl << "+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
        for(int a = 0; a < 8; a++)
        {
            if (memory[i * 8 + a] == 0)
            {
                cout << "|     ";
            }
            else
            {
                cout << "| " << setw(4) << static_cast<int>(memory[i * 8 + a]);
            }
        }
        cout << "|";
    }
    cout << endl << "+-----+-----+-----+-----+-----+-----+-----+-----+" << endl;
    cout << "                                61    62    63" << endl;;
}

int main()
{
    string fileName, asmFile;
    fstream inputFile;
    Interpreter interpreter;

    cout << "Type in file name (without .asm): ";
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
        cout << "File success." << endl << endl;

        interpreter.readFile(inputFile);

        inputFile.close();

        interpreter.outputFile(fileName);
    }

    return 0;
}
