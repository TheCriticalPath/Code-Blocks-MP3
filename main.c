/*
 *File: main.c
 *Machine Problem 3 implements a game of Nim
 *Author: Ashley Bauer
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

void print_greeting();
void print_scoreboard(int human_score, int computer_score);
int play_nim(int starting_player);
void get_computer_move(int heap1, int heap2, int heap3, char* chosen_heap, int* number_removed);
bool user_wishes_to_continue();

int main()
{
    int human_score = 0;
    int computer_score = 0;
    int starting_player = 1;
    bool wishes_to_continue = true;
    int winner;

    print_greeting();
    while(wishes_to_continue)
    {
        winner = play_nim(starting_player);
        if(winner == 1)
        {
            human_score++;
            printf("Player 1 wins!");
        }
        else if(winner == 2)
        {
            computer_score++;
            printf("Player 2 wins!");
        }
        print_scoreboard(human_score, computer_score);
        wishes_to_continue = user_wishes_to_continue();
    }
    return 0;
}

void print_greeting() /* prints the greeting for the user at the beginning of the game */
{
    printf("Welcome to the Ancient Game of Nim\n");
    printf("\n");
    printf("Player 1 is you (the human)\n");
    printf("Player 2 is me (the computer)\n");
}

void print_scoreboard(int human_score, int computer_score) /* prints out the current number of human wins and computer wins */
{
    printf("\n***********\n");
    printf("Current Score:\n");
    printf("Player 1 (Human):    %d\n", human_score);
    printf("Player 2 (Computer): %d\n", computer_score);
}

int play_nim(int starting_player) /* plays an entire single game of Nim with starting player going first */
{
    int heap_a = 5;
    int heap_b = 4;
    int heap_c = 3;
    char chosen_heap;
    int number_removed;
    int player_turn;
    int bad;

    player_turn = starting_player;

    if(starting_player == 1)
    {
        printf("Player 1 goes first this time!\n");
    }
    else
    {
        printf("Player 2 goes first this time!\n");
    }
    // This should be AND not OR.  You could add up the heap counts and see if the total = 0.
    while((heap_a != 0 || heap_b != 0 || heap_c != 0) == true)
    {
        if(player_turn == 1)
        {
            printf("Player 1\n");
            printf("Heaps:\n");
            printf("A: %d\n", heap_a);
            printf("B: %d\n", heap_b);
            printf("C: %d\n", heap_c);
            printf("Enter the letter of the heap and number of objects to remove:");
            scanf(" %c%d", &chosen_heap, &number_removed);
            chosen_heap = tolower(chosen_heap);



        if (number_removed <= 0){ // check the number removed first for > 0.
            bad = 1;
        }
        else if((chosen_heap == 'a') && (number_removed <= heap_a))
        {
            bad = 0;
        }else if((chosen_heap == 'b') && (number_removed <= heap_b))
        {
            bad = 0;
        }
        else if((chosen_heap == 'c') && (number_removed <= heap_c))
        {
            bad = 0;
        }else{
            bad = 1;
        }
//        if(chosen_heap == 'a' || chosen_heap == 'b' || chosen_heap == 'c')
//        {
//            bad = 0;
//        }
//        else
//        {
//            bad = 1;
//        }
//        if((number_removed > 0) && (number_removed <= heap_a || number_removed <= heap_b || number_removed <= heap_c))
//        {
//            bad = 0;
//        }
//        else
//        {
//            bad = 1;
//        }
        while(bad == 1)
        {
            printf("Illegal move! Try again.\n");
            printf("Player 1\n");
            printf("Heaps:\n");
            printf("A: %d\n", heap_a);
            printf("B: %d\n", heap_b);
            printf("C: %d\n", heap_c);
            printf("Enter the letter of the heap and number of objects to remove:");
            scanf(" %c%d", &chosen_heap, &number_removed);
            chosen_heap = tolower(chosen_heap);

            if (number_removed <= 0){ // check the number removed first for > 0.
                bad = 1;
            }
            else if((chosen_heap == 'a') && (number_removed <= heap_a))
            {
                bad = 0;
            }else if((chosen_heap == 'b') && (number_removed <= heap_b))
            {
                bad = 0;
            }
            else if((chosen_heap == 'c') && (number_removed <= heap_c))
            {
                bad = 0;
            }else{
                bad = 1;
            }

        }
        if(chosen_heap == 'a')
        {
            heap_a = heap_a - number_removed;
        }
        else if(chosen_heap == 'b')
        {
            heap_b = heap_b - number_removed;
        }
        else if(chosen_heap == 'c')
        {
            heap_c = heap_c - number_removed;
        }
        }
        else
        {
            printf("Player 2\n");
            printf("Heaps:\n");
            printf("A: %d\n", heap_a);
            printf("B: %d\n", heap_b);
            printf("C: %d\n", heap_c);
            get_computer_move(heap_a, heap_b, heap_c, &chosen_heap, &number_removed);
            printf("COMPUTER moves %c%d\n", chosen_heap, number_removed);
            if(chosen_heap == 'a')
            {
                heap_a = heap_a - number_removed;
            }
            if(chosen_heap == 'b')
            {
                heap_b = heap_b - number_removed;
            }
            if(chosen_heap == 'c')
            {
                heap_c = heap_c - number_removed;
            }
        }
        if(heap_a != 0 || heap_b != 0 || heap_c != 0)
        {
            if(player_turn == 1)
            {
                player_turn = 2;
            }
            else
            {
                player_turn = 1;
            }
        }
    }
    return
        player_turn;
}


void get_computer_move(int heap1, int heap2, int heap3, char* chosen_heap, int* number_removed) /* gets the move the computer has chosen */
{
    int nim_number = heap1 ^ heap2 ^ heap3;
    if(nim_number == 0)
    {
        if(heap1 != 0)
        {
            heap1--;
            *number_removed = 1;
            *chosen_heap = 'a';
        }
        else if(heap2 != 0)
        {
            heap2--;
            *number_removed = 1;
            *chosen_heap = 'b';
        }
        else
        {
            heap3--;
            *number_removed = 1;
            *chosen_heap = 'c';
        }
    }
    else
    {
        if((heap1 ^ nim_number) < heap1)
        {
            *number_removed = heap1 - (heap1 ^ nim_number);
            *chosen_heap = 'a';
        }
        else if((heap2 ^ nim_number) < heap2)
        {
            *number_removed = heap2 - (heap2 ^ nim_number);
            *chosen_heap = 'b';
        }
        else if((heap3 ^ nim_number) < heap3)
        {
            *number_removed = heap3 - (heap3 ^ nim_number);
            *chosen_heap = 'c';
        }
    }
}
bool user_wishes_to_continue() /* prompts the user if they wish to continue playing the game */
{
    char play_again;

    printf("Do you wish to play again? (y/n)");
    scanf(" %c", &play_again);
    play_again = tolower(play_again);

    if(play_again != 'y' && play_again != 'n')
    {
        printf("Bad input! Try again.\n");
        printf("Do you wish to play again? (y/n)");
        scanf(" %c", &play_again);
        play_again = tolower(play_again);
    }
    if(play_again == 'y')
    {
        return true;
    }
    else
    {
        return false;
    }
}
