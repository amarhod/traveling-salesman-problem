#include "k-opt.h"
#include "main.h"


void twoOpt(vector<int> &route, vector<vector<long>> &distances, high_resolution_clock::time_point start, int n){
  long change;
  auto durationValue = 0;
  bool better = true;
  while(durationValue < 1700000 && better == true){
    better = false;
    long minChange = 0;
    for(int i = 1; i < n; i++){
      for(int j = i+1; j < n; j++){
        change = distances[route[i-1]][route[j % n]] + distances[route[i]][route[(j+1) % n]] - distances[route[i-1]][route[i]] - distances[route[j % n]][route[(j+1) % n]];
        if(change < 0){
          reverse(begin(route)+i, begin(route)+j+1);
          better = true;
        }
      }
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    durationValue = duration.count();
  }
  return;
}

void threeOpt(vector<int> &route, vector<vector<long>> &distances, high_resolution_clock::time_point start, int n){
  vector<int> newRoute;
  long dist[5];
  int a, flip;
  int count = 0;
  long newDistance, bestDistance;
  bool better = true;
  bool breakLoops = false;
  while(count < 1000000 && better == true){
    better = false;
    bestDistance = routeDistance(route, distances);
    int shortest;
    for(int i = 0; i < n; i++){
      if(breakLoops == true){breakLoops = false; continue;}
      time_point stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      auto durationValue = duration.count();
      if(durationValue > 1400000){count = 100000; break;}
      for(int j = i+2; j < n-2; j++){
        if(breakLoops == true)
          break;
        for(int k = j+2; k < n-2; k++){
        int cityA = route[i];
        int cityB = route[(i+1)%n];
        int cityC = route[j];
        int cityD = route[(j+1)%n];
        int cityE = route[k];
        int cityF = route[(k+1)%n];

        dist[0] = distances[cityA][cityB] + distances[cityC][cityD] + distances[cityE][cityF];
        dist[1] = distances[cityA][cityC] + distances[cityB][cityD] + distances[cityE][cityF];
        dist[2] = distances[cityA][cityB] + distances[cityC][cityE] + distances[cityD][cityF];
        dist[3] = distances[cityA][cityD] + distances[cityE][cityB] + distances[cityC][cityF];
        dist[4] = distances[cityF][cityB] + distances[cityC][cityD] + distances[cityE][cityA];

      shortest = 0;
      for(int w = 1; w < 5; w++){
        if(dist[w] < dist[shortest]){
          shortest = w;
        }
      }
      flip = i;
        if(shortest == 0){
          count++;
          continue;
        }else if(shortest == 1){
          reverse(begin(route)+i+1, begin(route)+j+1);
        }else if(shortest == 2){
          reverse(begin(route)+j+1, begin(route)+k+1);
        }else if(shortest == 4){
          reverse(begin(route)+i, begin(route)+k+2);
        }else{
          newRoute = route;
          for(int m = j; m < k; m++) {
            newRoute[flip] = route[m];
            flip++;
          }
          for(int m = i; m < j; m++){
            newRoute[flip] = route[m];
            flip++;
          }
          route = newRoute;
        }
      better = true;
      breakLoops = true;
      break;
      }
    }
  }
  count++;
  }
  return;
}
