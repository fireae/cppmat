/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_VAR_SYMMETRIC_MATRIX_H
#define CPPMAT_VAR_SYMMETRIC_MATRIX_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace symmetric {

// =================================================================================================
// cppmat::symmetric::matrix
// =================================================================================================

template<typename X>
class matrix
{
protected:

  size_t              mSize=0;          // total size == data.size()
  static const size_t mRank=2;          // rank (number of axes)
  size_t              N=0;              // number of rows/columns
  std::vector<X>      mData;            // data container
  bool                mPeriodic=false;  // if true: disable bounds-check where possible

public:

  // constructor: default
  matrix() = default;

  // constructor: allocate, don't initialize
  matrix(size_t m, size_t n);

  // constructor: copy from own class (with different type)
  template<typename U, typename=typename std::enable_if<std::is_convertible<U,X>::value>::type>
  matrix(const cppmat::symmetric::matrix<U> &A);

  // constructor: copy from other class
  matrix(const cppmat::diagonal::matrix<X> &A);

  // constructor: copy from fixed size
  template<size_t m, size_t n> matrix(const cppmat::tiny::symmetric::matrix<X,m,n> &A);

  // constructor: copy from view
  template<size_t m, size_t n> matrix(const cppmat::view::symmetric::matrix<X,m,n> &A);

  // named constructor: initialize
  static matrix<X> Random  (size_t m, size_t n, X lower=(X)0, X upper=(X)1);
  static matrix<X> Arange  (size_t m, size_t n);
  static matrix<X> Zero    (size_t m, size_t n);
  static matrix<X> Ones    (size_t m, size_t n);
  static matrix<X> Constant(size_t m, size_t n, X D);
  static matrix<X> Copy    (size_t m, size_t n, const std::vector<X> &D);

  // named constructor: copy
  template<typename Itr> static matrix<X> Copy     (size_t m, size_t n, Itr first);
  template<typename Itr> static matrix<X> Copy     (size_t m, size_t n, Itr first, Itr last);
  template<typename Itr> static matrix<X> CopyDense(size_t m, size_t n, Itr first);
  template<typename Itr> static matrix<X> CopyDense(size_t m, size_t n, Itr first, Itr last);

  // return plain storage as vector
  template<typename U, typename=typename std::enable_if<std::is_convertible<U,X>::value>::type>
  operator std::vector<U> () const;

  // resize
  void resize(size_t m, size_t n);
  void resize(size_t m, size_t n, const X &D);

  // modify bounds-checks
  void setPeriodic(bool periodic);

  // get dimensions
  size_t size() const;
  size_t rank() const;
  size_t shape(int    i) const;
  size_t shape(size_t i) const;
  std::vector<size_t> shape() const;

  // get using a different return type
  template<typename U> U size() const;
  template<typename U> U rank() const;
  template<typename U> U shape(int    i) const;
  template<typename U> U shape(size_t i) const;
  template<typename U> std::vector<U> shape() const;

  // index operators: access plain storage
  X&       operator[](size_t i);
  const X& operator[](size_t i) const;

  // index operators: access using matrix-indices
  X&       operator()(int a, int b);
  const X& operator()(int a, int b) const;

  // index operators: access using matrix-indices
  template<typename T, typename=typename std::enable_if<std::is_unsigned<T>::value,void>::type>
  X&       operator()(T a, T b);

  template<typename T, typename=typename std::enable_if<std::is_unsigned<T>::value,void>::type>
  const X& operator()(T a, T b) const;

  // index operators: matrix-indices -> plain storage (a,b -> i)
  size_t compress(int a, int b) const;

  // index operators: matrix-indices -> plain storage (a,b -> i)
  template<typename T, typename=typename std::enable_if<std::is_unsigned<T>::value,void>::type>
  size_t compress(T a, T b) const;

  // index operators: plain storage -> matrix-indices (i -> a,b)
  std::vector<size_t> decompress(size_t i) const;

  // get index of the midpoint (along a certain axis)
  std::vector<size_t> midpoint() const;
  size_t              midpoint(size_t axis) const;

  // pointer to data
  X*       data();
  const X* data() const;

  // iterator to first and last entry
  auto begin();
  auto begin() const;
  auto end();
  auto end() const;

  // iterator to specific entry: access plain storage
  auto index(size_t i);
  auto index(size_t i) const;

  // iterator to specific entry: access using matrix-indices
  auto item(int a, int b);
  auto item(int a, int b) const;

  // iterator to specific entry: access using matrix-indices
  template<typename T, typename=typename std::enable_if<std::is_unsigned<T>::value,void>::type>
  auto item(T a, T b);

  template<typename T, typename=typename std::enable_if<std::is_unsigned<T>::value,void>::type>
  auto item(T a, T b) const;

  // initialization
  void setRandom(X lower=(X)0, X upper=(X)1);
  void setArange();
  void setZero();
  void setOnes();
  void setConstant(X D);
  template<typename Iterator> void setCopy     (Iterator first);
  template<typename Iterator> void setCopy     (Iterator first, Iterator last);
  template<typename Iterator> void setCopyDense(Iterator first);
  template<typename Iterator> void setCopyDense(Iterator first, Iterator last);

  // copy to target
  template<typename Iterator> void copyTo     (Iterator first) const;
  template<typename Iterator> void copyTo     (Iterator first, Iterator last) const;
  template<typename Iterator> void copyToDense(Iterator first) const;
  template<typename Iterator> void copyToDense(Iterator first, Iterator last) const;

  // check in an index in within the matrix bound:
  // ( a >= 0 and a < shape[0] ) or ( periodic )
  template<typename T> bool inBounds(T a) const;
  template<typename T> bool inBounds(T a, T b) const;

  // sign change
  matrix<X> operator- () const;
  matrix<X> operator+ () const;

  // arithmetic operators
  matrix<X>& operator*= (const cppmat::symmetric::matrix<X> &B);
  matrix<X>& operator/= (const cppmat::symmetric::matrix<X> &B);
  matrix<X>& operator+= (const cppmat::symmetric::matrix<X> &B);
  matrix<X>& operator-= (const cppmat::symmetric::matrix<X> &B);
  matrix<X>& operator*= (X B);
  matrix<X>& operator/= (X B);
  matrix<X>& operator+= (X B);
  matrix<X>& operator-= (X B);

  // extra arithmetic operators
  matrix<X>& operator*= (const cppmat::diagonal ::matrix<X> &B);
  matrix<X>& operator+= (const cppmat::diagonal ::matrix<X> &B);
  matrix<X>& operator-= (const cppmat::diagonal ::matrix<X> &B);

  // absolute value
  matrix<X> abs() const;

  // norm (sum of absolute values)
  X norm() const;

  // return the indices that would sort the matrix
  matrix<size_t> argsort(bool ascending=true) const;

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
  double average(const matrix<X> &weights, bool norm=true) const;

  // return matrix of booleans, based on condition
  matrix<int> equal        (const        X  &D) const;
  matrix<int> not_equal    (const        X  &D) const;
  matrix<int> greater      (const        X  &D) const;
  matrix<int> greater_equal(const        X  &D) const;
  matrix<int> less         (const        X  &D) const;
  matrix<int> less_equal   (const        X  &D) const;
  matrix<int> equal        (const matrix<X> &D) const;
  matrix<int> not_equal    (const matrix<X> &D) const;
  matrix<int> greater      (const matrix<X> &D) const;
  matrix<int> greater_equal(const matrix<X> &D) const;
  matrix<int> less         (const matrix<X> &D) const;
  matrix<int> less_equal   (const matrix<X> &D) const;

  // find the plain storage indices of all non-zero entries
  std::vector<size_t> where() const;
  size_t              where(int    index) const;
  size_t              where(size_t index) const;

};

// equality operators
template<typename X> bool operator!= (const matrix<X> &A, const matrix<X> &B);
template<typename X> bool operator== (const matrix<X> &A, const matrix<X> &B);

// external arithmetic operators (cppmat::symmetric::matrix)
template<typename X> matrix<X> operator* (const matrix<X> &A, const matrix<X> &B);
template<typename X> matrix<X> operator/ (const matrix<X> &A, const matrix<X> &B);
template<typename X> matrix<X> operator+ (const matrix<X> &A, const matrix<X> &B);
template<typename X> matrix<X> operator- (const matrix<X> &A, const matrix<X> &B);
template<typename X> matrix<X> operator* (const matrix<X> &A, const        X  &B);
template<typename X> matrix<X> operator/ (const matrix<X> &A, const        X  &B);
template<typename X> matrix<X> operator+ (const matrix<X> &A, const        X  &B);
template<typename X> matrix<X> operator- (const matrix<X> &A, const        X  &B);
template<typename X> matrix<X> operator* (const        X  &A, const matrix<X> &B);
template<typename X> matrix<X> operator/ (const        X  &A, const matrix<X> &B);
template<typename X> matrix<X> operator+ (const        X  &A, const matrix<X> &B);
template<typename X> matrix<X> operator- (const        X  &A, const matrix<X> &B);

// print operator
template<typename X> std::ostream& operator<<(std::ostream& out, const matrix<X>& src);

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

