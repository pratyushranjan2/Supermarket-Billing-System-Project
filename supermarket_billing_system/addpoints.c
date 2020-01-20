#include <stdio.h>
#include <math.h>
void addpoints(int cust_id,float total_amount)
{
	struct data
	{
		char name[21];
		int id;
		long int number;
		int points;
	}data;
	FILE* fp;
	fp=fopen("Customers.txt","r+");
	if (fp==NULL)
		printf("file failed to open");
	else
	{
		while (fread(&data,sizeof(struct data),1,fp))
		{
			if (data.id==cust_id)
			{
				data.points+=ceil(0.05*total_amount);
				fseek(fp,-sizeof(struct data),SEEK_CUR);
				fwrite(&data,sizeof(struct data),1,fp);
				printf("%d Points Added\n",data.points);
				break;
			}
		}
	}
	fclose(fp);
}