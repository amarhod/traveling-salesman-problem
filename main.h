#pragma once

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <chrono> 
#include <stdlib.h>
#include <time.h>

using namespace std::chrono; 
using namespace std;


void printRoute(vector<int> &route);
long distance(float x1, float y1, float x2, float y2);
long routeDistance(vector<int> &route, vector<vector<long>> &distances);
