#include "main_aux.h"

# define N 32

int main() {
    int heap_sizes[N];
    int num_of_heaps;
    int turn_num = 1;

    initialize_game(&num_of_heaps, heap_sizes);
    play_game(heap_sizes, num_of_heaps, turn_num);
    print_winner(turn_num);
	return 0;
}
