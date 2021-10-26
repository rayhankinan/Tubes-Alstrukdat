#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef int ElTypeNode;
typedef struct node* Address;
typedef struct node {
    ElTypeNode info;
    Address next;
} Node;

#define INFO_NODE(p) (p)->info
#define NEXT_NODE(p) (p)->next

Address newNode(ElTypeNode val);

#endif