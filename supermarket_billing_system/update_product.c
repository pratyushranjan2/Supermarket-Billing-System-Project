#include "declarations.h"
#include <string.h>
void update_product()
{
	FILE *fp;
	char ch;
	int code,selling_price,cost_price,quantity;
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
    struct Product p_data;
    switch(ch)
     {

      case 'F' : 
                fp=fopen("fruits","r+");
                break;
      case 'V' : 
                fp=fopen("vegetables","r+");
                break;
      case 'S' : 
                fp=fopen("stationary","r+");
                break;
      case 's' : 
                fp=fopen("snack_Items","r+");
                break;
      case 'K' : 
                fp=fopen("kitchenware","r+");
                break;
      case 'T' : 
                fp=fopen("toys","r+");
                break;
      case 'G' : 
                fp=fopen("grocery","r+");
                break;
      case 'C' : 
                fp=fopen("cosmetics","r+");
                break;
      default :
               printf("Error opening file");
               break;
      }

	char str[15];
	printf("Enter the code of the product: ");
	scanf("%d",&code);
	printf("Column names:\n");
	printf("selling_price,cost_price,quantity\n");
    printf("Type the column for which you want to make change:");
	scanf("%s",str);
	if(strcmp(str,"selling_price") == 0)
	while (fread(&p_data,sizeof(struct Product),1,fp))
	{
		if (p_data.code==code)
		{
			printf("Enter the new selling-price:");
			scanf("%d",&selling_price);
			p_data.selling_price=selling_price;
			fseek(fp,-sizeof(struct Product),SEEK_CUR);
			fwrite(&p_data,sizeof(struct Product),1,fp);
			break;
		}
	}
	if(strcmp(str,"cost_price") == 0)
	while (fread(&p_data,sizeof(struct Product),1,fp))
	{
		if (p_data.code==code)
		{
			printf("Enter the new cost-price:");
			scanf("%d",&cost_price);
			p_data.cost_price=cost_price;
			fseek(fp,-sizeof(struct Product),SEEK_CUR);
			fwrite(&p_data,sizeof(struct Product),1,fp);
			break;
		}
	}

	if(strcmp(str,"quantity") == 0)

	while (fread(&p_data,sizeof(struct Product),1,fp))
	{
		if (p_data.code==code)
		{
			printf("Enter the new Quantity:");
			scanf("%d",&quantity);
			p_data.quantity=quantity;
			fseek(fp,-sizeof(struct Product),SEEK_CUR);
			fwrite(&p_data,sizeof(struct Product),1,fp);
			break;
		}
	}
	fclose(fp);
}

