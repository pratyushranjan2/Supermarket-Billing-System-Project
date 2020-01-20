/*`````````````````````````````````````````````````````````````````````*
 *  This is the function used for listing customer data on the screen. *
 *  It uses stdio.h file and a library file Cuslib.h containing the    *
 *  customer structure. This uses file handling to read the contents   *
 *  of the file and then display it on the screen.                     *
 *                                                                     *
 *`````````````````````````````````````````````````````````````````````*/

#include<stdio.h>
#include "Cuslib.h"


int List_Cus() {

	FILE *fp;
	Cust rec;

	fp = fopen("Customers.txt","r");
	if(fp == NULL)
    {
        printf("error in opening Customers' file : \n");
        return -1;
    }

	int recsize = sizeof(rec);

    printf("|%s|%s|%s|%s|\n\n","          NAME          ", "  Customer id  ", "  Phone Number  ", "  Points  ");
	
	while( fread(&rec, recsize, 1, fp)) {
        printf("|  %20s  |  %11d  |    %.10ld  |  %6d  |\n", rec.Name, rec.Cid, rec.PhNo, rec.Points);
    }

    fclose(fp);

	return 0;
}