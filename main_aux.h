#ifndef SP_EX_2_MAIN_AUX_H
#define SP_EX_2_MAIN_AUX_H

#endif

int input_invalid(const int *heap_index, int tokens_to_remove, const int *heap_sizes, int num_of_heaps);
void print_game_board(int heap_sizes[], int num_of_heaps, int turn_num);
void print_winner(int turn_num);
void initialize_game(int *num_of_heaps, int heap_sizes[]);
void play_game(int heap_sizes[], int num_of_heaps, int turn_num);
