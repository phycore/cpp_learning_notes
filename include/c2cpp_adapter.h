#ifndef _C2CPP_ADAPTER_H
#define _C2CPP_ADAPTER_H

// clang-format off

// Imitate private members. (by opaque pointer)
typedef void* private_t;

// Imitate C++ private methods. (static function in src *.c)
#define private static

// Imiteate C++ public members. (Itsn't working in C.)
#define public_t

// Imitate C++ public methods. (Itsn't working in C.)
#define public

// Macro function to imitate C++ new and delete operator.
#define NEW_OBJECT(obj_name) struct obj_name* new_##obj_name(void)

#define DELETE_OBJECT(obj_name) void delete_##obj_name(struct obj_name* p_obj)

// clang-format on
#endif  //  _C2CPP_ADAPTER_H