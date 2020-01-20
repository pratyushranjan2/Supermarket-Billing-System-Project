#include"declarations.h"
void delete_product()
{
    FILE *fpointer,*fpointer2;
    char ch;
    struct Product read,write;
    fpointer2=fopen("temp","w");
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
    printf("\n");
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
		printf("enter valid letter");
                break;
     }
    int code;
    printf("Enter the code to delete :"); 
    scanf("%d",&code);
    getchar();
    while( fread( &read,sizeof(read), 1, fpointer) && read.code!=code) 
    {
        fwrite(&read, sizeof(struct Product), 1, fpointer2); 
    }
    while( fread( &read,sizeof(read), 1, fpointer)) 
    {
        fwrite(&read, sizeof(struct Product), 1, fpointer2); 
    }
  switch(ch){
    case 'F' : 
                remove("fruits");
                rename("temp","fruits");
                break;
    case 'V' : 
                remove("vegetables");
                rename("temp","vegetables");
                break;
    case 'S' : 
                remove("stationary");
                rename("temp","stationary");
                break;
    case 's' : 
                remove("snack_Items");
                rename("temp","snack_Items");
                break;
    case 'K' : 
                remove("kitchenware");
                rename("temp","kitchenware");
                break;
    case 'T' : 
                remove("toys");
                rename("temp","toys");
                break;
    case 'G' : 
                remove("grocery");
                rename("temp","grocery");
                break;
    case 'C' : 
                remove("cosmetics");
                rename("temp","cosmetics");
                break;
    default:
		printf("enter valid letter");
                break;
     }
    fclose(fpointer);
    fclose(fpointer2);
}
