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
    int finished_state[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};  
    struct queue q;
    struct game_state current = start;
    enqueue(&q, current);
    
    current = dequeue(&q);
    if (current.tiles != finished_state)
    {
        enqueue()
    }

    return current.num_steps;
}
