#include "utils.h"

/**
 * TODO:   Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */
int **findPaths(graph_matrix *graph)
{
    for (int k = 0; k < graph->V; k++)
        for (int i = 0; i < graph->V; i++)
            for (int j = 0; j < graph->V; j++)
                if (graph->matrix[i][j] == 0&&i!=j)
                    graph->matrix[i][j] = graph->matrix[i][k] * graph->matrix[k][j];
    return graph->matrix;
}