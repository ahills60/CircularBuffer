/*
 * CircularBuffer
 *
 * An implementation of a circular buffer with cache
 *
 *  Author: Andrew Hills (a.hills@sheffield.ac.uk)
 * Version: 1.1 (2018-08-30)
 */

#include <stdio.h>
#include <stdlib.h>

#include "circularbuffer.h"

unsigned int circularBufferCurrentLength = CIRCULAR_BUFFER_INITIAL_LENGTH;
unsigned int circularBufferPointer = 0;
BUFF_T circularBufferArray[CIRCULAR_BUFFER_MAX_LENGTH] = {0};
#ifdef DISABLE_MODULO
unsigned int circularBufferPointersArray[CIRCULAR_BUFFER_MAX_LENGTH] = {0};
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
    for (unsigned int i = 0; i < CIRCULAR_BUFFER_MAX_LENGTH - 1; i++)
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
    int currPtr = circularBufferPointer - circularBufferCurrentLength;

    if (currPtr < 0)
        currPtr += CIRCULAR_BUFFER_MAX_LENGTH;

    for (unsigned int cIdx = 0; cIdx < circularBufferCurrentLength; cIdx++)
    {
        array[cIdx] = circularBufferArray[currPtr];
#ifdef DISABLE_MODULO
        currPtr = circularBufferPointersArray[currPtr];
#else
        currPtr = (currPtr + 1) % CIRCULAR_BUFFER_MAX_LENGTH;
#endif
    }
}

/*
 * Change the size of the buffer array
 *
 * \param[in]   length  The size of the buffer array to return
 * \return      A status code: 0 on success, -1 on error
 */
int changeSize(unsigned int length)
{
    // Validate the size
    if (length > CIRCULAR_BUFFER_MAX_LENGTH)
    {
        printf("ERROR: Exceeded the maximum size of the circular buffer\n");
        return -1;
    }
    else if (length < 1)
    {
        printf("ERROR: The size of the circular buffer must be at least 1\n");
        return -1;
    }

    // Set the size
    circularBufferCurrentLength = length;
    return 0;
}
