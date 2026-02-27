#include "linked_list.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    Element element;
    struct Node* next;
} Node;

struct LinkedList {
    Node* head;
    size_t size;
};

void list_error(const char* message) {
    fprintf(stderr, "Error: %s\n", message);
}

bool list_is_position_valid(LinkedList* list, size_t position) {
    return position < list_size(list);
}

LinkedList* list_create() {
    LinkedList* list = malloc(sizeof(LinkedList));

    list->head = NULL;
    list->size = 0;

    return list;
}

void list_destroy(LinkedList* list) {
    Node* trash = list->head;

    while (trash != NULL) {
        list->head = trash->next;

        free(trash);
        trash = list->head;
    }
    free(list);
}

void list_insert_first(LinkedList* list, Element element) {
    Node* new_node = malloc(sizeof(Node));

    new_node->element = element;
    new_node->next = list->head;
    list->head = new_node;
    list->size++;
}

void list_insert_after(LinkedList *list, size_t position, Element element) {
    if (!list_is_position_valid(list, position)) {
        list_error("Invalid position");
    } else {
        Node* cur = list->head;
        size_t i = 0;       

        while (i < position) {
            cur = cur->next;
            i++;
        }

        Node* new_node = malloc(sizeof(Node));        
        
        new_node->element = element;
        new_node->next = cur->next;
        cur->next = new_node;
        list->size++;
    }
}

void list_remove_first(LinkedList* list) {
    if (list_is_empty(list)) {
        list_error("List is empty");
    } else {
        Node* trash = list->head;

        list->head = list->head->next;
        free(trash);
        list->size--;
    }
}

void list_remove_at(LinkedList* list, size_t position) {
    if (!list_is_position_valid(list, position)) {
        list_error("Invalid position");
    } else if (position == 0) {
        list_remove_first(list);
    } else {
        Node* prev = list->head;
        size_t i = 0;

        while (i < position - 1) {
            prev = prev->next;
            i++;
        }

        Node* trash = prev->next;

        prev->next = trash->next;
        free(trash);
        list->size--;
    }
}

Element list_get_at(LinkedList* list, size_t position) {
    if (!list_is_position_valid(list, position)) {
        list_error("Invalid position");
        
        return element_null();
    } else {
        Node* cur = list->head;
        size_t i = 0;

        while (i < position) {
            cur = cur->next;
            i++;
        }

        return cur->element;
    }
}

size_t list_size(LinkedList* list) {
    return list->size;
}

bool list_is_empty(LinkedList* list) {
    return list->size == 0;
}

void list_print(LinkedList* list) {
    Node* cur = list->head;

    while (cur != NULL) {
        element_print(&cur->element);
        if (cur->next != NULL) {
            printf(" -> ");
        }
        cur = cur->next;
    }
    printf("\n");
}

/**
 * Search for an element in the list
 * 
 * @param list The list to search
 * @param element The element to search for
 * 
 * @return The position of the element in the list, or -1 if the element is not found
*/
size_t list_search(LinkedList* list, Element element) {
    Node* cur = list->head;
    size_t position = 0;

    while (cur != NULL) {
        if (element_compare(&cur->element, &element) == 0) {
            return position;
        }
        cur = cur->next;
        position++;
    }

    return -1;
}