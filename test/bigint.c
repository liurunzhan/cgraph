#include "cgraph.h"
#include <stdio.h>

#define TYPE_BIGINT
#include "template.h"

int main(int argc, char *argv[])
{
    TYPE *bigint1 = FUNCTION(NAME, calloc)(DATA_ID, 20);
    TYPE *bigint2 = FUNCTION(NAME, calloc)(DATA_ID, 20);
    TYPE *bigint3 = FUNCTION(NAME, calloc)(DATA_ID, 20);

    printf("%u %ld %ld\n", bigint3->data[0], bigint3->len, bigint3->size);
    bigint1->postive = CGRAPH_TRUE;
    bigint1->data[0] = 255;
    bigint1->len = 1;
    bigint2->postive = CGRAPH_TRUE;
    bigint2->data[0] = 1;
    bigint2->data[1] = 1;
    bigint2->len = 2;

    printf("%u %ld %ld\n", bigint1->data[0], bigint1->len, bigint1->size);
    printf("%u %ld %ld\n", bigint2->data[0], bigint2->len, bigint2->size);

    FUNCTION(NAME, add)(bigint1, bigint2, bigint3);
    printf("%u %ld %ld\n", bigint3->data[0], bigint3->len, bigint3->size);
    printf("%u %ld %ld\n", bigint3->data[1], bigint3->len, bigint3->size);
    /* FUNCTION(NAME, fprintf)(stdout, bigint2, ""); */

    FUNCTION(NAME, free)(bigint1);
    FUNCTION(NAME, free)(bigint2);
    FUNCTION(NAME, free)(bigint3);

    return 0;
}

#include "template_off.h"
