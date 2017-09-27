#ifndef BinaryTree_H 
#define BinaryTree_H

#include"stdio.h"
#include"stdlib.h"

#define TRUE 1
#define FALSE  0

typedef struct node Node;

//Intialize
int CreateNode(Node**, int );
int InsertNode(Node*, int);

//Work
Node* MaxNodeValue(const Node*);
Node* MinNodeValue(const Node*);
int SearchNode(const Node*, int);
Node* SeachParent(const Node*, int);
Node* SearchChild(const Node*, int);
int CountNode(const Node*);
long SumValueTree(const Node*);
int HighTree(const Node*);

//Delete
void DeleteTree(Node*);

#endif
