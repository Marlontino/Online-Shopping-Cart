#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ItemToPurchase.h"
#include "ShoppingCart.h"

void PrintMenu() {
   printf("MENU\n");
   printf("a - Add item to cart\n");
   printf("r - Remove item from cart\n");
   printf("c - Change item quantity\n");
   printf("i - Output items' descriptions\n");
   printf("o - Output shopping cart\n");
   printf("q - Quit\n");
}

void ExecuteMenu(char userChoice, ShoppingCart cart) {
   if (userChoice == 'a') {

   }
   else if (userChoice == 'r') {
      
   }
   else if (userChoice == 'c') {
      
   }
   else if (userChoice == 'i') {
      printf("OUTPUT ITEM'S DESCRIPTIONS\n");
      PrintDescriptions(*cart);
   }
   else if (userChoice == 'o') {
      printf("OUTPUT SHOPPING CART\n");
      printf("%s's Shopping Cart - %s\n", cart->customerName, cart->currentDate);
      printf("Number of Items: %d\n\n", cart->cartSize);

      if (cart->cartSize == 0) {
       printf("SHOPPING CART IS EMPTY\n");
      } else {
         for (int i = 0; i < cart->cartSize; i++) {
            printf("%s %d @ $%d = $%d\n\n", cart->cartItems[i].itemName, cart->cartItems[i].itemQuantity, cart->cartItems[i].itemPrice, cart->cartItems[i].itemPrice * cart->cartItems[i].itemQuantity);
         }
      }
      printf("Total: $%d\n", GetCostOfCart(*cart));
   }
   else if (userChoice == 'q') {
      printf("\n");
      exit(0);
   }
   else {
      printf("\nChoose an option:");
      scanf(" %c", &userChoice);
      ExecuteMenu(userChoice, cart);
   }

}


int main(void) {
   char customerName[50];
   char currentDate[50];
   char menuChoice;
   ShoppingCart cart;

   printf("Enter Customer's Name:\n");
   fgets(customerName, sizeof(customerName), stdin);
   strtok(customerName, "\n");

   printf("Enter Today's Date:\n");
   fgets(currentDate, sizeof(currentDate), stdin);
   strtok(currentDate, "\n");

   printf("\nCustomer Name: %s\n", customerName);
   printf("Today's Date: %s\n\n", currentDate);


   do {
      PrintMenu();
      printf("\nChoose an option:");
      scanf(" %c", &menuChoice);

      if (menuChoice != 'q') {
         ExecuteMenu(menuChoice, cart);
      }
      printf("\n");
   } while (menuChoice != 'q');

   return 0;
}