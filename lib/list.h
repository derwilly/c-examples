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
    int elements;
    freeFunction fnPtr;
} List;

List *createList();
void appendNode(List *list, void *data);
void removeNode(List *list, Node *node);
