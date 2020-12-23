#include <stdio.h>

#define MAX_SIZE 1000

int node, edge, start;
int matrix[MAX_SIZE+1][MAX_SIZE+1];
int dfs_visit[MAX_SIZE+1], bfs_visit[MAX_SIZE+1];
int queue[MAX_SIZE];

void dfs(int now);
void bfs(int start);

//main///////////////////////////////////////////

int main(){
	int row, col;

	scanf("%d %d %d", &node, &edge, &start);

	for(int i=0; i<edge; i++){
		scanf("%d %d", &row, &col);
		matrix[row][col] = matrix[col][row] = 1; //undirect
	}

	dfs(start);
	printf("\n");
	bfs(start);
	printf("\n");

	return 0;
}


//function///////////////////////////////////////

void dfs(int now){ //recursion --> add start, print

	dfs_visit[now] = 1;

	printf("%d ", now);

	for(int j=1; j<=node; j++){
		int next = j;
		if(matrix[now][next]){ //yes link
			if(!(dfs_visit[next])){ //no visit
				dfs_visit[next] = 1;
				dfs(next);
			}
		}
	}
}

void bfs(int start){

	bfs_visit[start] = 1;
	int front = 0, rear = -1;
	queue[++rear] = start; //Enqueue

	while(front <= rear){
		int now = queue[front++]; //Dequeue
		printf("%d ", now);

		for(int j=1; j<=node; j++){
			int next = j;
			if(matrix[now][next]){ //yes link
				if(!(bfs_visit[next])){ //no visit
					bfs_visit[next] = 1;
					queue[++rear] = next;
				}
			}
		}
	}
}
