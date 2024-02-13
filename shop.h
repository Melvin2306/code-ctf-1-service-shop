// shop.h

#pragma once

#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

#define NUM_ITEMS 3 // Define NUM_ITEMS as a constant

typedef struct
{
    char name[32];
    i32 price;
    i32 num_items_available;
} product;

typedef struct
{
    product items[32];
    u32 number_of_items;
} items;

extern i32 wallet;
extern int bag[NUM_ITEMS]; // Now NUM_ITEMS is defined here

void menu(i32 *wallet, i32 *bag);
void buy(i32 *wallet, i32 *bag);
void sell(i32 *wallet, i32 *bag);
void show_owned(i32 *wallet, i32 *bag);
void show_flag();
