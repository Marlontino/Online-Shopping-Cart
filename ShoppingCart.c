#include "ShoppingCart.h"
#include <stdio.h>
#include <string.h>

ShoppingCart AddItem(ItemToPurchase item, ShoppingCart cart) {
   if (cart.cartSize < 10) {
      cart.cartItems[cart.cartSize] = item;
      cart.cartSize++;
   }
   return cart;
}

ShoppingCart RemoveItem(char itemName[], ShoppingCart cart) {
   // check if item is in cart
   int i, itemIndex = -1;
   for (i = 0; i < cart.cartSize; i++) {
      if (strcmp(cart.cartItems[i].itemName, itemName) == 0) {
         itemIndex = i;
         break;
      }
   }
   
   // if item is in cart, remove it and update cart
   if (itemIndex != -1) {
      for (i = itemIndex; i < cart.cartSize - 1; i++) {
         cart.cartItems[i] = cart.cartItems[i + 1];
      }
      cart.cartSize--;
   } else {
      printf("Item not found in cart. Nothing removed.\n");
   }

   return cart;
}

ShoppingCart ModifyItem(ItemToPurchase item, ShoppingCart cart) {
   int i;
   for (i = 0; i < cart.cartSize; i++) {
      if (strcmp(cart.cartItems[i].itemName, item.itemName) == 0) {
         strcpy(cart.cartItems[i].itemDescription, item.itemDescription);
         cart.cartItems[i].itemPrice = item.itemPrice;
         cart.cartItems[i].itemQuantity = item.itemQuantity;
         break;
      }
   }

   return cart;
}

int GetNumItemsInCart(ShoppingCart cart) {
   int totalQuantity = 0;
   int i;
   for (i = 0; i < cart.cartSize; i++) {
      totalQuantity += cart.cartItems[i].itemQuantity;
   }
   return totalQuantity;
}

int GetCostOfCart(ShoppingCart cart) {
  int totalCost = 0;
   int i;
   for (i = 0; i < cart.cartSize; i++) {
      totalCost += cart.cartItems[i].itemPrice * cart.cartItems[i].itemQuantity;
   }
   return totalCost;
}

void PrintDescriptions(ShoppingCart cart) {
   int i;

   printf("%s's Shopping Cart - %s\n\n", cart.customerName, cart.currentDate);
   printf("Item Descriptions\n");

   if (cart.cartSize == 0) {
      printf("SHOPPING CART IS EMPTY\n");
   } else {
      for (i = 0; i < cart.cartSize; i++) {
         printf("%s: %s\n", cart.cartItems[i].itemName, cart.cartItems[i].itemDescription);
      }
   }
}
