#include <stdio.h>

#define INF 999999999

int n, e;
int node[1001][1001];
int dist[1001];
int visit[1001];

int dijkstra(int start, int end){
	dist[start] = 0;

	for(int t=1; t<=n; t++){
		int min = INF;
		int min_v;
		for(int i=1; i<=n; i++){
			if(visit[i] == 0 && min > dist[i]){
				min = dist[i];
				min_v = i;
			}
		}
		visit[min_v] = 1; // visit check

		for(int j=1; j<=n; j++){ // Relaxation
			if(dist[j] > (dist[min_v] + node[min_v][j]))
				dist[j] = dist[min_v] + node[min_v][j];
		}
	}
	return dist[end];
}

int main(){
	int u, v, w;
	int start, end;

	scanf("%d", &n);
	scanf("%d", &e);

	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++)
			node[i][j] = INF;
		dist[i] = INF; // distance init
		visit[i] = 0; // no visit
	}
	
	for(int i=0; i<e; i++){
		scanf("%d %d %d", &u, &v, &w);
		node[u][v] = w;
	}
	
	scanf("%d %d", &start, &end);
	printf("%d\n", dijkstra(start, end));

	return 0;
}
