#include <stdio.h>
# include "main_aux.h"

void wait_for_valid_user_turn(const int *heap_sizes, int num_of_heaps, int *heap_index, int *tokens_to_remove) {
    while (input_invalid(heap_index, *tokens_to_remove, heap_sizes, num_of_heaps)) {
        printf("Error: Invalid input.\nPlease enter again the heap index and the number of removed objects.\n");
        scanf("%d", heap_index);
        scanf("%d", tokens_to_remove);
    }
}

int check_for_winner(int heaps[], int num_of_heaps) {
    /* there is a winner if all heaps are empty*/
    int i;
    for (i = 0; i < num_of_heaps; i++) {
        if (heaps[i] > 0) {
            return 0; /* means that there is a non empty heap. */
        }
    }
    return 1;
}

int computer_turn(int heap_sizes[], int number_of_heaps) {
    int nim_sum; /* the nim_sum is defined to be the result of the XOR operation on all heaps */
    int i;
    int heap_index;
    int tokens_to_remove;
    int minimum;
    nim_sum = heap_sizes[0];
    /* calculating the nim_sum value in this turn */
    for (i = 1; i < number_of_heaps; i++) {
        nim_sum = nim_sum ^ heap_sizes[i];
    }
    if (nim_sum != 0) {
        /*  find the minimum i such that (the size of the heap)XOR(nim_sum)<(the size of the heap) */
        for (i = 0; i < number_of_heaps; i++) {
            if ((heap_sizes[i] ^ nim_sum) < heap_sizes[i]) {
                minimum = i;
                break;
            }
        }
        heap_index = minimum;
        tokens_to_remove = heap_sizes[minimum] - (heap_sizes[minimum] ^ nim_sum);
    } else {
        for (i = 0; i < number_of_heaps; i++) {
            if (heap_sizes[i] > 0) {
                minimum = i;
                break;
            }
        }
        heap_index = minimum;
        tokens_to_remove = 1;
    }
    printf("Computer takes %d objects from heap %d.\n", tokens_to_remove, heap_index);
    heap_sizes[heap_index] = heap_sizes[heap_index] - tokens_to_remove;
    return 0;
}

int user_turn(int heap_sizes[], int num_of_heaps) {
    int heap_index;
    int tokens_to_remove;
    printf("Your turn: please enter the heap index and the number of removed objects.\n");
    scanf("%d", &heap_index);
    scanf("%d", &tokens_to_remove);
    wait_for_valid_user_turn(heap_sizes, num_of_heaps, &heap_index, &tokens_to_remove);
    printf("You take %d objects from heap %d.\n", tokens_to_remove, heap_index);
    heap_sizes[heap_index - 1] = heap_sizes[heap_index - 1] - tokens_to_remove;
    return 0;
}