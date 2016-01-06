//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/quat_access.hpp>
#include <boost/qvm/vec_access.hpp>
#include "test_qvm_quaternion.hpp"

int
main()
    {       
    using namespace boost::qvm;

    test_qvm::quaternion<Q1> q;
    q.a[0]=42.0f;
    q.a[1]=43.0f;
    q.a[2]=44.0f;
    q.a[3]=45.0f;
    test_qvm::quaternion<Q1> const & qq=q;

    BOOST_TEST_EQ((qq,V,X),q.a[1]);
    BOOST_TEST_EQ((qq,V,Y),q.a[2]);
    BOOST_TEST_EQ((qq,V,Z),q.a[3]);
    BOOST_TEST(&(q,V,X)==&q.a[1]);
    BOOST_TEST(&(q,V,Y)==&q.a[2]);
    BOOST_TEST(&(q,V,Z)==&q.a[3]);

    BOOST_TEST_EQ((qq,V(),X),q.a[1]);
    BOOST_TEST_EQ((qq,V(),Y),q.a[2]);
    BOOST_TEST_EQ((qq,V(),Z),q.a[3]);
    BOOST_TEST(&(q,V(),X)==&q.a[1]);
    BOOST_TEST(&(q,V(),Y)==&q.a[2]);
    BOOST_TEST(&(q,V(),Z)==&q.a[3]);

    BOOST_TEST_EQ((qq,S),q.a[0]);
    BOOST_TEST_EQ((qq,X),q.a[1]);
    BOOST_TEST_EQ((qq,Y),q.a[2]);
    BOOST_TEST_EQ((qq,Z),q.a[3]);
    BOOST_TEST(&(q,S)==&q.a[0]);
    BOOST_TEST(&(q,X)==&q.a[1]);
    BOOST_TEST(&(q,Y)==&q.a[2]);
    BOOST_TEST(&(q,Z)==&q.a[3]);

    BOOST_TEST_EQ((qq,S()),q.a[0]);
    BOOST_TEST_EQ((qq,X()),q.a[1]);
    BOOST_TEST_EQ((qq,Y()),q.a[2]);
    BOOST_TEST_EQ((qq,Z()),q.a[3]);
    BOOST_TEST(&(q,S())==&q.a[0]);
    BOOST_TEST(&(q,X())==&q.a[1]);
    BOOST_TEST(&(q,Y())==&q.a[2]);
    BOOST_TEST(&(q,Z())==&q.a[3]);

    return boost::report_errors();
    }
