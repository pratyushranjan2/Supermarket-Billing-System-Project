#include<stdlib.h>
#include<stdio.h>
struct Product{
    int code;
    char name[20];
    int selling_price;
    int cost_price;
    int quantity;
};
void search();
void add_product();
void delete_product();
void display();