#include <iostream>
#include <vector>
using namespace std;

bool getpathdfs(int **edges, int start, int end, int n, bool *visited,
                vector<int> &v) {
  if (start == end) {
      visited[start]=true;
    return true;
  }
  visited[start] = true;
  bool a = false;
  for (int i = 0; i < n; i++) {
    if (edges[start][i] == 1 and visited[i] == false) {
      a = a or getpathdfs(edges, i, end, n, visited, v);
    }
    if (a == true) {
      v.push_back(i);
      break;
    }
  }
  return a;
}

int main() {
  int v, e;
  cin >> v >> e;
  int **edges = new int *[v];
  for (int i = 0; i < v; i++) {
    edges[i] = new int[v];
    for (int j = 0; j < v; j++) {
      edges[i][j] = 0;
    }
  }
  for (int i = 0; i < e; i++) {
    int f, s;
    cin >> f >> s;
    edges[f][s] = 1;
    edges[s][f] = 1;
  }
  int start, end;
  cin >> start >> end;
  bool *visited = new bool[v];
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  vector<int> v1;
  if (getpathdfs(edges, start, end, v, visited, v1)) {
      v1.push_back(start);
    for (int i = 0; i < v1.size(); i++) {
      cout << v1[i] << " ";
    }
    cout << endl;
  }

  return 0;
}