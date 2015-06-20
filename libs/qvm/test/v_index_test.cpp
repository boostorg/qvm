//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/v_index.hpp>
#include <boost/exception/get_error_info.hpp>
#include "test_qvm_vector.hpp"

int
main()
    {       
    using namespace boost::qvm;

    test_qvm::vector<V1,4> v;
    v.a[0]=42.0f;
    v.a[1]=43.0f;
    v.a[2]=44.0f;
    v.a[3]=45.0f;
    BOOST_TEST(v_index_read(v,0)==v.a[0]);
    BOOST_TEST(v_index_read(v,1)==v.a[1]);
    BOOST_TEST(v_index_read(v,2)==v.a[2]);
    BOOST_TEST(v_index_read(v,3)==v.a[3]);
    BOOST_TEST(&v_index_write(v,0)==&v.a[0]);
    BOOST_TEST(&v_index_write(v,1)==&v.a[1]);
    BOOST_TEST(&v_index_write(v,2)==&v.a[2]);
    BOOST_TEST(&v_index_write(v,3)==&v.a[3]);
    try
        {
        (void) v_index_read(v,-1);
        BOOST_TEST(false);
        }
    catch(
    vector_index_out_of_bounds_error & e )
        {
        BOOST_TEST(boost::get_error_info<vector_index>(e) && *boost::get_error_info<vector_index>(e)==-1);
        BOOST_TEST(boost::get_error_info<vector_size>(e) && *boost::get_error_info<vector_size>(e)==4);
        }
    try
        {
        (void) v_index_write(v,-1);
        BOOST_TEST(false);
        }
    catch(
    vector_index_out_of_bounds_error & e )
        {
        BOOST_TEST(boost::get_error_info<vector_index>(e) && *boost::get_error_info<vector_index>(e)==-1);
        BOOST_TEST(boost::get_error_info<vector_size>(e) && *boost::get_error_info<vector_size>(e)==4);
        }
    return boost::report_errors();
    }
