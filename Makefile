# '-fvisibility=hidden' is the main culprit here, '-fvisibility-inlines-hidden' doesn't appear to make a different
# (and there is no '-fvisibility-inlines-default')
CXX=clang++ -std=c++17 -fvisibility=hidden -fvisibility-inlines-hidden

.PHONY: default clean

default: libfoo.so libbar.so main

clean:
	rm -f libfoo.so libbar.so main

foo.h: export.h
foo.cc: foo.h
bar.h: export.h
bar.cc: bar.h foo.h
main.cc: foo.h bar.h

libfoo.so: foo.cc Makefile
	$(CXX) -DFOO_IMPL -fPIC -shared foo.cc -o libfoo.so

libbar.so: bar.cc libfoo.so Makefile
	$(CXX) -DBAR_IMPL -fPIC -shared -L./ -lfoo -Wl,-rpath,./ bar.cc -o libbar.so

main: main.cc libbar.so
	$(CXX) -L./ -lfoo -lbar -Wl,-rpath,./ main.cc -o main
