CC=../../../RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/clang                           
CXX=../../../RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/clang++                         
CFLAGS=--sysroot /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/share/wasi-sysroot -c
LD=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/wasm-ld                          
LDLIBS=wasm2c_sandbox_wrapper.o                                                
LDFLAGS=--export-all --no-entry --growable-table                  
INC=../../../RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/share/wasi-sysroot/lib/wasm32-wasi/libc.a

execute:
	$(CC) $(CFLAGS) wasm2c_sandbox_wrapper.c -c -o wasm2c_sandbox_wrapper.o
	$(CC) $(CFLAGS) lib.c -o lib.o 
	$(LD) $(LDFLAGS) lib.o $(LDLIBS) libclang_rt.builtins-wasm32.a $(INC) -o lib.wasm  
