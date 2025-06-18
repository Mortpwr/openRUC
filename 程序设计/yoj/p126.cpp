/*#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int array[10][10] = {};
int flag[10][10] = {};
int count[10000] = {};
int k = 0;
int n, m;
int x[3] = {1, -1, 0};
int y[3] = {0, 0, 1};
void dfs(int mx, int my){
    if(mx == m && my == n){
        count[k] += array[mx][my];
        k++;
        return;
    }
    else{
        for(int i = 0; i < 3; ++i){
            int nx = mx + x[i];
            int ny = my + y[i];
            if(nx > 0 && nx <= m && ny > 0 && ny <= n && !flag[nx][ny]){
                count[k] += array[nx][ny];
                flag[nx][ny] = 1;
                dfs(nx, ny);
                flag[nx][ny] = 0;
                count[k] -= array[nx][ny];
            }
        }
    }
}
int main(){
    int max = -0x7ffffff;
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            scanf("%d", &array[i][j]);
        }
    }
    dfs(1, 1);
    for(int i = 0; i < 10000; ++i){
        if(count[i] > max) max = count[i];
    }
    printf("%d", max);
return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 8
#define INF -100000

int grid[MAXN][MAXN];        // 存储棋盘上的宝物数
bool visited[MAXN][MAXN];    // 标记格子是否已经访问
int max_treasure = INF;      // 全局变量，记录最大宝物数
int n, m;                    // 棋盘的大小

// 深度优先搜索函数
void dfs(int x, int y, int current_sum) {
    // 如果到达终点，更新最大宝物数
    if (x == n && y == m) {
        if (current_sum > max_treasure) {
            max_treasure = current_sum;
        }
        return;
    }

    // 定义方向数组，分别表示右、下、左的移动
    int directions[3][2] = {{0, 1}, {1, 0}, {0, -1}};

    // 遍历三个方向
    for (int i = 0; i < 3; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];

        // 检查边界条件和是否已访问
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny]) {
            visited[nx][ny] = true;  // 标记当前格子已访问
            dfs(nx, ny, current_sum + grid[nx - 1][ny - 1]);
            visited[nx][ny] = false; // 回溯，标记当前格子未访问
        }
    }
}

int main() {
    // 读取棋盘大小
    scanf("%d %d", &n, &m);

    // 读取棋盘中的宝物数
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
        }
    }

    // 初始化起点
    visited[1][1] = true; // 起点 (1,1) 标记为已访问
    dfs(1, 1, grid[0][0]); // 从 (1,1) 开始递归搜索

    // 输出结果
    printf("%d\n", max_treasure);

    return 0;
}
