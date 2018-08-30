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
    float *myArray = (float *)calloc(CIRCULAR_BUFFER_INITIAL_LENGTH, sizeof(float));
    float *biggerArray = NULL;

    printf("Initialising the circular buffer...\n");
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
    printArray(myArray, CIRCULAR_BUFFER_INITIAL_LENGTH);

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
    printArray(myArray, CIRCULAR_BUFFER_INITIAL_LENGTH);

    printf("Resize the array to max...\n");
    changeSize(CIRCULAR_BUFFER_MAX_LENGTH);
    biggerArray = (float *) realloc(myArray, CIRCULAR_BUFFER_MAX_LENGTH * sizeof(float));

    // Check if realloc was a success
    if (biggerArray != NULL)
        myArray = biggerArray;
    else
    {
        printf("Unable to reallocate memory\n");
        exit(1);
    }

    printf("Get the circular buffer contents...\n");
    listItems(myArray);

    printf("Return the buffer contents...\n");
    printArray(myArray, CIRCULAR_BUFFER_MAX_LENGTH);

    // Free the memory used to store the data:
    free(myArray);
}
