#include <stdio.h>
#include <stdlib.h>
void display_all_products()
{
	struct product_data
    {
	    int p_code;
	    char p_name[100];
	    float p_price;
	    int p_amount;
    }p_data;
	FILE *fp;
	fp=fopen("product_database.txt","r");
	if (fp==NULL)
	{
		printf("Error opening product database");
		exit(1);
	}
	printf("\nProducts -->\n\n");
	while (fread(&p_data,sizeof(struct product_data),1,fp))
	{
		printf("Name: %s  |  Code: %d  |  Price: INR %.2f  |  Stock Amount: %d\n",p_data.p_name,p_data.p_code,p_data.p_price,p_data.p_amount);
	}
    printf("\n\n");
    fclose(fp);
}