#include <stdio.h>
#include <string.h>
#include "StoreItem.h"
#include "StockTxn.h"
void Menu();
int main()
{
	InitializeItems();
	Menu();
}

void Menu()
{
	int opt;
	
	while(1)
	{
		
		system("cls");
		printf("\n     XYZ  Corporation    ");
		printf("\n\n Stock Management");
		printf("\n1. Recipt Entry");
		printf("\n2. Issue Entry");
		printf("\n3. Stock List");
		printf("\n4. Stock Transactions Report");
		printf("\n5. View Store Item");
		printf("\n6. Exits");
		printf("\n\n Enter Your Choice(1 - 6):");
		scanf("%d", &opt);
		fflush(stdin);
		
		switch(opt)
		{
			case 1:
				ReceiptEntry();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				ListTransaction();
				break;
			case 5:
				ListItems();
				break;
			case 6:
				return;
				break;
			default:
				printf("\n\n Invalid Choice. Please Try Again (1 - 6) ");
		}
		printf("\n\n Press a Key to Proceed");
		getch();
		
	}	 
}

