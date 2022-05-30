#include <iostream>
#include <limits.h>
#include <set>
#include <stdint.h>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void readGraph(vector<vector<int>> &, unordered_map<int, char> &,
               unordered_map<char, int> &);
void printAdjacencyMatrix(vector<vector<int>>);
vector<vector<pair<int, int>>> djikstra(vector<vector<int>>, int, int);
vector<vector<char>> getShortestPaths(vector<vector<pair<int, int>>>, int, int);
void printDMNumbers(vector<vector<pair<int, int>>>);
void printDMChar(vector<vector<pair<int, int>>>, unordered_map<int, char>);

int main() {
  int n;
  cin >> n;
  unordered_map<int, char> int_to_char;
  unordered_map<char, int> char_to_int;
  vector<vector<int>> graph(n, vector<int>(n, -1));
  readGraph(graph, int_to_char, char_to_int);

  char origin, destiny;
  cin >> origin >> destiny;
  vector<vector<pair<int, int>>> dijkstra_matrix =
      djikstra(graph, char_to_int[origin], char_to_int[destiny]);

  printDMChar(dijkstra_matrix, int_to_char);

  /*
  vector<vector<char>> paths = getShortestPaths( dijkstra_matrix,
  char_to_int[origin], char_to_int[destiny]);

  for (auto path : paths) {
    for (auto number : path) {
      cout << int_to_char[number] << " ";
    }
    cout << destiny << endl;
  }
  */

  return 0;
}

void readGraph(vector<vector<int>> &graph, unordered_map<int, char> &v_m,
               unordered_map<char, int> &vertex_read) {

  char vertex_origin, vertex_destiny;
  int n, cost, vertex_counter = 0;
  cin >> n;
  cout << n << endl;
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
}

void printAdjacencyMatrix(vector<vector<int>> matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++) {
      cout << matrix[i][j] << "  ";
    }
    cout << endl;
  }
}

vector<vector<pair<int, int>>> djikstra(vector<vector<int>> graph, int origin,
                                        int destiny) {
  vector<pair<int, int>> initial_row(graph.size(), pair<int, int>(-1, -1));
  vector<vector<pair<int, int>>> dm;

  // inicializamos la matriz
  for (int i = 0; i < graph.size(); i++) {
    dm.push_back(initial_row);
  }

  dm[origin][0].first = 0;
  dm[origin][0].second = origin;

  pair<int, int> pair_compared = dm[origin][0];
  int vertex_compared = origin;

  set<int> visited;
  for (int p = 0; p < graph.size(); p++) {
    visited.insert(vertex_compared);
    int lower_value = INT_MAX;
    for (int vertex = 0; vertex < graph.size(); vertex++) {
      if (visited.find(vertex) == visited.end()) { // no se ha visitado
        if (graph[vertex][vertex_compared] != -1) {
          dm[vertex][p].first =
              graph[vertex][vertex_compared] + pair_compared.first;
          dm[vertex][p].second = vertex_compared;
        }
        if (dm[vertex][p].first < lower_value and dm[vertex][p].first != -1)
          lower_value = dm[vertex][p].first;
      }
    }
    for (int vertex = 0; vertex < graph.size(); vertex++) {
      //   cout << lower_value << endl;
      if (dm[vertex][p].first == lower_value) {
        pair_compared = dm[vertex][p];
        vertex_compared = vertex;
        if (p + 1 < graph.size())
          dm[vertex][p + 1] = pair_compared;
      }
    }
  }

  return dm;
}

void printDMNumbers(vector<vector<pair<int, int>>> dm) {
  for (int i = 0; i < dm.size(); i++) {
    for (int j = 0; j < dm.size(); j++) {
      cout << "(" << dm[i][j].first << "," << dm[i][j].second << ")";
    }
    cout << endl;
  }
}

void printDMChar(vector<vector<pair<int, int>>> dm,
                 unordered_map<int, char> int_to_char) {
  for (int i = 0; i < dm.size(); i++) {
    for (int j = 0; j < dm.size(); j++) {
      cout << "(" << dm[i][j].first << "," << int_to_char[dm[i][j].second]
           << ")";
    }
    cout << endl;
  }
}
