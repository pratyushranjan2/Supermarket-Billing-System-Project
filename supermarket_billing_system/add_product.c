#include "declarations.h"
void add_product()
{
  FILE *fpointer;
  char ch;
  int count=0;
  getchar();
  printf(" Enter F for fruits\n");
  printf(" Enter V for vegetables\n");
  printf(" Enter S for stationary\n");
  printf(" Enter s for snack_Items\n");
  printf(" Enter K for kitchenware\n");
  printf(" Enter T for toys\n");
  printf(" Enter G for Grocery\n");
  printf(" Enter C for cosmetics\n");
  printf("Enter your category: ");
  scanf("%c",&ch);
  switch(ch){
    case 'F' : 
                fpointer=fopen("fruits","a");
                break;
    case 'V' : 
                fpointer=fopen("vegetables","a");
                break;
    case 'S' : 
                fpointer=fopen("stationary","a");
                break;
    case 's' : 
                fpointer=fopen("snack_Items","a");
                break;
    case 'K' : 
                fpointer=fopen("kitchenware","a");
                break;
    case 'T' : 
                fpointer=fopen("toys","a");
                break;
    case 'G' : 
                fpointer=fopen("grocery","a");
                break;
    case 'C' : 
                fpointer=fopen("cosmetics","a");
                break;
    default:
		printf("Enter valid letter");
                break;
     }
    
    
  struct Product new_product;
  printf("Enter the code of the product: ");
  scanf("%d",&new_product.code);
  printf("Enter the name of the product: ");
  scanf("%s",new_product.name);
  printf("Enter the selling price of the product: ");
  scanf("%d",&new_product.selling_price);
  printf("Enter the cost price of the product: ");
  scanf("%d",&new_product.cost_price);
  printf("Enter the Quantity of the product: ");
  scanf("%d",&new_product.quantity);
  fwrite(&new_product, sizeof(struct Product), 1, fpointer); 
  fclose(fpointer);
}

//int main(void)
//{
//  add_product();
//}
