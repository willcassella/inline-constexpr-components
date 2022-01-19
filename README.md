# Taking the address of C++17 inline variables across components

C++17 introduced "inline variables", which is great for defining constants however you cannot rely on the address of 
those constants to be stable across shared objects (components). This repo is a simple demo of that issue, to test it 
out run `make -f Makefile.clang && ./main` on Linux, or on Windows run `make -f Makefile.msvc && ./main.exe` from the 
Visual Studio command prompt.

Sample output:
```
Addresses inside libfoo:
&Foo::kInlineVar = 0x7f77d3e12004
&Foo:kNonInlineVar = 0x7f77d3e12000

Addresses inside libbar:
&Foo::kInlineVar = 0x7f77d3e0d04c
&Foo::kNonInlineVar = 0x7f77d3e12000
```
