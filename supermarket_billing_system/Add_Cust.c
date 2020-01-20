/*`````````````````````````````````````````````````````````````````````*
 *  This is the function used for adding customer data into customer   *
 *  database. It uses stdio.h file and a library file Cuslib.h         *
 *  containing the customer structure. This uses file handling to      *
 *  update in the file containing the details. The input is taken from *
 *  the users and stored in a strcut of Cust type and later appended   *
 *  into the file.                                                     *
 *                                                                     *
 *`````````````````````````````````````````````````````````````````````*/


#include <stdio.h>
#include<string.h>
#include "Cuslib.h"


int Add_Cust(void) {

    FILE *fp;
    Cust inp, rec;
    int recsize = sizeof(rec);

    fp = fopen("Customers.txt" , "a+");

    if(fp == NULL)
    {
        printf("Error in opening Customers' file : \n");
        return -1;
    }

    printf("Enter Customer's Name : ");
    scanf("%s" , inp.Name);
    printf("Enter Customer_id     : ");
    scanf("%d" , &inp.Cid);
    printf("Enter the Phone No.   : ");
    scanf("%ld" , &inp.PhNo);
    
    inp.Points = 0;

    fseek(fp , 0 ,SEEK_SET);

    while( fread(&rec, recsize, 1, fp)) {
        if(!strcmp(inp.Name, rec.Name) && inp.PhNo == rec.PhNo ) {
            printf("Customer data already existing :\n");
            printf("Name : %s\nId : %d\nPhone number : %ld\nPoints: %d\n\n",rec.Name, rec.Cid, rec.PhNo, rec.Points);
            return rec.Cid;
        }
    }

    fseek(fp , 0 ,SEEK_END);

    fwrite(&inp,sizeof(inp),1,fp);

    printf("Customer is added\n");

	int id=inp.Cid;
    fclose(fp);

    return id;

}
