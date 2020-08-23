#include <iostream>
#include <string>
using namespace std;

const char Wall = '#', Road = '.';

char Maze[1001][1001];
unsigned H, W, Ch, Cw, Dh, Dw;

int
main()
{
  cin >> H >> W >> Ch >> Cw >> Dh >> Dw;
  for (size_t i = 1; i <= H; i++) {
    for (size_t j = 1; j <= W; j++) {
      cin >> Maze[i][j];
    }
  }

  for (size_t i = 0; i <= H; i++) {
    for (size_t j = 0; j <= W; j++) {
      cout << Maze[i][j] << "\t";
    }
    cout << "\n";
  }

  return 0;
}
