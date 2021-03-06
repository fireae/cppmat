/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_VAR_CARTESIAN_H
#define CPPMAT_VAR_CARTESIAN_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace cartesian {

// =================================================================================================
// tensor products: ddot
// =================================================================================================

template<typename X>
cppmat::cartesian::tensor4<X> ddot(
  const cppmat::cartesian::tensor4<X> &A, const cppmat::cartesian::tensor4<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> ddot(
  const cppmat::cartesian::tensor4<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> ddot(
  const cppmat::cartesian::tensor4<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> ddot(
  const cppmat::cartesian::tensor4<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> ddot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor4<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> ddot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor4<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> ddot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor4<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X ddot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// =================================================================================================
// tensor products: dot
// =================================================================================================

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2d<X> dot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::vector<X> dot(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::vector<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::vector<X> dot(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::vector<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::vector<X> dot(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::vector<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::vector<X> dot(
  const cppmat::cartesian::vector<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::vector<X> dot(
  const cppmat::cartesian::vector<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::vector<X> dot(
  const cppmat::cartesian::vector<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
X dot(
  const cppmat::cartesian::vector<X> &A, const cppmat::cartesian::vector<X> &B
);

// =================================================================================================
// tensor products: dyadic
// =================================================================================================

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2s<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2s<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> dyadic(
  const cppmat::cartesian::tensor2d<X> &A, const cppmat::cartesian::tensor2d<X> &B
);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> dyadic(
  const cppmat::cartesian::vector<X> &A, const cppmat::cartesian::vector<X> &B
);

// =================================================================================================
// cross (outer) product
// =================================================================================================

template<typename X>
cppmat::cartesian::vector<X> cross(
  const cppmat::cartesian::vector<X> &A, const cppmat::cartesian::vector<X> &B
);

// =================================================================================================
// transpositions
// =================================================================================================

template<typename X>
cppmat::cartesian::tensor4<X> T(const cppmat::cartesian::tensor4<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> RT(const cppmat::cartesian::tensor4<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor4<X> LT(const cppmat::cartesian::tensor4<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2<X> T(const cppmat::cartesian::tensor2<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2d<X> T(const cppmat::cartesian::tensor2d<X> &A);

// =================================================================================================
// trace
// =================================================================================================

template<typename X>
X trace(const cppmat::cartesian::tensor2<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
X trace(const cppmat::cartesian::tensor2d<X> &A);

// =================================================================================================
// determinant
// =================================================================================================

template<typename X>
X det(const cppmat::cartesian::tensor2<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
X det(const cppmat::cartesian::tensor2d<X> &A);

// =================================================================================================
// inverse
// =================================================================================================

template<typename X>
cppmat::cartesian::tensor2<X> inv(const cppmat::cartesian::tensor2<X> &A);

// -------------------------------------------------------------------------------------------------

template<typename X>
cppmat::cartesian::tensor2d<X> inv(const cppmat::cartesian::tensor2d<X> &A);

// =================================================================================================
// miscellaneous tensor operations
// =================================================================================================

template<typename X>
X length(const cppmat::cartesian::vector<X> &A);

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

