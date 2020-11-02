#ifndef _AFXDEX_H_H
#define _AFXDEX_H_H

using number_t = double;

#ifdef _MSC_VER
// We are using a Microsoft compiler:
#ifdef FBLOCKSOLVER_SHARED_LIBS
#ifdef core_EXPORTS
#define FBLOCKSOLVER_CORE_API __declspec(dllexport)
#else
#define FBLOCKSOLVER_CORE_API __declspec(dllimport)
#endif
#else
#define FBLOCKSOLVER_CORE_API
#endif

#else
// Not Microsoft compiler so set empty definition:
#define FBLOCKSOLVER_CORE_API
#endif

#include "eigen_types.h"


#endif