#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat de o matrice de adiacenta 
 * intr-unul reprezentat cu ajutorul listelor de adiacenta
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - Graful in reprezentarea liste de adiacenta
 */
graph_list *matrixToList(graph_matrix *graph)
{
    graph_list *g = (graph_list *)malloc(sizeof(graph_list));
    g->V = 0;
    g->E = 0;
    if (g == NULL)
    {
        printf(" no memory for this graph");
        return NULL;
    }
    g->listHeads = (node **)calloc(graph->V, sizeof(node *));
    // for (int i = 0; i < graph->V; i++)
    // {
    //     node *newnode = (node *)malloc(sizeof(node));
    //     newnode->vertexNr = i;
    //     newnode->next = NULL;
    //     g->listHeads[i] = newnode;
    //     node *p = g->listHeads[i];
    //     for (int j = 0; j < graph->V; j++)
    //         if (graph->matrix[i][j] == 1)
    //         {
    //             node *newnode1 = (node *)malloc(sizeof(node));
    //             newnode1->vertexNr = j;
    //             newnode1->next = NULL;
    //             p->next = newnode1;
    //             p = p->next;
    //             (g->E)++;
    //         }
    // }
    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (graph->matrix[i][j] == 1)
            {
                g->listHeads[i] = push_values(g->listHeads[i], j);
            }
        }
    }
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea matrice de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_matrix(graph_matrix **graph)
{
    for (int i = 0; i < ((*graph)->V); i++)
    {
        free((*graph)->matrix[i]);
    }
    free(graph);
}

node *push_values(node *root, int val)
{
    // nice to have; functie de adauga o valoare intr-o lista
    node *cop=root;
    node *newnode1 = (node *)malloc(sizeof(node));
    newnode1->vertexNr = val;
    newnode1->next = NULL;

    if (root == NULL)
    {
        root = newnode1;
        return root;
    }
    while (root->next)
    {
        root = root->next;
    }
    root->next = newnode1;
    return cop;
}

void print_graph_list(graph_list *graph)
{
    // nice to have; functie care afiseaza continutul unui graf reprezentat prin liste de adiacenta
}
