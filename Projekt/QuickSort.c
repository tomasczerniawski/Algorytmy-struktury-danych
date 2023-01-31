#include <stdio.h>
#include <stdlib.h>
  

struct wezel
{
    int data;
    struct wezel *next;
    struct wezel *prev;
};
  

void swap ( int* a, int* b )
{ int t = *a; *a = *b; *b = t; }
  

struct wezel *lastNode(struct wezel *root)
{
    while (root && root->next)
        root = root->next;
    return root;
}
  

struct wezel* przegroda(struct wezel *l, struct wezel *h)
{
 
    int x = h->data;
  
   
    struct wezel *i = l->prev;
  
    
    for (struct wezel *j = l; j != h; j = j->next)
    {
        if (j->data <= x)
        {
          
            i = (i == NULL) ? l : i->next;
  
            swap(&(i->data), &(j->data));
        }
    }
    i = (i == NULL) ? l : i->next; 
    swap(&(i->data), &(h->data));
    return i;
}
  

void _quickSort(struct wezel* l, struct wezel *h)
{
    if (h != NULL && l != h && l != h->next)
    {
        struct wezel *p = przegroda(l, h);
        _quickSort(l, p->prev);
        _quickSort(p->next, h);
    }
}
  


void quickSort(struct wezel *head)
{
 
    struct wezel *h = lastNode(head);
  
    
    _quickSort(head, h);
}
  

void printList(struct wezel *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
  

void push(struct wezel** head_ref, int new_data)
{
    struct wezel* new_node = (struct wezel*) 
               malloc(sizeof(struct wezel)); 
    new_node->data = new_data;
  
   
    new_node->prev = NULL;
  
    
    new_node->next = (*head_ref);
  
   
    if ((*head_ref) != NULL) (*head_ref)->prev = new_node ;
  
   
    (*head_ref) = new_node;
}
  

int main(int argc, char **argv)
{
    struct wezel *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
  
    printf("Linked List before sorting \n");
    printList(a);
  
    quickSort(a);
  
    printf("Linked List after sorting \n");
    printList(a);
  
    return 0;
}
