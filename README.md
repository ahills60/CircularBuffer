# Circular Buffer

This is a demonstration of a circular buffer of time-series data with the ability to offload the data whenever it's necessary. This demonstration is written in C and the circular buffer can be moved to other projects if required.

This circular buffer has a basic optimisation of pre-computing pointer indices to avoid the modulo operation which can be useful for implementations that:

  * Add data many times.
  * Extract the contents of the buffer many times.
  * Do not have access to hardware support for faster modulo evaluations without the need for if statements.

  Note that this workaround requires more memory, particular for large arrays. It may therefore be necessary to consider the impact of memory versus modulo evaluation in the intended application of this circular buffer.
  