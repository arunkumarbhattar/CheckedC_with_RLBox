This is a simple example that uses the RLBox API to call functions from two sandboxed CheckedC libraries. This example uses the NOOP-sandbox.

- `main.cpp` is our main program

### Build  and run

```
make
./hello
```

Running the program should produce:

```
*****************Purely Called from Library 1
Called from Lib1 implementation
Adding... 3+4 = 7
>Lib1 prints: hey, whats up!

*****************Purely Called from Library 2
Length of the string is: 20,  and the string is: Extreme Performance
```
