#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void encounters(int n)
{
    if (n < 20) // good encounter
    {
        if (n == 0 || n == 1)
        {
            printf("You meet an old hag on the path. She is small and adorned with rags worn and frayed. She smiles up\nat you as you walk past each other.\n");
            printf("\n");
        }
        else if (n == 2 || n == 3)
        {
            printf("A boy and his father are walking their dog. The dog bounces over to you and let's you scratch under\nhis chin. The boy smiles and waves at you as they walk past and you give the man a friendly nod\nbefore walking on.\n");
            printf("\n");
        }
        else if (n == 4 || n == 5)
        {
            printf("You wander through a bush, having lost the path, and come across a squirrel standing over a small\npile of nuts. You ate not that long ago so you quietly walk around trying your best not to disturb.\n");
            printf("\n");
        }
        else if (n == 6 || n == 7)
        {
            printf("You find yourself by a picturesque waterfall, roaring invitingly on this hot day. You decide to\nwalk by the lake below it and you spy a beautiful, blonde and buxom creature showering underneath\nthe falling water. They turn and spot you, stopping to gasp and cover themselves, so you cover\nyour eyes and back away slowly..\n");
            printf("\n");
        }
        else if (n == 8 || n == 9)
        {
            printf("The way has become dense. You lost the path a while back and find yourself wrestling with bush\nand thicket to keep going forwards. Fortunately it's still light and you continue struggling\nthrough. Anxiety is creeping in after some hours of this, but then suddenly you are on a path in\nthe open space again and sigh relief before continuing your journey.\n");
            printf("\n");
        }
        else if (n == 10 || n == 11)
        {
            printf("You reach the square of a small village. There are market stalls selling fruits and other goods,\na flower girl brightening up the atmosphere and a few men sitting around playing a board game,\nwhilst a cat is perched, relaxing by the fountain.\n");
            printf("\n");
        }
        else if (n == 12 || n == 13)
        {
            printf("Walking along a well maintained path, you come across a working smithy. The local blacksmith\nlooks up from his work to give you quick assessing glare and a nod.You grip your pack a bit\ntighter and nod back as you walk past. You hear the reassuring clinking of his hammer grow fainter\nas you continue.\n");
            printf("\n");
        }
        else if (n == 14 || n == 15)
        {
            printf("You decided to walk into the woods for a change of scenery and chance upon a group of young\nactors practicing for a play. They're clearly in the early stages of rehearsal and don't entertain\nyou for long before you move on.\n");
            printf("\n");
        }
        else if (n == 16 || n == 17)
        {
            printf("You exchange nods with a large cat on the path in a quiet area. It saunters past you, and a\nfew moments later you hear a hiss. You whirl round reactively, but there's nothing there.. you\nwalk on nervously..\n");
            printf("\n");
        }
        else if (n == 18 || n == 19)
        {
            printf("A travelling merchant has set up shop in this area with a small selection of expensive looking\nwares. Only selling magical trinkets that you can't afford you don't stop to talk for too long.\n");
            printf("\n");
        }
    }
    else if (n >= 20) // bad encounter
    {
        if (n == 20)
        {
            printf("Caves are much too enticing to ignore. You creep inside, your sword at the ready. There is a\nwarm orange glow ahead, lighting up the darkness that spurs you forwards, and you stumble upon a\ngroup of mercenaries. They raise their swords and rummage through your pack and pockets.\n");
            if (silver >= 60)
            {
                printf("They decide they like what they've found, kill you and take all of your loot.\nThat's the end of your journey.\n");
                printf(RED"GAME OVER"RESET);
                printf("\n");
                exit(0);
            }
            else
            {
                printf("They laugh at the pathetic contents and take pity on you. They kick you out of their cave and\nsend you on your way with a bruised ego but your life and your loot intact.");
            }
            printf("\n");
        }
        else if (n == 21)
        {
            printf("You have a spring in your step as you walk along the path on this sunny afternoon. You look at the\nclouds creating all sorts of interesting and distracting shapes...\nShould have been paying attention though.. You fall off a cliff to your death.\n");
            printf(RED"GAME OVER"RESET);
            printf("\n");
            exit(0);
        }
        else if (n == 22)
        {
            printf("A little girl is crying under a tree. You go over to find out the cause of her distress. As you\nnear, 2 men appear either side of the tree, armed with crossbows aimed at your head. They\nindicate that you should throw your pack on the ground in front of them, and one of them puts\ndown his weapon to inspect your loot.\n");
            if (silver >= 60)
            {
                printf("You see his eyes widen and he smiles. He empties your valuable items into his pack, chucks your\njunk back on the ground in front of you, and indicates that you should leave. Quickly.\nYou pick it up and scurry off. You should check what they've left you with apart from your life.\n");
                for (int i = 0; i < MAX_ITEMS; i++)
                {
                    if (pack[i].type > 1)
                    {
                        silver -= pack[i].value;
                        numberofitems--;
                        pack[i].item = NULL;
                        pack[i].value = 0;
                        pack[i].type = 0;
                        if (full == true)
                        {
                            full = false;
                        }
                        if (numberofitems == 0)
                        {
                            empty = true;
                        }
                    }
                }
            }
            else
            {
                printf("They check around inside your bag but don't find enough worth having. They throw your bag back\nat you and scurry off to find a new mark.\n");
            }

        }
        else if (n == 23)
        {
            printf("You hear thunder, but the sky is blue and clear. Over the hill a band of horsemen appear, the\nriders are covered in black robes, glimpses of steel armour shining beneath as they gallop\ndirectly towards you. You give them your pack without prompting, cowering in terror at their\nunholy presence and before you know it, you are on your knees praying to any of the gods\nwho will listen...\n");
            for (int i = 0; i < MAX_ITEMS; i++)
            {
                if (pack[i].type == 4)
                {
                    printf("They inspect the contents, seemingly ignoring most of it, perhaps searching for something in\nparticular. They pull out the ");
                    printf(ORANGE"%s"RESET, pack[i].item);
                    printf(" and screech a hideous cacophony of triump.\nThey decapitate you, dump the rest of your pack on your corpse and ride away with what they came for.\n");
                    printf(RED"GAME OVER"RESET);
                    printf("\n");
                    exit(0);
                }
            }
            printf("They inspect the contents of your pack, but they don't seem to find what they've been looking\nfor. The rider in black throws your pack at you with incredible force and you fall back, knocking\nyour head hard on the ground.\n");
            printf("You wake up in daze some time later to find the contents of your pack intact and your breeches soaked in urine.\n");
            
        }
        else if (n == 24)
        {
            printf("The figure walking towards you appears to be an adventurer like yourself, dressed in random bits\nof armour and a pack on their back. They unsheathe their sword as they walk towards you, nodding at\nyou for understanding. You nod bad and unsheathe your own weapon. You battle this nameless\nadventurer but eventually yield. They take your loot but leave you with your pack and your life.\nThey bow before you and walk away.\n");
            for (int i = 0; i < MAX_ITEMS; i++)
            {
                if (pack[i].item != NULL)
                {
                    silver -= pack[i].value;
                    numberofitems--;
                    pack[i].item = NULL;
                    pack[i].value = 0;
                    pack[i].type = 0;
                }
            }
            full = false;
            empty = true;
        }
    }
}