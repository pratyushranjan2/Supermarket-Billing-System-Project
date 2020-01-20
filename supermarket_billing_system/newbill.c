#include <stdio.h>
#include <string.h>
#include "changeProductAmount.h"
#include "isAvailable.h"
#include "productDetails.h"
#include "displayAllProducts.h"
#include "priceof.h"
#include "nameof.h"
#include "Add_Cust.h"
#include "display_subproducts.h"
#include "category_products.h"
#include "update_revenue_details.h"
#include "costof.h"
#include "addpoints.h"

void newbill()
{
	//display_all_products();  
    char sub_category=display_subproducts();
    int code;
	printf("\nAdd a product code or enter 0 to exit: ");
	scanf("%d",&code);
	
    int products_purchased[100];int quantity_purchased[500];char category[100];
    float total_amount=0.0,total_cost=0.00;int i=1;
	while (code!=0)
	{
        int response;
        display_product_details(code,sub_category); // displays product details  
        printf("\nEnter 1 to add to cart\nEnter 2 to skip and continue\nEnter 0 to exit and calculate the final bill: \n");
        scanf("%d",&response);
        if (response==1)
        {
            int quantity;
            printf("Enter the quantity: ");
            scanf("%d",&quantity);
            if (is_available(code,quantity,sub_category)==0) // returns 0 if required quantity
            {                                   // is available, 1 if not available
                products_purchased[i]=code;
                quantity_purchased[i]=quantity;
                category[i]=sub_category;
                total_amount+=quantity*priceof(code,sub_category);
                total_cost=costof(code,sub_category);
                i+=1;
                change_product_amount(code,quantity,sub_category);
                printf("\nEnter your category or enter 0 to exit: ");
                scanf("%s",&sub_category);
                if (sub_category=='0')
                    break;
                category_products(sub_category); //displays the products of the sub_category
                printf("\nAdd a product code or enter 0 to exit: ");
                scanf("%d",&code);
            }
            else 
            {
                printf("\nThe given quantity is unavailable\nEnter your category or enter 0 to exit: ");
                scanf("%s",&sub_category);
                if (sub_category=='0')
                    break;
                category_products(sub_category); //displays the products of the sub_category
                printf("\nAdd a product code or enter 0 to exit: ");
                scanf("%d",&code);
            }
        }
        else if (response==2)
        {
        	printf("\nEnter your category or enter 0 to exit: ");
            scanf("%s",&sub_category);
            if (sub_category=='0')
                break;
            category_products(sub_category); 
            printf("\nAdd a product code or enter 0 to exit: ");
            printf("\nAdd a product code or enter 0 to exit: ");
            scanf("%d",&code);
        }
        else if (response==0)
        	break;
    } 
    if (i>1)
    {
    	int cust_id=Add_Cust();
        update_revenue_details(cust_id,total_amount,total_cost);
        addpoints(cust_id,total_amount);
        printf("\nBill:\n");
        for (int j=1;j<i;j++)
        {
            printf("--> %-20s||Price: INR %-6d||Quantity Purchased: %-6d\n",nameof(products_purchased[j],category[j]),priceof(products_purchased[j],category[j]),quantity_purchased[j]);
        }
        printf("\nTotal bill          : INR %.2f \n",total_amount);
        printf("G.S.T.              : INR %.2f\n",0.05*total_amount);
        printf("Total Amount Payable: INR %.2f\n\n",total_amount+0.05*total_amount);
    }
}

// driver for testing 
//int main(void)
//{
//    newbill();
//}
