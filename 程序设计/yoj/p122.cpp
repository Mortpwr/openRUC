#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
int n, m;
int visited[10][10] = {};
int s[10][10] = {};
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int dfs(int x, int y) {
    if (x == n-1 && y == m-1) {
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && s[nx][ny] == 1) {
            visited[nx][ny] = 1;
            if (dfs(nx, ny)) {
                return 1;
            }
        }
    }
    return 0;
}
int main(){
    int ok = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &s[i][j]);
        }
    }     
    ok = dfs(0, 0);
    if(ok) printf("YES");
    else printf("NO");
return 0;
}