//
//  main.cpp
//  Game_Theory_Zero_Sum
//
//  Created by Patryk Piwowarczyk on 07/12/2020.
//

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main(int argc, const char * argv[])
{
    cout << endl << " Zero-sum game 2x2 variant code "<< endl;
    
  
    
    
    int x[2][2] =  {{12,6},
                    {3,18}};
    
    
    
    
    int m;
    int n;
    int b;
    int v;

    
    m = x[0][0];
    n = x[0][1];
    b = x[1][0];
    v = x[1][1];
    
   int Nx= 2;
    int Ny= 2;  // input of X x Y matrix
    
    cout << endl << "At the moment the Matrix is: " << endl;
    for (int i = 0; i < Nx; i++)
            {
                for (int j = 0; j < Ny; j++)
                {
    
    cout <<  x[i][j] << "    ";
                    
                }
                            cout << endl;
                        }
                        cout << endl;
                    
                    
    
    int maxx1;
    int maxx2;
    int minn1;
    int minn2;
    
    int max;
    int min;
    //select minimum from the maximum of the colums
    
    if (m > b)
        maxx1 = m;
    else
        maxx1 = b;
    
    if (n>v)
        maxx2 = n;
    else
        maxx2 = v;
    
    
    
    if (maxx1 < maxx2)
        min = maxx1;
    else
        min = maxx2;
    
    cout << " min of the maximum of the columns is: " << min << endl;  // it works!
    
    if (m < n)
        minn1 = m;
        else
            minn1 =n;
    
    if (b< v)
        minn2 = b;
    else
        minn2 = v;
    
    
    
    if (minn1 > minn2)
        max = minn1;
    else
        max = minn2;
    
    cout << " max of the minimum of rows is: " << max << endl; // it works!
    
    
    if (max==min)   //it works!
    {
        cout << endl << " this game has saddle point " << endl;
        
        if (min == maxx1)
            cout << "player  1 choose strategy 1, its a saddle point" << endl;
        else
            cout << "player 1 choose strategy 2, its a saddle point" << endl;
        if (max == minn1)
            cout << "player  2 choose strategy 1, its a saddle point" << endl;
        else
            cout << "player 2 choose strategy 2, its a saddle point" << endl;
    }else
    {
        cout << " ---------------------------- " <<  endl<< endl;
        
        cout<< endl << "this game doesn't have saddle point " << endl;
        
        cout << " ---------------------------- " <<  endl<< endl;
        
        // checking dominance rule.
        
        if (m >= b && n >= v)
            cout << "player 1 is dominant " << endl;
        if (m <= n && b<= v)
            cout <<"player 2 is dominant"<< endl;
        
        // the point of optimal solution occurs at the intersection of two lines
        
       
        double p1;
        double p2;
    
        
        
        
        double g1 = (-n + v);
        double f1 = (m-n-b+v);
   
      
       
        p1 = g1/f1;
        
        
        
        
        p2 = 1 - p1;
     
       
        
        
        
        cout <<endl << "p1 is:  "  << p1 << endl << endl;
        cout << "p2 is:  " << p2 << endl<< endl;
        
    
        double E1;
        
        E1 = m*p1 + n * p2;
        
        cout << " E1 is equal:  " << E1 << endl<< endl;

        cout << " ---------------------------- " <<  endl<< endl;
        double g2= (-b + v);
        double f2= (m - b - n + v);
        
        
     
        double q1;
        double q2;
    
        
        //q1 = ((-b + v)/(m - b -n - v));
        
        q1 = g2/f2;
        q2 = 1-q1;
        cout << "q1 is equal : " << q1 <<  endl<< endl;
        cout << "q2 is equal : " << q2 <<  endl<< endl;
        
        
        double E2;
        
        E2 = m*q1 + b * q2;
        
        cout << " E2 is equal:  " << E2 << endl<< endl;
        
        cout << " ---------------------------- " <<  endl<< endl;
    }
    
}
