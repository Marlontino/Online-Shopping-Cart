#include<stdio.h>
#include<string.h>

#include "ItemToPurchase.h"

/* Type your code here */
void MakeItemBlank(ItemToPurchase* item) {
    if (item != NULL) {
        item->itemPrice = 0;
        item->itemQuantity = 0;
        strcpy(item->itemName, "none");
        strcpy(item->itemDescription, "none");
    }
}

void PrintItemCost(ItemToPurchase item) {
    printf("%s %d @ $%d = $%d\n", item.itemName, item.itemQuantity, item.itemPrice, item.itemPrice * item.itemQuantity);
}

void PrintItemDescription(ItemToPurchase item) {
    printf("%s: %s\n", item.itemName, item.itemDescription);
}
