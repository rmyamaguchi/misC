
#include "LList.h"

int main(void)
{
    int len = 10;
    Data del = 7;

    NodePtr aux, head = createLList(0);

    for (int i = 1; i < len; i++)
    {
        printLList(head);
        PRINT("\r\n");
        pushLList(&head, i);
    }
    printLList(head);
    PRINT("\r\n");

    aux = head;
    do
        aux = getNodeNext(aux);
    while (aux != NULL && getNodeData(aux) != del);
    if (aux != NULL)
        deleteNode(aux);
    printLList(head);

    deleteLList(head);
}