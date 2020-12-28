/* 
Noah Flores  
Z1861588 
CSCI 340-1 

I certify that this is my own work and where appropriate an extension  
of the starter code provided for the assignment. 
*/ 
#include "rgi.h"

const int VECTOR_SIZE = 200;
const int LOW = 1; 
const int HIGH = 10000; 
const int SEED = 1; 
const int NO_ITEMS = 12; 
const int ITEM_W = 5; 

/***************************************************************
Function: genRndNums

Use: Generates randoms numbers to fill the vector

Parameter: Takes vector of integers to be filled with 
random numbers.

returns: nothing
***************************************************************/
void genRndNums(vector<int>& v) 
{
    srand((SEED));  
    for (int i = 0; i < VECTOR_SIZE; i++) 
    { 
        v[i] = rand() % HIGH + LOW; 
    } 
} 
/***************************************************************
Function: printVec

Use: Prints out vector 

Parameter: Takes vector of integers to be printed

returns: nothing
***************************************************************/
void printVec(const vector<int>& v) 
{ 
    int g = 0; 
    for (int i = 0; i < VECTOR_SIZE; i++) 
    { 
        //Limits the amount of integer printed per line
        if (g % NO_ITEMS == 0 && g != 0) 
        { 
            cout << endl; 
        } 
        cout << setw(ITEM_W) << v[i] << " "; 
        g++; 
    } 
    cout << endl;
} 

int main() 
{
    vector<int> v(VECTOR_SIZE); 
    genRndNums(v); 
    //sorts the vector smallest to biggest
    sort(v.begin(), v.end()); 
    printVec(v); 
    return 1;
}


