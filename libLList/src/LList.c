
#include <stdlib.h>
#include "LList.h"

struct Node
{
    Data data;
    NodePtr next;
};

/**
 * @brief Create a Node object
 */
static NodePtr createNode(const Data data)
{
    NodePtr node = malloc(sizeof(*node));
    if (node != NULL)
    {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

/**
 * @brief Delete a Node
 * @note node outputs as former note->next
 */
void deleteNode(NodePtr node)
{
    NodePtr aux = node->next;
    if (aux != NULL)
    {
        *node = *aux;
        free(aux);
    }
}

/**
 * @brief Get the Data from Node object
 */
Data getNodeData(const NodePtr node)
{
    return node->data;
}

/**
 * @brief Get the next Node object
 */
NodePtr getNodeNext(const NodePtr node)
{
    return node->next;
}

/**
 * @brief Push data to the head of a LList
 */
void pushLList(NodePtr *head, const Data data)
{
    NodePtr node = createNode(data);
    node->next = *head;
    *head = node;
}

/**
 * @brief Create a LList with data in the head
 */
NodePtr createLList(const Data data)
{
    return createNode(data);
}

/**
 * @brief Delete the entire LList from head
 */
void deleteLList(NodePtr head)
{
    while (head->next != NULL)
        deleteNode(head);
    free(head);
}

/**
 * @brief Print the LList starting from head
 */
void printLList(const NodePtr head)
{
    NodePtr aux = head;
    while (aux != NULL)
    {
        PRINT(PRINT_DATA_FORMAT, aux->data);
        aux = aux->next;
    }
}