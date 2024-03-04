#include <stdio.h>
#include <string.h>
#include "storeitem.h"


STOREITEM items[50];
int itemscount;

char FileName[] = "./storeitems.bin";

void InitializeItems()
{
	FILE *f = fopen(FileName, "rb");
	STOREITEM item;
	itemscount = 0;
	printf("\n");
	while(fread(&item, sizeof(STOREITEM), 1, f))
	{
		itemscount++;
		items[itemscount-1].itemcode = item.itemcode;
		strcpy(items[itemscount-1].itemname, item.itemname);
		
		/* printf("%d %-s\n", item.itemcode, item.itemname); */
	}
	fclose(f);
}

STOREITEM *GetStoreItems()
{
	return items;
}

int GetItemsCount()
{
	return itemscount;
}

void WriteItem(STOREITEM item)
{
	FILE *f = fopen(FileName, "ab");
	fwrite(&item, sizeof(STOREITEM), 1, f);
	fclose(f);
}

int ReadItemName(int itemcode, char *itemname)
{
	FILE *f = fopen(FileName, "rb");
	STOREITEM item;
	int itemfound = 0;

	strcpy(itemname, "");
	while(fread(&item, sizeof(STOREITEM), 1, f))
	{
		if(item.itemcode == itemcode)
		{
			strcpy(itemname, item.itemname);
			itemfound = 1;
			break;
		}
	}
	fclose(f);
	
	return itemfound;
}

void ListItems()
{
	int itemcount = GetItemsCount();
	
	int i;
	for(i=0; i<itemcount; i++)
	{
		printf("\n%3d  %-30s", items[i].itemcode,
				items[i].itemname);
	}
	
	printf("\n\nPress a key...");
	getch();
}

