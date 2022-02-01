#include<stdio.h>
#include<string.h>
#include<stdlib.h>
float totalBill;
struct item 
{
    char itemName[50];
    float price;
    int quantity;
    char productCode[10];
};
int pos;
void outPutPannel()
{
    printf("\n\n-----------------------------------------------------------\n\n");
}
 void input(char str[], int n)
 {
	int ch, i=0;
	while((ch = getchar()) != '\n')
		if(i < n)
		str[i++]=ch;
	str[i]='\0';
	return;
 }
struct item itemList[50];
void mainMenu()
{
    printf("\nClothing Store Management System\n\n"
           "1.add item\n"
           "2.search item\n"
           "3.view item\n"
           "4.calculate bill\n");
}
void addItem()
{
    printf("\nEnter the name of item: ");
    input(itemList[pos].itemName, 50); 
    printf("Enter the price of the item: ");
    scanf("%f", &itemList[pos].price);
    printf("Enter the quantity of the item: ");
    scanf("%d", &itemList[pos].quantity);
    printf("Enter the product code: \n");
    fflush(stdin);
    input(itemList[pos].productCode, 10);
    pos++;
}
void searchItem()
{
    char tem[50];
    int i;
    int ifFound = 0;
    printf("ENTER DETAILS OF PRODUCT TO BE SEARCHED");
    printf("\nEnter item name or product code: ");
    input(tem, 50);
    for(i=0; i<50; i++)
    {
        if((strcasecmp(itemList[i].itemName, tem) == 0) || (strcasecmp(itemList[i].productCode, tem) == 0))
        {
            printf("\nItem found\nDetails\n\n"
                   "Product Name     = %s\n"
                   "Product price    = %.2f\n"
                   "Product Quantity = %d"
                   "Product Code     = %s", itemList[i].itemName, itemList[i].price, itemList[i].quantity, itemList[i].productCode);
            ifFound = 1;
        }  
    }
    if(!ifFound)
    {
        printf("\n\nProduct not found! \n");
    }
}
void viewItem()
{
    int i;
    printf("\n\nList of all products in shop:\n\n"
          "| S.No | %-20s |    price   |  qnt | %-10s |\n\n"
          , "Item Name ", "pcode");

    for(i=0; i<50 && (itemList[i].quantity) > 0; i++)
    {
        printf("| %-4d | %-20s |    %.2f   |  %-3d | %-10s |\n"
               , (i+1), itemList[i].itemName , itemList[i].price
               , itemList[i].quantity, itemList[i].productCode);
    }    
}
void calculateBill()
{
    int i;
    for(i=0; i<50 && (itemList[i].quantity) > 0; i++)
    {
        totalBill += itemList[i].price * itemList[i].quantity;
    }
}
int main()
{
    FILE *fp, *fp2;
    fp = fopen("billCopy.txt", "w");
	fp2 = fopen("billCopy.txt", "a"); 
    int ch, i;
    outPutPannel();
    mainMenu();
    addItem();
    addItem();
    addItem();
	searchItem();  
    viewItem();
    calculateBill();
    // File handing
    printf("\n\nList of all products in shop:\n\n"
          "| S.No | %-20s |    price   |  qnt | %-10s |\n\n"
          , "Item Name ", "pcode");
    
    fprintf(fp, "\n\nList of all products in shop:\n\n"
          "| S.No | %-20s |    price   |  qnt | %-10s |\n\n"
          , "Item Name ", "pcode");
    for(i=0; i<50 && (itemList[i].quantity) > 0; i++)
    {
        printf("| %-4d | %-20s |    %.2f   |  %-3d | %-10s |\n"
               , (i+1), itemList[i].itemName , itemList[i].price
               , itemList[i].quantity, itemList[i].productCode);
        
        fprintf(fp2, "| %-4d | %-20s |    %.2f   |  %-3d | %-10s |\n"
               , (i+1), itemList[i].itemName , itemList[i].price
               , itemList[i].quantity, itemList[i].productCode);
    }  
    printf("\n\nTotal payable amount Rs. %.2f", totalBill);
    fprintf(fp2,"\n\nTotal payable amount Rs. %.2f", totalBill);
    outPutPannel();
    return 0;
}
