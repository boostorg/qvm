//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.
//Copyright (c) 2019 agate-pris

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_A0F4BD501E7241189A9100EF896F06CC
#define UUID_A0F4BD501E7241189A9100EF896F06CC

#include <boost/qvm/inline.hpp>
#include <boost/qvm/quat_traits.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        namespace
        qvm_detail
            {
            template <int I>
            struct
            cmp_quat
                {
                template <class A,class B,class Cmp>
                static
                BOOST_QVM_INLINE_CRITICAL
                bool
                g( A const & a, B const & b, Cmp & comp )
                    {
                    return comp(
                        quat_traits<A>::template read_element<I>(a),
                        quat_traits<B>::template read_element<I>(b))
                        && cmp_quat<I+1>::g(a,b,comp);
                    }

                template <class A,class B,class Cmp>
                static
                BOOST_QVM_INLINE_CRITICAL
                bool
                h( A const & a, B const & b, Cmp & comp )
                    {
                    return comp(
                        quat_traits<A>::template read_element<I>(a),
                        -quat_traits<B>::template read_element<I>(b))
                        && cmp_quat<I+1>::h(a,b,comp);
                    }

                template <class A,class B,class Cmp>
                static
                BOOST_QVM_INLINE_CRITICAL
                bool
                f( A const & a, B const & b, Cmp & comp )
                    {
                    return g(a,b,comp) || h(a,b,comp);
                    }
                };

            template <>
            struct
            cmp_quat<3>
                {
                template <class A,class B,class Cmp>
                static
                BOOST_QVM_INLINE_CRITICAL
                bool
                g( A const & a, B const & b, Cmp const & comp )
                    {
                    return comp(
                        quat_traits<A>::template read_element<3>(a),
                        quat_traits<B>::template read_element<3>(b));
                    }

                template <class A,class B,class Cmp>
                static
                BOOST_QVM_INLINE_CRITICAL
                bool
                h( A const & a, B const & b, Cmp const & comp )
                    {
                    return comp(
                        quat_traits<A>::template read_element<3>(a),
                        -quat_traits<B>::template read_element<3>(b));
                    }
                };
            }
        }
    }

#endif
