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



<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/arunkumarbhattar/CheckedC_with_RLBox">
    <img src="CheckBox.png" alt="Logo" width="80" height="80">
  </a>

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

Memory safety is absolutely crucial when working with programming languages (like C/C++) that use memory pointers to handle memory directly.
In an effort to make C even more safe, Microsoft Research has come up with the **Checked-C**. Checked-C extends C language with two additional checked pointer types: **\_Ptr<T>** and **\_Array\_ptr<T>**.

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

### Running Basic Projects


<!-- USAGE EXAMPLES -->
## Usage

<!-- ROADMAP -->
## Roadmap

<!-- CONTRIBUTING -->
## Contributing

<!-- LICENSE -->
## License

<!-- CONTACT -->
## Contact

<!-- ACKNOWLEDGMENTS -->
## Acknowledgments


<!-- MARKDOWN LINKS & IMAGES -->
