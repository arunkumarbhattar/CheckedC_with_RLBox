<div id="top"></div>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![LinkedIn][linkedin-shield]][linkedin-url]

<p align="center">
  <img src="./images/CheckBox.gif" alt="animated" />
</p>

  <h3 align="center">A Fusion of Checked-C and RLBOX</h3>

  <p align="center">
    A basic repository containing simple examples to get you started off!
    <br />
    <a href="https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/docs"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-C-Prototype">View Demo</a>
    ·
    <a href="https://github.com/arunkumarbhattar/CheckedC_with_RLBox/issues">Report Bug</a>
    ·
    <a href="https://github.com/arunkumarbhattar/CheckedC_with_RLBox/issues">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#what-is-rlbox">What is RLBOX?</a></li>
      </ul>
      <ul>
        <li><a href="#what-is-checked-c">What is Checked-C?</a></li>
      </ul>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project
We intend to fuse the goodness of Checked-C and RL Sandboxing to make C more secure than ever. 
While Microsoft's Checked-C already takes care of Spatial safety by encapsulating C code to Checked-C regions. 
What about "Unchecked" regions?, How can we guarantee spatial safety for unchecked regions?

Thats where we intend to use RLBOX Sandboxing. 
With a fusion of the above two, we intend to kick Legacy C's memory safety and security issues to the curb. 

Specifically, our plan is to **encapsulate unchecked regions of code into a RLBOX sandbox and allow transparent communication between checked and unchecked regions**.

## Background
### What is RLBOX?
RLBox ensures that a sandboxed library is memory isolated from the rest of the application. The library cannot directly access memory outside its designated region; and that all boundary crossings are explicit. This ensures that the library cannot, for example, corrupt program's address space. It also ensures that Firefox cannot inadvertently expose sensitive data to the library

[More Details](docs/background/rlbox.md)

### What is Checked-C?
Checked C extends C with checked pointer types which are restricted by the compiler to spatially safe uses.
Such pointers have one of three possible types, `ptr<T>` , `array_ptr<T>` ,
or `nt_array_ptr<T>` representing a pointer to a single element, array
of elements, or null-terminated array of elements of type `T`, respectively. The latter two have an
associated bounds annotation; e.g., a declaration `array_ptr<int> p : count(n)` says that `p` is a pointer
to an int array whose size is `n` . Checked C's Clang/LLVM-based compiler represents checked
pointers as system-level memory words, i.e., without “fattening” metadata ensuring backward
compatibility. 
**The bounds annotations are used to add dynamic checks on corresponding pointer
accesses to prevent spatial safety violations. Furthermore, these run-time checks are optimized
by LLVM, yielding good performance.**

[More Details](docs/background/checkedc.md)

## Our Idea
When a program is ported to completly converted to Checked C, **spatial safety is guaranteed**.
However, converting to Checked C requires some effort, and the developer may not be able to convert the entire codebase to Checked C.
As Checked C is backward compatible, a programmer is able to designate regions of code—whole files, single functions, or even single
blocks of code—**as checked regions**; these are often designated with a checked annotation. 
Such a region must contain only checked pointer types and adhere to a few other restrictions (e.g., no variadic function calls). The region is sure to be spatially safe.
We call the other not converted regions as **unchecked regions**.
However, there are no protections in unchecked regions, and thus bugs in unchecked regions can affect the execution of code in checked regions. 

To handle this, we use RLBOX. Specifically, **all unchecked functions (or unchecked regions) will be encapsulated into a RLBOX sandbox and will convert the calls to unchecked function as sandbox calls**.


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites

Firstly, you have to clone, compile and build a Checked-C Clang compiler.
This modified clang compiler will be used to compile Checked C annotated code.

Please refer to [https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/Setup-and-Build.md](https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/Setup-and-Build.md) to build your Checked-C capable Clang Compiler.

Secondly (NOT MANDATORY), you might want to install the 3c tool which would allow for a semi-automatic convertion of legacy-C code to Checked-C code.

Please refer to [https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/3C/INSTALL.md](https://github.com/correctcomputation/checkedc-clang/blob/main/clang/docs/checkedc/3C/INSTALL.md) to build your 3C tool.

(NOT MANDATORY) Now if you have a large legacy-C codebase you want to convert to checked-C, you would want to generate a one-stop-shop script that would take your codebase's compile\_commands.json file and generate you a convert\_all.sh script file. Just executing this one command will run 3C tool recursively directory to directory and file to file (C) dictated by your compile\_commands.json. 

Please refer to [https://github.com/correctcomputation/checkedc-clang/tree/main/clang/tools/3c/utils](https://github.com/correctcomputation/checkedc-clang/tree/main/clang/tools/3c/utils)

If your project does NOT contain a compile\_commands.json, you would typically make use of the **bear** utility to generate compile\_commands.json from the **Makefile**. However, if that bear does not work well, you can use **compile\_db** command. 

Please refer to [https://github.com/nickdiego/compiledb](https://github.com/nickdiego/compiledb) 

### LEGACY-C EXAMPLES

### Basic Operations -->
This example intends to use RLBOX as a mechanism to call unsafe/untrusted/unchecked functions from safe/trusted/checked functions.

[Example Directory](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-C-Prototype/examples/legacy-c/basic_operations)

#### Overview:
[Safe Library](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/examples/legacy-c/basic_operations/safe_library.c)'s main()
attempts to call unsafe function [unsafe\_int\_pointer][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/examples/legacy-c/basic_operations/unsafe_library.c#L17] through a RLBOX interface API [invoke\_unchecked\_function][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L110].

This very function takes care of all the dirty work of creating a RL-sandbox, creating tainted types, calling the unchecked/unsafe/untrusted function, followed by untainting the returned values after appropriate verification and then assigning the untainted(unwrapped) result back to the result argument. 

The function [unsafe\_char\_pointer][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/examples/legacy-c/basic_operations/unsafe_library.c#L25] also is called through its sandboxed interface API [invoke\_unchecked\_print\_function][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L119].

For more instructions on how to simulate this, please refer to README [here](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/examples/legacy-c/basic_operations/README.md)

### Struct Marshalling -->
This examples takes the above approach of uncapsulating unsafe functions within RLBOX sandbox a step higher and attempts to showcase more capabilities of the concept of RLBOX encapsulation.
This example showcases the capabilities of this concept on more of an engineering standpoint as compared to the theoretical end.

This [Project](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/tree/master/RL-C-Prototype/examples/legacy-c/struct_marshalling) aims to practicalize (through code example) the below engineering capabilities -->

1.) Parsing structs to/from a sandbox
	* Defining structs in a manner that RLBOX Sandbox understands them [lib\_struct\_file.h](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/include/library_3/lib_struct_file.h).
	* Loading structs into the RLBOX\_ENGINE [rlbox\_load\_structs\_from\_library](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/master/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L29) 

2.) Receiving and Handling a struct pointer [header](https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L54)

3.) Sandboxing a function that accepts a function pointer as an argument. [check\_here][https://github.com/arunkumarbhattar/CheckedC_with_RLBox/blob/da04c8836f5a4d5a0b52874b3f39f9f142e9a26f/RL-C-Prototype/rlbox_core_engine/rlbox_engine_main.cpp#L89] 
  
<!-- ROADMAP -->
## Roadmap (02/7/2022 - 02/14/2022)

1.) Add more WASM-sandbox examples
2.) Verify test cases based on the capabilities of memory partitioning.
3.) Add Checked-C Examples
4.) Extend 3C tool support semi-automatically convert legacy-c code to CheckBoxed code

<!-- CONTACT -->
## Contact

* Professor/Lead: [Dr. Aravind Machiry](https://machiry.github.io/)

* Lab: [PurS3](https://purs3lab.github.io/)

Researcher(s):
 * Arun Kumar Bhattar

<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/arunkumarbhattar/CheckedC_with_RLBox?style=for-the-badge
[contributors-url]: https://github.com/arunkumarbhattar/CheckedC_with_RLBox/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/arunkumarbhattar/CheckedC_with_RLBox?style=for-the-badge
[forks-url]: https://github.com/arunkumarbhattar/CheckedC_with_RLBox/network/members
[stars-shield]: https://img.shields.io/github/stars/arunkumarbhattar/CheckedC_with_RLBox?style=for-the-badge
[stars-url]: https://github.com/arunkumarbhattar/CheckedC_with_RLBox/stargazers
[issues-shield]: https://img.shields.io/bitbucket/issues/arunkumarbhattar/CheckedC_with_RLBox?style=for-the-badge
[issues-url]: https://github.com/arunkumarbhattar/CheckedC_with_RLBox/issues
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/arun-kumar-bhattar-093693148/
[product-screenshot]: images/screenshot.png
