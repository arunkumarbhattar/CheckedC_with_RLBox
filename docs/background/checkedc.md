# Checked-C
Memory safety is absolutely crucial when working with programming languages (like C/C++) that use memory pointers to handle memory directly.
In an effort to make C even more safe, Microsoft Research has come up with the **Checked-C**. Checked-C extends C language with two additional checked pointer types: **\_Ptr<T>** and **\_Array\_ptr<T>**.

For more details, Please check -->
	* [Checked-C Paper](https://www.microsoft.com/en-us/research/uploads/prod/2018/09/checkedc-secdev2018-preprint.pdf)
	* [Repository](https://github.com/microsoft/checkedc)

## \_Ptr<T>:
Any pointer to an object that is only referenced indirectly, without any arithmetic or array subscript operations, can be replaced by \_Ptr<T>. Whenever the function holding this using this pointer is called, the compiler will confirm that it is given a valid pointer, or null. Within the function the compiler will insert a null check before writing to the pointer.

## \_Array\_ptr<T>: 
It is a pointer to array values where the programmer associates a bounds expression with each \_Array\_ptr<T>-typed variable and member to indicate where the bounds are stored. The compiler then inserts a run-time check that ensures that dereferencing an \_Array\_Ptr<T> is safe. 

## Null terminated Arrays

### \_Nt\_array_ptr<T>:
It is a pointer to an array of values (often chars) that end with a NUL('\0'). The bounds expression identifies the known-to-be-valid range of the pointer. 
This range can be expanded by reading the character just past the bounds to see if it is NUL. If not, the bounds can be expanded by one. Otherwise, the current bounds cannot be expanded, and only a '\0' may be written to this location.

After converting the codebase legacy-C to Checked-C, either manually or by using the "3C" annotation tool, the programmer is left with two regions in his codebase. 

## \_Checked regions: 
The code enclosed within the braces of this region/scope is guranteed to be spatially safe.

## \_Unchecked regions:
Although the code in this region may use Checked pointers, it is not guaranteed to be spatially safe. This could probably be due to atleast one unsafe use of pointers 
somewhere within this region.

Now, in a codebase that contains both Checked and Unchecked regions, how can we guarantee maximum spatial and memory safety?

With the use of RLBOX sandboxing mechanism, we can guarantee the even the Unchecked Regions to be memory safe. 

Every function call from a Checked Region to an Unchecked region will be encapsulated within a RLBOX sandbox. 
Therefore, before the information(memory pointers) are handed over to the Checked Region, there will be a verifier that govern the validity and safety of the memory being received. 
