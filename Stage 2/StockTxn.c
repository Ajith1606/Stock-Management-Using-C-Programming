#include <stdio.h>
#include "StockTxn.h"

char stkfilename[] = "./StockTxn.bin";
void ReceiptEntry()
{
	STOCK stk;
	FILE *f;
	f = fopen(stkfilename, "ab");
	
	printf("\n Enter Item Code: ");
	scanf("%d", &stk.itemcode);
	
	printf("\nReceipt Quantity: ");
	scanf("%f", &stk.qty);
	fflush(stdin);
	
	stk.txn = 'R';
	fwrite(&stk, sizeof(STOCK), 1, f);
	fclose(f);
}

