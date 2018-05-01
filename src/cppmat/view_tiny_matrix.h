/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_VIEW_MATRIX2_H
#define CPPMAT_VIEW_MATRIX2_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace view {

// =================================================================================================
// alias name-space with "normal" class
// =================================================================================================

namespace reg = cppmat::tiny;

// =================================================================================================
// cppmat::view::matrix
// =================================================================================================

template<class X, size_t m, size_t n>
class matrix
{
private:

  const X *m_data;    // pointer to data (points outside)
  size_t m_size=m*n;  // total number of entries

public:

  // constructor
  matrix();

  // constructor: map external pointer
  static matrix<X,m,n> Map(const X *D);

  // reset external pointer
  void setMap(const X *D);

  // get dimensions
  size_t size() const;
  size_t ndim() const;
  size_t shape(int    i) const;
  size_t shape(size_t i) const;
  std::vector<size_t> shape() const;
  std::vector<size_t> strides(bool bytes=false) const;

  // index operators: access plain storage
  const X& operator[](size_t i) const;

  // index operators: access using matrix indices
  const X& operator()(size_t a) const;
  const X& operator()(size_t a, size_t b) const;

  // pointer to data
  const X* data() const;

  // iterator to first and last entry
  auto begin() const;
  auto end() const;

  // basic algebra
  X      minCoeff() const;
  X      maxCoeff() const;
  X      sum() const;
  double mean() const;
  double average(const matrix<X,m,n> &weights) const;

  // formatted print; NB also "operator<<" is defined
  void printf(std::string fmt) const;

};

// arithmetic operators
template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator* (const matrix<X,m,n> &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator/ (const matrix<X,m,n> &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator+ (const matrix<X,m,n> &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator- (const matrix<X,m,n> &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator* (const matrix<X,m,n> &A, const        X      &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator/ (const matrix<X,m,n> &A, const        X      &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator+ (const matrix<X,m,n> &A, const        X      &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator- (const matrix<X,m,n> &A, const        X      &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator* (const        X      &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator/ (const        X      &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator+ (const        X      &A, const matrix<X,m,n> &B);

template<class X, size_t m, size_t n>
inline reg::matrix<X,m,n> operator- (const        X      &A, const matrix<X,m,n> &B);

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif
