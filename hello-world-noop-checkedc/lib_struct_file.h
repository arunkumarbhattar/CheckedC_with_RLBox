    #define sandbox_fields_reflection_mylibheader_class_bn(f, ...) \
        f(uint32[10000], array, FIELD_NORMAL, ##__VA_ARGS__)g()\
    
    #define sandbox_fields_reflection_mylibheader_allClasses(f, ...) \
        f(bn, mylibheader, ##__VA_ARGS__)
