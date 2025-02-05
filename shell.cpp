#include "VM.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

int ReadFiles(const char* initFile, const char* inputFile, const char* output)
{
    std::ifstream f(initFile);
    std::ifstream ip(inputFile);
 
    if (!f.is_open() || !ip.is_open())
    {
        exit(1); // error reading file
    }

    std::string s,num;
    std::vector<int> init1,init2,input;
    int lineNo = 0;

    while (std::getline(f,s))   
    {
        std::istringstream iss(s);
        while (std::getline(iss, num, ' '))
        {
            if (lineNo == 0)
            {
                init1.push_back(std::stoi(num));
            }
            else 
            {
                init2.push_back(std::stoi(num));
            }

        }
        lineNo++;
    }

    // close files 
    

    // initialize VM 
    VM memory = VM();

    memory.SetPM1(init1);
    memory.SetPM2(init2);

    while (std::getline(ip,s, ' '))   
    {
        input.push_back(std::stoi(s));
    }

    f.close();
    ip.close();
    // open a write file and do the stuff 

    std::ofstream outputFile;
    outputFile.open(output);

    for (int i =0; i < input.size(); i++)
    {
        outputFile << memory.calculatePA(input[i]) << " ";
    }

    return 0;
}

int main()
{
    // handles reading from init and input passing ARRAY of ints into functions 

    // init-no-dp
    const char* initNdp = "init-no-dp.txt";
    const char* inputNdp = "input-no-dp.txt";
    const char* outputNdp = "output-no-dp.txt";

    ReadFiles(initNdp, inputNdp, outputNdp);

    const char* initdp = "init-dp.txt";
    const char* inputdp = "input-dp.txt";
    const char* outputdp = "output-dp.txt";
    
    ReadFiles(initdp, inputdp, outputdp);

    return 0;
}