#include <stdio.h>
#include "StockTxn.h"

char stkfilename[] = "./StockTxn.bin";
void ReceiptEntry()
{
	STOCK stk;
	char itemname[31];
	int itemfound;
	char opt;
	FILE *f;
	f = fopen(stkfilename, "ab");
	
	printf("\n Enter Item Code: ");
	scanf("%d", &stk.itemcode);
	fflush(stdin);
	
	itemfound = ReadItemName(stk.itemcode, itemname);
	if(itemfound == 0)
	{
		printf("\nInvalid Input..");
		return;
	}
	printf("\nItem Name : %-s", itemname);
	printf("\nIs the Item Name is correct? (Yes/No) : ");
	scanf("%c", &opt);
	
	if(opt == 'n'|| opt == 'N')
		return;
	
	printf("\nReceipt Quantity: ");
	scanf("%f", &stk.qty);
	fflush(stdin);
	
	stk.txn = 'R';
	fwrite(&stk, sizeof(STOCK), 1, f);
	fclose(f);
}

void ListTransaction()
{
	FILE *f;
	char itemname[31];
	int itemcode, itemfound;
	STOCK item;
	
	printf("\n Enter Item Code: ");
	scanf("%d", &itemcode);
	fflush(stdin);
	
	itemfound = ReadItemName(itemcode, itemname);
	if(itemfound == 0)
	{
		printf("\nInvalid Input..");
		return;
	}
	printf("\nitem Name : %-s", itemname);
	f = fopen(stkfilename, "rb");
	
	while(fread(&item, sizeof(STOCK), 1, f))
	{
		if(item.itemcode == itemcode)
		{
			printf("\n%c %10.3f", item.txn, item.qty);
		}
	}
	fclose(f);
}

