//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_C5DC682E196211E0A4C1686BDFD72085
#define UUID_C5DC682E196211E0A4C1686BDFD72085

#include <boost/qvm/deduce_s.hpp>
#include <boost/qvm/m_traits.hpp>
#include <boost/qvm/static_assert.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        template <class T,int Rows,int Cols>
        struct mat;

        namespace
        qvm_detail
            {
            template <class M,int R,int C,
                int MR=m_traits<M>::rows,
                int MC=m_traits<M>::cols>
            struct
            deduce_m_default
                {
                BOOST_QVM_STATIC_ASSERT(is_m<M>::value);
                typedef mat<typename m_traits<M>::scalar_type,R,C> type;
                };

            template <class M,int R,int C>
            struct
            deduce_m_default<M,R,C,R,C>
                {
                BOOST_QVM_STATIC_ASSERT(is_m<M>::value);
                typedef M type;
                };
            }

        template <class Type,int Rows=m_traits<Type>::rows,int Cols=m_traits<Type>::cols>
        struct
        deduce_m
            {
            BOOST_QVM_STATIC_ASSERT(is_m<Type>::value);
            typedef typename qvm_detail::deduce_m_default<Type,Rows,Cols>::type type;
            };

        namespace
        qvm_detail
            {
            template <class A,class B,int R,int C,
                bool VA=is_m<A>::value,
                bool VB=is_m<B>::value,
                int AR=m_traits<A>::rows,
                int AC=m_traits<A>::cols,
                int BR=m_traits<B>::rows,
                int BC=m_traits<B>::cols>
            struct
            deduce_m2_default
                {
                typedef mat<
                    typename deduce_s<
                        typename scalar<A>::type,
                        typename scalar<B>::type>::type,
                    R,C> type;
                };

            template <class M,int R,int C>
            struct
            deduce_m2_default<M,M,R,C,true,true,R,C,R,C>
                {
                typedef M type;
                };
            };

        template <class A,class B,int R,int C>
        struct
        deduce_m2
            {
            BOOST_QVM_STATIC_ASSERT(is_m<A>::value || is_m<B>::value);
            typedef typename qvm_detail::deduce_m2_default<A,B,R,C>::type type;
            };
        }
    }

#endif
