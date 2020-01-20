#include <stdio.h>
#include <stdlib.h>

void update_revenue_details(int cust_id,float total_amount,float total_cost)
{
	struct data
	{
		int id;
		float cp;
		float sp;
	};
	FILE* fp;
	fp=fopen("revenue_data","a");
	if (fp==NULL)
		printf("error opening file");
	else
	{
		struct data inp={cust_id,total_cost,total_amount};
		fwrite(&inp,sizeof(struct data),1,fp);
	}
	fclose(fp);
} 