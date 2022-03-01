# RLBox <-> Checked C interactions

This folder contains examples demonstrating how program with checked and unchecked
functions can be converted to sandboxed and host code using RLBox.


## Setup
..Setup instructions...

## Terminology
* Host: Checked region (i.e., the unsandboxed code) containing only fully checked functions.

* Sandboxed/Sandbox: Combined unchecked regions (i.e., functions within a sandbox) containing all unchecked functions.


## Checked -> Unchecked
This example demonstrates how to call an unchecked function inside noop-sandbox using different types of arguments:

* Scalar types (e.g., int, char, etc).
* Pointer to scalar types (e.g., int *, char *, etc)
* Pointer to structure types (e.g., struct foo*, etc) 

> Folder: [example\_playground\_directory](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-CC-Prototype/checked_calling_unchecked/struct_marshalling)

### Building

```
make -j4 CC=clang

```

### Running

```
./execute
```

## Unchecked -> Checked
This example demonstrates how a unchecked function inside noop-sandbox can call a function in the checked region (host) using different types of arguments:

* Scalar types (e.g., `int`, `char`, etc).
* Pointer to scalar types (e.g., `int *`, `char *`, etc)
* Pointer to structure types (e.g., `struct foo*`, etc) 

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-CC-Prototype/unchecked_to_checked/struct_marshalling)

### Building

```
make -j4 CC=clang
```

### Running

```
./execute
```

## Checked -> Checked
This example demonstrates how a unchecked function inside noop-sandbox can call a function in the checked region (host) using different types of arguments:

* Scalar types (e.g., `int`, `char`, etc).
* Pointer to scalar types (e.g., `int *`, `char *`, etc)
* Pointer to structure types (e.g., `struct foo*`, etc) 

> Folder: [struct\_marshalling](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-CC-Prototype/checked_calling_checked/struct_marshalling)

### Building

```
make -j4 CC=clang
```

### Running

```
./execute
```
## WASM-SANDBOX Checked -> Unchecked
This example demonstrates how a unchecked function inside wasm-sandbox can call a function in the checked region (host) using different types of arguments:

* Scalar types (e.g., `int`, `char`, etc).
* Pointer to scalar types (e.g., `int *`, `char *`, etc)
* Pointer to structure types (e.g., `struct foo*`, etc) 

> Folder: [struct\_marshalling\_wasm](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-CC-Prototype/checked_calling_unchecked/struct_marshalling_wasm)

### Building

```
cmake -S ./ -B ./build
cmake --build ./build --parallel
```

### Running

```
./execute
```

