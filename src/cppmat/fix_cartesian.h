/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_FIX_CARTESIAN_H
#define CPPMAT_FIX_CARTESIAN_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace cartesian {

// =================================================================================================
// tensor products: ddot
// =================================================================================================

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor4<X,ND> &A, const cppmat::tiny::cartesian::tensor4<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor4<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor4<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor4<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor4<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor4<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> ddot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor4<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X ddot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// =================================================================================================
// tensor products: dot
// =================================================================================================

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2d<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::vector<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::vector<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> dot(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::vector<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> dot(
  const cppmat::tiny::cartesian::vector<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> dot(
  const cppmat::tiny::cartesian::vector<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> dot(
  const cppmat::tiny::cartesian::vector<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X dot(
  const cppmat::tiny::cartesian::vector<X,ND> &A, const cppmat::tiny::cartesian::vector<X,ND> &B
);

// =================================================================================================
// tensor products: dyadic
// =================================================================================================

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2s<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2s<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> dyadic(
  const cppmat::tiny::cartesian::tensor2d<X,ND> &A, const cppmat::tiny::cartesian::tensor2d<X,ND> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> dyadic(
  const cppmat::tiny::cartesian::vector<X,ND> &A, const cppmat::tiny::cartesian::vector<X,ND> &B
);

// =================================================================================================
// cross (outer) product
// =================================================================================================

template<typename X, size_t ND>
cppmat::tiny::cartesian::vector<X,ND> cross(
  const cppmat::tiny::cartesian::vector<X,ND> &A, const cppmat::tiny::cartesian::vector<X,ND> &B
);

// =================================================================================================
// transpositions
// =================================================================================================

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> T(const cppmat::tiny::cartesian::tensor4<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> RT(const cppmat::tiny::cartesian::tensor4<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor4<X,ND> LT(const cppmat::tiny::cartesian::tensor4<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> T(const cppmat::tiny::cartesian::tensor2<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2d<X,ND> T(const cppmat::tiny::cartesian::tensor2d<X,ND> &A);

// =================================================================================================
// trace
// =================================================================================================

template<typename X, size_t ND>
X trace(const cppmat::tiny::cartesian::tensor2<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X trace(const cppmat::tiny::cartesian::tensor2d<X,ND> &A);

// =================================================================================================
// determinant
// =================================================================================================

template<typename X, size_t ND>
X det(const cppmat::tiny::cartesian::tensor2<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
X det(const cppmat::tiny::cartesian::tensor2d<X,ND> &A);

// =================================================================================================
// inverse
// =================================================================================================

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2<X,ND> inv(const cppmat::tiny::cartesian::tensor2<X,ND> &A);

// -------------------------------------------------------------------------------------------------

template<typename X, size_t ND>
cppmat::tiny::cartesian::tensor2d<X,ND> inv(const cppmat::tiny::cartesian::tensor2d<X,ND> &A);

// =================================================================================================
// miscellaneous tensor operations
// =================================================================================================

template<typename X, size_t ND>
X length(const cppmat::tiny::cartesian::vector<X,ND> &A);

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

