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




 						![](./images/CheckBox.mp4)

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

### What is RLBOX?
RLBox ensures that a sandboxed library is memory isolated from the rest of the application. The library cannot directly access memory outside its designated region; and that all boundary crossings are explicit. This ensures that the library cannot, for example, corrupt program's address space. It also ensures that Firefox cannot inadvertently expose sensitive data to the library

For more details, Please check -->
	* [RLBOX Paper](https://www.usenix.org/conference/usenixsecurity20/presentation/narayan)
	* [Developer Read](https://plsyssec.github.io/rlbox_sandboxing_api/sphinx/#passing-structs-to-from-a-sandbox)
	* [Repository](https://github.com/PLSysSec/rlbox_sandboxing_api)

### What is Checked-C?
Memory safety is absolutely crucial when working with programming languages (like C/C++) that use memory pointers to handle memory directly.
In an effort to make C even more safe, Microsoft Research has come up with the **Checked-C**. Checked-C extends C language with two additional checked pointer types: **\_Ptr<T>** and **\_Array\_ptr<T>**.

For more details, Please check -->
	* [Checked-C Paper](https://www.microsoft.com/en-us/research/uploads/prod/2018/09/checkedc-secdev2018-preprint.pdf)
	* [Repository](https://github.com/microsoft/checkedc)

#### \_Ptr<T>:
Any pointer to an object that is only referenced indirectly, without any arithmetic or array subscript operations, can be replaced by \_Ptr<T>. Whenever the function holding this using this pointer is called, the compiler will confirm that it is given a valid pointer, or null. Within the function the compiler will insert a null check before writing to the pointer.

#### \_Array\_ptr<T>: 
It is a pointer to array values where the programmer associates a bounds expression with each \_Array\_ptr<T>-typed variable and member to indicate where the bounds are stored. The compiler then inserts a run-time check that ensures that dereferencing an \_Array\_Ptr<T> is safe. 

#### Null terminated Arrays

#### \_Nt\_array_ptr<T>:
It is a pointer to an array of values (often chars) that end with a NUL('\0'). The bounds expression identifies the known-to-be-valid range of the pointer. 
This range can be expanded by reading the character just past the bounds to see if it is NUL. If not, the bounds can be expanded by one. Otherwise, the current bounds cannot be expanded, and only a '\0' may be written to this location.

After converting the codebase legacy-C to Checked-C, either manually or by using the "3C" annotation tool, the programmer is left with two regions in his codebase. 

#### \_Checked regions: 
The code enclosed within the braces of this region/scope is guranteed to be spatially safe.

#### \_Unchecked regions:
Although the code in this region may use Checked pointers, it is not guaranteed to be spatially safe. This could probably be due to atleast one unsafe use of pointers 
somewhere within this region.

Now, in a codebase that contains both Checked and Unchecked regions, how can we guarantee maximum spatial and memory safety?

With the use of RLBOX sandboxing mechanism, we can guarantee the even the Unchecked Regions to be memory safe. 

Every function call from a Checked Region to an Unchecked region will be encapsulated within a RLBOX sandbox. 
Therefore, before the information(memory pointers) are handed over to the Checked Region, there will be a verifier that govern the validity and safety of the memory being received. 

<p align="right">(<a href="#top">back to top</a>)</p>

### Built With

* [C](https://www.gnu.org/software/libc/manual/html_node/index.html)
* [C++](https://www.cplusplus.com/reference/)
* [Clang](https://github.com/correctcomputation/checkedc-clang)

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

### Prerequisites/Installations

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

<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- LICENSE -->
## License

<!-- CONTACT -->
## Contact

Professor/Lead: [Dr. Aravind Machiry](https://machiry.github.io/)
Lab: [PurS3](https://purs3lab.github.io/)

Developers:
1.) Arun Kumar Bhattar

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
