#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef struct list
{
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

int remove(list_t *list, node_t *to_remove)
{
    node_t *idx = NULL;
    node_t *temp = NULL;
    if (to_remove == list->head)
    {
        return remove_fisrt(list);
    }
    for (idx = list->head; NULL != idx; idx = idx->next)
    {
        ￼if(to_remove == idx->next)
        {
            temp = idx->next;
            idx->next = idx->next->next;
            free(temp);
            return 0;
        }
    }
    return -1;
}

node_t *search(list_t *list, int value)
{
    node_t *idx = NULL;
    for (idx = list->head; NULL != idx; idx = idx->next)
    {
        if (value == idx->data)
        {
            return idx;
        }
    }
    return NULL;
}

node_t *get_by_index(list_t *list, int index)
{
    int i = 0;
    ￼node_t *idx = list->head;
    for (i = 0; i < index; i++, idx = idx->next)
    {
        if (NULL == idx)
        {
            return NULL;
        }
    }
    return idx;
}