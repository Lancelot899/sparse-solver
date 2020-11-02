#ifndef FBLOCKSOLVER_CSPARSE_EXTENSION_API_H
#define FBLOCKSOLVER_CSPARSE_EXTENSION_API_H

#ifdef _MSC_VER
// We are using a Microsoft compiler:
#ifdef FBLOCKSOLVER_LGPL_SHARED_LIBS
#ifdef csparse_extension_EXPORTS
#define FBLOCKSOLVER_CSPARSE_EXTENSION_API __declspec(dllexport)
#else
#define FBLOCKSOLVER_CSPARSE_EXTENSION_API __declspec(dllimport)
#endif
#else
#define FBLOCKSOLVER_CSPARSE_EXTENSION_API
#endif

#else
// Not Microsoft compiler so set empty definition:
#define FBLOCKSOLVER_CSPARSE_EXTENSION_API
#endif

#endif // FBLOCKSOLVER_CSPARSE_API_H
