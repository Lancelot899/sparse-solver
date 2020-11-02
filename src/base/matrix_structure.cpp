#include "base/matrix_structure.h"

#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

namespace FblockSolver {

struct ColSort
{
  bool operator()(const pair<int, int>& e1, const pair<int, int>& e2) const
  {
    return e1.second < e2.second || (e1.second == e2.second && e1.first < e2.first);
  }
};

MatrixStructure::MatrixStructure() :
  n(0), m(0), Ap(0), Aii(0), maxN(0), maxNz(0)
{
}

MatrixStructure::~MatrixStructure()
{
  free();
}

void MatrixStructure::alloc(int n_, int nz)
{
  if (n == 0) {
    maxN = n = n_;
    maxNz = nz;
    Ap  = new int[maxN + 1];
    Aii = new int[maxNz];
  }
  else {
    n = n_;
    if (maxNz < nz) {
      maxNz = 2 * nz;
      delete[] Aii;
      Aii = new int[maxNz];
    }
    if (maxN < n) {
      maxN = 2 * n;
      delete[] Ap;
      Ap = new int[maxN + 1];
    }
  }
}

void MatrixStructure::free()
{
  n = 0;
  m = 0;
  maxN = 0;
  maxNz = 0;
  delete[] Aii; Aii = 0;
  delete[] Ap; Ap = 0;
}

bool MatrixStructure::write(const char* filename) const
{
  const int& cols = n;
  const int& rows = m;

  string name = filename;
  std::string::size_type lastDot = name.find_last_of('.');
  if (lastDot != std::string::npos) 
    name = name.substr(0, lastDot);

  vector<pair<int, int> > entries;
  for (int i=0; i < cols; ++i) {
    const int& rbeg = Ap[i];
    const int& rend = Ap[i+1];
    for (int j = rbeg; j < rend; ++j) {
      entries.push_back(make_pair(Aii[j], i));
      if (Aii[j] != i)
        entries.push_back(make_pair(i, Aii[j]));
    }
  }

  sort(entries.begin(), entries.end(), ColSort());

  std::ofstream fout(filename);
  fout << "# name: " << name << std::endl;
  fout << "# type: sparse matrix" << std::endl;
  fout << "# nnz: " << entries.size() << std::endl;
  fout << "# rows: " << rows << std::endl;
  fout << "# columns: " << cols << std::endl;
  for (vector<pair<int, int> >::const_iterator it = entries.begin(); it != entries.end(); ++it) {
    const pair<int, int>& entry = *it;
    fout << entry.first << " " << entry.second << " 0" << std::endl; // write a constant value of 0
  }

  return fout.good();
}

} // end namespace
