#ifndef VM_H
#define VM_H


class VM
{
    public:
        int* calculatePA(int VA); // returns an array which contains the PA 
        int* ItoBin(int VA); // converts a given integer into its binary representation 

        



    private:
        int* PM;
        int* Disk;

};


#endif