#pragma once

#ifdef __cplusplus
extern "C" {
#endif
    void hello();
    unsigned add(unsigned, unsigned);
    void echo(const char* str : itype(_Nt_array_ptr<const char>));
#ifdef __cplusplus
}
#endif
