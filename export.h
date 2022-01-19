#if defined(_MSC_VER)
#define IMPORT __declspec(dllimport)
#define EXPORT __declspec(dllexport)
#else
#define IMPORT __attribute__((visibility("default")))
#define EXPORT IMPORT
#endif
