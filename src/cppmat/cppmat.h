/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef CPPMAT_H
#define CPPMAT_H

// =================================================================================================

#include <algorithm>
#include <assert.h>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

// =================================================================================================

#define CPPMAT_WORLD_VERSION 0
#define CPPMAT_MAJOR_VERSION 3
#define CPPMAT_MINOR_VERSION 9

#define CPPMAT_VERSION_AT_LEAST(x,y,z) \
  (CPPMAT_WORLD_VERSION>x || (CPPMAT_WORLD_VERSION>=x && \
  (CPPMAT_MAJOR_VERSION>y || (CPPMAT_MAJOR_VERSION>=y && \
                              CPPMAT_MINOR_VERSION>=z))))

#define CPPMAT_VERSION(x,y,z) \
  (CPPMAT_WORLD_VERSION==x && \
   CPPMAT_MAJOR_VERSION==y && \
   CPPMAT_MINOR_VERSION==z)

// =================================================================================================

// dummy operation that can be use to suppress the "unused parameter" warnings
#define UNUSED(p) ( (void)(p) )

// =================================================================================================

#include "cppmat.h"
#include "matrix.h"
#include "matrix2.h"
#include "vector.h"
#include "periodic_matrix.h"
#include "periodic_matrix2.h"
#include "periodic_vector.h"
#include "tiny_matrix2.h"
#include "tiny_vector.h"
#include "tensor.h"
#include "tensor2.h"
#include "tensor3.h"

#include "matrix.cpp"
#include "matrix2.cpp"
#include "vector.cpp"
#include "periodic_matrix.cpp"
#include "periodic_matrix2.cpp"
#include "periodic_vector.cpp"
#include "tiny_matrix2.cpp"
#include "tiny_vector.cpp"
#include "tensor.cpp"
#include "tensor2.cpp"
#include "tensor3.cpp"

// =================================================================================================

#endif

