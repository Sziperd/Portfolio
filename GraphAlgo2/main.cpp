//
//  main.cpp
//  GraphAlgo2
//
//  Created by Patryk Piwowarczyk on 12/05/2022.
//


#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;



void f()
{
    string line;
    while(getline(cin, line))  //input from the file in.txt
    {
        cout << line << "\n";   //output to the file out.txt
    }
}
void print(vector<vector<double>> dist, vector<vector<int>> next, int iterationNum) {
  cout << "(First pair num, Distance, Path)" << endl;
    int o = 0;
    
  const auto size = std::size(next);
  for (auto i = 0; i < size; ++i) {
    for (auto j = 0; j < size; ++j) {
      if (i != j) {
        auto u = i + 1;
        auto v = j + 1;
          //printing the path
          o++;
          cout << endl << "Number of route:"<< o << endl;
        cout << "(" << u << " -> " << v << ", " << dist[i][j]
          << ", ";
        stringstream path;
        path << u;
        do {
          u = next[u - 1][v - 1];
          path << " -> " << u;
        } while (u != v);
        cout << path.str() << ")" << endl;
          
      }
    }
  }
    cout << endl << "Number of iterations needed: "<< iterationNum << endl;
}
 
void GraphAlgo(vector<vector<int>> w_s, const int verticeNum) {
  vector<vector<double>> dist(verticeNum);
    int iterationNum = 0;
  for (auto& dim : dist) {
    for (auto i = 0; i < verticeNum; ++i) {
        //then insert inf (below)
      dim.push_back(INT_MAX);
    }
  }
  for (auto& v : w_s) {
    dist[v[0] - 1][v[1] - 1] = v[2];
  }
    //basic algorithm, comparing longer distance (more vertices) road with closer ones by means of weights of each path. If the longer wins it saves it and keeps comparing it to even longer ones up untill it compares it to every single one.
    
  vector<vector<int>> next(verticeNum);
  for (auto i = 0; i < verticeNum; ++i) {
    for (auto j = 0; j < verticeNum; ++j) {
      next[i].push_back(0);
    }
    for (auto j = 0; j < verticeNum; ++j) {
      if (i != j) {
        next[i][j] = j + 1;
      }
    }
  }
    //comparisons...
  for (auto k = 0; k < verticeNum; ++k) {
      
      
    for (auto i = 0; i < verticeNum; ++i) {
      for (auto j = 0; j < verticeNum; ++j) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
          next[i][j] = next[i][k];
            iterationNum++;
        }
      }
    }
  }
    //and then it prints everything
  print(dist, next, iterationNum);
}
int main() {
   

    vector< vector<int> > v;
   
        string sFileName = "/Users/patrykpiwowarczyk/Desktop/studia/AADS/GraphAlgo2/GraphAlgo2/g10.txt";
    ifstream fileStream(sFileName);
    string line;
    while(getline(fileStream, line, '\n')) {
          stringstream ss(line);
          vector<int> numbers;
          string in_line;
          while(getline (ss, in_line, ' ')) {
            numbers.push_back(stoi(in_line, 0));
          }
          v.push_back(numbers);
      }
    //read_data(fileStream, v, 9, 3);
    //print_data(v, 9, 3);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j];
        }
    }
    
    
  int verticeNum = 10;
    freopen("/Users/patrykpiwowarczyk/Desktop/studia/AADS/GraphAlgo2/GraphAlgo2//output.txt","w",stdout);
       cout<<"writing in file" << endl;
    
  GraphAlgo(v, verticeNum);

    
    
    
  return 0;
}
