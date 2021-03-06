/* CUDA tutorial: Basic Linear Algebra (BLA) Library

!Copyright (C) 2018-2018 Dmitry I. Lyakh (Liakh)
!Copyright (C) 2018-2018 Oak Ridge National Laboratory (UT-Battelle)

!This file is part of CUDA BLA tutorial.

!CUDA BLA is free software: you can redistribute it and/or modify
!it under the terms of the GNU Lesser General Public License as published
!by the Free Software Foundation, either version 3 of the License, or
!(at your option) any later version.

!CUDA BLA is distributed in the hope that it will be useful,
!but WITHOUT ANY WARRANTY; without even the implied warranty of
!MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
!GNU Lesser General Public License for more details.

!You should have received a copy of the GNU Lesser General Public License
!along with CUDA BLA. If not, see <http://www.gnu.org/licenses/>. */

#ifndef BLA_LIB_HPP_
#define BLA_LIB_HPP_

#include "memory.hpp"
#include "timer.hpp"

#include <cassert>

#include <complex>

namespace bla{

/** Initialization of BLA **/
void init();

/** Shutdown of BLA **/
void shutdown();

/** Testing BLA **/
bool test_bla();

/** Device properites **/
void print_device_properties(int device);

/** Resets GEMM algorithm:
    0: Custom GEMM from BLA;
    1: cuBLAS GEMM. **/
void reset_gemm_algorithm(int algo);

/** Matrix squared "norm" (sum of the squared elements) **/
float matrix_norm2_gpu(size_t num_elems, const float * matrix_body);
double matrix_norm2_gpu(size_t num_elems, const double * matrix_body);

/** Matrix addition **/
void matrix_addition_gpu(size_t num_elems, float * matrix0_body, const float * matrix1_body, float alpha);
void matrix_addition_gpu(size_t num_elems, double * matrix0_body, const double * matrix1_bod, double alpha);

/** Matrix multiplication **/
void matrix_multiplication_gpu(bool left_transp, bool right_transp,
                               float * matrix0_body, int nrows0, int ncols0,
                               const float * matrix1_body, int nrows1, int ncols1,
                               const float * matrix2_body, int nrows2, int ncols2);
void matrix_multiplication_gpu(bool left_transp, bool right_transp,
                               double * matrix0_body, int nrows0, int ncols0,
                               const double * matrix1_body, int nrows1, int ncols1,
                               const double * matrix2_body, int nrows2, int ncols2);

} //namespace bla

#endif //BLA_LIB_HPP_
