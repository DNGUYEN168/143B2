#include "VM.cpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


int main()
{
    // handles reading from init and input passing ARRAY of ints into functions 

    // init-no-dp

    std::ifstream f("init.txt");
 
    if (!f.is_open())
    {
        return -1; // error 
    }

    std::string s,num;
    std::vector<int> init1,init2;
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

    // initialize VM 
    VM memory = VM();

    memory.SetPM1(init1);
    memory.SetPM2(init2);






    // init-dp (same as init-no-dp)







    return 0;
}