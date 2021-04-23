#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
graph_matrix *listToMatrix(graph_list *graph)
{
    graph_matrix *g = (graph_matrix *)calloc(1, sizeof(graph_matrix));
    g->V = graph->V;
    g->E = graph->E;
    if (g == NULL)
    {
        printf(" no memory for this graph");
        return NULL;
    }
    g->matrix = (int **)calloc(graph->V, sizeof(int *));
    for (int i = 0; i < graph->V; i++)
    {
        g->matrix[i] = (int *)calloc(graph->V, sizeof(int));
        for (int j = 0; graph->listHeads[i] != NULL; j++)
        {
            g->matrix[i][graph->listHeads[i]->vertexNr] = 1;
            graph->listHeads[i] = graph->listHeads[i]->next;
        }
    }
    return g;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_list(graph_list **graph)
{
    node *aux;
    for (int i = 0; i < (*graph)->V; i++)
    {
        // aux1 = *graph->listHeads[i];
        while ((*graph)->listHeads[i])
        {
            aux = (*graph)->listHeads[i];
            (*graph)->listHeads[i] = (*graph)->listHeads[i]->next;
            free(aux);
        }
        // free(aux1);
    }
    free(*graph);
    *graph=NULL;
}

void print_graph_matrix(graph_matrix *graph)
{
    // nice to have; functie de afiseaza continutul unui graf reprezentat prin matrice de adiacenta
}