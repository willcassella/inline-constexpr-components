# Taking the address of C++17 inline variables across components

C++17 introduced "inline variables", which is great for defining constants in header files, however you cannot rely on 
the address of those constants to be stable across shared objects (components) if they have *hidden linker visibility*. 
This repo is a simple demo of that issue, to test it out run `make -f Makefile.clang && ./main` on Linux, or on Windows 
run `make -f Makefile.msvc && ./main.exe` from the Visual Studio command prompt. Windows only generates different 
addresses for the global inline variable due to the way its linker attributes work (which are explicitly either 
`dllimport` or `dllexport`, rather than `hidden` or `default` on Linux).

Sample output on Linux:
```
Addresses inside libfoo:
&Foo::kInlineVar = 0x7fabd420b004
&Foo:kNonInlineVar = 0x7fabd420b000
&kGlobalInlineVar = 0x7fabd420b06c

Addresses inside libbar:
&Foo::kInlineVar = 0x7fabd4206064
&Foo::kNonInlineVar = 0x7fabd420b000
&kGlobalInlineVar = 0x7fabd4206068
```
