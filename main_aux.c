#include <stdio.h>
#include <stdlib.h>
#include "sp_nim.h"

int input_invalid(const int *heap_index, int tokens_to_remove, const int *heap_sizes, int num_of_heaps) {
    if (*heap_index < 1 || *heap_index > num_of_heaps || heap_sizes[*heap_index - 1] < tokens_to_remove) {
        return 1;
    } else {
        return 0;
    }
}

void print_game_board(int heap_sizes[], int num_of_heaps, int turn_num) {
    int heap_i;
    printf("In turn %d heap sizes are:", turn_num);
    for (heap_i = 0; heap_i < num_of_heaps; heap_i++) {
        printf(" h%d=%d", heap_i + 1, heap_sizes[heap_i]);
    }
    printf(".\n");
}

void initialize_game(int *num_of_heaps, int heap_sizes[]) {
    int heap_i = 0;
    int curr_heap_size;
    printf("Enter the number of heaps:\n");
    scanf("%d", num_of_heaps);
    if (*num_of_heaps < 1 || *num_of_heaps > 32) {
        printf("Error: the number of heaps must be between 1 and 32.\n");
        exit(1);
    }
    printf("Enter the heap sizes:\n");
    for (heap_i = 0; heap_i < *num_of_heaps; heap_i++) {
        scanf("%d", &curr_heap_size);
        if (curr_heap_size < 1) {
            printf("Error: the size of heap %d should be positive.\n", heap_i);
            exit(1);
        }
        heap_sizes[heap_i] = curr_heap_size;
    }
}

void print_winner(int turn_num) {
    if (turn_num % 2 == 0) { /*the heaps were emptied on an odd turn, so the user is the winner*/
        printf("You win!\n");
        exit(0);
    } else { /*the heaps were emptied on an even turn, so the computer is the winner*/
        printf("Computer wins!\n");
        exit(0);
    }
}

void play_game(int heap_sizes[], int num_of_heaps, int turn_num) {
    while (!check_for_winner(heap_sizes, num_of_heaps)) {
        print_game_board(heap_sizes, num_of_heaps, turn_num); /*prints the status of the heaps*/
        if (turn_num % 2 == 1) { /*user plays first - so user plays on odd turns*/
            user_turn(heap_sizes, num_of_heaps);
        } else {
            computer_turn(heap_sizes, num_of_heaps);
        }
        turn_num = turn_num + 1;
    }
}
