#ifndef FBLOCKSOLVER_SOLVER_CSPARSE_API_H
#define FBLOCKSOLVER_SOLVER_CSPARSE_API_H


#ifdef _MSC_VER
// We are using a Microsoft compiler:
#ifdef FBLOCKSOLVER_SHARED_LIBS
#ifdef solver_csparse_EXPORTS
#define FBLOCKSOLVER_SOLVER_CSPARSE_API __declspec(dllexport)
#else
#define FBLOCKSOLVER_SOLVER_CSPARSE_API __declspec(dllimport)
#endif
#else
#define FBLOCKSOLVER_SOLVER_CSPARSE_API
#endif

#else
// Not Microsoft compiler so set empty definition:
#define FBLOCKSOLVER_SOLVER_CSPARSE_API
#endif

#endif // FBLOCKSOLVER_CSPARSE_API_H
