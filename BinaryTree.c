#include"BinaryTree.h"

struct node{
  int data;
  Node* pright;
  Node* pleft;
};

int CreateNode(Node** p, int data){
  (*p) = (Node*)malloc(sizeof(Node));
		
  if(*p == NULL){
    return FALSE;
  }
  else{
    (*p)->data = data;
    (*p)->pright = NULL;
    (*p)->pleft = NULL;
  }

  return TRUE;
}

/* less will insert left, greater and equals will insert right */
int InsertNode(Node* root, int data){
  Node* p;
  if(!CreateNode(&p, data)){
    puts("Initialize pointer failed!");
        
    return FALSE;
  }
  
  if(data >= root->data){
    if(root->pright != NULL){
      InsertNode(root->pright, data);	
    }
    else{
      root->pright = p;
    }
  }
  else{
    if(root->pleft != NULL){
      InsertNode(root->pleft, data);
    }
    else{
      root->pleft = p;
    }
  }

  return TRUE;
}

/* max value of tree will be right outer */
Node* MaxNodeValue(const Node* root){
  const Node* p;

  p = root;
  while(p->pright != NULL){
    p = p->pright;	
  }

  return p;
}

/* Min value of tree will be left outer */
Node* MinNodeValue(const Node* root){
  const  Node* p;
  
  p = root;
  while(p->pleft != NULL){
    p = p->pleft;
  }

  return p;
}

/* search data if found it will true contrary */
int SearchNode(const Node* root, int data){
  const Node* p = NULL;

  p = root;	
  while(p != NULL){
    if(p->data == data){
      return TRUE;
    }
    else{
      if(data > p->data){
        p = p->pright;
      }
      else{
        p = p->pleft;
      }
    }
  }
  
  return FALSE;
}

/* use 2 pointer if found, it will return tmp, contrary it will return NULL */
Node* SearchParent(const Node* root, int data){
  const Node* p;
  const Node* tmp;

  p = root;
  while(p != NULL){
    if(p->data == data){
      return p;
    }
    else{
      tmp = p;
      if(data > p->data){
        p = p->pright;
      }
      else{
        p = p->pleft;
      }
    }
  }

  return NULL;
}

/* similar search node but it will return node */
Node* SearchChild(const Node* root, int data){
  const Node* p;

  p = root;	
  while(p != NULL){
    if(p->data == data){
      break;
    }
    else{
      if(data > p->data){
        p = p->pright;
      }
      else{
        p = p->pleft;
      }
    }
  }

  return p;
}

/* use recursive to count node */
int CountNode(const Node* root){
  const Node* p;
  int count = 1;
  
  p = root;
  if(p->pleft != NULL){
    count = count + CountNode(p->pleft);
  }	

  if(p->pright != NULL){
    count = count + CountNode(p->pright);
  }
  
  return count;
}

/* use recuresive to sum node */
long SumValueTree(const Node* root){
  const Node* p;

  int sum = root->data;
  if(p->pleft != NULL){
    sum = sum + SumValueTree(p->pleft);
  }

  if(p->pright != NULL){
    sum = sum + SumValueTree(p->pright);
  }

  return sum;
}

/* use recuresive to destroy tree */
void DeleteTree(Node* root){
  if(root->pleft != NULL){
    DeleteTree(root->pleft);
  }

  if(root->pright != NULL){
    DeleteTree(root->pright);
  }

  if(root->pright == NULL && root->pleft == NULL){
    free(root);
  }
}

int HighTree(const Node* root){
  Node* p;
  int i, j, rs;

  i = j = 0;

  p = root;
  while(p != NULL){
    i++;
    p = p->pright;
  }

  p = root;
  while(p != NULL){
    j++;
    p = p->pleft;
  }

  rs = (i>j?i:j) - 1;

  return rs;
}
