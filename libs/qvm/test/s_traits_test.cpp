//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/scalar_traits.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat.hpp>
#include <boost/qvm/quat.hpp>

template <bool>
struct tester;

template <>
struct
tester<true>
    {
    };

using namespace boost::qvm;
tester<is_s<char>::value> t1;
tester<is_s<signed char>::value> t2;
tester<is_s<unsigned char>::value> t3;
tester<is_s<signed short>::value> t4;
tester<is_s<unsigned short>::value> t5;
tester<is_s<signed int>::value> t6;
tester<is_s<unsigned int>::value> t7;
tester<is_s<signed long>::value> t8;
tester<is_s<unsigned long>::value> t9;
tester<is_s<float>::value> t10;
tester<is_s<double>::value> t11;
tester<!is_s<vec<float,4> >::value> t12;
tester<!is_s<mat<float,4,4> >::value> t13;
tester<!is_s<quat<float> >::value> t14;
