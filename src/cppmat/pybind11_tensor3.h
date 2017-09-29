/* =================================================================================================

(c - MIT) T.W.J. de Geus (Tom) | tom@geus.me | www.geus.me | github.com/tdegeus/cppmat

================================================================================================= */

#ifndef TENSOR_PYBIND11_H
#define TENSOR_PYBIND11_H

#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

#include "tensor3.h"

namespace py = pybind11;

namespace pybind11 { namespace detail {

// =================================================================================================
// type caster: cppmat::tensor3_4 <-> NumPy-array
// =================================================================================================

template <typename T> struct type_caster<cppmat::tensor3_4<T>>
{
public:

  PYBIND11_TYPE_CASTER(cppmat::tensor3_4<T>, _("cppmat::tensor3_4<T>"));

  // Python -> C++
  // -------------

  bool load(py::handle src, bool convert)
  {
    // - basic pybind11 check
    if ( !convert && !py::array_t<T>::check_(src) )
      return false;

    // - require contiguous and row-major storage from NumPy
    auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);

    // - check storage requirements
    if ( !buf )
      return false;

    // - extract rank of the array (number of indices)
    auto rank = buf.ndim();

    // - input should be rank 4
    if ( rank != 4 )
      return false;

    // - read number of dimensions (shape in each direction)
    ssize_t nd = buf.shape()[0];

    // - the shape in each direction should be equal ( == nd )
    for ( ssize_t i=0 ; i<buf.ndim() ; i++ )
      if ( buf.shape()[i] != nd )
        return false;
    // - the direction should be 3
    if ( nd != 3 )
      return false;

    // - all checks passed: create the proper C++ variable
    value = cppmat::tensor3_4<T>(buf.data());

    // - signal successful variable creation
    return true;
  }

  // C++ -> Python
  // -------------

  static py::handle cast(const cppmat::tensor3_4<T>& src, py::return_value_policy policy,
    py::handle parent)
  {
    // - create "shape" array required by Python
    std::vector<size_t> shape(4,3);

    // - create Python variable (all variables are copied)
    py::array a(std::move(shape),std::move(src.strides(true)),src.data());

    // - release variable to Python
    return a.release();
  }
};

// =================================================================================================
// type caster: cppmat::tensor3_2 <-> NumPy-array
// =================================================================================================

template <typename T> struct type_caster<cppmat::tensor3_2<T>>
{
public:

  PYBIND11_TYPE_CASTER(cppmat::tensor3_2<T>, _("cppmat::tensor3_2<T>"));

  // Python -> C++
  // -------------

  bool load(py::handle src, bool convert)
  {
    // - basic pybind11 check
    if ( !convert && !py::array_t<T>::check_(src) )
      return false;

    // - require contiguous and row-major storage from NumPy
    auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);

    // - check storage requirements
    if ( !buf )
      return false;

    // - extract rank of the array (number of indices)
    auto rank = buf.ndim();

    // - input should be rank 2
    if ( rank != 2 )
      return false;

    // - read number of dimensions (shape in each direction)
    ssize_t nd = buf.shape()[0];

    // - the shape in each direction should be equal ( == nd )
    for ( ssize_t i=0 ; i<buf.ndim() ; i++ )
      if ( buf.shape()[i] != nd )
        return false;
    // - the direction should be 3
    if ( nd != 3 )
      return false;

    // - all checks passed: create the proper C++ variable
    value = cppmat::tensor3_2<T>(buf.data());

    // - signal successful variable creation
    return true;
  }

  // C++ -> Python
  // -------------

  static py::handle cast(const cppmat::tensor3_2<T>& src, py::return_value_policy policy,
    py::handle parent)
  {
    // - create "shape" array required by Python
    std::vector<size_t> shape(2,3);

    // - create Python variable (all variables are copied)
    py::array a(std::move(shape),std::move(src.strides(true)),src.data());

    // - release variable to Python
    return a.release();
  }
};

// =================================================================================================
// type caster: cppmat::tensor3_2s <-> NumPy-array
// =================================================================================================

template <typename T> struct type_caster<cppmat::tensor3_2s<T>>
{
public:

  PYBIND11_TYPE_CASTER(cppmat::tensor3_2s<T>, _("cppmat::tensor3_2s<T>"));

  // Python -> C++
  // -------------

  bool load(py::handle src, bool convert)
  {
    // - basic pybind11 check
    if ( !convert && !py::array_t<T>::check_(src) )
      return false;

    // - require contiguous and row-major storage from NumPy
    auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);

    // - check storage requirements
    if ( !buf )
      return false;

    // - extract rank of the array (number of indices)
    auto rank = buf.ndim();

    // - input should be rank 2
    if ( rank != 2 )
      return false;

    // - read number of dimensions (shape in each direction)
    ssize_t nd = buf.shape()[0];

    // - the shape in each direction should be equal ( == nd )
    for ( ssize_t i=0 ; i<buf.ndim() ; i++ )
      if ( buf.shape()[i] != nd )
        return false;
    // - the direction should be 3
    if ( nd != 3 )
      return false;

    // - all checks passed: create the proper C++ variable
    value = cppmat::tensor3_2s<T>(buf.data());

    // - signal successful variable creation
    return true;
  }

  // C++ -> Python
  // -------------

  static py::handle cast(const cppmat::tensor3_2s<T>& src, py::return_value_policy policy,
    py::handle parent)
  {
    // - extract number of dimensions
    size_t nd = src.ndim();

    // - create "shape", allocate "data" as 'full matrix'
    std::vector<size_t> shape(2,nd);
    std::vector<T>      data(nd*nd);

    // - copy 'full matrix' "data" from symmetrically stored variable
    for ( size_t i = 0 ; i < nd ; ++i )
      for ( size_t j = 0 ; j < nd ; ++j )
        data[i*nd+j] = src(i,j);

    // - create Python variable (all variables are copied)
    py::array a(std::move(shape),std::move(src.strides(true)),data.data());

    // - release variable to Python
    return a.release();
  }
};

// =================================================================================================
// type caster: cppmat::tensor3_2d <-> NumPy-array
// =================================================================================================

template <typename T> struct type_caster<cppmat::tensor3_2d<T>>
{
public:

  PYBIND11_TYPE_CASTER(cppmat::tensor3_2d<T>, _("cppmat::tensor3_2d<T>"));

  // Python -> C++
  // -------------

  bool load(py::handle src, bool convert)
  {
    // - basic pybind11 check
    if ( !convert && !py::array_t<T>::check_(src) )
      return false;

    // - require contiguous and row-major storage from NumPy
    auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);

    // - check storage requirements
    if ( !buf )
      return false;

    // - extract rank of the array (number of indices)
    auto rank = buf.ndim();

    // - input should be rank 2
    if ( rank != 2 )
      return false;

    // - read number of dimensions (shape in each direction)
    ssize_t nd = buf.shape()[0];

    // - the shape in each direction should be equal ( == nd )
    for ( ssize_t i=0 ; i<buf.ndim() ; i++ )
      if ( buf.shape()[i] != nd )
        return false;
    // - the direction should be 3
    if ( nd != 3 )
      return false;

    // - all checks passed: create the proper C++ variable
    value = cppmat::tensor3_2d<T>(buf.data());

    // - signal successful variable creation
    return true;
  }

  // C++ -> Python
  // -------------

  static py::handle cast(const cppmat::tensor3_2d<T>& src, py::return_value_policy policy,
    py::handle parent)
  {
    // - extract number of dimensions
    size_t nd = src.ndim();

    // - create "shape", allocate "data" as 'full matrix'
    std::vector<size_t> shape(2,nd);
    std::vector<T>      data(nd*nd,static_cast<T>(0));

    // - copy 'full matrix' "data" from symmetrically stored variable
    for ( size_t i = 0 ; i < nd ; ++i )
      data[i*nd+i] = src[i];

    // - create Python variable (all variables are copied)
    py::array a(std::move(shape),std::move(src.strides(true)),data.data());

    // - release variable to Python
    return a.release();
  }
};

// =================================================================================================
// type caster: cppmat::vector3 <-> NumPy-array
// =================================================================================================

template <typename T> struct type_caster<cppmat::vector3<T>>
{
public:

  PYBIND11_TYPE_CASTER(cppmat::vector3<T>, _("cppmat::vector3<T>"));

  // Python -> C++
  // -------------

  bool load(py::handle src, bool convert)
  {
    // - basic pybind11 check
    if ( !convert && !py::array_t<T>::check_(src) )
      return false;

    // - require contiguous and row-major storage from NumPy
    auto buf = py::array_t<T, py::array::c_style | py::array::forcecast>::ensure(src);

    // - check storage requirements
    if ( !buf )
      return false;

    // - extract rank of the array (number of indices)
    auto rank = buf.ndim();

    // - input should be rank 1
    if ( rank != 1 )
      return false;

    // - read number of dimensions (shape in each direction)
    ssize_t nd = buf.shape()[0];

    // - the shape in each direction should be equal ( == nd )
    for ( ssize_t i=0 ; i<buf.ndim() ; i++ )
      if ( buf.shape()[i] != nd )
        return false;
    // - the direction should be 3
    if ( nd != 3 )
      return false;

    // - all checks passed: create the proper C++ variable
    value = cppmat::vector3<T>(buf.data());

    // - signal successful variable creation
    return true;
  }

  // C++ -> Python
  // -------------

  static py::handle cast(const cppmat::vector3<T>& src, py::return_value_policy policy,
    py::handle parent)
  {
    // - create "shape" array required by Python
    std::vector<size_t> shape(1,3);

    // - create Python variable (all variables are copied)
    py::array a(std::move(shape),std::move(src.strides(true)),src.data());

    // - release variable to Python
    return a.release();
  }
};

// =================================================================================================

}} // namespace pybind11 { namespace detail {

#endif