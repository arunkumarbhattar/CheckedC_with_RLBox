RLBOX and CHECKEDC FUSION

Description: Basic Program that encapsulates _Unchecked_ functions into a RLBOX sandbox. This way, even if Unchecked code's "unsafe" operations 
	     cause a crash, only the Sandbox will crash and not the entire program. This way we can achieve stronger spatial safety by encapsulating 
	     _Unchecked code in a different memory address space, thereby allowing for controlled crash, if it ever so happens.
	  
Steps to clone this repository:
git clone https://github.com/arunkumarbhattar/CheckedC_with_RLBox.git

Since we are making use of rlbox submodule for our header dependencies-->
git submodule update --force --recursive --init --remote

Steps to build:
Enter the directory: example_noop_checkedC_rlbox/
and hit make.

This will generate a hello executable, simple execute it. "./hello" 


