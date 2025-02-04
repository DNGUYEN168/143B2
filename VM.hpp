#ifndef VM_H
#define VM_H


class VM
{
    public:
        VM();
        int calculatePA(int VA); // calculates new PA
        int* InttoBinary(int VA); // converts a given integer into its binary 32-bit representation 
        int BinarytoInt(int* BitStr, int length);




    private:
        int* PM;
        int* Disk;

};


#endif