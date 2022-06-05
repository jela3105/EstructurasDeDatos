#include <iostream>
#include <limits.h>
#include <limits>
#include <unordered_map>
#include <vector>

#define infinite 1000
using namespace std;

void readGraph(vector<vector<int>> &, unordered_map<int, char> &,
               unordered_map<char, int> &);

void printMatrix(vector<vector<int>>);
void initializeRoutes(vector<vector<int>> &);
void floyd(vector<vector<int>> &, vector<vector<int>> &);

int main() {
  int n;
  cin >> n;
  unordered_map<int, char> int_to_char;
  unordered_map<char, int> char_to_int;
  vector<vector<int>> graph(n, vector<int>(n, infinite));
  vector<vector<int>> routes(n, vector<int>(n, infinite));
  readGraph(graph, int_to_char, char_to_int);
  printMatrix(graph);
  vector<vector<int>> costs = graph;
  initializeRoutes(routes);
  floyd(costs, routes);
  cout << endl;
  printMatrix(costs);
  cout << endl;
  printMatrix(routes);
}

void readGraph(vector<vector<int>> &graph, unordered_map<int, char> &v_m,
               unordered_map<char, int> &vertex_read) {

  char vertex_origin, vertex_destiny;
  int n, cost, vertex_counter = 0;
  cin >> n;
  // cout << n << endl;
  for (int i = 0; i < n; i++) {
    cin >> vertex_origin;
    if (vertex_read.find(vertex_origin) == vertex_read.end()) {
      vertex_read[vertex_origin] = vertex_counter;
      v_m[vertex_counter] = vertex_origin;
      vertex_counter++;
    }
    cin >> vertex_destiny;
    if (vertex_read.find(vertex_destiny) == vertex_read.end()) {
      vertex_read[vertex_destiny] = vertex_counter;
      v_m[vertex_counter] = vertex_destiny;
      vertex_counter++;
    }
    cin >> cost;
    graph[vertex_read[vertex_origin]][vertex_read[vertex_destiny]] = cost;
    graph[vertex_read[vertex_destiny]][vertex_read[vertex_origin]] = cost;
  }
  for (int i = 0; i < graph.size(); i++) {
    for (int j = 0; j < graph.size(); j++) {
      if (i == j)
        graph[i][j] = 0;
    }
  }
}

void printMatrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      matrix[i][j] == infinite ? cout << "i\t" : cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void initializeRoutes(vector<vector<int>> &routes) {
  for (int i = 0; i < routes.size(); i++) {
    for (int j = 0; j < routes.size(); j++) {
      routes[j][i] = i;
    }
  }
  for (int i = 0; i < routes.size(); i++) {
    for (int j = 0; j < routes.size(); j++) {
      if (i == j)
        routes[i][j] = infinite;
    }
  }
}

void floyd(vector<vector<int>> &costs, vector<vector<int>> &routes) {
  for (int compared = 0; compared < costs.size(); compared++) {
    for (int i = 0; i < costs.size(); i++) {
      if (i == compared)
        continue;
      for (int j = 0; j < costs.size(); j++) {
        if (j == compared)
          continue;
        int cost = costs[i][compared] + costs[compared][j];
        if (cost < costs[i][j]) {
          costs[i][j] = cost;
          routes[i][j] = compared;
        }
      }
    }
  }
}
