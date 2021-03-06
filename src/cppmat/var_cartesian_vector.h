/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_VAR_CARTESIAN_VECTOR_H
#define CPPMAT_VAR_CARTESIAN_VECTOR_H

// -------------------------------------------------------------------------------------------------

#include "cppmat.h"

// -------------------------------------------------------------------------------------------------

namespace cppmat {
namespace cartesian {

// =================================================================================================
// cppmat::cartesian::vector
// =================================================================================================

template<typename X>
class vector : public cppmat::vector<X>
{
protected:

  // local variables
  size_t ND=0; // number of dimensions (== mShape[0] == mShape[1])

public:

  // constructor: default
  vector() = default;

  // constructor: allocate, don't initialize
  vector(size_t nd);

  // constructor: copy from parent (with different type)
  template<typename U, typename=typename std::enable_if<std::is_convertible<U,X>::value>::type>
  vector(const cppmat::array<U> &A);

  // constructor: copy from other classes
  template<typename U, typename=typename std::enable_if<std::is_convertible<U,X>::value>::type>
  vector(const std::vector<U> &A);

  // constructor: copy from fixed size
  template<size_t nd> vector(const cppmat::tiny::cartesian::vector<X,nd> &A);

  // constructor: copy from view
  template<size_t nd> vector(const cppmat::view::cartesian::vector<X,nd> &A);

  // named constructor: initialize
  static vector<X> Random  (size_t nd, X lower=(X)0, X upper=(X)1);
  static vector<X> Arange  (size_t nd);
  static vector<X> Zero    (size_t nd);
  static vector<X> Ones    (size_t nd);
  static vector<X> Constant(size_t nd, X D);
  static vector<X> Copy    (size_t nd, const std::vector<X> &D);
  static vector<X> Copy    (           const std::vector<X> &D);

  // named constructor: copy
  template<typename Iterator> static vector<X> Copy(size_t nd, Iterator first);
  template<typename Iterator> static vector<X> Copy(size_t nd, Iterator first, Iterator last);
  template<typename Iterator> static vector<X> Copy(           Iterator first, Iterator last);

  // resize
  void resize(size_t nd);

  // get dimensions
  size_t ndim() const;

  // tensor products / operations
  X          dot   (const vector  <X> &B) const; // dot    product: C   = A_i*B_i
  vector <X> dot   (const tensor2 <X> &B) const; // dot    product: C_j = A_i*B_ij
  vector <X> dot   (const tensor2s<X> &B) const; // dot    product: C_j = A_i*B_ij
  vector <X> dot   (const tensor2d<X> &B) const; // dot    product: C_j = A_i*B_ij
  tensor2<X> dyadic(const vector  <X> &B) const; // dyadic product: C_ij = A_i*B_j
  vector <X> cross (const vector  <X> &B) const; // cross  product (only in 3D)
  X          length()                     const; // sqrt(sum(pow(A_i,2.)))
  void       setUnitLength();                    // A_i /= A.length()

};

// =================================================================================================

}} // namespace ...

// -------------------------------------------------------------------------------------------------

#endif

