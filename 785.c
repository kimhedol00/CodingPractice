#include <stdio.h>
#include <stdbool.h>

bool isBipartite(int** graph, int graphSize, int* graphColSize){
	int8_t sides[graphSize];	//-1 : left, 0 : undefined, 1 : right
	memset( &sides, 0, sizeof (sides) );

	for (int i = 0; i < graphSize; i += 1){
		if (sides[i] != 0){
			continue;
		}

		int curSide = -1;

		int bfsQueue[graphSize];
		int get = 0, set = 0;

		sides[i] = curSide;
		bfsQueue[set] = i;
		set += 1;

		do {
			curSide = -curSide;
			for (int remain = set - get; remain > 0; remain -= 1){
				const int cur = bfsQueue[get];
				get += 1;

				for (int j = 0; j < graphColSize[cur]; j += 1){
					const int next = graph[cur][j];

					if (sides[next] == -curSide){
						return false;
					}

					if (0 == sides[next]){
						sides[next] = curSide;
						bfsQueue[set] = next;
						set += 1;
					}
				}
			}
		}while (get < set);
	}

	return true;
}

/*
Best Solution
bool DFS(int** graph, int graphSize, int* graphColSize, int depth[], int i, int parent){
    bool oddCycle = false;
    for(int j = 0; j < graphColSize[i]; j++){
        if(graph[i][j] == parent)
            continue;
        //printf("%d ", graph[i][j]);
        if(depth[graph[i][j]] != -1){
            int cycle = abs(depth[graph[i][j]] - depth[i]);
            if(cycle > 1 && (cycle % 2 == 0))
                return true;
            continue;
        }
        depth[graph[i][j]] = depth[i] + 1;
        oddCycle |= DFS(graph, graphSize, graphColSize, depth, graph[i][j], i);
    }
    return oddCycle;
}
bool isBipartite(int** graph, int graphSize, int* graphColSize){

    int depth[graphSize];
    for(int i = 0; i < graphSize; i++)
        depth[i] = -1;
    for(int i = 0; i < graphSize; i++){
        if(depth[i] != -1)
            continue;
        depth[i] = 0;
        bool flag = DFS(graph, graphSize, graphColSize, depth, i, -1);
        if(flag)
            return false;
        //printf("\n");
    }
    return true;
}
*/