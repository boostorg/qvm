//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3B4919D8A41411DEB0818E4C56D89593
#define UUID_3B4919D8A41411DEB0818E4C56D89593

#include <boost/qvm/detail/swizzle_traits.hpp>
#include <boost/qvm/swizzle2.hpp>
#include <boost/qvm/swizzle3.hpp>
#include <boost/qvm/swizzle4.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        template <int A0>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<A0>
        sw() { return qvm_detail::swizzle_idx<A0>(); }

        template <int A0,int A1>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<A0,qvm_detail::swizzle_idx<A1> >
        sw() { return qvm_detail::swizzle_idx<A0,qvm_detail::swizzle_idx<A1> >(); }

        template <int A0,int A1,int A2>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<A0,qvm_detail::swizzle_idx<A1,qvm_detail::swizzle_idx<A2> > >
        sw() { return qvm_detail::swizzle_idx<A0,qvm_detail::swizzle_idx<A1,qvm_detail::swizzle_idx<A2> > >(); }

        template <int A0,int A1,int A2,int A3>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<A0,qvm_detail::swizzle_idx<A1,qvm_detail::swizzle_idx<A2,qvm_detail::swizzle_idx<A3> > > >
        sw() { return qvm_detail::swizzle_idx<A0,qvm_detail::swizzle_idx<A1,qvm_detail::swizzle_idx<A2,qvm_detail::swizzle_idx<A3> > > >(); }

        template <class A0>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value>
        sw() { return qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value>(); }

        template <class A0,class A1>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A1>::value> >
        sw() { return qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A1>::value> >(); }

        template <class A0,class A1,class A2>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A1>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A2>::value> > >
        sw() { return qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A1>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A2>::value> > >(); }

        template <class A0,class A1,class A2,class A3>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A1>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A2>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A3>::value> > > >
        sw() { return qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A0>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A1>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A2>::value,qvm_detail::swizzle_idx<qvm_detail::swizzle_tag<A3>::value> > > >(); }
        }
    }

#endif
