/*
 * Circular buffer header file
 *
 */

#ifndef __CIRCULARBUFFER_H_
#define __CIRCULARBUFFER_H_

// Define DISABLE_MODULO for improved speed per add and return
#define     DISABLE_MODULO

// Length of circular buffer
#define     CIRCULAR_BUFFER_LENGTH         10
// Data type to use for the circular buffer
#define     BUFF_T                         float

// Functions
void addItem(BUFF_T item);
void initialiseCircularBuffer(void);
void listItems(BUFF_T *array);

#endif
