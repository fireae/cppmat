/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_MAP_REGULAR_ARRAY_H
#define CPPMAT_MAP_REGULAR_ARRAY_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace view {

// =================================================================================================
// cppmat::array
// =================================================================================================

template<class X, size_t RANK, size_t I, size_t J, size_t K, size_t L, size_t M, size_t N>
class array
{
protected:

  static const size_t MAX_DIM=6;  // maximum number of dimensions
  size_t mSize=I*J*K*L*M*N;       // total size == data.size() == prod(shape)
  size_t mRank=RANK;              // rank (number of axes)
  size_t mShape  [MAX_DIM];       // number of entries along each axis
  size_t mStrides[MAX_DIM];       // stride length for each index
  const X *mData;                 // data container

public:

  // return size without constructing
  static size_t Size();

  // constructor: allocate, don't initialize
  array();

  // constructor: map external pointer
  array(const X *D);

  // named constructor: map external pointer
  static array<X,RANK,I,J,K,L,M,N> Map(const X *D);

  // copy constructor
  operator cppmat::array<X>() const;

  // return plain storage as vector
  std::vector<X> asVector() const;

  // get dimensions
  size_t size() const;
  size_t rank() const;
  size_t shape(int    i) const;
  size_t shape(size_t i) const;
  std::vector<size_t> shape() const;
  std::vector<size_t> strides(bool bytes=false) const;

  // index operators: access plain storage
  const X& operator[](size_t i) const;

  // index operators: access using array-indices
  const X& operator()(size_t a) const;
  const X& operator()(size_t a, size_t b) const;
  const X& operator()(size_t a, size_t b, size_t c) const;
  const X& operator()(size_t a, size_t b, size_t c, size_t d) const;
  const X& operator()(size_t a, size_t b, size_t c, size_t d, size_t e) const;
  const X& operator()(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f) const;

  // index operators: access using iterator
  // N.B. the iterator points to list of array-indices (a,b,c,...)
  template<class Iterator> const X& at(Iterator first, Iterator last) const;

  // index operators: array-indices -> plain storage (a,b,c,... -> i)
  size_t compress(size_t a) const;
  size_t compress(size_t a, size_t b) const;
  size_t compress(size_t a, size_t b, size_t c) const;
  size_t compress(size_t a, size_t b, size_t c, size_t d) const;
  size_t compress(size_t a, size_t b, size_t c, size_t d, size_t e) const;
  size_t compress(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f) const;

  // index operators: plain storage -> array-indices (i -> a,b,c,...)
  std::vector<size_t> decompress(size_t i) const;

  // pointer to data
  const X* data() const;

  // iterator to first and last entry
  auto begin() const;
  auto end() const;

  // iterator to specific entry: access plain storage
  auto index(size_t i) const;

  // iterator to specific entry: access using array-indices
  auto item(size_t a) const;
  auto item(size_t a, size_t b) const;
  auto item(size_t a, size_t b, size_t c) const;
  auto item(size_t a, size_t b, size_t c, size_t d) const;
  auto item(size_t a, size_t b, size_t c, size_t d, size_t e) const;
  auto item(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f) const;

  // initialization
  void setMap(const X *D);

  // copy to target
  template<typename Iterator> void copyTo(Iterator first) const;
  template<typename Iterator> void copyTo(Iterator first, Iterator last) const;

  // absolute value
  cppmat::tiny::array<X,RANK,I,J,K,L,M,N> abs() const;

  // norm (sum of absolute values)
  X norm() const;

  // return the indices that would sort an array
  cppmat::tiny::array<size_t,RANK,I,J,K,L,M,N> argsort(bool ascending=true) const;

  // location of the minimum/maximum: plain storage (use decompress to convert to indices)
  size_t argmin() const;
  size_t argmax() const;

  // minimum
  X min() const;

  // maximum
  X max() const;

  // sum
  X sum() const;

  // mean
  double mean() const;

  // weighted average
  double average(const array<X,RANK,I,J,K,L,M,N> &weights, bool norm=true) const;

  // find the plain storage indices of all non-zero entries
  std::vector<size_t> where() const;

  // find the plain storage indices of all entries equal to some constant
  std::vector<size_t> where(X D) const;

};

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

