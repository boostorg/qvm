//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/v.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/sw.hpp>
#include "test_qvm_vector.hpp"

int
main()
    {       
    using namespace boost::qvm;
    test_qvm::vector<V1,4> v1;
    v1.a[0]=42.0f;
    v1.a[1]=43.0f;
    v1.a[2]=44.0f;
    v1.a[3]=45.0f;
    (v1,XXX) + (v1,XXX);
    -(v1,XXX);
        {
        test_qvm::vector<V2,3> r;
        r.a[0]=v1.a[0];
        r.a[1]=v1.a[0];
        r.a[2]=v1.a[0];
        test_qvm::vector<V2,3> v2=(v1,XXX);
        BOOST_QVM_TEST_EQ(v2,r);
        }
        {
        test_qvm::vector<V2,3> r;
        r.a[0]=v1.a[0];
        r.a[1]=v1.a[0];
        r.a[2]=v1.a[1];
        test_qvm::vector<V2,3> v2=(v1,XXY);
        BOOST_QVM_TEST_EQ(v2,r);
        }
        {
        test_qvm::vector<V2,3> r;
        r.a[0]=v1.a[0];
        r.a[1]=v1.a[0];
        r.a[2]=v1.a[2];
        test_qvm::vector<V2,3> v2=(v1,XXZ);
        BOOST_QVM_TEST_EQ(v2,r);
        }
        {
        test_qvm::vector<V2,3> r;
        r.a[0]=v1.a[0];
        r.a[1]=v1.a[0];
        r.a[2]=v1.a[3];
        test_qvm::vector<V2,3> v2=(v1,XXW);
        BOOST_QVM_TEST_EQ(v2,r);
        }
        {
        test_qvm::vector<V2,3> r;
        r.a[0]=v1.a[0];
        r.a[1]=v1.a[0];
        r.a[2]=0;
        test_qvm::vector<V2,3> v2=(v1,XX0);
        BOOST_QVM_TEST_EQ(v2,r);
        }
        {
        test_qvm::vector<V2,3> r;
        r.a[0]=v1.a[0];
        r.a[1]=v1.a[0];
        r.a[2]=1;
        test_qvm::vector<V2,3> v2=(v1,XX1);
        BOOST_QVM_TEST_EQ(v2,r);
        }
        {
        test_qvm::vector<V2,3> v2=(v1,XYZ);
        (v1,XYZ) *= 2;
        v2 *= 2;
        test_qvm::vector<V2,3> v3=(v1,XYZ);
        BOOST_QVM_TEST_EQ(v2,v3);
        }
        {
        test_qvm::vector<V2,3> v2=(v1,XYZ);
        test_qvm::vector<V3,3> v3;
        (v3,XYZ)=(v2,XYZ);
        BOOST_QVM_TEST_EQ(v2,v3);
        }
    return boost::report_errors();
    }
