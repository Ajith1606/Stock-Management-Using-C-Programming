#include <stdio.h>
#include <string.h>
#include "storeitem.h"
#include "stock.h"
void CreateItemsFile();
void CreateTestTransactions();
void Menu();
int main()
{	 	 
	InitializeItems();
	Menu();
	
	printf("\n\nSuccessully completed.");
}

void Menu()
{
	int opt;
	/* Enter into a infinite Loop */
	while(1)
	{
		system("cls");
		printf("\n\n   Artifice Corporation\n\n");
		printf("     Stock Management\n\n");
		printf("\n1. Stock Receipt");
		printf("\n2. Stock Issue");
		printf("\n3. Stock List");
		printf("\n4. Stock Transaction List");
		printf("\n5. View Store Items");
		printf("\n6. Exit");
		printf("\n\nEnter Choice (1-6) : ");
		scanf("%d", &opt);
		fflush(stdin);
		switch(opt)
		{
			case 1:
				InputTransaction('R');
				break;
			case 2:
				InputTransaction('I');
				break;
			case 3:
				PrintStockList();
				break;
			case 4:
				PrintTransactionsInput();
				break;
			case 5:
				ListItems();
				break;
			case 6:
				exit(0);
				break;
			default:
				printf("\nInvalid Input.");
				break;	  	  	  	  
		}
	}
}

void CreateItemsFile()
{
	STOREITEM item;
	item.itemcode = 1;
	strcpy(item.itemname, "Pencil");
	
	WriteItem(item);
	
	item.itemcode = 2;
	strcpy(item.itemname, "Paper");
	WriteItem(item);
	
	item.itemcode = 3;
	strcpy(item.itemname, "Mouse");
	WriteItem(item);
	
	item.itemcode = 4;
	strcpy(item.itemname, "Keyboard");
	WriteItem(item);
	
	item.itemcode = 5;
	strcpy(item.itemname, "Router");
	WriteItem(item);
}

void CreateTestTransactions()
{
	RecordTxn(1, 'R', 100);
	RecordTxn(1, 'I', (float)10);
	RecordTxn(1, 'I', (float)10.5);
	RecordTxn(2, 'R', (float)12.5);
	RecordTxn(2, 'R', (float)3.5);
}

