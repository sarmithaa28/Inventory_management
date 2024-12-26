#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Item {
    int id;
    char name[50];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];
int itemCount = 0;

// Function prototypes
void addItem();
void viewInventory();
void searchItem();
void updateItem();
void deleteItem();
void calculateTotalValue();

int main() {
    int choice;

    do {
        printf("\nInventory Management System\n");
        printf("1. Add Item\n");
        printf("2. View Inventory\n");
        printf("3. Search Item\n");
        printf("4. Update Item\n");
        printf("5. Delete Item\n");
        printf("6. Calculate Total Value\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                viewInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                calculateTotalValue();
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}

void addItem() {
    if (itemCount == MAX_ITEMS) {
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter Item ID: ");
    scanf("%d", &inventory[itemCount].id);

    printf("Enter Item Name: ");
    scanf("%s", inventory[itemCount].name);

    printf("Enter Quantity: ");
    scanf("%d", &inventory[itemCount].quantity);

    printf("Enter Price: ");
    scanf("%f", &inventory[itemCount].price);

    itemCount++;
    printf("Item added successfully!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("----------------------------------\n");
     printf("ID\tName\tQuantity\tPrice\n");
     printf("----------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].price);
    }


}

void searchItem() {
    int searchId, found = 0;
    printf("Enter Item ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == searchId) {
            printf("Item Found:\n");
            printf("ID: %d\n", inventory[i].id);
            printf("Name: %s\n", inventory[i].name);
            printf("Quantity: %d\n", inventory[i].quantity);
            printf("Price: %.2f\n", inventory[i].price);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

void updateItem() {
    int updateId, found = 0;
    printf("Enter Item ID to update: ");
    scanf("%d", &updateId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == updateId) {
            printf("Enter new Item Name: ");
            scanf("%s", inventory[i].name);

            printf("Enter new Quantity: ");
            scanf("%d", &inventory[i].quantity);

            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);

            printf("Item updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

void deleteItem() {
    int deleteId, found = 0;
    printf("Enter Item ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == deleteId) {
            // Shift items to fill the gap
            for (int j = i; j < itemCount - 1; j++) {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item not found!\n");
    }
}

void calculateTotalValue() {
    float totalValue = 0;

    for (int i = 0; i < itemCount; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }

    printf("Total Inventory Value: %.2f\n", totalValue);
}
