#include <cstdlib>

#define LOAD_FACTOR 20

struct LinkedListNode {
    int data;
    LinkedListNode* next;
};

struct HashTableNode {
    int key;
    int count;
    LinkedListNode* next;
};

struct HashTable {
    int size;
    int count;
    HashTableNode** hash_table;
};

HashTable* CreateHashTable(int size);
int Hash(int data, int size);
int Insert(HashTable* hash_table, int data);
int Delete(HashTable* hash_table, int data);
void Rehash(HashTable* hash_table);


HashTable* CreateHashTable(int size) {
    HashTable* hash_table = (HashTable*) malloc(sizeof(HashTable));
    
    hash_table->size = size;
    hash_table->count = 0;
    hash_table->hash_table = (HashTableNode**) malloc(sizeof(HashTableNode*) * hash_table->size);

    for (int i(0); i < hash_table->size; ++i) {
        hash_table->hash_table[i] = (HashTableNode*) malloc(sizeof(HashTableNode));

        hash_table->hash_table[i]->count = 0;
        hash_table->hash_table[i]->next = NULL;
    }

    return hash_table;
}

int Hash(int data, int size) {
    return data % size;
}

int Search(HashTable* hash_table, int data) {
    int key(Hash(data, hash_table->size));
    LinkedListNode* linked_list_node(hash_table->hash_table[key]->next);

    while (linked_list_node) {
        if (linked_list_node->data == data) {
            return 1;
        }

        linked_list_node = linked_list_node->next;
    }

    return 0;
}

int Insert(HashTable* hash_table, int data) {
    if (Search(hash_table, data)) {
        return 0;
    }

    int key(Hash(data, hash_table->size));
    LinkedListNode* linked_list_node = (LinkedListNode*) malloc(sizeof(LinkedListNode));

    linked_list_node->data = data;
    linked_list_node->next = hash_table->hash_table[key]->next;

    hash_table->hash_table[key]->key = key;
    hash_table->hash_table[key]->next = linked_list_node;
    hash_table->hash_table[key]->count++;
    hash_table->count++;

    if (hash_table->count / hash_table->size > LOAD_FACTOR) {
        Rehash(hash_table);
    }

    return 1;
}

int Delete(HashTable* hash_table, int data) {
    int key(Hash(data, hash_table->size));
    LinkedListNode* current;
    LinkedListNode* previous;

    for (
        current = hash_table->hash_table[key]->next, previous = NULL;
        previous;
        previous = current, current = current->next
    ) {
        if (current->data == data) {
            if (previous) {
                previous->next = current->next;
            }

            free(current);

            hash_table->hash_table[key]->count--;
            hash_table->count--;

            return 1;
        }
    }

    return 0;
}

void Rehash(HashTable* hash_table) {
    HashTable* old_hash_table(hash_table);
    hash_table->size = old_hash_table->size * 2;
    hash_table->hash_table = (HashTableNode**) malloc(sizeof(HashTableNode*) * hash_table->size);

    for (int i(0); i < hash_table->size; ++i) {
        hash_table->hash_table[i] = (HashTableNode*) malloc(sizeof(HashTableNode));

        hash_table->hash_table[i]->count = 0;
        hash_table->hash_table[i]->next = NULL;
    }

    for (int i(0); i < old_hash_table->size; ++i) {
        HashTableNode* hash_table_node = old_hash_table->hash_table[i];
        LinkedListNode* linked_list_node = hash_table_node->next;

        while(linked_list_node) {
            Insert(hash_table, linked_list_node->data);

            linked_list_node = linked_list_node->next;
        }
    }
}
