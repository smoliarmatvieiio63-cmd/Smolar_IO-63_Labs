#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define CAPACITY 5

typedef struct Node {
    char data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int count;
} ListLogBuffer;

void list_buffer_init(ListLogBuffer *cb) {
    cb->head = NULL;
    cb->tail = NULL;
    cb->count = 0;
}

bool list_buffer_is_empty(const ListLogBuffer *cb) {
    return cb->count == 0;
}

bool list_buffer_is_full(const ListLogBuffer *cb) {
    return cb->count == CAPACITY;
}

bool list_buffer_dequeue(ListLogBuffer *cb, char *out_val) {
    if (list_buffer_is_empty(cb)) {
        return false;
    }
    Node *temp = cb->head;
    if (out_val != NULL) {
        *out_val = temp->data;
    }
    cb->head = cb->head->next;
    free(temp);
    cb->count--;

    if (cb->head == NULL) {
        cb->tail = NULL;
    }
    return true;
}

void list_buffer_enqueue(ListLogBuffer *cb, char c) {
    if (list_buffer_is_full(cb)) {
        char dropped;
        list_buffer_dequeue(cb, &dropped);
        printf("[List LogBuffer] Buffer full! Dropped oldest '%c', added '%c'\n", dropped, c);
    } else {
        printf("[List LogBuffer] Added '%c'\n", c);
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        fprintf(stderr, "Memory allocation error!\n");
        return;
    }
    new_node->data = c;
    new_node->next = NULL;

    if (list_buffer_is_empty(cb)) {
        cb->head = new_node;
        cb->tail = new_node;
    } else {
        cb->tail->next = new_node;
        cb->tail = new_node;
    }
    cb->count++;
}

void list_buffer_print(const ListLogBuffer *cb) {
    if (list_buffer_is_empty(cb)) {
        printf("Buffer is empty [ ] (0/%d)\n", CAPACITY);
        return;
    }
    printf("Content (oldest -> newest): [ ");
    Node *curr = cb->head;
    while (curr != NULL) {
        printf("%c ", curr->data);
        curr = curr->next;
    }
    printf("] (%d/%d)\n", cb->count, CAPACITY);
}

void list_buffer_free(ListLogBuffer *cb) {
    while (!list_buffer_is_empty(cb)) {
        list_buffer_dequeue(cb, NULL);
    }
}

int main(void) {
    printf("=== TESTING LINKED LIST IMPLEMENTATION (LIST LOG BUFFER) ===\n");
    ListLogBuffer buf;
    list_buffer_init(&buf);

    char val;

    printf("\n--- Test 1: Dequeue from an empty buffer ---\n");
    if (!list_buffer_dequeue(&buf, &val)) {
        printf("Success: Dequeue on empty buffer returned false without crashing.\n");
    }

    printf("\n--- Test 2: Filling buffer to maximum capacity (5 elements) ---\n");
    list_buffer_enqueue(&buf, 'A');
    list_buffer_enqueue(&buf, 'B');
    list_buffer_enqueue(&buf, 'C');
    list_buffer_enqueue(&buf, 'D');
    list_buffer_enqueue(&buf, 'E');
    list_buffer_print(&buf);
    printf("\n--- Test 3: Adding new elements to full buffer ---\n");
    list_buffer_enqueue(&buf, 'F');
    list_buffer_enqueue(&buf, 'G');
    list_buffer_print(&buf);
    list_buffer_free(&buf);
    return 0;
}