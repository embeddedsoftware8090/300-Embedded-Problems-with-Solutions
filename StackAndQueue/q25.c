#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for a cache node
typedef struct CacheNode {
    int key;
    int value;
    struct CacheNode* next;
    struct CacheNode* prev;
} CacheNode;

// Define a structure for the cache
typedef struct {
    int capacity;
    int size;
    CacheNode* head; // Most recently used item
    CacheNode* tail; // Least recently used item
} LRUCache;

// Initialize the cache
LRUCache* initCache(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    if (cache == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = NULL;
    cache->tail = NULL;
    return cache;
}

// Remove a cache node from the list
void removeFromList(LRUCache* cache, CacheNode* node) {
    if (node->prev != NULL) {
        node->prev->next = node->next;
    } else {
        cache->head = node->next;
    }
    if (node->next != NULL) {
        node->next->prev = node->prev;
    } else {
        cache->tail = node->prev;
    }
}

// Move a cache node to the front of the list (most recently used)
void moveToFront(LRUCache* cache, CacheNode* node) {
    if (node == cache->head) {
        return; // Already at the front
    }
    removeFromList(cache, node);
    node->next = cache->head;
    node->prev = NULL;
    if (cache->head != NULL) {
        cache->head->prev = node;
    }
    cache->head = node;
    if (cache->tail == NULL) {
        cache->tail = node;
    }
}

// Evict the least recently used item from the cache
void evict(LRUCache* cache) {
    if (cache->tail != NULL) {
        CacheNode* tailPrev = cache->tail->prev;
        if (tailPrev != NULL) {
            tailPrev->next = NULL;
        }
        free(cache->tail);
        cache->tail = tailPrev;
        if (cache->tail == NULL) {
            cache->head = NULL;
        }
        cache->size--;
    }
}

// Get a value from the cache
int get(LRUCache* cache, int key) {
    CacheNode* current = cache->head;
    while (current != NULL) {
        if (current->key == key) {
            moveToFront(cache, current);
            return current->value;
        }
        current = current->next;
    }
    return -1; // Key not found in cache
}

// Put a key-value pair into the cache
void put(LRUCache* cache, int key, int value) {
    CacheNode* current = cache->head;
    while (current != NULL) {
        if (current->key == key) {
            current->value = value;
            moveToFront(cache, current);
            return;
        }
        current = current->next;
    }

    // Key not found, add a new node
    CacheNode* newNode = (CacheNode*)malloc(sizeof(CacheNode));
    if (newNode == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }
    newNode->key = key;
    newNode->value = value;
    newNode->next = cache->head;
    newNode->prev = NULL;

    if (cache->head != NULL) {
        cache->head->prev = newNode;
    }
    cache->head = newNode;

    if (cache->tail == NULL) {
        cache->tail = newNode;
    }

    cache->size++;

    if (cache->size > cache->capacity) {
        evict(cache);
    }
}

int main() {
    LRUCache* cache = initCache(2);

    put(cache, 1, 1);
    put(cache, 2, 2);
    int val = get(cache, 1); // Returns 1
    printf("Get 1: %d\n", val);
    put(cache, 3, 3); // Evicts key 2
    val = get(cache, 2); // Returns -1 (not found)
    printf("Get 2: %d\n", val);
    put(cache, 4, 4); // Evicts key 1
    val = get(cache, 1); // Returns -1 (not found)
    printf("Get 1: %d\n", val);
    val = get(cache, 3); // Returns 3
    printf("Get 3: %d\n", val);
    val = get(cache, 4); // Returns 4
    printf("Get 4: %d\n", val);

    return 0;
}
