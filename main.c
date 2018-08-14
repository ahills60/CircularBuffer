#include <stdio.h>
#include <stdlib.h>
#include "circularbuffer.h"

void printArray(float *array, unsigned int length)
{
    for (unsigned int idx = 0; idx < length; idx++)
        printf("Item[%i] = %f\n", idx, *(array + idx));
}

int main(void)
{
    float *myArray = (float *)calloc(CIRCULAR_BUFFER_LENGTH, sizeof(float));

    printf("Initialising the ciruclar buffer...\n");
    initialiseCircularBuffer();

    printf("Adding a few items to the buffer array...\n");
    addItem(7.0);
    addItem(12.4);
    addItem(13.6);
    addItem(15.0);
    addItem(58.1);
    addItem(89.3);

    // Get the contents
    printf("Get the circular buffer contents...\n");
    listItems(myArray);

    printf("Return the buffer contents...\n");
    printArray(myArray, CIRCULAR_BUFFER_LENGTH);

    printf("Add a few more items...\n");
    addItem(107.0);
    addItem(1012.4);
    addItem(2013.6);
    addItem(18.0);
    addItem(16.2);
    addItem(1800.0);

    printf("Get the circular buffer contents...\n");
    listItems(myArray);

    printf("Return the buffer contents...\n");
    printArray(myArray, CIRCULAR_BUFFER_LENGTH);

    // Free the memory used to store the data:
    free(myArray);
}
