/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_PERIODIC_MATRIX_H
#define CPPMAT_PERIODIC_MATRIX_H

#include "macros.h"

namespace cppmat {
namespace periodic {

#define MAX_DIM 6

// =================================================================================================
// cppmat::matrix
// =================================================================================================

template <class X> class matrix
{
private:

  std::vector<X> m_container;        // data container
  X             *m_data;             // pointer to data container (may point outside)
  size_t         m_ndim=0;           // actual number of dimensions
  size_t         m_size=0;           // total number of entries == data.size() == prod(shape)
  size_t         m_shape[MAX_DIM];   // number of entries in each dimensions
  size_t         m_strides[MAX_DIM]; // stride length for each index
  bool           m_owner=true;       // signal if m_data pointer to "m_container"

public:

  // constructors
  // ------------

  matrix(){}

  matrix(const std::vector<size_t> &shape){ resize(shape); }

  matrix(const std::vector<size_t> &shape, X D)
  {
    resize(shape);

    for ( size_t i=0; i<m_size; ++i )
      m_data[i] = D;
  }

  matrix(const std::vector<size_t> &shape, const X *D)
  {
    resize(shape);

    for ( size_t i=0; i<m_size; ++i )
      m_data[i] = D[i];
  }

  // map external pointer
  // --------------------

  // raw pointer
  // N.B. the user is responsible for the correct storage and to keep the pointer alive
  void map(const std::vector<size_t> &shape, X *D)
  {
    // - release 'ownership' of data
    m_owner = false;

    // - change size settings without expanding "m_container"
    resize(shape);

    // - point to input pointer
    m_data = D;
  }

  // copy from external data array
  // -----------------------------

  void copy(const std::vector<size_t> &shape, const X *D)
  {
    assert( m_owner );

    resize(shape);

    for ( size_t i=0; i<m_size; ++i )
      m_data[i] = D[i];
  }

  // constructor to copy + change data type
  // --------------------------------------

  template<\
    typename U,typename V=X,\
    typename=typename std::enable_if<std::is_convertible<X,U>::value>::type\
  >
  operator matrix<U> ()
  {
    matrix<U> out(shape());

    for ( size_t i = 0 ; i < size() ; ++i )
      out[i] = static_cast<U>( m_data[i] );

    return out;
  }

  // resize matrix
  // -------------

  void resize(const std::vector<size_t> &shape)
  {
    assert( shape.size()  > 0       );
    assert( shape.size() <= MAX_DIM );

    for ( size_t i = 0 ; i < MAX_DIM ; ++i ) {
      m_shape  [i] = 1;
      m_strides[i] = 1;
    }

    m_ndim = shape.size();
    m_size = 1;

    for ( size_t i = 0 ; i < m_ndim ; ++i ) {
      m_shape[i] = shape[i];
      m_size    *= shape[i];
    }

    for ( size_t i = 0 ; i < m_ndim ; ++i )
      for ( size_t j = i+1 ; j < m_ndim ; ++j )
        m_strides[i] *= m_shape[j];

    if ( m_owner )
    {
      m_container.resize(m_size);
      m_data = &m_container[0];
    }
  }

  // change number of dimensions
  // ---------------------------

  void chdim(size_t ndim)
  {
    #ifndef NDEBUG
      for ( size_t i = ndim ; i < MAX_DIM ; ++i ) assert( m_shape[i] == 1 );
    #endif

    m_ndim = ndim;
  }

  // reshape
  // -------

  void reshape(const std::vector<size_t> &shape)
  {
    assert( m_owner );

    #ifndef NDEBUG
      size_t n = 1;

      for ( auto &i : shape ) n *= i;

      assert( n == m_size );
    #endif

    resize(shape);
  }

  // operator[] : direct storage access
  // ----------------------------------

  X& operator[](size_t i)
  { return m_data[i]; }

  const X& operator[](size_t i) const
  { return m_data[i]; }

  // operator() : indices along each dimension (up to 6-d, extend if needed)
  // -----------------------------------------------------------------------

  X& operator()(size_t a)
  { return m_data[a*m_strides[0]]; }

  X& operator()(size_t a, size_t b)
  { return m_data[a*m_strides[0]+b*m_strides[1]]; }

  X& operator()(size_t a, size_t b, size_t c)
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]]; }

  X& operator()(size_t a, size_t b, size_t c, size_t d)
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]]; }

  X& operator()(size_t a, size_t b, size_t c, size_t d, size_t e)
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]]; }

  X& operator()(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f)
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]+f*m_strides[5]]; }

  // const versions of the above (otherwise identical)

  const X& operator()(size_t a) const
  { return m_data[a*m_strides[0]]; }

  const X& operator()(size_t a, size_t b) const
  { return m_data[a*m_strides[0]+b*m_strides[1]]; }

  const X& operator()(size_t a, size_t b, size_t c) const
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]]; }

  const X& operator()(size_t a, size_t b, size_t c, size_t d) const
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]]; }

  const X& operator()(size_t a, size_t b, size_t c, size_t d, size_t e) const
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]]; }

  const X& operator()(size_t a, size_t b, size_t c, size_t d, size_t e, size_t f) const
  { return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]+f*m_strides[5]]; }


  // operator() : indices along each dimension, allowing for "i < 0" or "i >= N"
  // ---------------------------------------------------------------------------

  X& operator()(int a)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;

    return m_data[a*m_strides[0]];
  }

  // --

  X& operator()(int a, int b)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]];
  }

  X& operator()(size_t a, int b)
  {
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]];
  }

  X& operator()(int a, size_t b)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;

    return m_data[a*m_strides[0]+b*m_strides[1]];
  }

  // --

  X& operator()(int a, int b, int c)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  X& operator()(size_t a, int b, int c)
  {
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  X& operator()(size_t a, size_t b, int c)
  {
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  X& operator()(size_t a, int b, size_t c)
  {
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  X& operator()(int a, size_t b, int c)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  X& operator()(int a, size_t b, size_t c)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  X& operator()(int a, int b, size_t c)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  // --

  X& operator()(int a, int b, int c, int d)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;
    d = ( d < 0 ) ? d + static_cast<int>(m_shape[3]) : ( d >= static_cast<int>(m_shape[3]) ) ? d - static_cast<int>(m_shape[3]) : d ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]];
  }

  // --

  X& operator()(int a, int b, int c, int d, int e)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;
    d = ( d < 0 ) ? d + static_cast<int>(m_shape[3]) : ( d >= static_cast<int>(m_shape[3]) ) ? d - static_cast<int>(m_shape[3]) : d ;
    e = ( e < 0 ) ? e + static_cast<int>(m_shape[4]) : ( e >= static_cast<int>(m_shape[4]) ) ? e - static_cast<int>(m_shape[4]) : e ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]];
  }

  // --

  X& operator()(int a, int b, int c, int d, int e, int f)
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;
    d = ( d < 0 ) ? d + static_cast<int>(m_shape[3]) : ( d >= static_cast<int>(m_shape[3]) ) ? d - static_cast<int>(m_shape[3]) : d ;
    e = ( e < 0 ) ? e + static_cast<int>(m_shape[4]) : ( e >= static_cast<int>(m_shape[4]) ) ? e - static_cast<int>(m_shape[4]) : e ;
    f = ( f < 0 ) ? f + static_cast<int>(m_shape[5]) : ( f >= static_cast<int>(m_shape[5]) ) ? f - static_cast<int>(m_shape[5]) : f ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]+f*m_strides[5]];
  }

  // const versions of the above (otherwise identical)

  const X& operator()(int a) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;

    return m_data[a*m_strides[0]];
  }

  // --

  const X& operator()(int a, int b) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]];
  }

  const X& operator()(size_t a, int b) const
  {
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]];
  }

  const X& operator()(int a, size_t b) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;

    return m_data[a*m_strides[0]+b*m_strides[1]];
  }

  // --

  const X& operator()(int a, int b, int c) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  const X& operator()(size_t a, int b, int c) const
  {
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  const X& operator()(size_t a, size_t b, int c) const
  {
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  const X& operator()(size_t a, int b, size_t c) const
  {
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  const X& operator()(int a, size_t b, int c) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  const X& operator()(int a, size_t b, size_t c) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  const X& operator()(int a, int b, size_t c) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]];
  }

  // --

  const X& operator()(int a, int b, int c, int d) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;
    d = ( d < 0 ) ? d + static_cast<int>(m_shape[3]) : ( d >= static_cast<int>(m_shape[3]) ) ? d - static_cast<int>(m_shape[3]) : d ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]];
  }

  // --

  const X& operator()(int a, int b, int c, int d, int e) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;
    d = ( d < 0 ) ? d + static_cast<int>(m_shape[3]) : ( d >= static_cast<int>(m_shape[3]) ) ? d - static_cast<int>(m_shape[3]) : d ;
    e = ( e < 0 ) ? e + static_cast<int>(m_shape[4]) : ( e >= static_cast<int>(m_shape[4]) ) ? e - static_cast<int>(m_shape[4]) : e ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]];
  }

  // --

  const X& operator()(int a, int b, int c, int d, int e, int f) const
  {
    a = ( a < 0 ) ? a + static_cast<int>(m_shape[0]) : ( a >= static_cast<int>(m_shape[0]) ) ? a - static_cast<int>(m_shape[0]) : a ;
    b = ( b < 0 ) ? b + static_cast<int>(m_shape[1]) : ( b >= static_cast<int>(m_shape[1]) ) ? b - static_cast<int>(m_shape[1]) : b ;
    c = ( c < 0 ) ? c + static_cast<int>(m_shape[2]) : ( c >= static_cast<int>(m_shape[2]) ) ? c - static_cast<int>(m_shape[2]) : c ;
    d = ( d < 0 ) ? d + static_cast<int>(m_shape[3]) : ( d >= static_cast<int>(m_shape[3]) ) ? d - static_cast<int>(m_shape[3]) : d ;
    e = ( e < 0 ) ? e + static_cast<int>(m_shape[4]) : ( e >= static_cast<int>(m_shape[4]) ) ? e - static_cast<int>(m_shape[4]) : e ;
    f = ( f < 0 ) ? f + static_cast<int>(m_shape[5]) : ( f >= static_cast<int>(m_shape[5]) ) ? f - static_cast<int>(m_shape[5]) : f ;

    return m_data[a*m_strides[0]+b*m_strides[1]+c*m_strides[2]+d*m_strides[3]+e*m_strides[4]+f*m_strides[5]];
  }

  // arithmetic operators: matrix ?= matrix
  // --------------------------------------

  matrix<X>& operator*= (const matrix<X> &B)
  {
    assert( size() == B.size() );
    assert( ndim() == B.ndim() );

    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] *= B[i];

    return *this;
  }

  matrix<X>& operator/= (const matrix<X> &B)
  {
    assert( size() == B.size() );
    assert( ndim() == B.ndim() );

    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] /= B[i];

    return *this;
  }

  matrix<X>& operator+= (const matrix<X> &B)
  {
    assert( size() == B.size() );
    assert( ndim() == B.ndim() );

    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] += B[i];

    return *this;
  }

  matrix<X>& operator-= (const matrix<X> &B)
  {
    assert( size() == B.size() );
    assert( ndim() == B.ndim() );

    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] -= B[i];

    return *this;
  }

  // arithmetic operators: matrix ?= scalar
  // --------------------------------------

  matrix<X>& operator*= (X B)
  {
    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] *= B;

    return *this;
  }

  matrix<X>& operator/= (X B)
  {
    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] /= B;

    return *this;
  }

  matrix<X>& operator+= (X B)
  {
    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] += B;

    return *this;
  }

  matrix<X>& operator-= (X B)
  {
    for ( size_t i = 0 ; i < m_size ; ++i )
      m_data[i] -= B;

    return *this;
  }

  // pointer / iterators
  // -------------------

  const X* data () const { return &m_data[0];          }
  auto     begin() const { return &m_data[0];          }
  auto     end  () const { return &m_data[0] + m_size; }

  // return shape array [ndim]
  // -------------------------

  std::vector<size_t> shape() const
  {
    std::vector<size_t> ret(m_ndim);

    for ( size_t i = 0 ; i < m_ndim ; ++i ) ret[i] = m_shape[i];

    return ret;
  }

  // return shape in one direction
  // -----------------------------

  size_t shape(size_t i) const
  {
    assert( i < MAX_DIM );

    return m_shape[i];
  }

  // return strides array [ndim]
  // ---------------------------

  std::vector<size_t> strides(bool bytes=false) const
  {
    std::vector<size_t> ret(m_ndim);

    for ( size_t i = 0 ; i < m_ndim ; ++i )
      ret[i] = m_strides[i];

    if ( bytes )
      for ( size_t i = 0 ; i < m_ndim ; ++i )
        ret[i] *= sizeof(X);

    return ret;
  }

  // return size
  // -----------

  size_t size() const { return m_size; }
  size_t ndim() const { return m_ndim; }

  // minimum / maximum / mean / sum
  // ------------------------------

  X sum() const
  {
    X out = static_cast<X>(0);

    for ( size_t i = 0 ; i < m_size ; ++i )
      out += m_data[i];

    return out;
  }

  double mean() const { return static_cast<double>(this->sum())/static_cast<double>(m_size); }
  X      min () const { return *std::min_element(begin(),end()); }
  X      max () const { return *std::max_element(begin(),end()); }

  // initialize all entries to zero/one/constant
  // -------------------------------------------

  void setConstant(X D) { for ( size_t i=0; i<m_size; ++i ) m_data[i] = D;                 }
  void setZero    (   ) { for ( size_t i=0; i<m_size; ++i ) m_data[i] = static_cast<X>(0); }
  void setOnes    (   ) { for ( size_t i=0; i<m_size; ++i ) m_data[i] = static_cast<X>(1); }
  void zeros      (   ) { for ( size_t i=0; i<m_size; ++i ) m_data[i] = static_cast<X>(0); }
  void ones       (   ) { for ( size_t i=0; i<m_size; ++i ) m_data[i] = static_cast<X>(1); }

  // print to screen
  // ---------------

  void printf(std::string fmt) const
  {
    std::vector<size_t> s = strides();

    if ( m_ndim == 1 )
    {
      for ( size_t h = 0 ; h < shape(0)-1 ; ++h ) {
        std::printf((fmt+",").c_str(),m_data[h]);
      }
      std::printf((fmt+"\n").c_str(),m_data[shape(0)-1]);
    }
    else if ( m_ndim == 2 )
    {
      for ( size_t h = 0 ; h < shape(0) ; ++h ) {
        for ( size_t i = 0 ; i < shape(1)-1 ; ++i ) {
          std::printf((fmt+",").c_str(),m_data[h*s[0]+i*s[1]]);
        }
        std::printf((fmt+";\n").c_str(),m_data[h*s[0]+(shape(1)-1)*s[1]]);
      }
    }
    else if ( m_ndim == 3 )
    {
      for ( size_t h = 0 ; h < shape(0) ; ++h ) {
        for ( size_t i = 0 ; i < shape(1) ; ++i ) {
          for ( size_t j = 0 ; j < shape(2)-1 ; ++j ) {
            std::printf((fmt+",").c_str(),m_data[h*s[0]+i*s[1]+j*s[2]]);
          }
          std::printf((fmt+";\n").c_str(),m_data[h*s[0]+i*s[1]+(shape(2)-1)*s[2]]);
        }
        if ( h<shape(0)-1 )
          std::printf("\n");
      }
    }
    else
    {
      std::cout << "cppmat::matrix[";

      for ( size_t i = 0 ; i < m_ndim-1 ; ++i )
        std::cout << m_shape[i] << ",";

      std::cout << m_shape[m_ndim-1] << "]" << std::endl;
    }
  }

}; // class matrix

// arithmetic operators: matrix = matrix ? matrix
// ----------------------------------------------

template <class X> matrix<X> operator* (const matrix<X> &A, const matrix<X> &B)
{
  assert( A.size() == B.size() );
  assert( A.ndim() == B.ndim() );

  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] * B[i];

  return C;
}

template <class X> matrix<X> operator/ (const matrix<X> &A, const matrix<X> &B)
{
  assert( A.size() == B.size() );
  assert( A.ndim() == B.ndim() );

  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] / B[i];

  return C;
}

template <class X> matrix<X> operator+ (const matrix<X> &A, const matrix<X> &B)
{
  assert( A.size() == B.size() );
  assert( A.ndim() == B.ndim() );

  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] + B[i];

  return C;
}

template <class X> matrix<X> operator- (const matrix<X> &A, const matrix<X> &B)
{
  assert( A.size() == B.size() );
  assert( A.ndim() == B.ndim() );

  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] - B[i];

  return C;
}

// arithmetic operators: matrix = matrix ? scalar
// ----------------------------------------------

template <class X> matrix<X> operator* (const matrix<X> &A, const X &B)
{
  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] * B;

  return C;
}

template <class X> matrix<X> operator/ (const matrix<X> &A, const X &B)
{
  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] / B;

  return C;
}

template <class X> matrix<X> operator+ (const matrix<X> &A, const X &B)
{
  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] + B;

  return C;
}

template <class X> matrix<X> operator- (const matrix<X> &A, const X &B)
{
  matrix<X> C(A.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A[i] - B;

  return C;
}

// arithmetic operators: matrix = scalar ? matrix
// ----------------------------------------------

template <class X> matrix<X> operator* (const X &A, const matrix<X> &B)
{
  matrix<X> C(B.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A * B[i];

  return C;
}

template <class X> matrix<X> operator/ (const X &A, const matrix<X> &B)
{
  matrix<X> C(B.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A / B[i];

  return C;
}

template <class X> matrix<X> operator+ (const X &A, const matrix<X> &B)
{
  matrix<X> C(B.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A + B[i];

  return C;
}

template <class X> matrix<X> operator- (const X &A, const matrix<X> &B)
{
  matrix<X> C(B.shape());

  for ( size_t i = 0 ; i < C.size() ; ++i )
    C[i] = A - B[i];

  return C;
}

// print to "std::cout"
// --------------------

template <class X>
std::ostream& operator<<(std::ostream& out, matrix<X>& src)
{
  if ( src.ndim() == 1 )
  {
    for ( size_t i = 0 ; i < src.shape(0)-1 ; ++i ) {
      out << src(i) << " , ";
    }
    out << src(src.shape(0)-1) << std::endl;
  }
  else if ( src.ndim() == 2 )
  {
    for ( size_t i = 0 ; i < src.shape(0) ; ++i ) {
      for ( size_t j = 0 ; j < src.shape(1)-1 ; ++j ) {
        out << src(i,j) << ", ";
      }
      out << src(i,src.shape(1)-1) << "; " << std::endl;
    }
  }
  else if ( src.ndim() == 3 )
  {
    for ( size_t h = 0 ; h < src.shape(0) ; ++h ) {
      for ( size_t i = 0 ; i < src.shape(1) ; ++i ) {
        for ( size_t j = 0 ; j < src.shape(2)-1 ; ++j ) {
          out << src(h,i,j) << ", ";
        }
        out << src(h,i,src.shape(2)-1) << "; " << std::endl;
      }
      if ( h < src.shape(0)-1 )
        out << std::endl;
    }
  }
  else
    {
      std::cout << "cppmat::matrix[";

      for ( size_t i = 0 ; i < src.ndim()-1 ; ++i )
        std::cout << src.shape(i) << ",";

      std::cout << src.shape(src.ndim()-1) << "]" << std::endl;
    }

  return out;
}

}} // namespace cppmat::periodic

#endif
