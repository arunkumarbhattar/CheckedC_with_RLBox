#include "lib.hpp"
#include "tainted_sub_functions.hpp" 

void sandboxed_image_parsing_progress(rlbox_sandbox<rlbox_sandbox_t>& sandbox, tainted_img<unsigned int> progress) {
    auto checked_progress = progress.copy_and_verify([](unsigned int value) {
        // progress is expected to be between 1 and 100, so we check this
        // However, in this case, even if we didn't check for this condition,
        // and the library returned an out of range value like 1000, no memory
        // safety issue will occur. The application would just print a very
        // confusing message "Image parsing: 1000 out of 100".
        assert(value >=1 && value <= 100);
        return value;
    });
    //then call the original C function
    image_parsing_progress(checked_progress);
    return;
}

