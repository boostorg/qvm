//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/map.hpp>
#include <boost/qvm/m_traits_array.hpp>
#include <boost/qvm/v.hpp>
#include <boost/qvm/m.hpp>
#include <boost/qvm/mat.hpp>
#include "test_qvm_vector.hpp"
#include "gold.hpp"

namespace
    {
    template <int Dim>
    void
    test()
        {
        using namespace boost::qvm;
        test_qvm::vector<V1,Dim-1> x(42,1);
        float r1[Dim][Dim];
        test_qvm::translation(r1,x.a);
        float r2[Dim][Dim];
        assign(r2,trans_m(x));
        BOOST_QVM_TEST_EQ(r1,r2);
        test_qvm::scalar_multiply_v(x.b,x.a,2.0f);
        col<Dim-1>(delr<Dim-1>(trans_m(x))) *= 2;
        BOOST_QVM_TEST_EQ(x.a,x.b);
        trans_m(x) + trans_m(x);
        -trans_m(x);
        }
    }

int
main()
    {
    test<3>();
    test<4>();
    test<5>();
    return boost::report_errors();
    }
