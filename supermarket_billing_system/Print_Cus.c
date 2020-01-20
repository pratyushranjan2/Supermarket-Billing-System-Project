#include<stdio.h>
#include<string.h>
#include"Cuslib.h"

int Print_Cus(char *name) {

    FILE *fp;
    Cust rec;
    int recsize = sizeof(rec), state = 0; 

    fp = fopen("Customers.txt","r");
	if(fp == NULL)
    {
        printf("Error in opening Customers' file. \n");
        return -1;
    }

    while( fread(&rec, recsize, 1, fp)) {
        if(!strcmp(name, rec.Name)) {
            state = 1;
            printf("Name : %s\nId : %11d\nPhone number : %.10ld\nPoints: %d\n\n",rec.Name, rec.Cid, rec.PhNo, rec.Points);    
        }
    }

    if(state == 0) {
        printf("Customer not found.\n\n");
        return -1;
    }

    fclose(fp);

    return 0;
}
