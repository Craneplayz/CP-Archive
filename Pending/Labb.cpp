#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<string> grid(N, string(N,'a'));
  
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++)
      cin >> grid[i][j]; 

  int mid = (N >> 1);
  int lastX = (N >> 1), lastY = (N >> 1);
  cout << grid[mid][mid];
  for (int layer = 1; layer <= (N >> 1); layer++ ){
      int k = 2 * layer + 1;
      for (int i = 0; i < k-2; i++)
        cout << grid[lastX-i][lastY-layer];

      for (int i = 0; i < k; i++)
        cout << grid[lastX - k + 2][lastY - layer + i];

      for (int i = 0; i < k - 2; i++)
        cout << grid[lastX-i][lastY+layer];

      for (int i = 0; i < k; i++)
        cout << grid[lastX + k - 2][lastY + layer - i];

    //   lastX = mid + layer;
    //   lastY--;
  }
  
  return 0;
}