# CS436

Overwriting the return address located on the stack in the activation record that was created when calling func(). A buffer is inside func() that is automatically allocated on the stack as well. Filling the buffer (its length is arbitrary) is required and then corrupt the stack such that when we return from the function, the return address is now invalidated (its now the return address of some other function). This is called a buffer overflow attack. A number of bytes to write is determined to accomplish this.
