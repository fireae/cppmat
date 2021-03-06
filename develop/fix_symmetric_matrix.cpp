
#include "support.h"

static const size_t M = 11;
static const size_t N = 11;

typedef cppmat::tiny::symmetric::matrix<double,M,N> sMat;

// =================================================================================================

TEST_CASE("cppmat::tiny::symmetric::matrix", "matrix.h")
{

// =================================================================================================
// arithmetic
// =================================================================================================

SECTION( "matrix += matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) += b(i,j);

  A += B;

  Equal(A, a);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix -= matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) -= b(i,j);

  A -= B;

  Equal(A, a);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix *= matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) *= b(i,j);

  A *= B;

  Equal(A, a);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix /= matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N) + MatD::Ones(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) /= b(i,j);

  A /= B;

  Equal(A, a);
}

// =================================================================================================
// arithmetic
// =================================================================================================

SECTION( "matrix += scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) += b;

  A += b;

  Equal(A, a);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix -= scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) -= b;

  A -= b;

  Equal(A, a);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix *= scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) *= b;

  A *= b;

  Equal(A, a);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix /= scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0) + 1.0;

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      a(i,j) /= b;

  A /= b;

  Equal(A, a);
}

// =================================================================================================
// arithmetic
// =================================================================================================

SECTION( "matrix + matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) + b(i,j);

  sMat C = A + B;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix - matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) - b(i,j);

  sMat C = A - B;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix * matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) * b(i,j);

  sMat C = A * B;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix / matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N)) + MatD::Ones(M,N);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) / b(i,j);

  sMat C = A / B;

  Equal(C, c);
}

// =================================================================================================
// arithmetic
// =================================================================================================

SECTION( "matrix + scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) + b;

  sMat C = A + b;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix - scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) - b;

  sMat C = A - b;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix * scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) * b;

  sMat C = A * b;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "matrix / scalar" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0) + 1.0;

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = a(i,j) / b;

  sMat C = A / b;

  Equal(C, c);
}

// =================================================================================================
// arithmetic
// =================================================================================================

SECTION( "scalar + matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = b + a(i,j);

  sMat C = b + A;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "scalar - matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = b - a(i,j);

  sMat C = b - A;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "scalar * matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = b * a(i,j);

  sMat C = b * A;

  Equal(C, c);
}

// -------------------------------------------------------------------------------------------------

SECTION( "scalar / matrix" )
{
  MatD a = makeSymmetric(MatD::Random(M,N) + MatD::Ones(M,N));
  double b = a(0,0);

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = MatD::Zero(M,N);

  for ( size_t i = 0 ; i < M ; ++i )
    for ( size_t j = 0 ; j < N ; ++j )
      c(i,j) = b / a(i,j);

  sMat C = b / A;

  Equal(C, c);
}

// =================================================================================================
// algebra
// =================================================================================================

SECTION( "min" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  double c = a.minCoeff();

  double C = A.min();

  EQ(c, C);
}

// -------------------------------------------------------------------------------------------------

SECTION( "max" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  double c = a.maxCoeff();

  double C = A.max();

  EQ(c, C);
}

// -------------------------------------------------------------------------------------------------

SECTION( "sum" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  double c = 0.0;

  for ( auto i = 0 ; i < a.rows() ; ++i )
    for ( auto j = 0 ; j < a.cols() ; ++j )
      c += a(i,j);

  double C = A.sum();

  EQ(c, C);
}

// -------------------------------------------------------------------------------------------------

SECTION( "mean" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  double c = 0.0;

  for ( auto i = 0 ; i < a.rows() ; ++i )
    for ( auto j = 0 ; j < a.cols() ; ++j )
      c += a(i,j);

  c /= static_cast<double>(M*N);

  double C = A.mean();

  EQ(c, C);
}

// -------------------------------------------------------------------------------------------------

SECTION( "average" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));
  MatD b = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());
  sMat B = sMat::CopyDense(b.data(), b.data()+b.size());

  double c = 0.0;
  double d = 0.0;

  for ( auto i = 0 ; i < a.rows() ; ++i ) {
    for ( auto j = 0 ; j < a.cols() ; ++j ) {
      c += b(i,j) * a(i,j);
      d += b(i,j);
    }
  }

  c /= d;

  double C = A.average(B);

  EQ(c, C);
}

// =================================================================================================
// absolute value
// =================================================================================================

SECTION( "abs" )
{
  MatD a = makeSymmetric(MatD::Random(M,N) - MatD::Constant(M,N,.5));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  MatD c = a.cwiseAbs();

  sMat C = A.abs();

  Equal(C, c);
}

// =================================================================================================
// index operators
// =================================================================================================

SECTION( "decompress" )
{
  MatD a = makeSymmetric(MatD::Random(M,N));

  sMat A = sMat::CopyDense(a.data(), a.data()+a.size());

  std::vector<size_t> idx = A.decompress(A.compress(1,2));
  std::vector<size_t> jdx = {1,2};

  REQUIRE( idx == jdx );
}

// =================================================================================================

}
