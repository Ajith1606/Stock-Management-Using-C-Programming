typedef struct storeitem{
	
	int itemcode;
	char itemname[31];
}STOREITEM;

void InitializeItems();
int ReadItemName(int itemcode, char *itemname);
void ListItems();

STOREITEM *GetStoreItems();
int GetItemsCount();

