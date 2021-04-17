#include <stdio.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct list {
    node_t *head;
} list_t;

int insert(list_t *list, int data)
{
    node_t *new_node = (node_t *)malloc(sizeof(node_t));
    if (NULL == new_node)
    {
        return -1;
    }
    new_node->data = data;
    ￼new_node->next = list->head;
    list->head = new_node;
    return 0;
}

int remove_first(list_t *list)
{
    node_t *temp = list->head->next;
    free(list->head);
    list->head = temp;
    return 0;
}