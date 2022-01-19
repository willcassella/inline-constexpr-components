#include <stdio.h>
#include "bar.h"
#include "foo.h"

void bar_print_address() {
    printf("Addresses inside libbar:\n");
    printf("&Foo::kInlineVar = %p\n", &Foo::kInlineVar);
    printf("&Foo::kNonInlineVar = %p\n", &Foo::kNonInlineVar);
    printf("&kGlobalInlineVar = %p\n", &kGlobalInlineVar);
}
