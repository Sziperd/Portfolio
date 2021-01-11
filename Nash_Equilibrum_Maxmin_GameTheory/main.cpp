//
//  main.cpp
//  Nash_Equilibrum_GameTheory
//
//  Created by Patryk Piwowarczyk on 07/12/2020.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
   
    
    cout << endl << " First Part of the program, Nash Equilibrum checker:  " << endl << endl ;
    cout << endl << "----------------------------  " << endl << endl ;

    cout << endl << " NOTE: output [0][0] means first column and first row so analogically [2][2] means third row and third column." << endl;
    
    int matrix1[3][3]= {{10,-13,10},{13,15,-8},{11,12,-2}};
    int matrix2[3][3]= {{-1,-4,1},{1,8,3},{4,3,-7}};
    
    int q= matrix1[0][0];
    int w= matrix1[0][1];
    int e= matrix1[0][2];
    int a= matrix1[1][0];
    int s= matrix1[1][1];
    int d= matrix1[1][2];
    int z= matrix1[2][0];
    int x= matrix1[2][1];
    int c= matrix1[2][2];
    
    
    int r= matrix2[0][0];
    int t= matrix2[0][1];
    int y= matrix2[0][2];
    int f= matrix2[1][0];
    int g= matrix2[1][1];
    int h= matrix2[1][2];
    int v= matrix2[2][0];
    int b= matrix2[2][1];
    int n= matrix2[2][2];
    
    
    
    //nash equilibrum strategy.. when both know their matrixes
    
    
    //find maximum in columns
    int maxc1;
    int maxc2;
    int maxc3;
    
    int memory1;
    int memory2;
    int memory3;
    int memory4;
    int memory5;
    int memory6;
    string matrixx1;
    string matrixx2;
    string matrixx3;
    if (q > a && q > z){
        maxc1 = q;
        memory1 = matrix1[0][0];
        matrixx1 = ("[0][0]");
    }
    else if(a > q && a > z ) {
        maxc1 = a;
        memory1 = matrix1[1][0];
        matrixx1=("[1][0]");
    }
    else if (z > q && z > a ){
        maxc1 = z;
        memory1 = matrix1[2][0];
        matrixx1 =("[2][0]");
    }
    if (w> s && w>x){
        maxc2 = w;
        memory2 = matrix1[0][1];
        matrixx2 = ("[0][1]");
    }
    else if (s>w && s>x){
        maxc2 = s;
        memory2 = matrix1[1][1];
        matrixx2 = ("[1][2]");
    }
    else if (x>w && x>s){
            maxc2 = x;
        memory2 = matrix1[2][1];
        matrixx2 = ("[2][1]");
    }
    if (e > d & e> c){
        maxc3 = e;
        memory3 = matrix1[0][2];
        matrixx3 = ("[0][2]");
    }
    else if (d>e && d>c){
        maxc3 = d;
        memory3 = matrix1[1][2];
        matrixx3 = ("[1][2]");
    }
    else if (c>d && c>e){
        maxc3 = c;
        memory3 = matrix1[2][2];
        matrixx3 = ("[2][2]");
    }
    
    int maxr1;
    int maxr2;
    int maxr3;
    
    if (r > t && r > y){
        maxr1 = r;
    memory4 = matrix1[0][0];
    }
    else if (t > r && t > y ){
        maxr1 = t;
    memory5 = matrix1[0][1];
    }
        else if (y > r && y > t ){
        maxr1 = y;
    memory6 = matrix1[0][2];
        }
            if (f> g && f>h){
        maxr2 = f;
    memory5 = matrix1[1][0];
            }
                else if (g>f && g>h){
        maxr2 = g;
    memory5 = matrix1[1][1];
                }
                    else if (h>f && h>g){
        maxr2 = h;
    memory6 = matrix1[1][2];
                    }
                        if (v > b & v > n){
        maxr3 = v;
    memory4 = matrix1[2][0];
                    }
                            else if (b>v && b>n){
        maxr3 = b;
    memory5 = matrix1[2][1];
                            }
                                else if (n>v && n>b){
        maxr3 = n;
    memory6 = matrix1[2][2];
                                }
    
    cout << endl << "-----------------" << endl;
    
    cout <<" Max number in first column is: "<< maxc1 << endl << " Max number in second column is: "<< maxc2 << endl <<" Max number in third column is: "<< maxc3 << endl;
    cout << " Max number in first row is: " <<maxr1 << endl << " Max number in second row is: "<< maxr2 << endl <<" Max number in third row is: " <<maxr3 << endl;
    cout << endl << "-----------------" << endl;
    
    //check witch [x][y] double..
    
    
    if (memory1 == memory4)
        cout << endl <<"There is an equilibrum point in first column in: "<< matrixx1 << endl;
    if (memory2 ==memory5)
        cout << endl <<"There is an equilibrum point in second column in: "<< matrixx2 << endl;
    if (memory3 == memory6)
        cout << endl <<"There is an equilibrum point in third column in: "<< matrixx3 << endl << endl;
    
    
    cout << endl << "----------------------------  " << endl << endl ;
    cout << endl << " Second Part of the program, maxmin checker:  " << endl << endl ;
    cout << endl << "----------------------------  " << endl << endl ;
    
    //for maxmin
    
    cout << endl << " NOTE: output [0][0] means first column and first row so analogically [2][2] means third row and third column." << endl;
    
    cout << endl << "----------------------------  " << endl << endl ;
    
    cout << endl << "maxmin strategy for player D1 :" << endl ;
    
    
    
    int minr1;
    int minr2;
    int minr3;
    
    int num1 = 0;
    
    string matrixxx1;
    string matrixxx2;
    string matrixxx3;
    if (q < w && q < e){
        minr1 = q;
        memory1 = matrix1[0][0];
        matrixxx1 = ("[0][0]");
        num1 = 1;
    }
    else if(w < q && w < e ) {
        minr1 = w;
        memory1 = matrix1[0][1];
        matrixxx1=("[0][1]");
        num1 = 2;
    }
    else if (e < q && e < w ){
        minr1 = e;
        memory1 = matrix1[0][2];
        matrixxx1 =("[0][2]");
        num1 = 3;
    }
    if (a< s && a<d){
        minr2 = a;
        memory2 = matrix1[1][0];
        matrixxx2 = ("[1][0]");
        num1 = 4;
    }
    else if (s<a && s<d){
        minr2 = s;
        memory2 = matrix1[1][1];
        matrixxx2 = ("[1][1]");
        num1 = 5;
    }
    else if (d<a && d<s){
            minr2 = d;
        memory2 = matrix1[1][2];
        matrixxx2 = ("[1][2]");
        num1 = 6;
    }
    if (z < x & z<c){
        minr3 = z;
        memory3 = matrix1[2][0];
        matrixxx3 = ("[2][0]");
        num1 = 7;
    }
    else if (x<z && x<c){
        minr3 = x;
        memory3 = matrix1[2][1];
        matrixxx3 = ("[2][1]");
        num1 = 8;
    }
    else if (c<z && c<x){
        minr3 = c;
        memory3 = matrix1[2][2];
        matrixxx3 = ("[2][2]");
        num1 = 9;
    }
    
    
    int maxminp1;
    
    
    if (minr1 > minr2 && minr1 >minr3)
        maxminp1 = minr1;
    else if (minr2 > minr1 && minr2 >minr3)
        maxminp1 = minr2;
    else if (minr3 > minr2 && minr3 >minr1)
        maxminp1 = minr3;
    
    
    
    cout << endl <<"Maxmin for player 1 is: "<< maxminp1  << endl;
    
  
    
    if ( minr1 ==  maxminp1)
        cout << "that occurs in: "<< matrixxx1 << endl<< endl;
    else if (minr2 ==  maxminp1)
        cout << "that occurs in: "<< matrixxx2 << endl << endl;
    else if (minr3 ==  maxminp1 )
        cout << "that occurs in: "<< matrixxx3 << endl << endl;
    
  
    
    cout << endl << "----------------------------  " << endl << endl ;
    
    
    cout << endl << "maxmin strategy for player D2 :" << endl ;
    
    
    
    int minc1;
    int minc2;
    int minc3;
    
    int num2 = 0;
    
    string matrixxxx1;
    string matrixxxx2;
    string matrixxxx3;
    
    
    if (r < f && r < v){
        minc1 = r;
        memory1 = matrix1[0][0];
        matrixxxx1 = ("[0][0]");
        num2 = 1;
    }
    else if(f < r && f < v ) {
        minc1 = f;
        memory1 = matrix1[0][1];
        matrixxxx1=("[0][1]");
        num2 = 2;
    }
    else if (v < r && v < f ){
        minc1 = v;
        memory1 = matrix1[0][2];
       matrixxxx1 =("[0][2]");
        num2 = 3;
    }
    if (t< g && t<b){
        minc2 = t;
        memory2 = matrix1[1][0];
        matrixxxx2 = ("[1][0]");
        num2 = 4;
    }
    else if (g<t && g<b){
        minc2 = g;
        memory2 = matrix1[1][1];
        matrixxxx2 = ("[1][1]");
        num2 = 5;
    }
    else if (b<t && b<g){
            minc2 = b;
        memory2 = matrix1[1][2];
        matrixxxx2 = ("[1][2]");
        num2 = 6;
    }
    if (y < h & y<n){
        minc3 = y;
        memory3 = matrix1[2][0];
        matrixxxx3 = ("[2][0]");
        num2 = 7;
    }
    else if (h<y && h<n){
        minc3 = h;
        memory3 = matrix1[2][1];
        matrixxxx3 = ("[2][1]");
        num2 = 8;
    }
    else if (n<h && n<y){
        minc3 = n;
        memory3 = matrix1[2][2];
        matrixxxx3 = ("[2][2]");
        num2 = 9;
    }
    
    
    int maxminp2;

   
    
    if (minc1 > minc2 && minc1 >minc3)
    {
        maxminp2 = minc1;
     
    }
    else if (minc2 > minc1 && minc2 >minc3)
    {
        maxminp2 = minc2;
       
    }
    else if (minc3 > minc2 && minc3 >minc1)
    {
        maxminp2 = minc3;
  
    }
        
    cout << endl <<"Maxmin for player 2 is: "<< maxminp2  << endl;
    
   
    
    if ( minc1 ==  maxminp2)
        cout << "that occurs in: "<< matrixxxx1 << endl<< endl;
    else if (minc2 ==  maxminp2)
        cout << "that occurs in: "<< matrixxxx2 << endl << endl;
    else if (minc3 ==  maxminp2 )
        cout << "that occurs in: "<< matrixxxx3 << endl << endl;
    
    
   
   
    
 
    
    
    
    
    
    
    
    return 0;
    
    
    
    
    
    
    
    
    
}
