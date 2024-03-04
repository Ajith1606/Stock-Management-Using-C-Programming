#ifndef STOREH
#define STOREH

 
typedef struct storeitem{
	int itemcode;
	char itemname[31];		/* Maximum 30 characters Long */
} STOREITEM;


void InitializeItems();
void WriteItem(STOREITEM item);
STOREITEM *GetStoreItems();
int GetItemsCount();
int ReadItemName(int itemcode, char *itemname);
void ListItems();
#endif

