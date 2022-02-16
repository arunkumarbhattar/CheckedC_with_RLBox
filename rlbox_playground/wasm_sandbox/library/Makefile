CC=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/clang                           
CXX=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/clang++                         
CFLAGS=--sysroot /home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/share/wasi-sysroot
LD=/home/arunman_rb32/CheckedC_with_RLBox/RL-C-Prototype/rlbox_wasm2c_sandbox/build/_deps/wasiclang-src/bin/wasm-ld                          
LDLIBS=wasm2c_sandbox_wrapper.o                                                
LDFLAGS=--export-all --no-entry --growable-table                   

execute:
	$(CC) $(CFLAGS) wasm2c_sandbox_wrapper.c -c -o wasm2c_sandbox_wrapper.o

