//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_57E1C032B9F311DEB7D9BAFE55D89593
#define UUID_57E1C032B9F311DEB7D9BAFE55D89593

#include <boost/qvm/q_traits.hpp>
#include <boost/qvm/v_traits.hpp>
#include <boost/qvm/m_traits.hpp>
#include <boost/qvm/inline.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        template <class Scalar>
        struct
        s_traits
            {
            static
            BOOST_QVM_INLINE_CRITICAL
            Scalar
            value( int v )
                {
                return Scalar(v);
                }
            };

        template <class T>
        struct
        is_s
            {
            static bool const value=false;
            };
        template <> struct is_s<char> { static bool const value=true; };
        template <> struct is_s<signed char> { static bool const value=true; };
        template <> struct is_s<unsigned char> { static bool const value=true; };
        template <> struct is_s<signed short> { static bool const value=true; };
        template <> struct is_s<unsigned short> { static bool const value=true; };
        template <> struct is_s<signed int> { static bool const value=true; };
        template <> struct is_s<unsigned int> { static bool const value=true; };
        template <> struct is_s<signed long> { static bool const value=true; };
        template <> struct is_s<unsigned long> { static bool const value=true; };
        template <> struct is_s<float> { static bool const value=true; };
        template <> struct is_s<double> { static bool const value=true; };

        namespace
        qvm_detail
            {
            template <class A,bool M=is_m<A>::value,bool Q=is_q<A>::value,bool V=is_v<A>::value>
            struct
            scalar_impl
                {
                };

            template <class A>
            struct
            scalar_impl<A,true,false,false>
                {
                typedef typename m_traits<A>::scalar_type type;
                };

            template <class A>
            struct
            scalar_impl<A,false,true,false>
                {
                typedef typename q_traits<A>::scalar_type type;
                };

            template <class A>
            struct
            scalar_impl<A,false,false,true>
                {
                typedef typename v_traits<A>::scalar_type type;
                };
            }

        template <class A>
        struct
        scalar
            {
            typedef typename qvm_detail::scalar_impl<A>::type type;
            };
        }
    }

#endif
