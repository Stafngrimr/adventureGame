#include <stdlib.h>


// Max items you can carry
#define MAX_ITEMS 10

// Max items in the game
#define TOTAL_ITEMS 29

// colour swatches for some text
#define PURPLE    "\e[38;2;255;255;255;1m\x1b[35m"
#define WHITE   "\e[38;2;255;255;255;1m\x1b[37m"
#define GREEN   "\e[38;2;255;255;255;1m\x1b[32m"
#define RED     "\e[38;2;255;255;255;1m\x1b[41m"
#define ORANGE 	"\e[38;2;255;255;255;1m\x1b[38;5;214m"
#define RESET   "\e[0;39m"

// global variables
int visits = 0; // number of adventures you've been on
int silver; // amount of silver you have
int numberofitems = 0; // items in the bag
bool full = false; // your pack is full
bool empty = true; // your pack is empty

// Define item struct
typedef struct
{
    char *item;
    int value;
    int type;
}
loot;

// Create list of TOTAL items
loot items[TOTAL_ITEMS];
loot pack[MAX_ITEMS];