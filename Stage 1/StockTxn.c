#include <stdio.h>
#include "StockTxn.h"

char stkfilename[] = "./StockTxn.bin";

void ReceiptEntry()
{
	STOCK stk;
	
	printf("\nEnter the Item Code : ");
	scanf("%d", &stk.itemcode);

	printf("Enter the Receipt Quantity :");
	scanf("%f", &stk.qty);
	fflush(stdin);
	
	stk.txn = 'R';
	FILE *f = fopen(stkfilename,"ab");
	fwrite(&stk, sizeof(STOCK), 1, f);
	fclose(f);
}

