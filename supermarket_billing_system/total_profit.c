#include <stdio.h>

float total_profit()
{
	struct data
	{
		int id;
		float cp;
		float sp;
	}data;
	float profit=0;
	FILE* fp;
	fp=fopen("revenue_data","r");
	if (fp==NULL)
	{
		printf("Error opening file");
	}
	else
	{
		while (fread(&data,sizeof(data),1,fp))
			profit+=data.sp-data.cp;
	}
	return profit;
}

// driver for testing
//int main(void)
//{
//	printf("Total Profit = INR %.2f\n",total_profit());
//}