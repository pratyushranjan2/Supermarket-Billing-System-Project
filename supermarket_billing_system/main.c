#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "newbill.h"
#include "Add_Cust.h"
#include "HHDel_Cus.h"
#include "add_product.h"
#include "deleteproduct.h"
#include "update_product.h"
#include "HHPrint_Cus.h"
#include "total_profit.h"
#include "HHList_Cus.h"
#include "display_products.h"
#include "redeem.h"

int main(void)
{
    char customer_name[21];
    int option,id;
    printf("\nEnter 1 to frame a new bill\nEnter 2 to add a customer\nEnter 3 to delete a customer\nEnter 4 to add a product\nEnter 5 to delete a product\nEnter 6 to update a product details\nEnter 7 to search a customer\nEnter 8 to calculate the total profit by now\nEnter 9 to display all customers\nEnter 10 to display all products\nEnter 11 to redeem points of a customer\nEnter 0 to exit\n");
	scanf("%d",&option);
	int exitcode=0;
	//while (option!=0)
	//{
		switch (option)
		{
			case 0: exitcode=1;
			        break;
			case 1: newbill();
					getchar();
					getchar();
			        break;
			case 2: Add_Cust();
					getchar();
		            getchar();
			        break;
			case 3: printf("\nEnter the name of the customer: ");
			        scanf("%s",customer_name);
			        Del_Cus(customer_name);
					getchar();
					getchar();
			        break;
			case 4: add_product();
					getchar();
					getchar();
			        break;
			case 5: delete_product();
			        break;
			case 6: update_product();
					getchar();
					getchar();
			        break;
			case 7: printf("\nEnter the name of the customer: ");
			        scanf("%s",customer_name);
			        Print_Cus(customer_name);
					getchar();
					getchar();
			        break;
			case 8: printf("Net Profit Until Now: INR %.2f",total_profit());
					getchar();
					getchar();
			        break;
			case 9: List_Cus();
					getchar();
					getchar();
			        break;
			case 10: display();
					 getchar();
					 getchar();
			         break;
			case 11: printf("Enter Customer's Name: ");
			         scanf("%s",customer_name);
			         redeem(customer_name);
                     getchar();
                     getchar();
                     break;
			default: printf("\nPlease Enter a Valid Option\n");
					 getchar();
					 getchar();
					 break;
		}
		system("clear");
		if (exitcode==1)
		{
			return 0;
		}
		else
			system("./main");
	//}
}
