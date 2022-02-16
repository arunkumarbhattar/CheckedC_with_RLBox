[![Tests](https://github.com/PLSysSec/rlbox_wasm2c_sandbox/actions/workflows/cmake.yml/badge.svg)](https://github.com/PLSysSec/rlbox_wasm2c_sandbox/actions/workflows/cmake.yml)

# RLBox Wasm2c Sandbox Integration

Integration with RLBox sandboxing API to leverage the sandboxing in WASM modules compiled with a modified wasm2c compiler.

For details about the RLBox sandboxing APIs, see [here](https://github.com/PLSysSec/rlbox_api_cpp17).

This code has been tested on 64-bit versions of Ubuntu, Mac OSX and Windows and 32-bit versions of Ubuntu (other platforms would likely work out of the box too).

## Reporting security bugs

If you find a security bug, please do not create a public issue. Instead, file a security bug on bugzilla using the [following template link](https://bugzilla.mozilla.org/enter_bug.cgi?cc=tom%40mozilla.com&cc=nfroyd%40mozilla.com&cc=deian%40cs.ucsd.edu&cc=shravanrn%40gmail.com&component=Security%3A%20Process%20Sandboxing&defined_groups=1&groups=core-security&product=Core&bug_type=defect).

## Building/Running the tests

You can build and run the tests using cmake with the following commands.

```bash
cmake -S . -B ./build
cmake --build ./build --parallel
cmake --build ./build --target test
```

On Arch Linux you'll need to install [ncurses5-compat-libs](https://aur.archlinux.org/packages/ncurses5-compat-libs/).

## Using this tool

First, build the rlbox_wasm2c_sandbox repo with

```bash
cmake -S . -B ./build
cmake --build ./build --target all
```

This wasm2c/wasm integration with RLBox depends on 3 external tools/libraries that are pulled in **automatically** to run the tests included in this repo.

1. [A clang compiler with support for WASM/WASI backend, and the WASI sysroot](https://github.com/CraneStation/wasi-sdk). This allows you to compile C/C++ code to WASM modules usable outside of web browsers (in desktop applications).
2. [The **modified** wasm2c compiler](https://github.com/PLSysSec/wasm2c_sandbox_compiler/) that compiles the produced WASM/WASI module to C code that you can compile into a shared library with a c compiler.
3. [The RLBox APIs]((https://github.com/PLSysSec/rlbox_api_cpp17)) - A set of APIs that allow easy use of sandboxed libraries.

In the below steps, you can either use the automatically pulled in versions as described below, or download the tools yourself.

To sandbox a library of your choice and use the sandboxed library in an application follow the readme [here](https://github.com/PLSysSec/rlbox_wasm2c_sandbox/blob/master/LibrarySandbox.md)

To sandbox a full program of your choice (a program is code with main function) follow the readme [here](https://github.com/PLSysSec/rlbox_wasm2c_sandbox/blob/master/AppSandbox.md)

## Contributing Code

1. To contribute code, it is recommended you install clang-tidy which the build
uses if available. Install using:

   On Ubuntu:

   ```bash
   sudo apt install clang-tidy
   ```

   On Arch Linux:

   ```bash
   sudo pacman -S clang-tidy
   ```

2. It is recommended you use the dev mode for building during development. This
treat warnings as errors, enables clang-tidy checks, runs address sanitizer etc.
Also, you probably want to use the debug build. To do this, adjust your build
settings as shown below

   ```bash
   cmake -DCMAKE_BUILD_TYPE=Debug -DDEV=ON -S . -B ./build
   ```

3. After making changes to the source, add any new required tests and run all
tests as described earlier.

4. To make sure all code/docs are formatted with, we use clang-format.
Install using:

   On Ubuntu:

   ```bash
   sudo apt install clang-format
   ```

   On Arch Linux:

   ```bash
   sudo pacman -S clang-format
   ```

5. Format code with the format-source target:

   ```bash
   cmake --build ./build --target format-source
   ```

6. Submit the pull request.
=======
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

<!-- FOLDER STRUCTURE -->
## Folder Structure
This is the description of various folders in the repo.
## [rlbox_playground](./rlbox_playground)
This contains various examples demonstrating the basic usage and capabilities of RLBox.

## [RL-CC-Prototype](./RL-CC-Prototype)
This contains examples demonstrating how we can convert programs with checked and unchecked regions
so that unchecked regions are in a sandbox and calls between checked and unchecked functions are handled using calls through RLBox.

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
