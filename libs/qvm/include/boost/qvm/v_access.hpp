//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_10F2D1EA17B511E0BA29FE0BDFD72085
#define UUID_10F2D1EA17B511E0BA29FE0BDFD72085

#include <boost/qvm/v_traits.hpp>
#include <boost/qvm/inline.hpp>
#include <boost/qvm/static_assert.hpp>
#include <boost/qvm/enable_if.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        ////////////////////////////////////////////////

        template <int I>
        struct
        vector_access_tag
            {
            };

        template <class V,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<V>::value,
            typename v_traits<V>::scalar_type &>::type
        operator%( V & a, vector_access_tag<I> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<v_traits<V>::dim);
            return v_traits<V>::template w<I>(a);
            }

        template <class V,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<V>::value,
            typename v_traits<V>::scalar_type>::type
        operator%( V const & a, vector_access_tag<I> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<v_traits<V>::dim);
            return v_traits<V>::template r<I>(a);
            }

        template <class V,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<V>::value,
            typename v_traits<V>::scalar_type &>::type
        operator%( V & a, vector_access_tag<I> )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<v_traits<V>::dim);
            return v_traits<V>::template w<I>(a);
            }

        template <class V,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<V>::value,
            typename v_traits<V>::scalar_type>::type
        operator%( V const & a, vector_access_tag<I> )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<v_traits<V>::dim);
            return v_traits<V>::template r<I>(a);
            }

        template <int I>
        BOOST_QVM_INLINE_TRIVIAL
        vector_access_tag<I>
        A()
            {
            return vector_access_tag<I>();
            }

        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<0> X() { return vector_access_tag<0>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<1> Y() { return vector_access_tag<1>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<2> Z() { return vector_access_tag<2>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<3> W() { return vector_access_tag<3>(); }

        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<0> A0() { return vector_access_tag<0>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<1> A1() { return vector_access_tag<1>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<2> A2() { return vector_access_tag<2>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<3> A3() { return vector_access_tag<3>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<4> A4() { return vector_access_tag<4>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<5> A5() { return vector_access_tag<5>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<6> A6() { return vector_access_tag<6>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<7> A7() { return vector_access_tag<7>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<8> A8() { return vector_access_tag<8>(); }
        BOOST_QVM_INLINE_TRIVIAL vector_access_tag<9> A9() { return vector_access_tag<9>(); }

        ////////////////////////////////////////////////

        namespace
        sfinae
            {
            using ::boost::qvm::operator%;
            }

        ////////////////////////////////////////////////
        }
    }

#endif
