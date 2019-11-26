#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define N 10

int main(int argc, char **argv);
int *dijkstra(int **graph);
void findLower(int minDistance[N], int conexion[N], int *distance, int *vertex);
void matrix(int **graph);
void minDis(int minV, int conexion[N], int **graph, int minDistance[N]);

int main(int argc, char **argv)
{
    int i;
    int inf = 2147483647;
    int j;
    int *minDistance = 0;
    int **graph = (int **)malloc(N * sizeof(int *)); 
        for (int x=0; x<N; x++) 
        graph[x] = (int *)malloc(N * sizeof(int));

    // método que crea la matriz
    matrix(graph);

    // fprintf ( stdout, "\n" );
    // fprintf ( stdout, "  Matriz:\n" );
    // fprintf ( stdout, "\n" );

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (graph[i][j] == inf){
                fprintf ( stdout, "  Inf" );
            } else {
                fprintf ( stdout, "  %3d", graph[i][j] );
            }
        } // end fot
        fprintf ( stdout, "\n" );
    } // end for

    clock_t t; 
    t = clock(); 
    minDistance = dijkstra(graph);
    t = clock() - t; 
    double wtime = ((double)t)/CLOCKS_PER_SEC;
    printf ( "%8f milisegundos\n", wtime*1000); 
    printf ( "%8f segundos \n", wtime); 

    fprintf(stdout, "\n");
    fprintf(stdout, "  Distancia mínima del nodo 0:\n");
    fprintf(stdout, "\n");
    for (i = 0; i < N; i++) {
        fprintf(stdout, "  %2d  %2d\n", i, minDistance[i]);
    }
    printf("\n");

    free(minDistance);

    return 0;
}

void matrix(int **graph) {

    int i;
    int inf = 2147483647;
    int j;

    for (i = 0; i < N; i++)  {
        for (j = 0; j < N; j++) {
            if (rand()%2 == 1){
                graph[i][j] = rand() % N;
            } else {
                graph[i][j] = inf;
            }
        }
    }

    for (int i = 0; i < N; i++){
        graph[i][i] = 0;
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            graph[j][i] = graph[i][j];

  return;
}

int *dijkstra(int **graph){

    int *conexion, *minDistance;
    int i, j, md, minV, my_step;

    conexion = (int *)malloc(N *sizeof(int));
    conexion[0] = 1;
    for (i = 1; i < N; i++) {
        conexion[i] = 0;
    }

    minDistance = (int*)malloc(N*sizeof(int));
    for (i = 0; i < N; i++){
        minDistance[i] = graph[0][i];
    }

    for (my_step = 1; my_step < N; my_step++ ) {
        findLower(minDistance, conexion, &md, &minV);

        if (minV == - 1){
            break;
        }

        conexion[minV] = 1;

        minDis(minV, conexion, graph, minDistance);
    }

    free(conexion);

    return minDistance;
}

void findLower(int minDistance[N], int conexion[N], int *d, int *v){

    int i;
    int inf = 2147483647;

    *d = inf;
    *v = -1;

    for (i = 0; i < N; i++){
        if (!conexion[i] && (minDistance[i] < *d)){
            *d = minDistance[i];
            *v = i;
        }
    } // end for

  return;

} 

void minDis(int minV, int conexion[N], int **graph, int minDistance[N]){

    int i;
    int inf = 2147483647;

    for (i = 0; i < N; i++){
        if (!conexion[i]){
            if (graph[minV][i] < inf){
                if (minDistance[minV] + graph[minV][i] < minDistance[i]){
                    minDistance[i] = minDistance[minV] + graph[minV][i];
                }
            }
        }
    }
    return;
}