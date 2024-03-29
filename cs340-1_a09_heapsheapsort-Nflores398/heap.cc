/* 
Noah Flores  
z1861588 
CSCI 340-1 

I certify that this is my own work and where appropriate an extension  
of the starter code provided for the assignment. 
*/
#include "heap.h"
/***************************************************************
The progam opens up a file and takes the content of the file 
and stores them into a vector. Then the vector is made into a
heap and is sorted. The program will sort based of ascending
or descending. Finally the program calls a print function
to print the elements of the vector.
***************************************************************/
/***************************************************************
Function: get_list

Use: Opens a file and reads the elements into a vector.

Parameter: vector<T>, char *path

returns: nothing
***************************************************************/
template <typename T>
void get_list(vector<T> &v, const char *path)
{
  T x;
  fstream file;
  //Cleans vector
  v.clear();
  //Open the imput file
  file.open(path);
  while (file >> x)
  {
    //insert elements into vector.
    v.push_back(x);
  }
  file.close();
  return;
}
/***************************************************************
Function: construct_heap

Use: Makes a heap with the vector and then sorts them based on 
pred which can be greater or less

Parameter: Vector<T>, P pred

returns: nothing
***************************************************************/
template <typename T, typename P>
void construct_heap(vector<T> &v, P pred)
{
  //Makes heap
  make_heap(v.begin(), v.end(), pred);
  //Sorts heap based of pred
  sort_heap(v.begin(), v.end(), pred);
}

int main()
{
  vector<int> v1;    // heap of integers
  vector<float> v2;  // heap of floating-pt nums
  vector<string> v3; // heap of strings

  // print header message
  cout << "\t\t\t*** Heaps and Heapsort - Output ***\n\n";

  // first heap

  cout << "first heap - ascending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, less<int>());
  print_list<int> print1(v1.size(), INT_SZ, INT_LN);
  for_each(v1.begin(), v1.end(), print1);

  cout << "first heap - descending order:\n\n";
  get_list(v1, D1);
  construct_heap(v1, greater<int>());
  for_each(v1.begin(), v1.end(), print1);

  // second heap

  cout << "second heap - ascending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, less<float>());
  print_list<float> print2(v2.size(), FLT_SZ, FLT_LN);
  for_each(v2.begin(), v2.end(), print2);

  cout << "second heap - descending order:\n\n";
  get_list(v2, D2);
  construct_heap(v2, greater<float>());
  for_each(v2.begin(), v2.end(), print2);

  // third heap

  cout << "third heap - ascending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, less<string>());
  print_list<string> print3(v3.size(), STR_SZ, STR_LN);
  for_each(v3.begin(), v3.end(), print3);

  cout << "third heap - descending order:\n\n";
  get_list(v3, D3);
  construct_heap(v3, greater<string>());
  for_each(v3.begin(), v3.end(), print3);

  // print termination message
  cout << "\t\t\t*** end of program execution ***\n\n";
  return 0;
}
