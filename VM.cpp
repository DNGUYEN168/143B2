#include "VM.hpp"

#include <iostream>
#include <math.h>

VM::VM()
{
}

int VM::calculatePA(int VA)
{
    
    int* VAtoBin = InttoBinary(VA); // now we can easily break the array into subsections 

    //   [  5 bits |  s = 9 bits  | p = 9 bits   |   w = 9 bits  ]

    int sBits[9], pBits[9], wBits[9], pwBits[18];

    for (int x = 0; x < 9; x++) // 0 - 8
    {
        sBits[x] = VAtoBin[x + 18]; // copy over data for s
        pBits[x] = VAtoBin[x + 9]; // copy over data for p 
        wBits[x] = VAtoBin[x]; // copy over data for w  
    }

    for (int x = 0; x < 18; x++) // 0 - 8
    {
        pwBits[x] = VAtoBin[x]; // copy over data for s
    }

    // get the values for s,p,w
    int s = BinarytoInt(sBits, 9);
    int p = BinarytoInt(pBits, 9);
    int w = BinarytoInt(wBits, 9);
    int pw = BinarytoInt(pwBits, 18);

    // Bound checking 


    return 0;
}

int* VM::InttoBinary(int VA)
{
    int* Binary32 = new int[32];

    int i = 0;

    while (VA > 0)
    {
        Binary32[i] = VA % 2; // mode by two, either 0 or 1 at that place 
        VA = VA / 2;
        i++;
    }

    for (int p = i; p< 32; p++) {Binary32[p] = 0;} // fill the rest with 0
    return Binary32;
}

int VM::BinarytoInt(int *BitStr, int length) // converts a 9 bit binary string into an int 
{
    int retVal = 0;
    for (int i = 0; i < length; i++)
    {

        if (BitStr[i] == 1) // if one is at bit position, add 2^i (where i = position of bit) 
        {
            retVal += pow(2,i);
        }
    }
    
    return retVal;
}
