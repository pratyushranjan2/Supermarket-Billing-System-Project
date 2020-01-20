#include "declarations.h"
void category_products(char ch)
{
  FILE *fpointer;
  struct Product read;
  switch(ch){
    case 'F' : 
                fpointer=fopen("fruits","r");
                break;
    case 'V' : 
                fpointer=fopen("vegetables","r");
                break;
    case 'S' : 
                fpointer=fopen("stationary","r");
                break;
    case 's' : 
                fpointer=fopen("snack_Items","r");
                break;
    case 'K' : 
                fpointer=fopen("kitchenware","r");
                break;
    case 'T' : 
                fpointer=fopen("toys","r");
                break;
    case 'G' : 
                fpointer=fopen("grocery","r");
                break;
    case 'C' : 
                fpointer=fopen("cosmetics","r");
                break;
    default:
		        printf("Enter valid letter");
                break;
     }
    while( fread(&read,sizeof(struct Product), 1, fpointer)) 
    {
        printf("  %2d ||  %20s  || %5d ||  %5d  ||  %5d\n",read.code,read.name,read.selling_price,read.cost_price,read.quantity);
    } 
    fclose(fpointer);
}     