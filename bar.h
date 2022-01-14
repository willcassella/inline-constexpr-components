#include "export.h"

#ifdef BAR_IMPL
#   define BAR_EXPORT EXPORT
#else
#   define BAR_EXPORT IMPORT
#endif

BAR_EXPORT void bar_print_address();
