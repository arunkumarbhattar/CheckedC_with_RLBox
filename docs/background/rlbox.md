## RLBOX
RLBox ensures that a sandboxed library is memory isolated from the rest of the application. The library cannot directly access memory outside its designated region; and that all boundary crossings are explicit. This ensures that the library cannot, for example, corrupt program's address space. It also ensures that Firefox cannot inadvertently expose sensitive data to the library

For more details, Please check -->
	* [RLBOX Paper](https://www.usenix.org/conference/usenixsecurity20/presentation/narayan)
	* [Developer Read](https://plsyssec.github.io/rlbox_sandboxing_api/sphinx/#passing-structs-to-from-a-sandbox)
	* [Repository](https://github.com/PLSysSec/rlbox_sandboxing_api)
