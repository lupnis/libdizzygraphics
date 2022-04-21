#ifndef LIBDIZZYGRAPHICS_GLOBAL_H
#define LIBDIZZYGRAPHICS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(LIBDIZZYGRAPHICS_LIBRARY)
#  define LIBDIZZYGRAPHICS_EXPORT Q_DECL_EXPORT
#else
#  define LIBDIZZYGRAPHICS_EXPORT Q_DECL_IMPORT
#endif

#endif // LIBDIZZYGRAPHICS_GLOBAL_H