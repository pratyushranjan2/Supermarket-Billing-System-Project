#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "declarations.h"
char* nameof(int code,char ch)
{
	
	FILE *fp;
	struct Product p_data;
    static char name_of_product[100];
    switch(ch){
      case 'F' : 
                fp=fopen("fruits","r");
                break;
      case 'V' : 
                fp=fopen("vegetables","r");
                break;
      case 'S' : 
                fp=fopen("stationary","r");
                break;
      case 's' : 
                fp=fopen("snack_Items","r");
                break;
      case 'K' : 
                fp=fopen("kitchenware","r");
                break;
      case 'T' : 
                fp=fopen("toys","r");
                break;
      case 'G' : 
                fp=fopen("grocery","r");
                break;
      case 'C' : 
                fp=fopen("cosmetics","r");
                break;
      default:
		        //printf("Enter valid letter");
                break;
     }
	while (fread(&p_data,sizeof(struct Product),1,fp))
	{
		if (p_data.code==code)
		{
			strcpy(name_of_product,p_data.name);
			fclose(fp);
			return name_of_product;
		}
	}
    fclose(fp);
    return "0";
}