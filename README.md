## Traveling Salesman Problem
Solves the TSP for 2D euclidiean coordinates with the distances rounded off.

### Input
Expects the input to begin with the number of vertices (N) followed by the coordinate for each city.
```
10
95.0129 61.5432
23.1139 79.1937
60.6843 92.1813
48.5982 73.8207
89.1299 17.6266
76.2097 40.5706
45.6468 93.5470
1.8504 91.6904
82.1407 41.0270
44.4703 89.3650
```
### Output
Outputs the best route based on Nearest Neighbour construction algorithm and 2- & 3-OPT.
```
4
5
8
0
2
6
9
3
1
7
```

### Compilation
```
g++ -g -O2 -std=gnu++17 -static -o main main.cpp greedy.cpp k-opt.cpp
```

### Run
```
./main INPUTFILE
```