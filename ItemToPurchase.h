#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

/* Type your code here */
typedef struct {
    char itemName[50];
    char itemDescription[50];
    int itemPrice;
    int itemQuantity;
} ItemToPurchase;

void MakeItemBlank(ItemToPurchase* item);
void PrintItemCost(ItemToPurchase item);
void PrintItemDescription(ItemToPurchase item);
#endif
