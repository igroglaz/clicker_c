#include <stdio.h>

void game()
{
    char input;
    int ore = 0;

    while (input != 'e')
    {
        printf("(M)ine or (e)xit\n");
        scanf("%c", &input);
        while (getchar() != '\n')
            ; // clear buffer
        if (input == 'M' || input == 'm')
        {
            ore++;
            printf("You got piece of rock. You got %d rocks.\n", ore);
        }
    }

    if (input == 'e')
        return;
}

int main (void)
{
    printf( "Welcome back to Idle Tangaria! \n");
    
    game();

    printf("Thanks for playing!\n");

    getchar();
    getchar();
    return 0;
}