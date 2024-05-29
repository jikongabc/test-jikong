#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath> 
#include <unordered_map>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
typedef pair<double, int> PDI;
const int N = 2005;
int x[N], y[N];
double dist[N][N];
int n;

struct Edge{
    int a, b;
    double w;
} edges[N * N / 2];

bool cmp(Edge a,Edge b){
    return a.w < b.w;
}

double get_dist(int x,int y,int x2,int y2){
    return (double)sqrt((LL)(x - x2) * (x - x2) +(LL) (y - y2) * (y - y2));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> x[i] >> y[i];
    }
    int cnt = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(i==j)
                continue;
            dist[i][j] = get_dist(x[i], y[i], x[j], y[j]);
        }
    }
    for (int i = 0; i < n-1;i++){
        for (int j = i+1; j < n;j++){
            edges[cnt++] = {i, j, get_dist(x[i], y[i], x[j], y[j])};
        }
    }
    sort(edges, edges + cnt, cmp);
    LL res = 0;
    LL c = 0;
    for (int i = 0; i < cnt-1;i++){
        int j = i + 1;
        while(edges[j].w==edges[i].w){
            if(edges[i].a==edges[j].a && edges[i].w *2> dist[edges[i].b][edges[j].b]){
                if(edges[i].w==dist[edges[i].b][edges[j].b])
                    c++;
                else
                    res++;
            }
            if(edges[i].b==edges[j].b && edges[i].w *2> dist[edges[i].a][edges[j].a]){
                if (edges[i].w == dist[edges[i].a][edges[j].a])
                    c++;
                else
                    res++;
            }
            if(edges[i].a==edges[j].b && edges[i].w *2> dist[edges[i].b][edges[j].a]){
                if (edges[i].w == dist[edges[i].b][edges[j].a])
                    c++;
                else
                    res++;
            }
            if(edges[i].b==edges[j].a && edges[i].w *2> dist[edges[i].a][edges[j].b]){
                if (edges[i].w == dist[edges[i].a][edges[j].b])
                    c++;
                else
                    res++;
            }
            j++;
        }
    }
    res += c / 3;
    cout << res;
    return 0;
}