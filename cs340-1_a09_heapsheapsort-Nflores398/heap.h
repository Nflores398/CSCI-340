/* 
Noah Flores  
z1861588 
CSCI 340-1 

I certify that this is my own work and where appropriate an extension  
of the starter code provided for the assignment. 
*/
#include <assert.h>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef HEAP_H_
#define HEAP_H_

// data files

#define D1 "heap.d1"
#define D2 "heap.d2"
#define D3 "heap.d3"

#define INT_SZ 4  // width of integer
#define FLT_SZ 7  // width of floating-pt number
#define STR_SZ 12 // width of string

#define INT_LN 15 // no of integers in single line
#define FLT_LN 9  // no of floating-pt nums in single line
#define STR_LN 5  // no of strings in single line

// function and class prototypes

// stores items from input file into vector
template <typename T>
void get_list(vector<T> &, const char *);

// construct heap from items in vector
template <typename T, typename P>
void construct_heap(vector<T> &, P);

// class to print heap items

template <typename T>
class print_list
{
  unsigned sz, // heap size
      wid,     // min num of chars written in printout
      len,     // max num of items printed in single line
      cnt;     // counter for printout
public:
  print_list(const unsigned & = 1, const unsigned & = 1, const unsigned & = 1, const unsigned & = 0); // constructor
  void operator()(const T &);
};
template <typename T>
print_list<T>::print_list(const unsigned &s, const unsigned &w, const unsigned &l, const unsigned &c)
{
  sz = s;
  wid = w;
  len = l;
  cnt = c;
} // constructor
/***************************************************************
Function: operator()

Use: Prints the elements of the heap and adds fromating to
when it is printed.

Parameter: const T

returns: nothing
***************************************************************/
template <typename T>
void print_list<T>::operator()(const T &x)
{
  cout.width(wid);
  cout.precision(2);
  cout << fixed << showpoint;
  //Limits elements per line
  if (cnt % len == 0 && cnt != 0)
  {
    cout << endl;
  }
  cout << x << " ";
  cnt++;
  //Adds a new line when reaches the end of the heap
  if (cnt == sz)
  {
    cout << endl
         << endl;
    cnt = 0;
  }
}
#endif // HEAP_H_
