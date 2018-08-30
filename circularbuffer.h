/*
 * Circular buffer header file
 *
 */

#ifndef __CIRCULARBUFFER_H_
#define __CIRCULARBUFFER_H_

// C++ detection:
#ifdef __cplusplus
extern "C" {
#endif

// Define DISABLE_MODULO for improved speed per add and return
#define     DISABLE_MODULO

// Length of circular buffer
#define     CIRCULAR_BUFFER_INITIAL_LENGTH         5
#define     CIRCULAR_BUFFER_MAX_LENGTH             8
// Data type to use for the circular buffer
#define     BUFF_T                                 float

// Functions
void addItem(BUFF_T item);
void initialiseCircularBuffer(void);
void listItems(BUFF_T *array);
int changeSize(unsigned int length);

#ifdef __cplusplus
}
#endif
#endif // __CIRCULARBUFFER_H_
