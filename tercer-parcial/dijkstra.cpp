#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

void readGraph(vector<vector<int>> &, unordered_map<int, char> &,
               unordered_map<char, int> &);
void printAdjacencyMatrix(vector<vector<int>>);
vector<vector<pair<int, int>>> djikstra(vector<vector<int>>);
vector<vector<char>> getShortestPaths(vector<vector<pair<int, int>>>, int, int);

int main() {
  int n;
  cin >> n;
  unordered_map<int, char> int_to_char;
  unordered_map<char, int> char_to_int;
  vector<vector<int>> graph(n, vector<int>(n, -1));
  readGraph(graph, int_to_char, char_to_int);
  char origin, destiny;
  cin >> origin >> destiny;
  vector<vector<pair<int, int>>> dijkstra_matrix = djikstra(graph);
  vector<vector<char>> paths =
      getShortestPaths(dijkstra_matrix, origin, destiny);

  for (auto path : paths) {
    for (auto number : path) {
      cout << int_to_char[number] << " ";
    }
    cout << destiny << endl;
  }

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

vector<vector<pair<int, int>>> djikstra(vector<vector<int>> graph) {}
