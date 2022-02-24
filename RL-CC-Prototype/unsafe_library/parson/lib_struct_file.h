#pragma once
//definition of structs go here (these definitions would later be auto generated and written to this file 

#define sandbox_fields_reflection_parson_class_json_array_t(f,g, ...)\
	f(json_value_t*, wrapping_value, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(json_value_t**, items, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(size_t, count, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(size_t, capacity, FIELD_NORMAL, ##__VA_ARGS__)g()

#define sandbox_fields_reflection_parson_class_json_object_t(f,g, ...)\
	f(json_value_t*, wrapping_value, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(char**, names, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(json_value_t**,values, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(size_t, count, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(size_t, capacity, FIELD_NORMAL, ##__VA_ARGS__)g() 

#define sandbox_fields_reflection_parson_class_json_value_value(f,g, ...)\
        f(char *, string, FIELD_NORMAL, ##__VA_ARGS__)g()   \
        f(double , number , FIELD_NORMAL, ##__VA_ARGS__)g()        \
        f(json_object_t* , object, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(json_array_t* , array, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(int, boolean, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(int, null, FIELD_NORMAL, ##__VA_ARGS__)g()

#define sandbox_fields_reflection_parson_class_json_value_t(f,g, ...)\
	f(json_value_t*, parent, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(int, type, FIELD_NORMAL, ##__VA_ARGS__)g() \
	f(json_value_value, value, FIELD_NORMAL, ##__VA_ARGS__)g()


#define sandbox_fields_reflection_parson_allClasses(f, ...)     \
	f(json_value_t, parson, ##__VA_ARGS__)\
	f(json_value_value, parson, ##__VA_ARGS__)\
	f(json_object_t, parson, ##__VA_ARGS__) \
	f(json_array_t, parson, ##__VA_ARGS__) 


