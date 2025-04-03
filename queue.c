#include "queue.h"
#include "tile_game.h"

void enqueue(struct queue *q, struct game_state state) 
{
    struct linked_list list = q -> data;
    insert_at_tail(&list, serialize(state));
}

struct game_state dequeue(struct queue *q) 
{ 
    struct linked_list list = q -> data;
    return deserialize(remove_from_head(&list));
    // return (struct game_state){0}; 
}

int number_of_moves(struct game_state start) 
{ 
    return 0; 
}
