#include "export.h"

#ifdef FOO_IMPL
#   define FOO_EXPORT EXPORT
#else
#   define FOO_EXPORT IMPORT
#endif

struct FOO_EXPORT Foo {
    static constexpr int kInlineVar = 1;
    static const int kNonInlineVar = 1;
};

inline constexpr int kGlobalInlineVar = 1;

FOO_EXPORT void foo_print_address();
