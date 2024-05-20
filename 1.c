#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int vertex_count;
    int **matrix;
}GraphMatrix;

GraphMatrix *initialize_graph(int vertices){
    GraphMatrix *graph = malloc(sizeof(GraphMatrix));
    graph->vertex_count = vertices;
    graph->matrix = malloc(vertices * sizeof(int*));

    for(int i = 0; i < vertices; i++){
        graph->matrix[i] = malloc(sizeof(int) * vertices);
        for(int j = 0; j < vertices; j++){
            if(i == j){
                graph->matrix[i][j] = -1;
            } else {
                graph->matrix[i][j] = 0;
            }
        }
    }
    return graph;
}

int insert_edge(GraphMatrix* graph, int src, int dest){
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
    return 0;
}

int display_graph(GraphMatrix *graph){
    for(int i = 0; i < graph->vertex_count; i++){
        printf("%d: ", i);
        for(int j = 0; j < graph->vertex_count; j++){
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int main(){
    GraphMatrix *graph = initialize_graph(6);
    display_graph(graph);
    insert_edge(graph, 0, 1);
    insert_edge(graph, 0, 5);
    insert_edge(graph, 1, 2);
    insert_edge(graph, 1, 3);
    insert_edge(graph, 3, 4);
    insert_edge(graph, 4, 5);
    display_graph(graph);

    return 0;
}
