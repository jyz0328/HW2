#include <iostream>
#include <fstream>
#include <chrono>
#include <cstring>
//#include "makeSortedList.cpp"
using namespace std;

/***********************************************************
Main progam template for find by bisecton and dictonaruy
************************************************************/
// Global Variable -- We will learn more eleganat ways later

int  OpCountBisection = 0;
int  OpCountDictionary = 0;
// Accummulated Counter over NoOfKeys
double Total_bisection_time = 0.0;
double Total_dictionary_time = 0.0;
int Total_Op_bisection = 0;
int Total_Op_dictionary = 0;

int findBisection(int key, int *a, int n);
int findDictionary(int key, int *a, int n);

int main(int argc, char *argv[]) 
{
  /* Timeing and IO setup */
  chrono::time_point<chrono::steady_clock> start, stop; 
  chrono::duration<double> difference_in_time;
  double difference_in_seconds_bisection; // Holds the final run time
  double difference_in_seconds_dictionary; // Holds the final run time
  ifstream infile;
  
  /* Local data */
  int n;
  int k;
  int find_index_dictionary = -1; // flag set if found
  int find_index_bisection = -1;
  int  NoOfKeys = 100;
  int *key = new int[NoOfKeys];
  
  // Input Data:  DO NOT CHANGE 
  infile.open(argv[1]);
  if(!infile){
    cout << "Error opening file: Provide input " <<endl;
    return -1;
  }
  
  infile >> n;
  int *A = new int[n];

  for(int i=0; i<n ; i++)
    infile >> A[i];
  infile.close();
  
  /* Select Set of Keys */
  for( k = 0; k < NoOfKeys; k++)
    {
      key[k] = A[rand()%n];
    }

  // Try NoOfkeys 

  
  
  
  for( k = 0; k < NoOfKeys; k++)
    {
      find_index_dictionary = -1;
      find_index_dictionary = -1;
      
  /* Find Key by Bisection  Search  */

  start = chrono::steady_clock::now();
  find_index_bisection = findBisection(key[k], A,  n);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_seconds_bisection = double(difference_in_time.count());
  //accumulated time and operations
  Total_bisection_time += difference_in_seconds_bisection;
  Total_Op_bisection +=  OpCountBisection;
  
  
  /* Find Key by Dictionary Search  */
  start = chrono::steady_clock::now();
  find_index_dictionary = findDictionary(key[k], A, n);
  stop = chrono::steady_clock::now();
  difference_in_time = stop - start;
  difference_in_seconds_dictionary = double(difference_in_time.count());
   //accumulated time and operations
  Total_dictionary_time += difference_in_seconds_dictionary;
  Total_Op_dictionary +=  OpCountDictionary;
  
  // Begin output  
  
  // ofstream outfile(strcat(argv[1],"_out"));

  /* Check first key against Key by Bisection  */
  cout << "Bisection " << find_index_bisection << " vs Dictionary " <<  find_index_dictionary << endl;
  if(find_index_dictionary !=-1 && k == 0)
    {
      cout << "Value found for first pass = "<<A[find_index_dictionary] << " for  key = " <<  key[k]<< endl; }
  cout << "Bisection: Time =  " <<  difference_in_seconds_bisection << " OpCount = "  << OpCountBisection <<  endl;
  cout << "Dictionary: Time =  " <<  difference_in_seconds_dictionary << " OpCount =  "  << OpCountDictionary << endl;
    
  
 //End output 
    }
 /***************************
 realize makeSortedList.cpp
 *************************/
 
  
#if 0   // This calculates the average of the Keys. In the future we will look at deviations.
  
  cout << "\n For = " << NoOfKeys << "keys: Mean values are " << endl;

  cout << "Bisection: Mean Time =  " <<   Total_bisection_time/(double)NoOfKeys << "  Mean OpCount = "  << Total_Op_bisection/(double)NoOfKeys <<  endl;
  cout << "Dictionary: Mean Time =  " <<  Total_dictionary_time/(double)NoOfKeys<< "  Mean  OpCount =  "  << Total_Op_dictionary/(double)NoOfKeys << endl;

 #endif
  
  return 0;
}


/****************************************
Provide funtions below
****************************************/

int findBisection(int key, int *a, int N)
{
  int index = -1;
  // while(??) {
  //OpCountBisection++;  // counts the number of call to routine
   //}
  
  //return index;
  int left = 0;
  int right = N - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2; // Calculate the index of the middle element

    if (a[mid] == key){

      return mid; // Found the key, return the index position
    }else if (a[mid] < key){

      left = mid + 1; // Key is in the right half
    }else{

      right = mid - 1; // Key is in the left half
    }

    
    
  }

  return index; // Key not found
}

int findDictionary(int key, int *a, int N)
{
  int index = -1;
  // while(??) {
      //OpCountDictionary++;  // counts the number of call to routine
      //}
  //return index;
  int left = 0;
  int right = N - 1;

  while (left <= right) {
    double x = double(key - a[left]) / double(a[right] - a[left]);
    int m = int(left + x * (right - left));
    if (m < 0 || m >= N) {
      return index; // Index position is out of range, key does not exist
    }

    if (a[m] == key) {

      return m; // Found the key, return the index position
    } else if (a[m] < key) {

      left = m + 1; // Key is in the right half
    } else {

      right = m - 1; // Key is in the left half
    }

  }

    return index; // Key not found
}




