#include "linked_list.h"

int main(void){
    LinkedList* list = list_create();

    for(int i = 0; i < 10; i++){
        list_insert_last(list, i + 1);
    }

    list_print(list);
    list_destroy(list);

    return 0;

}