desc = '''
Module that provides a header-only library that contains an n-d matrix class and fourth-, second-,
and first-order tensors (a.k.a. vectors) in C++. Each of these classes has a direct interface to
NumPy through pybind11.

The purpose of this Python package is to simplify the installation and distribution of modules that
depend on cppmat. There is no direct use for Python.
'''

import re, os
from setuptools import setup

header = open('src/cppmat/cppmat.h','r').read()
world  = re.split('(.*)(\#define CPPMAT_WORLD_VERSION\ )([0-9]+)(.*)',header)[3]
major  = re.split('(.*)(\#define CPPMAT_MAJOR_VERSION\ )([0-9]+)(.*)',header)[3]
minor  = re.split('(.*)(\#define CPPMAT_MINOR_VERSION\ )([0-9]+)(.*)',header)[3]

__version__ = '.'.join([world,major,minor])

setup(
   name             = 'cppmat',
   description      = 'Multidimensional arrays and tensors in C++',
   long_description = desc,
   keywords         = 'C++, C++11, Python bindings, pybind11',
   version          = __version__,
   license          = 'MIT',
   author           = 'Tom de Geus',
   author_email     = 'tom@geus.me',
   url              = 'https://github.com/tdegeus/cppmat',
   packages         = ['cppmat'],
   headers          = [
      'src/cppmat/cppmat.h',
      'src/cppmat/stl.h',
      'src/cppmat/stl.cpp',
      'src/cppmat/private.h',
      'src/cppmat/private.cpp',
      'src/cppmat/regular_array.h',
      'src/cppmat/regular_array.cpp',
      'src/cppmat/regular_matrix.h',
      'src/cppmat/regular_matrix.cpp',
      'src/cppmat/regular_vector.h',
      'src/cppmat/regular_vector.cpp',
      'src/cppmat/periodic_array.h',
      'src/cppmat/periodic_array.cpp',
      'src/cppmat/periodic_matrix.h',
      'src/cppmat/periodic_matrix.cpp',
      'src/cppmat/periodic_vector.h',
      'src/cppmat/periodic_vector.cpp',
      'src/cppmat/tiny_matrix.h',
      'src/cppmat/tiny_matrix.cpp',
      'src/cppmat/tiny_vector.h',
      'src/cppmat/tiny_vector.cpp',
      'src/cppmat/tensor.h',
      'src/cppmat/tensor.cpp',
      'src/cppmat/tensor2.h',
      'src/cppmat/tensor2.cpp',
      'src/cppmat/tensor3.h',
      'src/cppmat/tensor3.cpp',
      'src/cppmat/view_tiny_matrix.h',
      'src/cppmat/view_tiny_matrix.cpp',
      'src/cppmat/view_tiny_vector.h',
      'src/cppmat/view_tiny_vector.cpp',
      'src/cppmat/view_tensor2.h',
      'src/cppmat/view_tensor2.cpp',
      'src/cppmat/view_tensor3.h',
      'src/cppmat/view_tensor3.cpp',
      'src/cppmat/pybind11.h',
      'src/cppmat/pybind11_regular_array.h',
      'src/cppmat/pybind11_regular_matrix.h',
      'src/cppmat/pybind11_regular_vector.h',
      'src/cppmat/pybind11_periodic_array.h',
      'src/cppmat/pybind11_periodic_matrix.h',
      'src/cppmat/pybind11_periodic_vector.h',
      'src/cppmat/pybind11_tiny_matrix.h',
      'src/cppmat/pybind11_tiny_vector.h',
      'src/cppmat/pybind11_tensor.h',
      'src/cppmat/pybind11_tensor2.h',
      'src/cppmat/pybind11_tensor3.h',
   ],
   install_requires = ['pybind11>=2.2.0'],
)

