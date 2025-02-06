#ifndef VM_H
#define VM_H

#include <vector>


class VM
{
    public:
        VM();
        ~VM();

        void SetPM1(std::vector<int> init1);
        void SetPM2(std::vector<int> init2);

        int calculatePA(int VA); // calculates new PA
        int* InttoBinary(int VA); // converts a given integer into its binary 32-bit representation 
        int BinarytoInt(int* BitStr, int length);




    private:
        int* PM;// int array of size 1024 * 512
        int** Disk;
        int* frames;

};


#endif