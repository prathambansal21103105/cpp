#include <climits>
#include <iostream>

using namespace std;

void primsalgo(int v, int e, int **adj, bool visited[], int weight[],
               int parent[]) {
  int curr = 0;
  int n = v-1;
  while (n > 0) {
    visited[curr] = true;
    for (int i = 0; i < v; i++) {
      if (adj[curr][i] != 0 and i != curr and visited[i]==false) {
        if (weight[i] > adj[curr][i]) {
          //   cout<<curr<<" "<<i<<" "<<weight[i]<<endl;
          weight[i] = adj[curr][i];
          parent[i] = curr;
        }
      }
    }
    // for (int i = 0; i < v; i++) {
    //   cout << weight[i] << endl;
    // }
    int min1 = INT_MAX;
    int index1 = 0;
    for (int i = 0; i < v; i++) {
      if (weight[i] < min1 and visited[i] == false) {
        min1 = weight[i];
        index1 = i;
      }
    }
    curr = index1;
    n -= 1;
  }
  for (int i = 1; i < v; i++) {
      if(i<parent[i]){
        cout << i << " " << parent[i] << " " << weight[i] << endl;
        if(parent[parent[i]]==i){
            visited[parent[i]]=false;
        }
      }
      else{
        cout << parent[i] << " " << i << " " << weight[i] << endl;
      }
  }
}

int main() {
  int v, e;
  cin >> v >> e;

  int **adj = new int *[v];
  for (int i = 0; i < v; i++) {
    adj[i] = new int[v];
    for (int j = 0; j < v; j++) {
      adj[i][j] = 0;
    }
  }
  int parent[v];
  parent[0] = 0;
  for (int i = 1; i < v; i++) {
    parent[i] = -1;
  }
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adj[a][b] = c;
    adj[b][a] = c;
  }
  bool visited[v];
  for (int i = 0; i < v; i++) {
    visited[i] = false;
  }
  int weight[v];
  weight[0] = INT_MAX;
  for (int i = 1; i < v; i++) {
    weight[i] = INT_MAX;
  }
  primsalgo(v, e, adj, visited, weight, parent);
  return 0;
}