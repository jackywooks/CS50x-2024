#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
} node;

int main (int argc, char *argv[])
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            free(n);
            return 1;
        }

        n->number = number;
        n->next = list;
        list = n;


    }

    // Print whole list
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr->number);
        ptr = ptr->next;
    }

    // free the memory of the list
    node *tmp = list;
    node *counter = list;
    while (tmp != NULL)
    {
        counter = tmp;
        tmp = tmp->next;
        free(counter);
    }

}
