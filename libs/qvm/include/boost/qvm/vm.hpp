//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_A61EC088D31511DFA59D2B03E0D72085
#define UUID_A61EC088D31511DFA59D2B03E0D72085

#include <boost/qvm/vm2.hpp>
#include <boost/qvm/vm3.hpp>
#include <boost/qvm/vm4.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            mul_mv_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value && is_v<B>::value &&
            m_traits<A>::cols==v_traits<B>::dim &&
            !qvm_detail::mul_mv_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            deduce_v2<A,B,m_traits<A>::rows> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename deduce_v2<A,B,m_traits<A>::rows>::type R;
            R r;
            for( int i=0; i<m_traits<A>::rows; ++i )
                {
                typedef typename v_traits<R>::scalar_type Tr;
                Tr x(s_traits<Tr>::value(0));
                for( int j=0; j<m_traits<A>::cols; ++j )
                    x += m_traits<A>::ir(i,j,a)*v_traits<B>::ir(j,b);
                v_traits<R>::iw(i,r) = x;
                }
            return r;
            }

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            mul_vm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_v<A>::value && is_m<B>::value &&
            v_traits<A>::dim==m_traits<B>::rows &&
            !qvm_detail::mul_vm_defined<m_traits<B>::rows,m_traits<B>::cols>::value,
            deduce_v2<A,B,m_traits<B>::cols> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename deduce_v2<A,B,m_traits<B>::cols>::type R;
            R r;
            for( int i=0; i<m_traits<B>::cols; ++i )
                {
                typedef typename v_traits<R>::scalar_type Tr;
                Tr x(s_traits<Tr>::value(0));
                for( int j=0; j<m_traits<B>::rows; ++j )
                    x += v_traits<A>::ir(j,a)*m_traits<B>::ir(j,i,b);
                v_traits<R>::iw(i,r) = x;
                }
            return r;
            }

        ////////////////////////////////////////////////

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            m_traits<A>::rows==4 && m_traits<A>::cols==4 &&
            v_traits<B>::dim==3,
            deduce_v2<A,B,3> >::type
        transform_point( A const & a, B const & b )
            {
            typedef typename m_traits<A>::scalar_type Ta;
            typedef typename v_traits<B>::scalar_type Tb;
            Ta const a00 = m_traits<A>::template r<0,0>(a);
            Ta const a01 = m_traits<A>::template r<0,1>(a);
            Ta const a02 = m_traits<A>::template r<0,2>(a);
            Ta const a03 = m_traits<A>::template r<0,3>(a);
            Ta const a10 = m_traits<A>::template r<1,0>(a);
            Ta const a11 = m_traits<A>::template r<1,1>(a);
            Ta const a12 = m_traits<A>::template r<1,2>(a);
            Ta const a13 = m_traits<A>::template r<1,3>(a);
            Ta const a20 = m_traits<A>::template r<2,0>(a);
            Ta const a21 = m_traits<A>::template r<2,1>(a);
            Ta const a22 = m_traits<A>::template r<2,2>(a);
            Ta const a23 = m_traits<A>::template r<2,3>(a);
            Tb const b0 = v_traits<B>::template r<0>(b);
            Tb const b1 = v_traits<B>::template r<1>(b);
            Tb const b2 = v_traits<B>::template r<2>(b);
            typedef typename deduce_v2<A,B,3>::type R;
            BOOST_QVM_STATIC_ASSERT(v_traits<R>::dim==3);
            R r;
            v_traits<R>::template w<0>(r)=a00*b0+a01*b1+a02*b2+a03;
            v_traits<R>::template w<1>(r)=a10*b0+a11*b1+a12*b2+a13;
            v_traits<R>::template w<2>(r)=a20*b0+a21*b1+a22*b2+a23;
            return r;
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            m_traits<A>::rows==4 && m_traits<A>::cols==4 &&
            v_traits<B>::dim==3,
            deduce_v2<A,B,3> >::type
        transform_vector( A const & a, B const & b )
            {
            typedef typename m_traits<A>::scalar_type Ta;
            typedef typename v_traits<B>::scalar_type Tb;
            Ta const a00 = m_traits<A>::template r<0,0>(a);
            Ta const a01 = m_traits<A>::template r<0,1>(a);
            Ta const a02 = m_traits<A>::template r<0,2>(a);
            Ta const a10 = m_traits<A>::template r<1,0>(a);
            Ta const a11 = m_traits<A>::template r<1,1>(a);
            Ta const a12 = m_traits<A>::template r<1,2>(a);
            Ta const a20 = m_traits<A>::template r<2,0>(a);
            Ta const a21 = m_traits<A>::template r<2,1>(a);
            Ta const a22 = m_traits<A>::template r<2,2>(a);
            Tb const b0 = v_traits<B>::template r<0>(b);
            Tb const b1 = v_traits<B>::template r<1>(b);
            Tb const b2 = v_traits<B>::template r<2>(b);
            typedef typename deduce_v2<A,B,3>::type R;
            BOOST_QVM_STATIC_ASSERT(v_traits<R>::dim==3);
            R r;
            v_traits<R>::template w<0>(r)=a00*b0+a01*b1+a02*b2;
            v_traits<R>::template w<1>(r)=a10*b0+a11*b1+a12*b2;
            v_traits<R>::template w<2>(r)=a20*b0+a21*b1+a22*b2;
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        sfinae
            {
            using ::boost::qvm::operator*;
            using ::boost::qvm::transform_point;
            using ::boost::qvm::transform_vector;
            }

        ////////////////////////////////////////////////
        }
    }

#endif
