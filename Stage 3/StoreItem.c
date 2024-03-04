#include <stdio.h>
#include <string.h>
#include "StoreItem.h"

STOREITEM items[50];
int itemcount;

char filename[] = "./Storeitem.bin";
void InitializeItems()
{
	STOREITEM item;
	FILE *f;
	f = fopen(filename, "rb");
	itemcount = 0;
	
	while(fread(&item, sizeof(STOREITEM), 1, f))
	{
		items[itemcount].itemcode = item.itemcode;
		strcpy(items[itemcount].itemname, item.itemname);
		itemcount ++;
	}
	fclose(f);
}
void ListItems()
{
	int i;
	STOREITEM item;
	printf("\nList Of Items\n");
	
	for(i=0; i<itemcount; i++)
	{
		item = items[i];
		printf("%3d %-30s", item.itemcode, item.itemname);
	}
}
int ReadItemName(int itemcode, char *itemname)
{
	int itemfound = 0;
	int i;
	for(i=0; i<itemcount; i++)
	{
		if(itemcode == items[i].itemcode)
		{
			strcpy(itemname, items[i].itemname);
			itemfound = 1;
			break;
		}
	}
	return itemfound;
}

