#include "queue.h"
#include "tile_game.h"

bool comp_arrays(uint8_t[4][4], uint8_t[4][4]);
void add_tiles(struct tile_list, uint8_t[4][4]);
void tile_copy(uint8_t[4][4], uint8_t[4][4]);


struct tile_node
{
    uint8_t tile[4][4];
    struct tile_node* next;
};

struct tile_list
{
    struct tile_node* head;
};

void enqueue(struct queue *q, struct game_state state) 
{
    struct linked_list* list = &(q -> data);
    insert_at_head(list, serialize(state));
}

struct game_state dequeue(struct queue *q) 
{ 
    struct linked_list* list = &(q -> data);
    return deserialize(remove_from_tail(list));
}

bool comp_arrays(uint8_t arr1[4][4], uint8_t arr2[4][4])
{
    bool equals = true;
    for (int i = 0; i < 4 && equals; i++)
    {
        for (int j = 0; j < 4 && equals; j++)
        {
            if (arr1[i][j] != arr2[i][j]) {equals = false;}
        }
    }
    return equals;
}

void add_tiles(struct tile_list list, uint8_t tiles[4][4])
{
    struct tile_node* head = list.head;
    struct tile_node new_head = {.tile = NULL, .next = head};

    tile_copy(new_head.tile, tiles);
    head -> next = NULL;
}

void tile_copy(uint8_t target[4][4], uint8_t source[4][4])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            target[i][j] = source[i][j];
        }
    }
}

int number_of_moves(struct game_state start) 
{   
    uint8_t finished_state[4][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}};  
    struct queue q;
    q.data.head = NULL;
    struct game_state current = start;
    enqueue(&q, current);
     
    while (q.data.head != NULL)
    {
        current = dequeue(&q);
        bool equals = comp_arrays(finished_state, current.tiles);
        if (!equals)
        {
            struct game_state pre_move;
            pre_move = current;

            move_left(&current);
            if (!comp_arrays(current.tiles, pre_move.tiles)){

                    enqueue(&q, current);
            }
            
            current = pre_move; 
            move_right(&current);
            if (!comp_arrays(current.tiles, pre_move.tiles)){
                enqueue(&q, current);
            }
            
            current = pre_move;
            move_up(&current);
            if (!comp_arrays(current.tiles, pre_move.tiles)){
                enqueue(&q, current);
            }
            
            current = pre_move;
            move_down(&current);
            if (!comp_arrays(current.tiles, pre_move.tiles)){
                enqueue(&q, current);
            }
        }
        else 
        {
            break;
        }
    }
    return current.num_steps;
}
