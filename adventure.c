#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

// some extra details and item lists
#include "itemdetails.h"
#include "items.c"
#include "encounters.c"

// prototypes
void additems(void);  // additems function in items.c
void packcontents(void);
void adventure(void);
void dumpitems(void);
void encounters(int n);

int main(void)
{
    // add all the items to the list of loot you can acquire
    additems();

    // all the welcoming messages and options
    printf("\n");
    printf(GREEN"WELCOME ADVENTURER!"RESET);
    printf("\n\n");
    printf("You're an adventurer on a brave journey and everyone knows the most important\nthing to do before going out is to make sure you're well provisioned whilst also\nhaving enough space in your pack to bring all the loot back.\n");
    printf("\n");
    printf("Type the number and press ENTER to decide what to do\n");
    printf("1 - Check the contents of your bag.\n");
    printf("2 - Check the total value of your items.\n");
    printf("3 - Take your bag and go out on an Adventure!\n");
    printf("4 - Dump something out of your bag. (UNDER CONSTRUCTION)\n");
    printf("5 - Decide to go home and put your feet up. (QUIT GAME)\n");
    printf("\n");

    // iterate through the possible options asking until 5 is selected
    while (true)
    {
        int choice = 0;        
        do
        {
            scanf("%d", &choice);
            while(getchar() != '\n'); // eats the invisible char
            {
                continue;
            }
            printf("\n");
        }
        while (choice < 1 || choice > 5 && !isdigit(choice));

        if (choice == 1)
        {
            packcontents(); // list pack items
            printf("\n");
            choice = 0;
        }
        else if (choice == 2)
        {
            if (silver < 60)
            {
                printf("You've got roughly %i silver worth of stuff in here. Not a lot really..\n", silver);
            }

            else if (silver >= 60)
            {
                printf("Your shit must be worth at least %i silver. Be cautious about going back out again, in case\nyou meet any unsavoury characters..\n", silver);
            }
            printf("\n");
            choice = 0;
        }

        else if (choice == 3)
        {
            if (visits == 0) // intro for first adventure
            {
                printf("You're all packed and ready to go. You wander out into the world to see what you can find.\n\n");
            }
            adventure(); // big adventure function
            printf("\n");
            choice = 0;
        }

        else if (choice == 4)
        {
            dumpitems();
            printf("\n");
            choice = 0;
        }

        else if (choice == 5)
        {
            printf("You've gone home with %i silver worth of stuff, after having had %i adventures and count yourself\nlucky for having had such an exellent time.\n", silver, visits);
            printf("\n");
            break;
        }
    }
}

// shows the contents of your pack
void packcontents(void)
{
    printf("You've got %i items.\n", numberofitems);
    for (int i = 0; i < MAX_ITEMS; i++)
    {        
        if (pack[i].item != NULL)
        {
            if (pack[i].type == 1)
            {
                printf(WHITE"%s"RESET, pack[i].item);
                printf("\n");
            }

            else if (pack[i].type == 2)
            {
                printf(GREEN"%s"RESET, pack[i].item);
                printf("\n");
            }

            else if (pack[i].type == 3)
            {
                printf(PURPLE"%s"RESET, pack[i].item);
                printf("\n");
            }

            else if (pack[i].type == 4)
            {
                printf(ORANGE"%s"RESET, pack[i].item);
                printf("\n");
            }
        }
    }
    if (full == true)
    {
        printf("\nand your pack is ");
        printf(RED"FULL"RESET);
        printf(".\n");
    }
    else if (empty == true)
    {
        printf("\nYou've got nothing in here!\n");
    }
    else
    {
        printf("\nand space for more.\n");
    }
}

// adventure settings
void adventure(void)
{
    visits++;
    srandom(time(NULL));
    int n1 = (random() / ((double) RAND_MAX + 1)) * 20;
    int n2 = (random() / ((double) RAND_MAX + 1)) * 30;
    int n3 = (random() / ((double) RAND_MAX + 1)) * 25;
    char select;

    if (n1 <= 8) // You found a person!
    {
        encounters(n3);
    }

    else if (n1 > 8) // You found some loot!
    {
        printf("You walk along the path before something catches your eye.. ");
        printf("You've found ");
        if (items[n2].type == 1)
        {
            printf(WHITE"%s"RESET, items[n2].item);
        }
        else if (items[n2].type == 2)
        {
            printf(GREEN"%s"RESET, items[n2].item);
        }
        else if (items[n2].type == 3)
        {
            printf(PURPLE"%s"RESET, items[n2].item);
        }
        else
        {
            printf(ORANGE"%s"RESET, items[n2].item);
        }
        printf("\n\n");

        if (numberofitems == MAX_ITEMS)
        {
            printf("You've got no space for that! You'll have to dump something out to pick anything else up\n");
            return;
        }

        printf("Do you want to put it in your pack? (y to keep)\n");

        scanf(" %c", &select);
        
        if (select == 121)
        {
            silver += items[n2].value;
            for (int i = 0; i < MAX_ITEMS; i++)
            {
                if (pack[i].item == NULL)
                {
                    printf("You carefully put it in your pack where it might fit and carry on your merry way\n");
                    pack[i] = items[n2];
                    numberofitems++;
                          
                    if (numberofitems == 1)
                    {
                        empty = false;
                    }
                    else if (numberofitems == MAX_ITEMS)
                    {
                        full = true;
                    }
                    break;
                }
            }
        }
        else if (select == 110)
        {
            printf("You left the item where it was and carried on your merry way.\n");
        }
        else 
        {
            printf("Your brain farts with indecision and you drop the item and forget you even held it in your hands.\nYou carry on walking.\n");
        }
        
    }
}

// dump one or multiple items
void dumpitems()
{
    if (empty == true)
    {
        printf("\nYou've got nothing in here to get rid of.\n");
        return;
    }

    printf("You've got..\n");
    for (int i = 0; i < MAX_ITEMS; i++)
    {
        if (pack[i].type == 1)
        {   
            printf("%i. ", i + 1);
            printf(WHITE"%s"RESET, pack[i].item);
            printf("\n");
        }

        else if (pack[i].type == 2)
        {
            printf("%i. ", i + 1);
            printf(GREEN"%s"RESET, pack[i].item);
            printf("\n");
        }

        else if (pack[i].type == 3)
        {
            printf("%i. ", i + 1);
            printf(PURPLE"%s"RESET, pack[i].item);
            printf("\n");
        }
        else if (pack[i].type == 4)
        {
            printf("%i. ", i + 1);
            printf(ORANGE"%s"RESET, pack[i].item);
            printf("\n");
        }
        else
        {
            printf("%i. ", i + 1);
            printf("SPACE FOR STUFF\n");
        }
    }
    printf("11. Nothing! I changed my mind!\n");

    int selection;
    
    do
    {
        printf("\nWhat would you like to get rid of? (1-11) \n");
        scanf("%i", &selection);
        while(getchar() != '\n'); // eats the invisible char
        {
            continue;
        }
    }
    while (selection > 11 || selection < 1);
    selection--;

    if (pack[selection].type == 1)
    {   
        printf("You dumped ");
        printf(WHITE"%s"RESET, pack[selection].item);
    }

    else if (pack[selection].type == 2)
    {
        printf("You dumped ");
        printf(GREEN"%s"RESET, pack[selection].item);
    }

    else if (pack[selection].type == 3)
    {
        printf("You dumped ");
        printf(PURPLE"%s"RESET, pack[selection].item);
    }
    else if (pack[selection].type == 4)
    {
        printf("You dumped ");
        printf(ORANGE"%s"RESET, pack[selection].item);
    }
    else if (selection == 10)
    {
        printf("You keep what you've got for now.\n");
        return;
    }
    else
    {
        printf("There's no item in that slot\n");
        return;
    }
    silver -= pack[selection].value;
    pack[selection].item = NULL;
    pack[selection].value = 0;
    pack[selection].type = 0;
    numberofitems--;
    if (numberofitems == 0)
    {
        empty = true;
    }
    else if (numberofitems == 9)
    {
        full = false;
    }
    printf(" out of your pack.\n");
}