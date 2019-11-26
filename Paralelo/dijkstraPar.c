#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>

#define N 10

int main (int argc, char **argv);
int *dijkstra(int **graph);
void findLower(int s, int e, int minDistance[N], int connected[N], int *distance, int *vertex);
void matrix(int **graph);
void minDis(int s, int e, int mv, int connected[N], int **graph, int minDistance[N]);

int main(int argc, char **argv){

    int i;
    int inf = 2147483647;
    int j;
    int *minDistance;
    int **graph =(int **)malloc(N * sizeof(int *)); 
        for (int x=0; x<N; x++) 
        graph[x] = (int *)malloc(N * sizeof(int));

    // método que crea la matriz
    matrix(graph);

// IMPRIME LA MATRIZ
//   fprintf ( stdout, "\n" );
//   fprintf ( stdout, "  Distancia:\n" );
//   fprintf ( stdout, "\n" );
//   for ( i = 0; i < N; i++ )
//   {
//     for ( j = 0; j < N; j++ ) {
//       if ( graph[i][j] == inf ){
//         fprintf ( stdout, "  Inf" );
//       }else{
//         fprintf ( stdout, "  %3d", graph[i][j] );
//       }
//     }
//     fprintf ( stdout, "\n" );
//   }


    double start = omp_get_wtime();
    minDistance = dijkstra(graph); 
    double end = omp_get_wtime();
    printf("\n");
    printf("%f milisegundos\n\n", (end - start)*1000); 
    printf("%f segundos\n\n", (end - start)); 

// IMPRIMIR LOS RESULTADOS
  fprintf ( stdout, "\n" );
  fprintf ( stdout, "  Distancias mínimas 0:\n");
  fprintf ( stdout, "\n" );
  for ( i = 0; i < N; i++ ){
    fprintf ( stdout, "  %2d  %2d\n", i, minDistance[i] );
  }
    printf("\n");

  free(minDistance);

  return 0;
}

void matrix(int **graph){

    int i, j;
    int inf = 2147483647;

    for (i = 0; i < N; i++){
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

int *dijkstra(int **graph) {

  int *conexion, *minDistance;
  int i, minD, minV, LminD, LminV, step, first_thread, last_thread, node, nth;
  int inf = 2147483647;

  conexion = (int*)malloc(N*sizeof(int));
  conexion[0] = 1;
  for (i = 1; i < N; i++){
    conexion[i] = 0;
  }

  minDistance = (int*)malloc(N*sizeof(int));
  for (i = 0; i < N; i++){
    minDistance[i] = graph[0][i];
  }

    #pragma omp parallel private (first_thread, node, last_thread, LminD, LminV, step) shared(conexion, minD, minDistance, minV, nth, graph)
    {
        node = omp_get_thread_num();
        nth = omp_get_num_threads(); 
        first_thread = (node* N)/nth;
        last_thread = ((node + 1) * N)/nth - 1;

        fprintf (stdout, "  P%d:  Primer valor=%d  Último valor=%d\n", node, first_thread, last_thread);

        for (step = 1; step < N; step++){
            #pragma omp single 
            {
                minD = inf;
                minV = -1; 
            }

            findLower(first_thread, last_thread, minDistance, conexion, &LminD, &LminV);

            #pragma omp critical
            {
                if (LminD < minD){
                minD = LminD;
                minV = LminV;
                }
            }

            #pragma omp barrier

            #pragma omp single 
            {
                if (minV != -1){
                conexion[minV] = 1;
                }
            }

            if(minV != -1){
                minDis(first_thread, last_thread, minV, conexion, graph, minDistance);
            }

            #pragma omp barrier
        }

    }

    free(conexion);
    return minDistance;

}

void findLower(int s, int e, int minDistance[N], int conexion[N], int *distance, int *vertex){

    int i;
    int inf = 2147483647;

    *distance = inf;
    *vertex = -1;

    #pragma omp parallel for schedule(runtime)
    for(i = s; i <= e; i++){
        if(!conexion[i] && (minDistance[i] < *distance)){
        *distance = minDistance[i];
        *vertex = i;
        }
    } // end for

  return;

}

void minDis(int s, int e, int minV, int conexion[N], int **graph, int minDistance[N]){

  int i;
  int inf = 2147483647;

  #pragma omp parallel for schedule(runtime)
  for(i = s; i <= e; i++){
    if(!conexion[i]){
        if(graph[minV][i] < inf){
            if(minDistance[minV] + graph[minV][i] < minDistance[i]){
                minDistance[i] = minDistance[minV] + graph[minV][i];
        }
      }
    }
  }
  return;
}