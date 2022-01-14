#include <stdio.h>
#include "foo.h"

// This *must* be defined
const int Foo::kNonInlineVar;

// This may be defined, but it makes no difference
constexpr int Foo::kInlineVar;

void foo_print_address() {
    printf("Addresses inside libfoo:\n");
    printf("&Foo::kInlineVar = %p\n", &Foo::kInlineVar);
    printf("&Foo:kNonInlineVar = %p\n", &Foo::kNonInlineVar);
}
