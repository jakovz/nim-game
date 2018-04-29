#ifndef SP_EX_2_SP_NIM_H
#define SP_EX_2_SP_NIM_H

#endif
int check_for_winner(int heaps[], int num_of_heaps);
int computer_turn(int heap_sizes[], int number_of_heaps);
int user_turn(int heap_sizes[], int num_of_heaps);
void wait_for_valid_user_turn(const int *heap_sizes, int num_of_heaps, int *heap_index, int *tokens_to_remove);