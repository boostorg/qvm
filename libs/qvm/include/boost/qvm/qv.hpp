//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_51968952D30A11DFAFE78CE3DFD72085
#define UUID_51968952D30A11DFAFE78CE3DFD72085

#include <boost/qvm/q_traits.hpp>
#include <boost/qvm/deduce_v.hpp>
#include <boost/qvm/inline.hpp>
#include <boost/qvm/enable_if.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_q<A>::value &&
            is_v<B>::value && v_traits<B>::dim==3,
            deduce_v2<A,B,3> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename deduce_v2<A,B,3>::type R;
            typedef typename v_traits<R>::scalar_type TR;
            typedef typename q_traits<A>::scalar_type TA;
            typedef typename v_traits<B>::scalar_type TB;
            TA const aa = q_traits<A>::template r<0>(a);
            TA const ab = q_traits<A>::template r<1>(a);
            TA const ac = q_traits<A>::template r<2>(a);
            TA const ad = q_traits<A>::template r<3>(a);
            TA const t2 = aa*ab;
            TA const t3 = aa*ac;
            TA const t4 = aa*ad;
            TA const t5 = -ab*ab;
            TA const t6 = ab*ac;
            TA const t7 = ab*ad;
            TA const t8 = -ac*ac;
            TA const t9 = ac*ad;
            TA const t10     = -ad*ad;
            TB const bx = v_traits<B>::template r<0>(b);
            TB const by = v_traits<B>::template r<1>(b);
            TB const bz = v_traits<B>::template r<2>(b);
            R r;
            v_traits<R>::template w<0>(r) = 2*((t8+t10)*bx + (t6-t4)*by + (t3+t7)*bz) + bx;
            v_traits<R>::template w<1>(r) = 2*((t4+t6)*bx + (t5+t10)*by + (t9-t2)*bz) + by;
            v_traits<R>::template w<2>(r) = 2*((t7-t3)*bx + (t2+t9)*by + (t5+t8)*bz) + bz;
            return r;
            }

        namespace
        sfinae
            {
            using ::boost::qvm::operator*;
            }
        }
    }

#endif
