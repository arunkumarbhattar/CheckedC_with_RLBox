# RLBox Playground

This folder contains examples demonstrating various capabilities of RLBox sandbox that are relevant to the project.


### Setup
Setup instructions..

### Terminology
* Host: The unsandboxed code.

* Sandboxed/Sandbox: The functions within a sandbox.

## Demonstrative examples

These examples demonstrate basic functionalities of RLBox.

### Simple sandbox
This example demonstrates how to call a function inside sandbox using  different types of arguments:

* Scalar types (e.g., int, char, etc).
* Pointer to scalar types (e.g., int *, char *, etc)
* Pointer to structure types (e.g., struct foo*, etc) 

> Folder:

#### Building

```
```

#### Running

```
```

### Sandbox calling host
This example demonstrates how a function inside sandbox can call a function in the host using different types of arguments:

* Scalar types (e.g., `int`, `char`, etc).
* Pointer to scalar types (e.g., `int *`, `char *`, etc)
* Pointer to structure types (e.g., `struct foo*`, etc) 

> Folder:

#### Building

```
```

#### Running

```
```

## Capabilities examples

The following examples demonstrate possible error cases in host and sandbox and how RLBox handles these cases.

### Host error

What happens to the sandbox when a memory error (e.g., segfault/null-ptr dereference) occurs in the host?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: The host and sandbox should error out and exit.**

### Sandbox error

What happens to the host when a memory error (e.g., segfault/null-ptr dereference) occurs in the sandbox?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: The host should stay intact, and any future (i.e., after the sandbox crash) calls to the sandboxed functions should just error out.**
### Sandbox host memory access

What happens to the sandbox when it tries to access host memory?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: The sandbox should error out (e.g., segfault), the host should stay intact, and any future (i.e., after the sandbox crash) calls to the sandboxed functions should just error out.**
### Host Sandbox memory access

What happens to the host when it tries to access the memory that belongs to the sandbox?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: This is expected behavior. Nothing should happen to the host or sandbox.**
### Use-after-free through sandbox

What happens to the host when it tries to access the memory that belongs to the sandbox after it is freed by the sandbox?

> Folder:

#### Building

```
```

#### Running

```
```

**Expectation: ..need to figure out..**