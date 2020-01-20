#include<stdio.h>
#include<string.h>
#include"Cuslib.h"

int Del_Cus(char *name) {

    FILE *fp1, *fp2;
    Cust rec;
    int recsize = sizeof(rec), count = 0;

    fp1 = fopen("Customers.txt","r");
	if(fp1 == NULL)
    {
        printf("error in opening Customers' file : \n");
        return -1;
    }

    fp2 = fopen("temp.txt","w");
    
    while( fread(&rec, recsize, 1, fp1)) {
        if(!strcmp(name, rec.Name)) {
            count ++;
        }
    }

    fseek(fp1, 0, SEEK_SET);


    if(count > 1) {
        printf("More than one customer with same name. Enter the phone number: ");
        long int a;
        scanf("%ld",&a);
        while( fread(&rec, recsize, 1, fp1)) {
            if(strcmp(name, rec.Name) || rec.PhNo != a) {
                fwrite(&rec,recsize,1,fp2);
            }
        }
    }

    else if(count == 1) {
        while( fread(&rec, recsize, 1, fp1)) {
            if(strcmp(name, rec.Name)) {
                fwrite(&rec,recsize,1,fp2);
            }
        }
    }

    else {
        printf("Customer not found\n");
        return -1;
    }


    fclose(fp1);
    fclose(fp2);
    remove("Customers.txt");

    printf("Customer data is deleted.\n");

    rename("temp.txt","Customers.txt"); 

    return 0;

}
