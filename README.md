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
