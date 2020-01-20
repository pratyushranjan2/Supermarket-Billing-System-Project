#include <stdio.h>
#include "Cuslib.h"
#include <string.h>

void redeem(char* customer_name)
{
	FILE* fp;
	Cust data;
	fp=fopen("Customers.txt","r+");
	if (fp==NULL)
		printf("error opening file");
	else
	{
		while (fread(&data,sizeof(data),1,fp))
		{
			if (strcmp(customer_name,data.Name)==0)
			{
				int deduction;
				printf("Points: %d\nHow many points you wish to redeem? ",data.Points);
				scanf("%d",&deduction);
				while (deduction>data.Points)
				{
					printf("Not enough points available\nEnter points to redeem again or press 0 to cancel: ");
					scanf("%d",&deduction);
					if (deduction==0)
						break;
				}
				data.Points-=deduction;
				fseek(fp,-sizeof(data),SEEK_CUR);
				fwrite(&data,sizeof(data),1,fp);
				printf("You have redeemed %d points\nPoints Remaining: %d\n",deduction,data.Points);
				break;
			}
		}
	}
	fclose(fp);
}