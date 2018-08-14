#include <stdio.h>
#include <stdlib.h>

#include "circularbuffer.h"

unsigned int circularBufferPointer = 0;
BUFF_T circularBufferArray[CIRCULAR_BUFFER_LENGTH] = {0};
#ifdef DISABLE_MODULO
unsigned int circularBufferPointersArray[CIRCULAR_BUFFER_LENGTH] = {0};
#endif

/*
 * Add an item to the circular buffer
 *
 * \param[in]   item    The item to add to the circular buffer.
 */
void addItem(BUFF_T item)
{
     circularBufferArray[circularBufferPointer] = item;

     // Increment pointer
#ifdef DISABLE_MODULO
    circularBufferPointer = circularBufferPointersArray[circularBufferPointer];
#else
    circularBufferPointer = (circularBufferPointer + 1) % CIRCULAR_BUFFER_LENGTH;
#endif
}

/*
 * Initialise the circular buffer.
 */
void initialiseCircularBuffer(void)
{
#ifdef DISABLE_MODULO
    for (unsigned int i = 0; i < CIRCULAR_BUFFER_LENGTH - 1; i++)
        circularBufferPointersArray[i] = i + 1;
#endif
}

/*
 * Return the items of the buffer array in order of oldest to newest
 *
 * \param[out]  array   The output of the time-ordered buffer
 */
void listItems(BUFF_T *array)
{
    unsigned int currPtr = circularBufferPointer;

    for (unsigned int cIdx = 0; cIdx < CIRCULAR_BUFFER_LENGTH; cIdx++)
    {
        array[cIdx] = circularBufferArray[currPtr];
#ifdef DISABLE_MODULO
        currPtr = circularBufferPointersArray[currPtr];
#else
        currPtr = (currPtr + 1) % CIRCULAR_BUFFER_LENGTH;
#endif
    }
}
