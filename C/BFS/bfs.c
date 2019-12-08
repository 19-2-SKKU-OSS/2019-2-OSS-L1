#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define SIZE 50
//in C, there is no <queue> header file
//so we must add function about Queue
typedef struct Queue{ 
	int items[SIZE];
       	int front; 
	int rear; 
}Queue;

typedef struct Graph{
       	int numOfVertex;
       	int **matrix;
       	int *visited;
}Graph;

Queue* createQueue(){ 
	Queue* newQueue = (Queue*)malloc(sizeof(Queue));
       	newQueue->front = -1;
       	newQueue->rear = -1;
       	return newQueue; 
}
int isFull(Queue* queue){
        if(queue->front = 0 && queue->rear == SIZE - 1)
                return 1;
        else
                return 0;
}
int isEmpty(Queue* queue){
        if(queue->rear == -1)
                return 1;
        else
                return 0;
}

void enQueue(Queue* queue, int data){ 
       	if(isFull(queue)){ 
		return; 
       	}
       	else{ 
		if(queue->front == -1){ 
			queue->front = 0;
	       	} 
		queue->rear++;
	       	queue->items[queue->rear] = data; 
	}
}
int deQueue(Queue* queue){ 
	int item = 0;
       	if(isEmpty(queue)) 
		return 1;
       	else{
	       	if(queue->front >= queue->rear){ 
		       	queue->front = -1;
		       	queue->rear = -1; 
	       	} 
	       	item = queue->items[queue->front]; 
	       	queue->front++; 
	} 
	printf("Dequeue : %d\n", item);
       	return item;
} 
Graph* makeGraph(int numOfVertex){
       	int i=0; Graph *graph = (Graph*)malloc(sizeof(Graph)*numOfVertex);
       	graph->matrix = (int**)malloc(sizeof(int*)*numOfVertex); 
	graph->visited = (int*)malloc(sizeof(int)*numOfVertex); 
	graph->numOfVertex = numOfVertex; 
	for(i=0; i<numOfVertex; i++){ 
		graph->matrix[i] = (int*)malloc(sizeof(int)*numOfVertex); 
		memset(graph->matrix[i], 0, sizeof(int)*numOfVertex); 
		graph->visited[i] = 0; 
	} 
	return graph; 
} 
void addEdge(Graph* graph, int start, int end){
       	graph->matrix[start][end] = 1;
       	graph->matrix[end][start] = 1;
}
void printGraph(Graph *graph) {
       	int i, j; 
	for (i = 0; i < graph->numOfVertex; i++) { 
		printf("start %d ->", i); 
		for (j = 0; j < graph->numOfVertex; j++) { 
			printf("%d ", graph->matrix[i][j]); 
		} 
		printf("\n"); 
	} 
} 
void BFS(Graph* graph, int vertex){ 
	Queue* queue = createQueue(); 
	int i=0; 
	enQueue(queue, vertex); 
	printf("%d visited \n", vertex); 
	while(!isEmpty(queue)){ 
		vertex = deQueue(queue); 
		for(i=vertex; i<graph->numOfVertex; i++){ 
			if(!graph->visited[i] && graph->matrix[vertex][i] == 1){ 				graph->visited[i] = 1; 
				enQueue(queue, i); 
				printf("%d visited \n", i); 
			} 
		} 
	} 
} 
int main(void) { 
	Graph *graph; graph = makeGraph(8); 
	addEdge(graph, 0, 1); 
	addEdge(graph, 0, 2); 
	addEdge(graph, 1, 3); 
	addEdge(graph, 1, 4); 
	addEdge(graph, 3, 7);
       	addEdge(graph, 4, 7);
       	addEdge(graph, 2, 5);
       	addEdge(graph, 2, 6);
       	addEdge(graph, 6, 7);
       	addEdge(graph, 5, 7);
       	printGraph(graph);
       	BFS(graph, 0);
       
	return 0; 
}
