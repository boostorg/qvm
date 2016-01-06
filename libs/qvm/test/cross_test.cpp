//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/vec_operations.hpp>
#include <boost/qvm/vec_access.hpp>
#include <boost/qvm/mat_access.hpp>
#include <boost/qvm/vec_operations3.hpp>
#include <boost/qvm/vec.hpp>
//#include <boost/qvm/quat_traits.hpp>
#include "test_qvm_vector.hpp"
#include "test_qvm_matrix.hpp"
#include "gold.hpp"

namespace
    {
    template <class T,class U> struct same_type_tester;
    template <class T> struct same_type_tester<T,T> { };
    template <class T,class U> void test_same_type( T, U ) { same_type_tester<T,U>(); }
    }

int
main()
    {
    using namespace boost::qvm;
    test_qvm::vector<V1,3> x(42,1);
    test_qvm::vector<V1,3> y=x*2;
    test_qvm::matrix<M1,3,3> m;
    (m,A00) = 0;
    (m,A01) = -(x,A2);
    (m,A02) = (x,A1);
    (m,A10) = (x,A2);
    (m,A11) = 0;
    (m,A12) = -(x,A0);
    (m,A20) = -(x,A1);
    (m,A21) = (x,A0);
    (m,A22) = 0;
        {
        test_same_type(x,cross(x,y));
        test_qvm::vector<V1,3> c=cross(x,y);
        test_qvm::multiply_mv(c.b,m.a,y.a);
        BOOST_QVM_TEST_EQ(c.a,c.b);
        }
        {
        test_qvm::vector<V2,3> c=cross(vref(x),y);
        test_qvm::multiply_mv(c.b,m.a,y.a);
        BOOST_QVM_TEST_EQ(c.a,c.b);
        }
        {
        test_qvm::vector<V2,3> c=cross(x,vref(y));
        test_qvm::multiply_mv(c.b,m.a,y.a);
        BOOST_QVM_TEST_EQ(c.a,c.b);
        }
    return boost::report_errors();
    }
