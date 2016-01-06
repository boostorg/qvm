//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/quat_traits_array.hpp>
#include <boost/qvm/quat_operations.hpp>
#include <boost/detail/lightweight_test.hpp>

template <class T,class U>
struct same_type;

template <class T>
struct
same_type<T,T>
    {
    };

template <class T,class P>
void
test_ref_cast( T & q, P * ptr )
    {
    using namespace boost::qvm;
    BOOST_QVM_STATIC_ASSERT(is_q<T>::value);
    BOOST_TEST(quat_traits<T>::template r<0>(q)==ptr[0]);
    BOOST_TEST(quat_traits<T>::template r<1>(q)==ptr[1]);
    BOOST_TEST(quat_traits<T>::template r<2>(q)==ptr[2]);
    BOOST_TEST(quat_traits<T>::template r<3>(q)==ptr[3]);
    BOOST_TEST(&quat_traits<T>::template w<0>(q)==&ptr[0]);
    BOOST_TEST(&quat_traits<T>::template w<1>(q)==&ptr[1]);
    BOOST_TEST(&quat_traits<T>::template w<2>(q)==&ptr[2]);
    BOOST_TEST(&quat_traits<T>::template w<3>(q)==&ptr[3]);
    BOOST_TEST(&q[0]==&ptr[0]);
    BOOST_TEST(&q[1]==&ptr[1]);
    BOOST_TEST(&q[2]==&ptr[2]);
    BOOST_TEST(&q[3]==&ptr[3]);
    }

int
main()
    {
    using namespace boost::qvm;
        {
        BOOST_QVM_STATIC_ASSERT(is_q<int[4]>::value);
        BOOST_QVM_STATIC_ASSERT(!is_q<int[4][4]>::value);
        BOOST_QVM_STATIC_ASSERT(!is_q<int[4][4][4]>::value);
        same_type<quat_traits<int[4]>::scalar_type,int>();
        same_type< quat<int>, deduce_quat<int[4]>::type >();
        same_type< quat<int>, deduce_quat<int const[4]>::type >();
        int arr[4] = {0,1,2,3};
        BOOST_TEST((quat_traits<int[4]>::r<0>(arr)==0));
        BOOST_TEST((quat_traits<int[4]>::r<1>(arr)==1));
        BOOST_TEST((quat_traits<int[4]>::r<2>(arr)==2));
        BOOST_TEST((quat_traits<int[4]>::r<3>(arr)==3));
        BOOST_TEST((quat_traits<int const[4]>::r<0>(arr)==0));
        BOOST_TEST((quat_traits<int const[4]>::r<1>(arr)==1));
        BOOST_TEST((quat_traits<int const[4]>::r<2>(arr)==2));
        BOOST_TEST((quat_traits<int const[4]>::r<3>(arr)==3));
        BOOST_TEST((quat_traits<int[4]>::ir(0,arr)==0));
        BOOST_TEST((quat_traits<int[4]>::ir(1,arr)==1));
        BOOST_TEST((quat_traits<int[4]>::ir(2,arr)==2));
        BOOST_TEST((quat_traits<int[4]>::ir(3,arr)==3));
        BOOST_TEST((quat_traits<int const[4]>::ir(0,arr)==0));
        BOOST_TEST((quat_traits<int const[4]>::ir(1,arr)==1));
        BOOST_TEST((quat_traits<int const[4]>::ir(2,arr)==2));
        BOOST_TEST((quat_traits<int const[4]>::ir(3,arr)==3));
        BOOST_TEST((&quat_traits<int[4]>::w<0>(arr)==&arr[0]));
        BOOST_TEST((&quat_traits<int[4]>::w<1>(arr)==&arr[1]));
        BOOST_TEST((&quat_traits<int[4]>::w<2>(arr)==&arr[2]));
        BOOST_TEST((&quat_traits<int[4]>::w<3>(arr)==&arr[3]));
        BOOST_TEST((&quat_traits<int[4]>::iw(0,arr)==&arr[0]));
        BOOST_TEST((&quat_traits<int[4]>::iw(1,arr)==&arr[1]));
        BOOST_TEST((&quat_traits<int[4]>::iw(2,arr)==&arr[2]));
        BOOST_TEST((&quat_traits<int[4]>::iw(3,arr)==&arr[3]));
        }
        {
        int arr[42] = {0};
        int * ptr=arr+5;
        ptr[0]=42;
        ptr[1]=43;
        ptr[2]=44;
        ptr[3]=45;
        test_ref_cast(ptr_qref(ptr),ptr);
        int q[4] = {1,1,1,1};
        ptr_qref(ptr) += qref(q);
        BOOST_TEST(ptr[0]==43);
        BOOST_TEST(ptr[1]==44);
        BOOST_TEST(ptr[2]==45);
        BOOST_TEST(ptr[3]==46);
        }
    return boost::report_errors();
    }
