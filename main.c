#include <stdio.h>
#include <time.h>
#include <unistd.h> // milliseconds; while windows.h sleep() - seconds
#include <ctype.h>

// main game loop
void game()
{
    char input;
    int ore = 0;

    // replace with setitimer()?
    time_t rawtime;

    while (input != 'e')
    {
        int tick = 0;

        time (&rawtime);
        sleep(1);

        // ask what to do
        if (!(rawtime % 10) && !tick)
        {
            tick++;

            printf("(R)un from monster!\n");
            // take player's input
            scanf("%c", &input);
            while (getchar() != '\n')
                ; // clear buffer

            // confirm input and perform action
            if (tolower(input) == 'r')
            {
                printf("You've managed to flee from goblin. You still got %d ore.\n", ore);
            }
            else
            {
                printf("Goblin has stolen all your ore!\n");
                ore = 0;
            }
        }

        if (rawtime % 2)
        {
            tick++;
            ore++;
            printf("You've managed to mine some iron ore. Now you have %d ore.\n", ore);
        }
    }

    if (input == 'e')
        return;
}

int main (void)
{
    printf( "Welcome back to Idle Tangaria! Press 'e' to exit \n");

    game();

    printf("Thanks for playing!\n");

    getchar();
    getchar();
    return 0;
}


// run program
// turn 1
// log++
// if player didn't made input: turn ++
// turn 2
// attacked by goblin
// if player didn't made input: die
// turn 3
