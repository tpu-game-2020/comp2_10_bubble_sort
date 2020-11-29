#include <iostream>
#include "../include/libsort.h"

int main()
{
    list list;
    initialize(&list);

    add_node(&list, 2, "world");
    add_node(&list, 1, "hello");
    add_node(&list, 3, "!");

    bubble_sort(&list);

    for (node* p = list.head; p != NULL; p = p->next) {
        printf("%s ", p->value);
    }
    printf("\n");

    finalize(&list);
}
