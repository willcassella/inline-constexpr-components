#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#define IMPORT __declspec(dllimport)
#else
#define EXPORT __attribute__((visibility("default")))
// Many projects define `IMPORT` as nothing here, causing the issue.
// You can safely define it the same way as `EXPORT` to fix this problem.
#define IMPORT
#endif
