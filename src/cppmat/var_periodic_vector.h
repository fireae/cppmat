/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_VAR_PERIODIC_VECTOR_H
#define CPPMAT_VAR_PERIODIC_VECTOR_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace periodic {

// =================================================================================================
// cppmat::vector
// =================================================================================================

template<class X>
class vector : public cppmat::periodic::array<X>
{
protected:

  int N=0; // number of entries

private:

  // hide functions
  using cppmat::periodic::array<X>::reshape;
  using cppmat::periodic::array<X>::chrank;

public:

  // constructor
  vector() = default;

  // constructor: allocate, don't initialize
  vector(size_t n);

  // constructor: copy
  vector(const cppmat::periodic::array<X> &A);

  // constructor: copy
  vector(const std::vector<X> &D);

  // constructor: initialize
  static vector<X> Random  (size_t n, X lower=(X)0, X upper=(X)1);
  static vector<X> Arange  (size_t n);
  static vector<X> Zero    (size_t n);
  static vector<X> Ones    (size_t n);
  static vector<X> Constant(size_t n, X D);

  // constructor: copy
  template<typename Itr> static vector<X> Copy(size_t n, Itr first);
  template<typename Itr> static vector<X> Copy(size_t n, Itr first, Itr last);

  // resize
  void resize(size_t n);

  // forward difference (x0, x1-x0, x2-x1, ...)
  vector<X> diff() const;

};

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

