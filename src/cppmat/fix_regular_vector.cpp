/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_FIX_REGULAR_VECTOR_CPP
#define CPPMAT_FIX_REGULAR_VECTOR_CPP

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace tiny {

// =================================================================================================
// constructors
// =================================================================================================

template<class X, size_t N>
inline
vector<X,N>::vector() : cppmat::tiny::array<X,1,N>()
{
}

// =================================================================================================
// constructors: copy from parent (with different type)
// =================================================================================================

template<class X, size_t N>
template<typename U, typename V>
inline
vector<X,N>::vector(const cppmat::tiny::array<U,1,N> &A) : cppmat::tiny::array<X,1,N>(A)
{
}

// =================================================================================================
// constructors: copy from other class
// =================================================================================================

template<class X, size_t N>
inline
vector<X,N>::vector(const std::vector<X> &A) : cppmat::tiny::array<X,1,N>::Copy(A)
{
}

// =================================================================================================
// constructors: copy from dynamic size
// =================================================================================================

template<class X, size_t N>
inline
vector<X,N>::vector(const cppmat::vector<X> &A) : cppmat::tiny::array<X,1,N>(A)
{
}

// =================================================================================================
// constructors: copy from view
// =================================================================================================

template<class X, size_t N>
inline
vector<X,N>::vector(const cppmat::view::vector<X,N> &A) : cppmat::tiny::array<X,1,N>(A)
{
}

// =================================================================================================
// finite difference
// =================================================================================================

template<class X, size_t N>
inline
vector<X,N> vector<X,N>::diff() const
{
  vector<X,N> out;

  std::adjacent_difference(this->begin(), this->end(), out.begin());

  return out;
}

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

