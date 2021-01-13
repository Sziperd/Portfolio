//
//  main.cpp
//  Von_stackelberg_GameTheory
//
//  Created by Patryk Piwowarczyk on 13/01/2021.
//

#include <iostream>
using namespace std;
int main() {
   
    std::cout << "Hello, this is von stackelberg equilibrum calculator made by Patryk Piwowarczyk, insert your 3x3 matrix below!\n";
    
    
    int matrix1[3][3]= {{15,8,-1},{-2,15,23},{6,-18,-12}};  // A
    int matrix2[3][3]= {{41,-15,41},{25,-18,25},{16,-6,-7}}; //B
    
    //B matrix
    
    int q= matrix2[0][0];
    int w= matrix2[0][1];
    int e= matrix2[0][2];
    int a= matrix2[1][0];
    int s= matrix2[1][1];
    int d= matrix2[1][2];
    int z= matrix2[2][0];
    int x= matrix2[2][1];
    int c= matrix2[2][2];
    
    //A matrix
    int r= matrix1[0][0];
    int t= matrix1[0][1];
    int y= matrix1[0][2];
    int f= matrix1[1][0];
    int g= matrix1[1][1];
    int h= matrix1[1][2];
    int v= matrix1[2][0];
    int b= matrix1[2][1];
    int n= matrix1[2][2];
    
   
    
    //von stackelberg strategy
    // we start with matrix B and search for smallest number in each row
    int num1 = 0;
    int minr1;   // variables to place minimum row numbers in them
    int minr2;
    int minr3;
    string matrixxx1; // just for the text outputs..
    string matrixxx2;
    string matrixxx3;
    
    int memory1;  //variables needed for the program to work, i use them later to determine what was each number's placement in a table..
    int memory2; //same for the rest..
    int memory3;
    int memory4;
    int memory5;
    int memory6;
    
    //finding smallest number in each row and memebering it.
    
    int corresp_num1;
    int corresp_num2;
    int corresp_num3;
    
    
    if (q < w && q < e){
        minr1 = q;
        corresp_num1 = r;
        memory1 = matrix2[0][0];
        matrixxx1 = ("[0][0]");
        num1 = 1;
    }
    else if(w < q && w < e ) {
        minr1 = w;
        corresp_num1 = t;
        memory1 = matrix2[0][1];
        matrixxx1=("[0][1]");
        num1 = 2;
    }
    else if (e < q && e < w ){
        minr1 = e;
        corresp_num1 = y;
        memory1 = matrix2[0][2];
        matrixxx1 =("[0][2]");
        num1 = 3;
    }
    if (a< s && a<d){
        minr2 = a;
        corresp_num2 = f;
        memory2 = matrix2[1][0];
        matrixxx2 = ("[1][0]");
        num1 = 4;
    }
    else if (s<a && s<d){
        minr2 = s;
        corresp_num2 = g;
        memory2 = matrix2[1][1];
        matrixxx2 = ("[1][1]");
        num1 = 5;
    }
    else if (d<a && d<s){
            minr2 = d;
        corresp_num2 = h;
        memory2 = matrix2[1][2];
        matrixxx2 = ("[1][2]");
        num1 = 6;
    }
    if (z < x & z<c){
        minr3 = z;
        corresp_num3 = v;
        memory3 = matrix2[2][0];
        matrixxx3 = ("[2][0]");
        num1 = 7;
    }
    else if (x<z && x<c){
        minr3 = x;
        corresp_num3 = b;
        memory3 = matrix2[2][1];
        matrixxx3 = ("[2][1]");
        num1 = 8;
    }
    else if (c<z && c<x){
        minr3 = c;
        corresp_num3 = n;
        memory3 = matrix2[2][2];
        matrixxx3 = ("[2][2]");
        num1 = 9;
    }
    
    cout << endl << "smallest number in first row of matrix B is: " << minr1 << endl << "smallest number in second row of matrix B is: " << minr2 << endl << "smallest number in third row of matrix B is: " << minr3 << endl;
    
    
    // after finding min of each row of B matrix we have to get corresponding A matrix numbers
    
    
    cout << endl << "corresponding numbers from matrix A are:" << endl<< corresp_num1 << endl << corresp_num2 << endl << corresp_num3 << endl;
    
    int mincorresp;
    
    if (corresp_num1 < corresp_num2 && corresp_num1 <corresp_num3)
        mincorresp = corresp_num1 ;
    else if (corresp_num2 < corresp_num1 && corresp_num2 < corresp_num3)
        mincorresp = corresp_num2 ;
    else if (corresp_num3 < corresp_num2 && corresp_num3 < corresp_num1)
        mincorresp = corresp_num3 ;
    
    cout <<endl << " Smallest corresponding number is: " << mincorresp << endl;
    cout << endl << "Therefore S*(A)=" << mincorresp << endl << endl;
    
    cout << endl << " Von Stackelberg equilibrum happens in point: ";
    
    if (mincorresp == corresp_num1)
    {
        cout << matrixxx1 << endl;
    }
    else if (mincorresp == corresp_num2)
    {
        cout << matrixxx2 << endl;
    }
    else if (mincorresp == corresp_num3)
    {
        cout << matrixxx3 << endl;
    }
    
    cout << endl <<endl << " (please note that for example [2][2] means third column and third row, displayed numbers are counted from [0][0]...)" << endl << endl;
    return 0;
}
