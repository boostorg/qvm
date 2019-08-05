//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/detail/equal_to.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/vec_operations.hpp>
#include <boost/qvm/vec_traits_array.hpp>
#include "test_qvm_vector.hpp"
#include "gold.hpp"
#include "test_qvm_scalar.hpp"
#include <functional>

namespace
    {
    template <int Dim>
    void
    test()
        {
        using namespace boost::qvm::sfinae;
        test_qvm::vector<V1,Dim> const x(42,1);
        for( int i=0; i!=Dim; ++i )
            {
                {
                test_qvm::vector<V1,Dim> y(x);
                BOOST_TEST(cmp(x,y,std::equal_to<float>()));
                y.a[i]=0;
                BOOST_TEST(!cmp(x,y,std::equal_to<float>()));
                }
            }
        }

    struct
    equal_to
    {
        template <class T,class U>
        bool
        operator()( T const & a, U const & b )
        {
            return a==b;
        }
    };

    template <class A, class B>
    void
    test2()
        {
        typedef test_qvm::inconvenient_scalar<A> scalar_a;
        typedef test_qvm::inconvenient_scalar<B> scalar_b;
        typedef boost::qvm::vec<scalar_a, 5> vec_a;
        typedef boost::qvm::vec<scalar_b, 5> vec_b;

        vec_a const a =
            {
            scalar_a(42),
            scalar_a(94),
            scalar_a(96),
            scalar_a(72),
            scalar_a(95)
            };

        vec_b const b =
            {
            scalar_b(42),
            scalar_b(94),
            scalar_b(96),
            scalar_b(72),
            scalar_b(95)
            };

        vec_a const c =
            {
            scalar_a(21),
            scalar_a(47),
            scalar_a(48),
            scalar_a(36),
            scalar_a(47)
            };

        vec_b const d =
            {
            scalar_b(21),
            scalar_b(47),
            scalar_b(48),
            scalar_b(36),
            scalar_b(47)
            };

        BOOST_TEST(cmp(a,a,equal_to()));
        BOOST_TEST(cmp(a,b,equal_to()));
        BOOST_TEST(cmp(b,a,equal_to()));
        BOOST_TEST(cmp(b,b,equal_to()));
        BOOST_TEST(cmp(c,c,equal_to()));
        BOOST_TEST(cmp(c,d,equal_to()));
        BOOST_TEST(cmp(d,c,equal_to()));
        BOOST_TEST(cmp(d,d,equal_to()));
        BOOST_TEST(!cmp(a,c,equal_to()));
        BOOST_TEST(!cmp(c,a,equal_to()));
        BOOST_TEST(!cmp(a,d,equal_to()));
        BOOST_TEST(!cmp(d,a,equal_to()));
        BOOST_TEST(!cmp(b,c,equal_to()));
        BOOST_TEST(!cmp(c,b,equal_to()));
        BOOST_TEST(!cmp(b,d,equal_to()));
        BOOST_TEST(!cmp(d,b,equal_to()));
        }
    }

int
main()
    {
    test<2>();
    test<3>();
    test<4>();
    test<5>();
    test2<int, int>();
    test2<int, double>();
    test2<double, int>();
    test2<double, double>();
    return boost::report_errors();
    }
