#include <cstring>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define CAPACITY 50000 // Size of the Hash Table

unsigned long hash_function(const char* str) {
    unsigned long res = 0, g = 31;
    for (int j = 0; str[j]; j++)
        res = g * res + str[j];
    return res % CAPACITY;
}

// Define the Hash Table Item here
struct Ht_item {
    char* key;
    char* value;
};

// Define the Hash Table here
struct HashTable {
    // Contains an array of pointers
    // to items
    Ht_item** items;
    int size;
    int count;
    void Size()
    {
        cout << "This is the number of the keys which have been writtened into the table: " << count << endl << endl;
    }
};

Ht_item* create_item(const char* key, const char* value) {
    // Creates a pointer to a new hash table item
    Ht_item* item = (Ht_item*)malloc(sizeof(Ht_item));
    item->key = (char*)malloc(strlen(key) + 1);
    item->value = (char*)malloc(strlen(value) + 1);

    strcpy(item->key, key);
    strcpy(item->value, value);

    return item;
}

HashTable* create_table(int size) {
    // Creates a new HashTable
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    table->size = size;
    table->count = 0;
    table->items = (Ht_item**)calloc(table->size, sizeof(Ht_item*));
    for (int i = 0; i < table->size; i++)
        table->items[i] = NULL;

    return table;

}

void free_item(Ht_item* item) {
    // Frees an item
    free(item->key);
    free(item->value);
    free(item);
}

void free_table(HashTable* table) {
    // Frees the table
    for (int i = 0; i < table->size; i++) {
        Ht_item* item = table->items[i];
        if (item != NULL)
            free_item(item);
    }

    free(table->items);
    free(table);
}

void ht_insert(HashTable* table, const char* key, const char* value) {
    // Create the item
    Ht_item* item = create_item(key, value);

    // Compute the index
    unsigned long index = hash_function(key);

    Ht_item* current_item = table->items[index];

    if (current_item == NULL) {
        // Key does not exist.
        if (table->count == table->size) {
            // Hash Table Full
            cout << "Insert Error: Hash Table is full\n" << endl;
            // Remove the create item
            free_item(item);
            return;
        }

        // Insert directly
        table->items[index] = item;
        table->count++;
    }

    else {
        //We only need to update value
        if (strcmp(current_item->key, key) == 0) {
            strcpy(table->items[index]->value, value);
            return;
        }
    }
}

char* ht_search(HashTable* table, const char* key) {
    // Searches the key in the hashtable
    // and returns NULL if it doesn't exist
    int index = hash_function(key);
    Ht_item* item = table->items[index];

    // Ensure that we move to a non NULL item
    if (item != NULL) {
        if (strcmp(item->key, key) == 0)
            return item->value;
    }
    return NULL;
}

void get(HashTable* table, const char* key) {
    char* value;
    if ((value = ht_search(table, key)) == NULL) {
        cout << "Sorry baby, there is no element with the key \"" << key << "\" in the table " << endl << endl;
        return;
    }
    else {
        cout << "There is the value:  " << value << "   finded by the key \"" << key << "\"" << endl << endl;
    }
}

void print_table(HashTable* table) {
    cout << "This is the hash-table" << endl << endl << endl;
    for (int i = 0; i < table->size; i++) {
        if (table->items[i]) {
            cout << "Index: " << i << "\t Key: " << table->items[i]->key << "\t\t Value: " << table->items[i]->value << endl;
        }
    }
    cout << endl << endl << endl;
}