#include "shop.h"

i32 wallet = 100;
int bag[NUM_ITEMS] = {0};

#include <stdio.h>
#include <stdlib.h>

#define NUM_ITEMS 3

product available_products[NUM_ITEMS] = {
    {"flag",
     123,
     1},
    {"Security Training",
     13,
     10},
    {"CTF Creation",
     27,
     5}};

void buy(i32 *wallet, i32 *bag)
{
    printf("You have %d coins\n", *wallet);

    printf("What do you want to buy?\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("    %d: %s for %d coins. %d are available \n", i + 1, available_products[i].name, available_products[i].price, available_products[i].num_items_available);
    }

    printf("\n> ");

    i32 choice = -1;

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input. Exiting...\n");
        exit(-1);
    }

    if (choice < 1 || choice > NUM_ITEMS)
    {
        printf("Incorrect input. \n");
        return;
    }

    printf("How many do you want to buy?\n");
    printf("\n> ");

    i32 amount = -1;

    if (scanf("%d", &amount) != 1)
    {
        printf("Invalid input. Exiting...\n");
        exit(-1);
    }

    if ((amount * available_products[choice - 1].price <= *wallet) && amount <= available_products[choice - 1].num_items_available)
    {
        *wallet -= amount * available_products[choice - 1].price;
        available_products[choice - 1].num_items_available -= amount;
        bag[choice - 1] += amount;

        printf("\nYou bought %d %s\n", amount, available_products[choice - 1].name);

        if (choice - 1 == 0)
        {
            show_flag();
        }
    }
    else
    {
        printf("\nYou do not have enough coins for this purchase!\n");
    }

    printf("\n");
}

void sell(i32 *wallet, i32 *bag)
{
    printf("You have %d coins\n", *wallet);

    printf("What do you want to sell?\n");

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        printf("    %d: %s: %d owned.\n", i + 1, available_products[i].name, bag[i]);
    }

    printf("\n");

    printf("\n> ");

    i32 choice = -1;

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input. Exiting...\n");
        exit(-1);
    }

    if (choice < 1 || choice > NUM_ITEMS)
    {
        printf("Incorrect input. \n");
        return;
    }

    printf("How many do you want to sell?\n");
    printf("\n> ");

    i32 amount = -1;

    if (scanf("%d", &amount) != 1)
    {
        printf("Invalid input. Exiting...\n");
        exit(-1);
    }

    if (amount <= bag[choice - 1] && amount >= 1)
    {
        *wallet += amount * available_products[choice - 1].price;
        available_products[choice - 1].num_items_available += amount;
        bag[choice - 1] -= amount;

        printf("\nYou sold %d %s\n", amount, available_products[choice - 1].name);
    }
    else
    {
        printf("\nUnable to sell items!\n");
    }

    printf("\n");
}

void show_owned(i32 *wallet, i32 *bag)
{
    printf("Showing your stuff!\n");
    printf("\nYou have %d coins.\n\n", *wallet);

    for (int i = 0; i < NUM_ITEMS; i++)
    {
        if (bag[i] == 0)
        {
            continue;
        }

        printf("%s: %d owned.\n", available_products[i].name, bag[i]);
    }

    printf("\n");
}

void show_flag()
{
    // CODE_CTF{Out_oF_tHe_BoX}
    char xyz[25] = {0xCF, 0x79, 0x9A, 0x07, 0xE4, 0x02, 0xE8, 0x8B, 0xFE, 0xAE, 0xDD, 0x95, 0x6B, 0xEC, 0xA9, 0x36, 0xE6, 0x30, 0xED, 0xD0, 0xA3, 0xAA, 0x68, 0x7D, 0x00};
    unsigned char rand_data[25] = {0xaf, 0x11, 0xf5, 0x6d, 0x88, 0x76, 0x87, 0xf2, 0x86, 0xe6, 0xa3, 0xee, 0x27, 0x94, 0xf4, 0x76, 0xf1, 0x1f, 0xe3, 0xe0, 0x92, 0xb2, 0x4b, 0xFE, 0x00};

    for (int i = 0; i < 23; i++)
    {
        xyz[i] ^= rand_data[i] ^ ((i << 2) ^ 0x23);
    }

    printf("%s\n\n", xyz);
    exit(0);
}

void menu(i32 *wallet, i32 *bag)
{
    printf("----{ Welcome to the CarByte store! }----\n\n");
    printf("You have %u coins.\n\n", *wallet);
    printf("What do you want to do?\n");
    printf("    1 > Buy Stuff :)\n");
    printf("    2 > Sell Stuff :)\n");
    printf("    3 > Display your owned items :)\n");
    printf("    4 > Exit :(\n");
    printf("\n> ");

    i32 choice = -1;

    if (scanf("%d", &choice) != 1)
    {
        printf("Invalid input. Exiting...\n");
        exit(-1);
    }

    printf("\n");

    switch (choice)
    {
    case 1:
        buy(wallet, bag);
        break;
    case 2:
        sell(wallet, bag);
        break;
    case 3:
        show_owned(wallet, bag);
        break;
    case 4:
        printf("Exiting...\n");
        exit(0);
    default:
        printf("Hmmm... that was not a valid input.\n");
        break;
    }

    printf("\n\n");
}

int main()
{
    i32 wallet = 100;

    int bag[NUM_ITEMS] = {0};

    while (1)
    {
        menu(&wallet, bag);
    }

    return 0;
}
