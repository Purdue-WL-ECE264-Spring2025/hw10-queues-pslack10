#include "linked_list.h"

#include <stdlib.h>

struct list_node *new_node(size_t value) 
{
  struct list_node *node = malloc(sizeof(struct list_node));

  node -> value = value;
  node -> next = NULL;

  return node; 
}

void insert_at_head(struct linked_list *list, size_t value) 
{
  struct list_node* new_head = new_node(value);

  new_head -> next = list -> head;
  list -> head = new_head;
}

void insert_at_tail(struct linked_list *list, size_t value) 
{
  struct list_node* new_tail = new_node(value);
  struct list_node* node = list -> head;

  while (node -> next != NULL)
  {
    node = node -> next;
  }

  node -> next = new_tail;
}

size_t remove_from_head(struct linked_list *list) 
{ 
  size_t removed_value = list -> head -> value;

  struct list_node* removed_head = list -> head;
  list -> head = list -> head -> next;
  free(removed_head);

  return removed_value; 
}

size_t remove_from_tail(struct linked_list *list) 
{ 
  struct list_node* current = list -> head;
  struct list_node* previous = NULL;

  while (current -> next != NULL)
  {
    previous = current;
    current = current -> next;
  }

  size_t removed_value = current -> value;
  if (previous == NULL)
  {
    list -> head = NULL;
  }
  else
  {
    previous -> next = NULL;
  }
  
  free(current);
  return removed_value; 
}

void free_list(struct linked_list list) 
{
  struct list_node* node = list.head;

  while (node != NULL)
  {
    struct list_node* next_node = node -> next;
    free(node);
    node = next_node;
  }
}

// Utility function to help you debugging, do not modify
void dump_list(FILE *fp, struct linked_list list) {
  fprintf(fp, "[ ");
  for (struct list_node *cur = list.head; cur != NULL; cur = cur->next) {
    fprintf(fp, "%zu ", cur->value);
  }
  fprintf(fp, "]\n");
}
