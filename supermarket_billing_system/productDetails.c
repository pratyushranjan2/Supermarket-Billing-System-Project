#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"
void display_product_details(int code,char ch)
{
	
	FILE *fp;
	struct Product p_data;
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
      default :
               printf("Error opening file");
               break;
      }
	while (fread(&p_data,sizeof(struct Product),1,fp))
	{
		if (p_data.code==code)
		{
			printf("\nName: %s  |  Price: INR %d  |  Stock: %d\n",p_data.name,p_data.selling_price,p_data.quantity);
			fclose(fp);
			break;
		}
	}
    fclose(fp);
}