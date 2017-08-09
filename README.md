
# Introduction

This header-only module provides C++ classes and several accompanying methods to work with n-d matrices and/or tensors. It's usage, programmatically and from a compilation perspective, is really simple. One just has to include the relevant header file and [tell your compiler](#compiling) where it is located (and to the C++11 or younger standard). Really, that's it!

- [cppmat/matrix.h](#cppmatmatrixh)
- [cppmat/tensor.h](#cppmattensorh)
- [Compiling](#compiling)
- [Python interface](#python-interface)
- [Develop](#develop)

>   A very basic introduction is given here. The step after this reader is to consult the code. It should be easy to understand, with several comments that guide this process.

# cppmat/matrix.h

Header-only module that provides a C++ class for n-d matrices.

```cpp
#include <cppmat/matrix.h>

int main()
{
    cppmat::matrix<double> A({10,10,10});
    // ...
    return 0;
}
```

# cppmat/tensor.h

Header-only module that provides C++ classes for 4th- and 2nd order tensors and vectors (the latter essentially coincide with `std::vector`, but with special methods).

```cpp
#include <cppmat/tensor.h>

int main()
{
    cppmat::tensor4<double> cppmat::identity4(3);
    // ...
    return 0;
}
```

> **Tip**
> 
> To print use the common C++ `std::cout << A << std::endl;`, or to customize formating use the more classic C syntax `A.printf("%16.8e");`

## Classes

The module consists of three basic classes:

*   `cppmat::vector`: vector (rank 1 tensor) of arbitrary dimensions. 

    ```cpp
    cppmat::vector<double> A(3);

    A(0) = ...
    ```

*   `cppmat::tensor2`: 2nd-order tensor (rank 2 tensor) of arbitrary dimensions. 

    ```cpp
    cppmat::tensor2<double> A(3);

    A(0,0) = ...
    ```

*   `cppmat::tensor4`: 4nd-order tensor (rank 4 tensor) of arbitrary dimensions. 

    ```cpp
    cppmat::tensor4<double> A(3);

    A(0,0,0,0) = ...
    ```

In addition, there are two specialized classes available which employ information available to end-user, and can be used to optimize the final code for speed and memory consumption. These classes are:

*   `cppmat::tensor2s`: symmetric 2nd-order tensor. For example, for the case of 3 dimensions, the following components are stored:

    ```cpp
    [ X , X , X ;
          X , X ;
              X ]
    ```

    *The remaining components are inferred from symmetry*.

*   `cppmat::tensor2d`: diagonal 2nd-order tensor. For example, for the case of 3 dimensions, the following components are stored:

    ```cpp
    [ X         ;
          X     ;
              X ]
    ```

    *The remaining components are imposed to be **zero***.

Because of the flexibility of C++ it is easy to switch between these specialized class and the more general `cppmat::tensor2` class. For example, the following will work:

```cpp
cppmat::tensor2d<double> I = cppmat::identity2(3);

cppmat::tensor<double> A = I;
```

or even 

```cpp
cppmat::tensor2<double> I = cppmat::identity2(3);
```

Also simple arithmetic works:

```cpp
cppmat::tensor<double> A = 3.*I;
```

Finally, all the [methods](#methods) accept all three classes - `cppmat::tensor2`, `cppmat::tensor2s`, `cppmat::tensor2d` - allowing their usage without any prior type casting. In fact the methods will often perform better for the specialized classes since fewer operations are needed.

> **Warning**
> 
> The order of operations may matter. For example
> 
>  ```cpp
>  cppmat::tensor2d<double> I = cppmat::identity2(3);
>  cppmat::tensor2 <double> A = 10.+I;
>  ```
>  
>  is not the same as
>  
>  ```cpp
>  cppmat::tensor2d<double> I = cppmat::identity2(3);
>  cppmat::tensor2 <double> A = I;
>  A += 10.;
>  ```
>  
>  The results:
>  
>  ```cpp
>  // A = 10.+I             // A = I; A += 10.;
>  [ 11. ,  0. ,  0. ;      [ 11. , 10. , 10. ;
>     0. , 11. ,  0. ;        10. , 11. , 10. ;
>     0. ,  0. , 11. ]        10. , 10. , 11. ]
>  ```
>  
>  This is logical, but one should be aware.

## Methods

For each class the index operator `(...)`, the arithmetic operators `*=`, `*`,`/=`, `/`,`+=`, `+`,`-=`, `-`, and the comparison operator `==` are available. Also, one can use `.zeros()` or `.ones()` to initialize all components respectively to zeros or ones. Furthermore, the following methods are available. 

>   Below each occurrence of `cppmat::tensor2` can be replaced by `cppmat::tensor2s` or `cppmat::tensor2d`. The latter two often perform better.
>   
>   Also notice the notation wherein `A` is the variable for with the method is called, `B` is the argument, while `C` is the result. For example:
>   
>   ```cpp
>   cppmat::tensor4<double> A = cppmat::identity4(3);
>   cppmat::tensor2<double> B = cppmat::identity2(3);
>   
>   cppmat::tensor2<double> C = A.ddot(B);
>   ```
>   
>   The rank of the output is straightforward to understand. Below, the rank can also be inferred from the indices.

*   `cppmat::tensor4`:

    -   `A.ddot(cppmat::tensor4)`
        
        Double tensor contraction C<sub>ijmn</sub> = A<sub>ijkl</sub> B<sub>lkmn</sub>

    -   `.ddot(cppmat::tensor2)`

        Double tensor contraction C<sub>ij</sub> = A<sub>ijkl</sub> B<sub>lk</sub>

    -   `.T()`

        Transposition C<sub>lkji</sub> = A<sub>ijkl</sub>

    -   `.LT()`

        Left-transposition C<sub>jikl</sub> = A<sub>ijkl</sub>

    -   `.RT()`

        Right-transposition C<sub>ijlk</sub> = A<sub>ijkl</sub>

*   `cppmat::tensor2`:

    -   `.ddot(cppmat::tensor4)`
        
        Double tensor contraction C<sub>kl</sub> = A<sub>ij</sub> B<sub>jikl</sub>

    -   `.ddot(cppmat::tensor2)`

        Double tensor contraction C = A<sub>ij</sub> B<sub>ji</sub>

    -   `.dot(cppmat::tensor2)`

        Tensor contraction C<sub>ik</sub> = A<sub>ij</sub> B<sub>jk</sub>

    -   `.dot(cppmat::vector)`

        Tensor contraction C<sub>i</sub> = A<sub>ij</sub> B<sub>j</sub>

    -   `.dyadic(cppmat::tensor2)`

        Dyadic product C<sub>ijkl</sub> = A<sub>ij</sub> B<sub>kl</sub>

    -   `.T()`

        Transposition C<sub>lkji</sub> = A<sub>ijkl</sub>

    -   `.trace()`

        The trace of the tensor (i.e. the sum of the diagonal components) C = A<sub>ii</sub>

    -   `.det()`

        The determinant `C` 

    -   `.inv()`

        The inverse C<sub>ij</sub> 

*   `cppmat::vector`:

    -   `.dot(cppmat::vector)`
        
        Tensor contraction C = A<sub>i</sub> B<sub>i</sub>

    -   `.dot(cppmat::tensor2)`

        Tensor contraction C<sub>j</sub> = A<sub>i</sub> B<sub>ij</sub>

    -   `.dyadic(cppmat::vector)`

        Dyadic product C<sub>ij</sub> = A<sub>i</sub> B<sub>j</sub>

    -   `.dyadic(cppmat::vector)`

        Cross product C<sub>i</sub>

>   One can also call the methods as functions using `cppmmat::ddot( A , B )`, `cppmmat::dot( A , B )`, `cppmmat::dyadic( A , B )`, `cppmmat::cross( A , B )`, `cppmmat::transpose( A )`, `cppmmat::transposeR( A )`, `cppmmat::transposeL( A )`, `cppmmat::inv( A )`, `cppmmat::det( A )`, and `cppmmat::trace( A )`, These methods are however just a front-end for the class-methods described above.

# Compiling

## pkg-config

To simplify matters greatly one can use `pkg-config` to keep track of the location of the header files. To that matter on has to:

1. Copy the file `cppmat.pc.in` to `cppmat.pc` to some location that can be found by `pkg_config` (for example by adding `export PKG_CONFIG_PATH=/path/to/cppmat.pc:$PKG_CONFIG_PATH` to the `.bashrc`). 
2. Modify the line `prefix=@CMAKE_INSTALL_PREFIX@` to `prefix=/path/to/cppmat`.

## GNU / Clang

Add the following compiler's arguments:

```bash
-I${PATH_TO_CPPMAT}/include -std=c++11
```

(or `-std=c++14`).

If `pkg-config` is configured on can also use

```bash
`pkg-config --cflags cppmat`
```

> **Tip**
> 
> If you want to avoid separately including the header files using a compiler flag, `git submodule` is a nice way to go:
> 
>  1.  Include this module as a submodule using `git submodule add https://github.com/tdegeus/cppmat.git`.
>  2.  Replace the first line of this example by `#include "cppmat/include/cppmat/matrix.h"`.
>  
> *If you decide to manually copy the header file, you might need to modify this relative path to your liking.*

## cmake

Add the following to your `CMakeLists.txt`:

```cmake
find_package(PkgConfig)
pkg_check_modules(CPPMAT REQUIRED cppmat)
include_directories(${CPPMAT_INCLUDE_DIRS})
```

# Python interface

This library includes provides an interface to [pybind11](https://github.com/pybind/pybind11) such that an interface to NumPy arrays is automatically provided when including a function with a `cppmat::matrix`, `tensor::tensor4`, `tensor::tensor2`, or `tensor::vector`. To use this feature one has to include (either or both):

```cpp
#include <cppmat/pybind11_matrix.h>
#include <cppmat/pybind11_tensor.h>
```

An example is provided in `docs/examples/tensorlib`. This example includes two forms of building:

1.  `CMakeList.txt` for building using `cmake` (`cmake .` and then `make`). For this to work, `pybind11` must be 'installed' on the system. Alternatively you can include `pybind11` as a sub-folder (for example using `git submodule add https://github.com/pybind/pybind11.git`). In that case, replace `find_package(pybind11 REQUIRED)` by `add_subdirectory(pybind11)` in `CMakeList.txt`.

2.  `setup.py` for building using `python` (`python3 setup.py build` and then `python3 setup.py install`). Using this option `python` will take care of the `pybind11` and `cppmat` dependencies.

# Develop

## Python

The Python package of this module `cppmat/__init__.py` is essentially used to allow distribution of the header files that constitute this library through PyPi. In addition a small Python package `cppmat` is provided that allows easy `setup.py` formulations of derived packages. These features can also be used when one is just interested in using pybind11 and one does not intend to use `cppmat` itself.

## Create a new release

1.  Update the version numbers as follows:

    -   Modify `__version__` in `setup.py`.
    -   Modify `version` in `cppmat.pc.in`

2.  Upload the changes to GitHub and create a new release there (with the correct version number).

3.  Upload the package to PyPi:

    ```bash
    $ python3 setup.py bdist_wheel --universal
    $ twine upload dist/*
    ```

