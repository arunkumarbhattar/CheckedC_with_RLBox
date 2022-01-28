This is a simple example that uses the RLBox API to call functions from two sandboxed CheckedC libraries. This example uses the NOOP-sandbox.

- `main.cpp` is our main program

```
make
./hello
```

Running the program should produce:

```
*****************Purely Called from Library 1
Called from Lib1 implementation
Adding... 3+4 = 7
The string * Printing this from main.cpp!
 * has been loaded to sandbox memory @ address 0x7fffffffdeb0
>Lib1 prints: Printing this from main.cpp!

*****************Purely Called from Library 2
Lib::call_cb function pointer address: 0x40b560
Length of the string is: 44,  and the string is: Callback printing this string from library2

```
