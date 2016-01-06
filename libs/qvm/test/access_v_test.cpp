//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/vec_access.hpp>
#include "test_qvm_vector.hpp"

template <class T,class U> struct same_type;
template <class T> struct same_type<T,T> { };

template <class T,class U>
void
check_type( U x )
    {
    same_type<T,U>();
    }

template <int I>
void
check_idx( boost::qvm::vector_access_tag<I> (*f)() )
    {
    }

int
main()
    {       
    using namespace boost::qvm;

    test_qvm::vector<V1,4> v;
    v.a[0]=42.0f;
    v.a[1]=43.0f;
    v.a[2]=44.0f;
    v.a[3]=45.0f;
    BOOST_TEST_EQ((v,X),v.a[0]);
    BOOST_TEST_EQ((v,Y),v.a[1]);
    BOOST_TEST_EQ((v,Z),v.a[2]);
    BOOST_TEST_EQ((v,W),v.a[3]);
    test_qvm::vector<V1,4> v1=v;
    (v,X) *= 2;
    BOOST_TEST_EQ(v.a[0],v1.a[0]*2);
    (v,Y) *= 2;
    BOOST_TEST_EQ(v.a[1],v1.a[1]*2);
    (v,Z) *= 2;
    BOOST_TEST_EQ(v.a[2],v1.a[2]*2);
    (v,W) *= 2;
    BOOST_TEST_EQ(v.a[3],v1.a[3]*2);

    check_type<float>((v,X));
    check_type<float>((const_cast<test_qvm::vector<V1,4> const &>(v),X));
    check_type<float>((v,X()));
    check_type<float>((const_cast<test_qvm::vector<V1,4> const &>(v),X()));

    check_idx<0>(X);
    check_idx<1>(Y);
    check_idx<2>(Z);
    check_idx<3>(W);

#define CHECK_A(i) check_idx<i>(A##i);check_idx<i>(A<i>)
    CHECK_A(0);
    CHECK_A(1);
    CHECK_A(2);
    CHECK_A(3);
    CHECK_A(4);
    CHECK_A(5);
    CHECK_A(6);
    CHECK_A(7);
    CHECK_A(8);
    CHECK_A(9);
#undef CHECK_A

    return boost::report_errors();
    }
