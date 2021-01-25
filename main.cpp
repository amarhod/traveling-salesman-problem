#include <random>
#include "main.h"
#include "greedy.h"
#include "k-opt.h"


void printRoute(vector<int> &route){
  for(int city: route){cout << city << endl;}
  return;
}

 //Eucledian distance between two points (rounded)
long distance(float x1, float y1, float x2, float y2){
  float dx = x2 - x1;
  float dy = y2 - y1;
  float distance = round(sqrt(dx*dx + dy*dy));
  if(distance == 0){
    distance = 500000;
  }
  return (long) distance;
}

long routeDistance(vector<int> &route, vector<vector<long>> &distances){
  long totalDistance = 0;
  for(long i = 0; i < route.size() - 1; i++){
      totalDistance += distances[route[i]][route[i+1]];
  }
  return totalDistance;
}

int main(int argc, char *argv[]) {
  //### READ INPUT ###
  
  freopen(argv[1], "r", stdin);
  int n;
  float x, y;
  cin >> n;
  if(n == 1){cout << 0 << endl;return 0;}
  float x_coordinates[n], y_coordinates[n];
  
  //Start timer for termination before 2s limit
  auto start = high_resolution_clock::now();
  
  vector<int> initCitys;
  vector<vector<int>> possibleRoutes;
  
  //Store input coordinates
  for(int i = 0; i < n; i++){
      cin >> x >> y;
      x_coordinates[i] = x;
      y_coordinates[i] = y;
      if(i < 100)
        initCitys.push_back(i);
  }
  
  //Randomize vector with starting cities
  random_device rd;
  mt19937 rng(rd());
  shuffle(initCitys.begin(), initCitys.end()+1, rng);

  long dist = 0;
  vector<vector<long>> distances(n,vector<long>(n)); 

  //calculate and store distances between all cities
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(j == i){distances[i][j] = 5000; continue;}
      dist = distance(x_coordinates[i], y_coordinates[i], x_coordinates[j], y_coordinates[j]);
      distances[i][j] = dist;
    }
  }
  
  int bestRoute = 0;
  long routeDist = 0;
  long shortestRouteDist = 10000000;
  vector<int> route;
  
  //Create a NN route for each starting city
  for(int initCity: initCitys){ 
    possibleRoutes.push_back(NN(distances, initCity, n));
  }
  
  //Optimize each route with 2- & 3-opt and keep track of the best one
  for(int i = 0; i < possibleRoutes.size(); i++){
    threeOpt(possibleRoutes[i], distances, start, n);
    twoOpt(possibleRoutes[i], distances, start, n);
    routeDist = routeDistance(possibleRoutes[i], distances);
    if(routeDist < shortestRouteDist){
      bestRoute = i;
      shortestRouteDist = routeDist;
    }
  }
  printRoute(possibleRoutes[bestRoute]);
  return 0;
}