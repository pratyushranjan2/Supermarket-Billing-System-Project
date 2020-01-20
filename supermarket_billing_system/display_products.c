#include "declarations.h"
void display()
{
  FILE *fpointer;
  char ch;
  getchar();
  printf("   Enter F for fruits\n");
  printf("   Enter V for vegetables\n");
  printf("   Enter S for stationary\n");
  printf("   Enter s for snack_Items\n");
  printf("   Enter K for kitchenware\n");
  printf("   Enter T for toys\n");
  printf("   Enter G for Grocery\n");
  printf("   Enter C for cosmetics\n");
  printf("Enter your category: ");
  scanf("%c",&ch);
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
    printf("  %s ||  %20s  || %s ||  %s\n","CODE","PRODUCT_NAME","PRICE", "STOCK");
    while( fread(&read,sizeof(struct Product), 1, fpointer)) 
    {
        printf("  %4d ||  %20s  || %5d ||  %5d\n",read.code,read.name,read.selling_price,read.quantity);
    } 
    fclose(fpointer);
}     
