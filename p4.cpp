//PRACTICA 3 VOLCÁN 
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAXN = 505;
const int MAXL = 6;
int N;
int height[MAXN][MAXN];
bool visited[MAXN][MAXN][MAXL];
struct Cell {
    int row, col, lavaHeight, seconds;
};
bool isValid(int row, int col, int lavaHeight) {
    return row >= 0 && row < N && col >= 0 && col < N && !visited[row][col][lavaHeight];
}
int escapeTime() {
    memset(visited, false, sizeof(visited));
    queue<Cell> q;
    q.push({0, 0, 0, 0});
    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();
        int row = curr.row;
        int col = curr.col;
        int lavaHeight = curr.lavaHeight;
        int seconds = curr.seconds;
        if (row == N - 1 && col == N - 1) {
            return seconds;
        }
        if (lavaHeight >= height[row][col]) {
            continue;
        }
        visited[row][col][lavaHeight] = true;
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int newRow = row + dr[i];
            int newCol = col + dc[i];
            int newLavaHeight = (lavaHeight + 1) % (MAXL - 1);

            if (isValid(newRow, newCol, newLavaHeight)) {
                q.push({newRow, newCol, newLavaHeight, seconds + 1});
            }
        }
    }
    return -1;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> height[i][j];
        }
    }
    int time = escapeTime();
    cout << time << endl;
    return 0;
}