//
//  main.cpp
//  Lab5_OADMTEST
//
//  Created by Patryk Piwowarczyk on 26/11/2020.
//

#include <iostream>
#include <stdio.h>
#include <math.h>


using namespace std;
int main(int argc, const char * argv[]) {

    
    int Y4= 17;
    int Y3= 10;
    int Y2= 5;
    int Y1= 2;
    int Y0= 1;
    
    
    //HERE insert prices of each part of a road
    
    int cost[] = {2,3,6,1,2,7};
  
    //for i=6
    
    
    
    
    
    double i6;
    double i6_0 = sqrt(Y4)*cost[5]; // 28
   // cout << " i6_0 equals: " << i6_0;
    double i6_1 = sqrt(Y3)*cost[5]; //22
    double i6_2= sqrt(Y2)*cost[5]; //15
    double i6_3= sqrt(Y1)*cost[5]; //9
    double i6_4= sqrt(Y0)*cost[5]; //7
    double min6;
    if (i6_1 <= i6_2 && i6_1 <= i6_3 && i6_1 <= i6_4 && i6_1 <=i6_0)
        min6 = i6_1;
    else if (i6_2 <= i6_1 && i6_2 <= i6_3 && i6_2 <= i6_4 && i6_2 <=i6_0)
        min6 = i6_2;
    else if(i6_3 <= i6_2 && i6_3 <= i6_1 && i6_3 <= i6_4 && i6_3 <=i6_0 )
        min6 = i6_3;
    else if(i6_4 <= i6_2 && i6_4 <= i6_3 && i6_4 <= i6_1 && i6_4 <=i6_0)
        min6 = i6_4;
    else if(i6_0 <= i6_2 && i6_0 <= i6_3 && i6_0 <= i6_1 && i6_0 <=i6_4)
        min6 = i6_0;
    
    i6= min6;
    cout << endl << "phase one, road for C6" << endl << endl;
    cout << "min number for C6 is: " << min6 << endl;
    
    double min5_0;
    double min5_1;
    double min5_2;
    double min5_3;
    double min5_4;
    
    double i5;
    double i5_0 = sqrt(Y4)*cost[4];
    double i5_1 = sqrt(Y3)*cost[4];
    double i5_2= sqrt(Y2)*cost[4];
    double i5_3= sqrt(Y1)*cost[4];
    double i5_4= sqrt(Y0)*cost[4];
    
    double _0_L4_Plus_G5_4 = i6_4 + i5_0;
    double _0_L4_Plus_G5_3 = i6_3 + i5_1;
    double _0_L4_Plus_G5_2 = i6_2 + i5_2;
    double _0_L4_Plus_G5_1 = i6_1 + i5_3;
    double _0_L4_Plus_G5_0 = i6_0 + i5_4;
    
    cout << endl << "next phase, road for C5" << endl << endl;
    
    if (_0_L4_Plus_G5_1 <= _0_L4_Plus_G5_2 && _0_L4_Plus_G5_1 <= _0_L4_Plus_G5_3 && _0_L4_Plus_G5_1 <= _0_L4_Plus_G5_4 && _0_L4_Plus_G5_1 <=_0_L4_Plus_G5_0)
        min5_0 = _0_L4_Plus_G5_1;
    else if (_0_L4_Plus_G5_2 <= _0_L4_Plus_G5_1 && _0_L4_Plus_G5_2 <= _0_L4_Plus_G5_3 && _0_L4_Plus_G5_2 <= _0_L4_Plus_G5_4 && _0_L4_Plus_G5_2 <=_0_L4_Plus_G5_0)
        min5_0 = _0_L4_Plus_G5_2;
    else if(_0_L4_Plus_G5_3 <= _0_L4_Plus_G5_2 && _0_L4_Plus_G5_3 <= _0_L4_Plus_G5_1 && _0_L4_Plus_G5_3 <= _0_L4_Plus_G5_4 && _0_L4_Plus_G5_3 <=_0_L4_Plus_G5_0 )
        min5_0 = _0_L4_Plus_G5_3;
    else if(_0_L4_Plus_G5_4<= _0_L4_Plus_G5_2 && _0_L4_Plus_G5_4 <= _0_L4_Plus_G5_3 && _0_L4_Plus_G5_4<= _0_L4_Plus_G5_1 && _0_L4_Plus_G5_4 <=_0_L4_Plus_G5_0)
        min5_0 = _0_L4_Plus_G5_4;
    else if(_0_L4_Plus_G5_0 <= _0_L4_Plus_G5_2 && _0_L4_Plus_G5_0 <= _0_L4_Plus_G5_3 && _0_L4_Plus_G5_0 <= _0_L4_Plus_G5_1 && _0_L4_Plus_G5_0 <=_0_L4_Plus_G5_4)
        min5_0 = _0_L4_Plus_G5_0;
    
    cout << " min for 5_0 is: " << min5_0<< endl;
    
    cout << "L4 + G5 is: " << _0_L4_Plus_G5_4 << endl;
    cout << "L4 + G5 is: " << _0_L4_Plus_G5_3 << endl;
    cout << "L4 + G5 is: " << _0_L4_Plus_G5_2 << endl;
    cout << "L4 + G5 is: " << _0_L4_Plus_G5_1 << endl;
    cout << "L4 + G5 is: " << _0_L4_Plus_G5_0 << endl;
    
    double _1_L4_Plus_G5_4 = i6_4 + i5_1;
    double _1_L4_Plus_G5_3 = i6_3 + i5_2;
    double _1_L4_Plus_G5_2 = i6_2 + i5_3;
    double _1_L4_Plus_G5_1 = i6_1 + i5_4;
    
    if (_1_L4_Plus_G5_1 <= _1_L4_Plus_G5_2 && _1_L4_Plus_G5_1 <= _1_L4_Plus_G5_3 && _1_L4_Plus_G5_1 <= _1_L4_Plus_G5_4)
        min5_1 = _1_L4_Plus_G5_1;
    else if (_1_L4_Plus_G5_2 <= _1_L4_Plus_G5_1 && _1_L4_Plus_G5_2 <= _1_L4_Plus_G5_3 && _1_L4_Plus_G5_2 <= _1_L4_Plus_G5_4)
        min5_1 = _1_L4_Plus_G5_2;
    else if(_1_L4_Plus_G5_3 <= _1_L4_Plus_G5_2 && _1_L4_Plus_G5_3 <= _1_L4_Plus_G5_1 && _1_L4_Plus_G5_3 <= _1_L4_Plus_G5_4)
        min5_1 = _1_L4_Plus_G5_3;
    else if(_1_L4_Plus_G5_4<= _1_L4_Plus_G5_2 && _1_L4_Plus_G5_4 <= _1_L4_Plus_G5_3 && _1_L4_Plus_G5_4<= _1_L4_Plus_G5_1)
        min5_1 = _1_L4_Plus_G5_4;
    
    cout << " min for 5_1 is: " << min5_1<< endl;
    
    cout << "L4 + G5 is: " << _1_L4_Plus_G5_4 << endl;
    cout << "L4 + G5 is: " << _1_L4_Plus_G5_3 << endl;
    cout << "L4 + G5 is: " << _1_L4_Plus_G5_2 << endl;
    cout << "L4 + G5 is: " << _1_L4_Plus_G5_1 << endl;
    
    double _2_L4_Plus_G5_4 = i6_4 + i5_2;
    double _2_L4_Plus_G5_3 = i6_3 + i5_3;
    double _2_L4_Plus_G5_2 = i6_2 + i5_4;
    
  
   if (_2_L4_Plus_G5_2 <= _2_L4_Plus_G5_3 && _2_L4_Plus_G5_2 <= _2_L4_Plus_G5_4)
        min5_2 = _2_L4_Plus_G5_2;
    else if(_2_L4_Plus_G5_3 <= _2_L4_Plus_G5_2&& _2_L4_Plus_G5_3 <= _2_L4_Plus_G5_4)
        min5_2 = _2_L4_Plus_G5_3;
    else if(_2_L4_Plus_G5_4<= _2_L4_Plus_G5_2 && _2_L4_Plus_G5_4 <= _2_L4_Plus_G5_3)
        min5_2 = _2_L4_Plus_G5_4;
    
    cout << " min for 5_2 is: " << min5_2<< endl;
    
    cout << "L4 + G5 is: " << _2_L4_Plus_G5_4 << endl;
    cout << "L4 + G5 is: " << _2_L4_Plus_G5_3 << endl;
    cout << "L4 + G5 is: " << _2_L4_Plus_G5_2 << endl;
    
    
    double _3_L4_Plus_G5_4 = i6_4 + i5_3;
    double _3_L4_Plus_G5_3 = i6_3 + i5_4;
    
 
    if(_3_L4_Plus_G5_3 <= _3_L4_Plus_G5_4)
         min5_3 = _3_L4_Plus_G5_3;
     else if( _3_L4_Plus_G5_4 <= _3_L4_Plus_G5_3)
         min5_3 = _3_L4_Plus_G5_4;
    
    cout << " min for 5_3 is: " << min5_3<< endl;
    
    cout << "L4 + G5 is: " << _3_L4_Plus_G5_4 << endl;
    cout << "L4 + G5 is: " << _3_L4_Plus_G5_3 << endl;
    
    double _4_L4_Plus_G5_4 = i6_4 + i5_4;
    
    min5_4 = _4_L4_Plus_G5_4;
    cout << " min for 5_4 is: " << min5_4<< endl;
    
    // 0
    
    //1
   
 //2
    
//3
    
  //4
    cout << "L4 + G5 is: " << _4_L4_Plus_G5_4 << endl;
 
    
    
    //////////////////////////////
    
    double i4_0 = sqrt(Y4)*cost[3];
    double i4_1 = sqrt(Y3)*cost[3];
    double i4_2= sqrt(Y2)*cost[3];
    double i4_3= sqrt(Y1)*cost[3];
    double i4_4= sqrt(Y0)*cost[3];

    
    double _0_L3_Plus_G4_4 = min5_4 + i4_0;
    double _0_L3_Plus_G4_3 = min5_3 + i4_1;
    double _0_L3_Plus_G4_2 = min5_2 + i4_2;
    double _0_L3_Plus_G4_1 = min5_1 + i4_3;
    double _0_L3_Plus_G4_0 = min5_0 + i4_4;
    
    double min4_0;
    double min4_1;
    double min4_2;
    double min4_3;
    double min4_4;
    
    
    cout << endl << "next phase, road for C4" << endl << endl;
    if (_0_L3_Plus_G4_1 <= _0_L3_Plus_G4_2 && _0_L3_Plus_G4_1 <= _0_L3_Plus_G4_3 && _0_L3_Plus_G4_1 <= _0_L3_Plus_G4_4 && _0_L3_Plus_G4_1 <=_0_L3_Plus_G4_0)
        min4_0 = _0_L3_Plus_G4_1;
    else if (_0_L3_Plus_G4_2 <= _0_L3_Plus_G4_1 && _0_L3_Plus_G4_2 <= _0_L3_Plus_G4_3 && _0_L3_Plus_G4_2 <= _0_L3_Plus_G4_4 && _0_L3_Plus_G4_2 <=_0_L3_Plus_G4_0)
        min4_0 = _0_L3_Plus_G4_2;
    else if(_0_L3_Plus_G4_3 <= _0_L3_Plus_G4_2 && _0_L3_Plus_G4_3 <= _0_L3_Plus_G4_1 && _0_L3_Plus_G4_3 <= _0_L3_Plus_G4_4 && _0_L3_Plus_G4_3 <=_0_L3_Plus_G4_0 )
        min4_0 = _0_L3_Plus_G4_3;
    else if(_0_L3_Plus_G4_4<= _0_L3_Plus_G4_2 && _0_L3_Plus_G4_4 <= _0_L3_Plus_G4_3 && _0_L3_Plus_G4_4<= _0_L3_Plus_G4_1 && _0_L3_Plus_G4_4 <=_0_L3_Plus_G4_0)
        min4_0 = _0_L3_Plus_G4_4;
    else if(_0_L3_Plus_G4_0 <= _0_L3_Plus_G4_2 && _0_L3_Plus_G4_0 <= _0_L3_Plus_G4_3 && _0_L3_Plus_G4_0 <= _0_L3_Plus_G4_1 && _0_L3_Plus_G4_0 <=_0_L3_Plus_G4_4)
        min4_0 = _0_L3_Plus_G4_0;
    
    cout << " min for 4_0 is: " << min4_0<< endl;
    
    
    cout << "L3 + G4 is: " << _0_L3_Plus_G4_4 << endl;
    cout << "L3 + G4 is: " << _0_L3_Plus_G4_3 << endl;
    cout << "L3 + G4 is: " << _0_L3_Plus_G4_2 << endl;
    cout << "L3 + G4 is: " << _0_L3_Plus_G4_1 << endl;
    cout << "L3 + G4 is: " << _0_L3_Plus_G4_0 << endl;
    

    
    
    
    
    double _1_L3_Plus_G4_4 = min5_4 + i4_1;
    double _1_L3_Plus_G4_3 = min5_3 + i4_2;
    double _1_L3_Plus_G4_2 = min5_2 + i4_3;
    double _1_L3_Plus_G4_1 = min5_1 + i4_4;
    
    
    if (_1_L3_Plus_G4_1 <= _1_L3_Plus_G4_2 && _1_L3_Plus_G4_1 <= _1_L3_Plus_G4_3 && _1_L3_Plus_G4_1 <= _1_L3_Plus_G4_4)
        min4_1 = _1_L3_Plus_G4_1;
    else if (_1_L3_Plus_G4_2 <= _1_L3_Plus_G4_1 && _1_L3_Plus_G4_2 <= _1_L3_Plus_G4_3 && _1_L3_Plus_G4_2 <= _1_L3_Plus_G4_4)
        min4_1 = _1_L3_Plus_G4_2;
    else if(_1_L3_Plus_G4_3 <= _1_L3_Plus_G4_2 && _1_L3_Plus_G4_3 <= _1_L3_Plus_G4_1 && _1_L3_Plus_G4_3 <= _1_L3_Plus_G4_4)
        min4_1 = _1_L3_Plus_G4_3;
    else if(_1_L3_Plus_G4_4<= _1_L3_Plus_G4_2 && _1_L3_Plus_G4_4 <= _1_L3_Plus_G4_3 && _1_L3_Plus_G4_4<= _1_L3_Plus_G4_1)
        min4_1 = _1_L3_Plus_G4_4;
   
    cout << " min for 4_1 is: " << min4_1<< endl;
    
    
    cout << "L3 + G4 is: " << _1_L3_Plus_G4_4 << endl;
    cout << "L3 + G4 is: " << _1_L3_Plus_G4_3 << endl;
    cout << "L3 + G4 is: " << _1_L3_Plus_G4_2 << endl;
    cout << "L3 + G4 is: " << _1_L3_Plus_G4_1 << endl;
    
    double _2_L3_Plus_G4_4 = min5_4 + i4_2;
    double _2_L3_Plus_G4_3 = min5_3 + i4_3;
    double _2_L3_Plus_G4_2 = min5_2 + i4_4;
 
    
  
    if (_2_L3_Plus_G4_2 <= _2_L3_Plus_G4_3 && _2_L3_Plus_G4_2 <= _2_L3_Plus_G4_4)
        min4_2 = _2_L3_Plus_G4_2;
    else if(_2_L3_Plus_G4_3 <= _2_L3_Plus_G4_2 && _2_L3_Plus_G4_3 <= _2_L3_Plus_G4_4)
        min4_2 = _2_L3_Plus_G4_3;
    else if(_2_L3_Plus_G4_4 <= _2_L3_Plus_G4_2 && _2_L3_Plus_G4_4 <= _2_L3_Plus_G4_3)
        min4_2 = _2_L3_Plus_G4_4;
    
    cout << " min for 4_2 is: " << min4_2<< endl;
    
    cout << "L3 + G4 is: " << _2_L3_Plus_G4_4 << endl;
    cout << "L3 + G4 is: " << _2_L3_Plus_G4_3 << endl;
    cout << "L3 + G4 is: " << _2_L3_Plus_G4_2 << endl;
    
    double _3_L3_Plus_G4_4 = min5_4 + i4_3;
    double _3_L3_Plus_G4_3 = min5_3 + i4_4;
    
    if(_3_L3_Plus_G4_3 < _3_L3_Plus_G4_4)
         min4_3 = _3_L3_Plus_G4_3;
     else if( _3_L3_Plus_G4_4 < _3_L3_Plus_G4_3)
         min4_3 = _3_L3_Plus_G4_4;
    
    cout <<" min for 4_3 is: " << min4_3<< endl;
    
    
    cout << "L3 + G4 is: " << _3_L3_Plus_G4_4 << endl;
    cout << "L3 + G4 is: " << _3_L3_Plus_G4_3 << endl;
    
    double _4_L3_Plus_G4_4 = min5_4 + i4_4;
    min4_4 = _4_L3_Plus_G4_4;
    cout <<" min for 4_4 is: " << min4_4<< endl;
    
    
    cout << "L3 + G4 is: " << _4_L3_Plus_G4_4 << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    //   dla i = 3 od teraz
    //
    //
    
    
    // test
    
    //////////////////////////////
    
    double i3_0 = sqrt(Y4)*cost[2];
    double i3_1 = sqrt(Y3)*cost[2];
    double i3_2= sqrt(Y2)*cost[2];
    double i3_3= sqrt(Y1)*cost[2];
    double i3_4= sqrt(Y0)*cost[2];

    
    double _0_L2_Plus_G3_4 = min4_4 + i3_0;
    double _0_L2_Plus_G3_3 = min4_3 + i3_1;
    double _0_L2_Plus_G3_2 = min4_2 + i3_2;
    double _0_L2_Plus_G3_1 = min4_1 + i3_3;
    double _0_L2_Plus_G3_0 = min4_0 + i3_4;
    
    double min3_0;
    double min3_1;
    double min3_2;
    double min3_3;
    double min3_4;
    
    
    cout << endl << "next phase, road for C3" << endl << endl;
    if (_0_L2_Plus_G3_1 <= _0_L2_Plus_G3_2 && _0_L2_Plus_G3_1 <= _0_L2_Plus_G3_3 && _0_L2_Plus_G3_1 <= _0_L2_Plus_G3_4 && _0_L2_Plus_G3_1 <=_0_L2_Plus_G3_0)
            min3_0 = _0_L2_Plus_G3_1;
        else if (_0_L2_Plus_G3_2 <= _0_L2_Plus_G3_1 && _0_L2_Plus_G3_2 <= _0_L2_Plus_G3_3 && _0_L2_Plus_G3_2 <= _0_L2_Plus_G3_4 && _0_L2_Plus_G3_2 <=_0_L2_Plus_G3_0)
            min3_0 = _0_L2_Plus_G3_2;
        else if(_0_L2_Plus_G3_3 <= _0_L2_Plus_G3_2 && _0_L2_Plus_G3_3 <= _0_L2_Plus_G3_1 && _0_L2_Plus_G3_3 <= _0_L2_Plus_G3_4 && _0_L2_Plus_G3_3 <=_0_L2_Plus_G3_0 )
            min3_0 = _0_L2_Plus_G3_3;
        else if(_0_L2_Plus_G3_4<= _0_L2_Plus_G3_2 && _0_L2_Plus_G3_4 <= _0_L2_Plus_G3_3 && _0_L2_Plus_G3_4<= _0_L2_Plus_G3_1 && _0_L2_Plus_G3_4 <=_0_L2_Plus_G3_0)
            min3_0 = _0_L2_Plus_G3_4;
        else if(_0_L2_Plus_G3_0 <= _0_L2_Plus_G3_2 && _0_L2_Plus_G3_0 <= _0_L2_Plus_G3_3 && _0_L2_Plus_G3_0 <= _0_L2_Plus_G3_1 && _0_L2_Plus_G3_0 <=_0_L2_Plus_G3_4)
            min3_0 = _0_L2_Plus_G3_0;

    
    cout << " min for 3_0 is: " << min3_0<< endl;
    
    
       cout << "L2 + G3 is: " << _0_L2_Plus_G3_4 << endl;
       cout << "L2 + G3 is: " << _0_L2_Plus_G3_3 << endl;
       cout << "L2 + G3 is: " << _0_L2_Plus_G3_2 << endl;
       cout << "L2 + G3 is: " << _0_L2_Plus_G3_1 << endl;
       cout << "L2 + G3 is: " << _0_L2_Plus_G3_0 << endl;
       

       
       
       
       
       double _1_L2_Plus_G3_4 = min4_4 + i3_1;
       double _1_L2_Plus_G3_3 = min4_3 + i3_2;
       double _1_L2_Plus_G3_2 = min4_2 + i3_3;
       double _1_L2_Plus_G3_1 = min4_1 + i3_4;
       
       
       if (_1_L2_Plus_G3_1 <= _1_L2_Plus_G3_2 && _1_L2_Plus_G3_1 <= _1_L2_Plus_G3_3 && _1_L2_Plus_G3_1 <= _1_L2_Plus_G3_4)
           min3_1 = _1_L2_Plus_G3_1;
       else if (_1_L2_Plus_G3_2 <= _1_L2_Plus_G3_1 && _1_L2_Plus_G3_2 <= _1_L2_Plus_G3_3 && _1_L2_Plus_G3_2 <= _1_L2_Plus_G3_4)
           min3_1 = _1_L2_Plus_G3_2;
       else if(_1_L2_Plus_G3_3 <= _1_L2_Plus_G3_2 && _1_L2_Plus_G3_3 <= _1_L2_Plus_G3_1 && _1_L2_Plus_G3_3 <= _1_L2_Plus_G3_4)
           min3_1 = _1_L2_Plus_G3_3;
       else if(_1_L2_Plus_G3_4<= _1_L2_Plus_G3_2 && _1_L2_Plus_G3_4 <= _1_L2_Plus_G3_3 && _1_L2_Plus_G3_4<= _1_L2_Plus_G3_1)
           min3_1 = _1_L2_Plus_G3_4;
    
    cout << " min for 3_1 is: " << min3_1<< endl;
      
      
      cout << "L2 + G3 is: " << _1_L2_Plus_G3_4 << endl;
      cout << "L2 + G3 is: " << _1_L2_Plus_G3_3 << endl;
      cout << "L2 + G3 is: " << _1_L2_Plus_G3_2 << endl;
      cout << "L2 + G3 is: " << _1_L2_Plus_G3_1 << endl;
      
      double _2_L2_Plus_G3_4 = min4_4 + i3_2;
      double _2_L2_Plus_G3_3 = min4_3 + i3_3;
      double _2_L2_Plus_G3_2 = min4_2 + i3_4;
   
      
    
      if (_2_L2_Plus_G3_2 <= _2_L2_Plus_G3_3 && _2_L2_Plus_G3_2 <= _2_L2_Plus_G3_4)
          min3_2 = _2_L2_Plus_G3_2;
      else if(_2_L2_Plus_G3_3 <= _2_L2_Plus_G3_2 && _2_L2_Plus_G3_3 <= _2_L2_Plus_G3_4)
          min3_2 = _2_L2_Plus_G3_3;
      else if(_2_L2_Plus_G3_4 <= _2_L2_Plus_G3_2 && _2_L2_Plus_G3_4 <= _2_L2_Plus_G3_3)
          min3_2 = _2_L2_Plus_G3_4;
      
      cout << " min for 3_2 is: " << min3_2<< endl;
      
      cout << "L2 + G3 is: " << _2_L2_Plus_G3_4 << endl;
      cout << "L2 + G3 is: " << _2_L2_Plus_G3_3 << endl;
      cout << "L2 + G3 is: " << _2_L2_Plus_G3_2 << endl;
      
      double _3_L2_Plus_G3_4 = min4_4 + i3_3;
      double _3_L2_Plus_G3_3 = min4_3 + i3_4;
      
      if(_3_L2_Plus_G3_3 < _3_L2_Plus_G3_4)
           min3_3 = _3_L2_Plus_G3_3;
       else if( _3_L2_Plus_G3_4 < _3_L2_Plus_G3_3)
           min3_3 = _3_L2_Plus_G3_4;
      
      cout <<" min for 3_3 is: " << min3_3<< endl;
      
      
      cout << "L2 + G3 is: " << _3_L2_Plus_G3_4 << endl;
      cout << "L2 + G3 is: " << _3_L2_Plus_G3_3 << endl;
      
      double _4_L2_Plus_G3_4 = min4_4 + i3_4;
      min3_4 = _4_L2_Plus_G3_4;
      cout <<" min for 3_4 is: " << min3_4<< endl;
      cout << "L2 + G3 is: " << _4_L2_Plus_G3_4 << endl;
    
    
    
    
    
    // kolejna czesc
    //
    // test
    //
    
    
    double i2_0 = sqrt(Y4)*cost[1];
    double i2_1 = sqrt(Y3)*cost[1];
    double i2_2= sqrt(Y2)*cost[1];
    double i2_3= sqrt(Y1)*cost[1];
    double i2_4= sqrt(Y0)*cost[1];

    
    double _0_L1_Plus_G2_4 = min3_4 + i2_0;
    double _0_L1_Plus_G2_3 = min3_3 + i2_1;
    double _0_L1_Plus_G2_2 = min3_2 + i2_2;
    double _0_L1_Plus_G2_1 = min3_1 + i2_3;
    double _0_L1_Plus_G2_0 = min3_0 + i2_4;
    
    double min2_0;
    double min2_1;
    double min2_2;
    double min2_3;
    double min2_4;
    
    
    cout << endl << "next phase, road for C2" << endl << endl;
    if (_0_L1_Plus_G2_1 <= _0_L1_Plus_G2_2 && _0_L1_Plus_G2_1 <= _0_L1_Plus_G2_3 && _0_L1_Plus_G2_1 <= _0_L1_Plus_G2_4 && _0_L1_Plus_G2_1 <=_0_L1_Plus_G2_0)
            min2_0 = _0_L1_Plus_G2_1;
        else if (_0_L1_Plus_G2_2 <= _0_L1_Plus_G2_1 && _0_L1_Plus_G2_2 <= _0_L1_Plus_G2_3 && _0_L1_Plus_G2_2 <= _0_L1_Plus_G2_4 && _0_L1_Plus_G2_2 <=_0_L1_Plus_G2_0)
            min2_0 = _0_L1_Plus_G2_2;
        else if(_0_L1_Plus_G2_3 <= _0_L1_Plus_G2_2 && _0_L1_Plus_G2_3 <= _0_L1_Plus_G2_1 && _0_L1_Plus_G2_3 <= _0_L1_Plus_G2_4 && _0_L1_Plus_G2_3 <=_0_L1_Plus_G2_0 )
            min2_0 = _0_L1_Plus_G2_3;
        else if(_0_L1_Plus_G2_4<= _0_L1_Plus_G2_2 && _0_L1_Plus_G2_4 <= _0_L1_Plus_G2_3 && _0_L1_Plus_G2_4<= _0_L1_Plus_G2_1 && _0_L1_Plus_G2_4 <=_0_L1_Plus_G2_0)
            min2_0 = _0_L1_Plus_G2_4;
        else if(_0_L1_Plus_G2_0 <= _0_L1_Plus_G2_2 && _0_L1_Plus_G2_0 <= _0_L1_Plus_G2_3 && _0_L1_Plus_G2_0 <= _0_L1_Plus_G2_1 && _0_L1_Plus_G2_0 <=_0_L1_Plus_G2_4)
            min2_0 = _0_L1_Plus_G2_0;

    
    cout << " min for 3_0 is: " << min2_0<< endl;
    
    
       cout << "L1 + G2 is: " << _0_L1_Plus_G2_4 << endl;
       cout << "L1 + G2 is: " << _0_L1_Plus_G2_3 << endl;
       cout << "L1 + G2 is: " << _0_L1_Plus_G2_2 << endl;
       cout << "L1 + G2 is: " << _0_L1_Plus_G2_1 << endl;
       cout << "L1 + G2 is: " << _0_L1_Plus_G2_0 << endl;
       

       
       
       
       
       double _1_L1_Plus_G2_4 = min3_4 + i2_1;
       double _1_L1_Plus_G2_3 = min3_3 + i2_2;
       double _1_L1_Plus_G2_2 = min3_2 + i2_3;
       double _1_L1_Plus_G2_1 = min3_1 + i2_4;
       
       
       if (_1_L1_Plus_G2_1 <= _1_L1_Plus_G2_2 && _1_L1_Plus_G2_1 <= _1_L1_Plus_G2_3 && _1_L1_Plus_G2_1 <= _1_L1_Plus_G2_4)
           min2_1 = _1_L1_Plus_G2_1;
       else if (_1_L1_Plus_G2_2 <= _1_L1_Plus_G2_1 && _1_L1_Plus_G2_2 <= _1_L1_Plus_G2_3 && _1_L1_Plus_G2_2 <= _1_L1_Plus_G2_4)
           min2_1 = _1_L1_Plus_G2_2;
       else if(_1_L1_Plus_G2_3 <= _1_L1_Plus_G2_2 && _1_L1_Plus_G2_3 <= _1_L1_Plus_G2_1 && _1_L1_Plus_G2_3 <= _1_L1_Plus_G2_4)
           min2_1 = _1_L1_Plus_G2_3;
       else if(_1_L1_Plus_G2_4<= _1_L1_Plus_G2_2 && _1_L1_Plus_G2_4 <= _1_L1_Plus_G2_3 && _1_L1_Plus_G2_4<= _1_L1_Plus_G2_1)
           min2_1 = _1_L1_Plus_G2_4;
    
    cout << " min for 3_1 is: " << min2_1<< endl;
      
      
      cout << "L1 + G2 is: " << _1_L1_Plus_G2_4 << endl;
      cout << "L1 + G2 is: " << _1_L1_Plus_G2_3 << endl;
      cout << "L1 + G2 is: " << _1_L1_Plus_G2_2 << endl;
      cout << "L1 + G2 is: " << _1_L1_Plus_G2_1 << endl;
      
      double _2_L1_Plus_G2_4 = min3_4 + i2_2;
      double _2_L1_Plus_G2_3 = min3_3 + i2_3;
      double _2_L1_Plus_G2_2 = min3_2 + i2_4;
   
      
    
      if (_2_L1_Plus_G2_2 <= _2_L1_Plus_G2_3 && _2_L1_Plus_G2_2 <= _2_L1_Plus_G2_4)
          min2_2 = _2_L1_Plus_G2_2;
      else if(_2_L1_Plus_G2_3 <= _2_L1_Plus_G2_2 && _2_L1_Plus_G2_3 <= _2_L1_Plus_G2_4)
          min2_2 = _2_L1_Plus_G2_3;
      else if(_2_L1_Plus_G2_4 <= _2_L1_Plus_G2_2 && _2_L1_Plus_G2_4 <= _2_L1_Plus_G2_3)
          min2_2 = _2_L1_Plus_G2_4;
      
      cout << " min for 3_2 is: " << min2_2<< endl;
      
      cout << "L1 + G2 is: " << _2_L1_Plus_G2_4 << endl;
      cout << "L1 + G2 is: " << _2_L1_Plus_G2_3 << endl;
      cout << "L1 + G2 is: " << _2_L1_Plus_G2_2 << endl;
      
      double _3_L1_Plus_G2_4 = min3_4 + i2_3;
      double _3_L1_Plus_G2_3 = min3_3 + i2_4;
      
      if(_3_L1_Plus_G2_3 < _3_L1_Plus_G2_4)
           min2_3 = _3_L1_Plus_G2_3;
       else if( _3_L1_Plus_G2_4 < _3_L1_Plus_G2_3)
           min2_3 = _3_L1_Plus_G2_4;
      
      cout <<" min for 3_3 is: " << min2_3<< endl;
      
      
      cout << "L1 + G2 is: " << _3_L1_Plus_G2_4 << endl;
      cout << "L1 + G2 is: " << _3_L1_Plus_G2_3 << endl;
      
      double _4_L1_Plus_G2_4 = min3_4 + i2_4;
      min2_4 = _4_L1_Plus_G2_4;
      cout <<" min for 3_4 is: " << min2_4<< endl;
      cout << "L1 + G2 is: " << _4_L1_Plus_G2_4 << endl;
    
    
    
    
    // last phase
    //ttttest
    
    //test
    double min1_0;
    
    double i1_0 = sqrt(Y4)*cost[0];
    double i1_1 = sqrt(Y3)*cost[0];
    double i1_2= sqrt(Y2)*cost[0];
    double i1_3= sqrt(Y1)*cost[0];
    double i1_4= sqrt(Y0)*cost[0];
    
    double L0_Plus_G1_0 = min2_4 + i1_0;
    double L0_Plus_G1_1 =min2_3 + i1_1;
    double L0_Plus_G1_2 =min2_2 + i1_2;
    double L0_Plus_G1_3 =min2_1 + i1_3;
    double L0_Plus_G1_4 =min2_0 + i1_4;
    
    cout << endl << "next phase, road for C1" << endl << endl;
        if (L0_Plus_G1_1 <= L0_Plus_G1_2 && L0_Plus_G1_1 <= L0_Plus_G1_3 && L0_Plus_G1_1 <= L0_Plus_G1_4 && L0_Plus_G1_1 <=L0_Plus_G1_0)
                min1_0 = L0_Plus_G1_1;
            else if (L0_Plus_G1_2 <= L0_Plus_G1_1 && L0_Plus_G1_2 <= L0_Plus_G1_3 && L0_Plus_G1_2 <= L0_Plus_G1_4 && L0_Plus_G1_2 <=L0_Plus_G1_0)
                min1_0 = L0_Plus_G1_2;
            else if(L0_Plus_G1_3 <= L0_Plus_G1_2 && L0_Plus_G1_3 <= L0_Plus_G1_1 && L0_Plus_G1_3 <= L0_Plus_G1_4 && L0_Plus_G1_3 <=L0_Plus_G1_0 )
                min1_0 = L0_Plus_G1_3;
            else if(L0_Plus_G1_4<= L0_Plus_G1_2 && L0_Plus_G1_4 <= L0_Plus_G1_3 && L0_Plus_G1_4<= L0_Plus_G1_1 && L0_Plus_G1_4 <=L0_Plus_G1_0)
                min1_0 = L0_Plus_G1_4;
            else if(L0_Plus_G1_0 <= L0_Plus_G1_2 && L0_Plus_G1_0 <= L0_Plus_G1_3 && L0_Plus_G1_0 <= L0_Plus_G1_1 && L0_Plus_G1_0 <=L0_Plus_G1_4)
                min1_0 = L0_Plus_G1_0;
    
    cout <<"1: " <<L0_Plus_G1_1 <<endl;
    cout <<"2: " <<L0_Plus_G1_2 <<endl;
    cout <<"3: " <<L0_Plus_G1_3 <<endl;
    cout <<"4: " <<L0_Plus_G1_4 <<endl;
    cout <<"0: " <<L0_Plus_G1_0 <<endl;
    
    cout << endl << "min1_0 equals: " << min1_0 << endl ;
    
    
    
    
    
    cout << endl << endl << " \n So as a summary: \n Total cost of a road with a given C1-C6 costs equals: " << min1_0 << endl<< endl;
    
    
   
    return 0;
}
