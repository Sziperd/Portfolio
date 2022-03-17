//
//  main.cpp
//  FastSortingandSelection
//
//  Created by Patryk Piwowarczyk on 05/03/2022.
//
#include  <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>
using namespace std;
 


std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
 
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}

int shellSort(int arr[], int n)
{
  
    for (int gap = n/2; gap > 0; gap /= 2)
    {
      
        for (int i = gap; i < n; i += 1)
        {
          
            int temp = arr[i];
 
           
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
       
            arr[j] = temp;
        }
    }
    return 0;
}
 
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void printArray2(int arr2[], int n2)
{
for (int i = 0; i < n2; i++) {
    cout << arr2[i] << " ";
}
}
 

int kthSmallest(int arr3[], int n3, int k3)
{
    // Sort the given array
    sort(arr3, arr3 + n3);
 
    // Return k'th element in the sorted array
    return arr3[k3 - 1];
}



void quickSortString(std::string &str, int left, int right) {
          int i = left, j = right;
          int mid = str[(left + right) / 2];

          /* partition */
          while (i <= j) {
                while (str[i] < mid)
                      i++;
                while (str[j] > mid)
                      j--;
                if (i <= j) {
                      std::swap(str[i], str[j]);
                      i++; j--;
                }
          };

          /* recursion */
          if (left < j)
                quickSortString(str, left, j);
          if (i < right)
                quickSortString(str, i, right);
    }

void insertion_sort(int arr[], int low, int n)
  {
 
    for(int i=low+1;i<n+1;i++)
    {
      int val = arr[i] ;
      int j = i ;
    while (j>low && arr[j-1]>val)
      {
        arr[j]= arr[j-1] ;
      j-= 1;
    }
    arr[j]= val ;
    }
 
  }

int partitionQSwI(int arr[], int low, int high)
{
  int pivot = arr[high] ;
  int i ,j;
  i = low;
  j = low;
 
  for (int i = low; i < high; i++)
     {
      if(arr[i]<pivot)
      {
        int temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      j += 1;
      }
    }
   
    int temp = arr[j];
    arr[j] = arr[high];
    arr[high] = temp;
 
  return j;
  }

void QS_with_insertion(int arr[], int low, int high)
{
  while (low < high)
    {
 
    // If the size of the array is less
    // than threshold apply insertion sort
    // and stop recursion
 
    if (high-low + 1 < 10)
      {
        insertion_sort(arr, low, high);
      break;
    }
 
    else
       
        {
            int pivot = partitionQSwI(arr, low, high) ;
 
      // Optimised quicksort which works on
      // the smaller arrays first
 
      // If the left side of the pivot
      // is less than right, sort left part
      // and move to the right part of the array
 
      if (pivot-low<high-pivot)
        {
          QS_with_insertion(arr, low, pivot - 1);
        low = pivot + 1;
      }
      else
        {
 
        // If the right side of pivot is less
        // than left, sort right side and
        // move to the left side
           
        QS_with_insertion(arr, pivot + 1, high);
        high = pivot-1;
        }
 
     }
 
   }
}
void quick_sort(int arr[], int low,int high)
{
  if (low < high)
  {
    int pivot = partition(arr, low, high);
    quick_sort(arr, low, pivot-1) ;
    quick_sort(arr, pivot + 1, high) ;
   
   
  }
}
int* random_array(int number_of_elements)
{
    int * array;
    array = (int*)malloc(number_of_elements * sizeof(int));
    if(array == NULL)
    {
        return NULL;
    }

    srand(time(0));
    for(int index = 0; index < number_of_elements; index++)
    {
        array[index] = rand()%number_of_elements;
    }

    return array;
    free(array);
}


int main()
{
  //  int arr[] = {12, 34, 54, 2, 3}, i;
    //int n = sizeof(arr)/sizeof(arr[0]);
   int size =
    512000;

    int array1[size];
    
    srand((unsigned)time(0));
        
       for(int p=0; p<size; p++){
           array1[p] = (rand()%100)+1;
         }
    int array2[size];
    
    srand((unsigned)time(0));
        
       for(int p=0; p<size; p++){
           array2[p] = (rand()%100)+1;
    }
    
    
    int array3[size];
    
    srand((unsigned)time(0));
        
       for(int p=0; p<size; p++){
           array3[p] = (rand()%100)+1;
    }
    
    
    cout << endl <<"Array sorting with shellsort \n";
    //printArray(array1, n);
    auto start = std::chrono::high_resolution_clock::now();
    shellSort(array1, size);
    auto finish = std::chrono::high_resolution_clock::now();
    cout << endl <<"Array was sorted with shellsort in: \n";
    std::chrono::duration<double> elapsed = finish - start;
    //printArray(array1, n);
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    
    cout << endl <<"\n next algorithm \n";
    
    cout << endl <<"Array sorting with quicksort \n";
    
    //printArray(array2, n);
    auto start2 = std::chrono::high_resolution_clock::now();
    quickSort(array2, 0, size - 1);
    auto finish2 = std::chrono::high_resolution_clock::now();
    cout << endl <<"Array was sorted with shellsort in: \n \n";
    std::chrono::duration<double> elapsed2 = finish2 - start2;
    std::cout << "Elapsed time: " << elapsed2.count() << " s\n";
    //printArray(array2, n);
    
    cout << endl <<"\n next algorithm \n";
    
    cout << endl <<"Array sorting with quicksort with insertion \n";
    
    //printArray(array3, n);
    
    cout << endl <<"Array sorted with quicksort with insertion in: \n";
    
    
    auto start3 = std::chrono::high_resolution_clock::now();
    QS_with_insertion(array3, 0, size-1);
   // printArray(array3, n);
    
    auto finish3 = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<double> elapsed3 = finish3 - start3;
    std::cout << "Elapsed time: " << elapsed3.count() << " s\n";
   
    cout << endl <<"\n next algorithm \n";
    cout << endl <<"\n String sorting using quick sort  \n";
    
    cout << endl << "\n Strings array sorted with  quicksort in: ";
    
    string test = gen_random(size);
    auto start4 = std::chrono::high_resolution_clock::now();
       quickSortString(test, 0, size);
    auto finish4 = std::chrono::high_resolution_clock::now();
      // cout << str;
    std::chrono::duration<double> elapsed4 = finish4 - start4;
    std::cout << "Elapsed time: " << elapsed4.count() << " s\n";
    cout << endl << endl;
    
   
    cout << endl << endl;
    return 0;
       }
