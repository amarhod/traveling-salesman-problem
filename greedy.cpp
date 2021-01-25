#include <random>
#include "greedy.h"
using namespace std;


 vector<int> NN(vector<vector<long>> &distances, int startingCity, int n){
  bool visited[n];
  for(int i = 0; i < n; i++){visited[i] = false;}
  int best = -1;
  long newDistance, bestDistance;
  vector <int> NNRoute;
  NNRoute.push_back(startingCity);
  visited[startingCity] = true;
  for(int i = 1; i < n; i++){
    best = -1;
    for(int j = 0; j < n; j++){
      newDistance = distances[NNRoute[i-1]][j];
      if(!visited[j] && (best == -1 || (newDistance < distances[NNRoute[i-1]][best]))){
        best = j;
        bestDistance = newDistance;
      }
    }
    if(best != -1){
    visited[best] = true;
    NNRoute.push_back(best);
    }
  }
  return NNRoute;
 }
