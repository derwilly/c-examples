/* Ferdinand Saufler <mail@saufler.de>
 * 10.03.2015
 * a simple implementation of a linked list */

typedef void (*freeFunction)(void *);

typedef struct Node
{
    void *data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *first;
    Node *last;
    Node *ptr;
    int elements;
    freeFunction DeleteFnPtr;
} List;

List *createList();
void clearList(List *list);
void removeNode(List *list, Node *node);
void pushNode(List *list, void *data);
void popNode(List *list);
int countNodes(List *list);
