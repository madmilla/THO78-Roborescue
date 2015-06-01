#if defined(_WIN64) || defined(_WIN32)
#include "serialWin.cpp"
#elif defined(linux)
#include "serialLinux.cpp"
#else
Error OS not defined.
#endif
