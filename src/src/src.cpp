#include <iostream>
#include "../include/libsort.h"

int main()
{
    array* a = create(3);

    a->nodes[0].key = 3; strcpy_s(a->nodes[0].value, 256, "!");
    a->nodes[1].key = 2; strcpy_s(a->nodes[1].value, 256, "world");
    a->nodes[2].key = 1; strcpy_s(a->nodes[2].value, 256, "hello");

    bubble_sort(a);

    for (int i = 0; i < a->num; i++) {
        printf("%s ", a->nodes[i].value);
    }
    printf("\n");

    finalize(a);
}
