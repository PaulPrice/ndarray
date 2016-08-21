// -*- c++ -*-
/*
 * Copyright (c) 2010-2016, Jim Bosch
 * All rights reserved.
 *
 * ndarray is distributed under a simple BSD-like license;
 * see the LICENSE file that should be present in the root
 * of the source distribution, or alternately available at:
 * https://github.com/ndarray/ndarray
 */
#ifndef NDARRAY_ArrayBase_2_hpp_INCLUDED
#define NDARRAY_ArrayBase_2_hpp_INCLUDED

#include "ndarray/common.hpp"
#include "ndarray/detail/ArrayRef_1.hpp"
#include "ndarray/detail/IterTraits_2.hpp"
#include "ndarray/detail/Iter_2.hpp"
#include "ndarray/detail/ArrayBase_2.hpp"

namespace ndarray {

template <typename T, size_t N, offset_t C>
inline typename ArrayBase<T,N,C>::iterator ArrayBase<T,N,C>::begin() const {
    return detail::ArrayTraits<T,N,C>::make_iterator_at(
        this->_impl.buffer,
        *this
    );
}

template <typename T, size_t N, offset_t C>
inline typename ArrayBase<T,N,C>::iterator ArrayBase<T,N,C>::end() const {
    return detail::ArrayTraits<T,N,C>::make_iterator_at(
        this->_impl.buffer + this->stride()*this->size(),
        *this
    );
}

template <typename T, size_t N, offset_t C>
inline typename ArrayBase<T,N,C>::reference
ArrayBase<T,N,C>::operator[](size_t n) const {
    return traits_t::make_reference_at(
        this->_impl.buffer + this->stride()*n,
        *this
    );
}

} // namespace ndarray

#endif // !NDARRAY_ArrayBase_2_hpp_INCLUDED
