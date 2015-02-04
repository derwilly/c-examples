typedef void (*freeFunction)(void *);

typedef struct Node
{
    void *data;
    struct Node *next;
    freeFunction freeFn;
} Node;

typedef struct List
{
    Node *first;
    Node *last;
    Node *ptr;
    int elements;
    freeFunction fnPtr;
} List;

List *createList();
void clearList(List *list);
void removeNode(List *list, Node *node);
void pushNode(List *list, void *data);
void popNode(List *list);
int countNodes(List *list);
