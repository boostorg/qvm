//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_E831FAD6B38F11DE8CECBF0D56D89593
#define UUID_E831FAD6B38F11DE8CECBF0D56D89593

#include <boost/qvm/inline.hpp>
#include <boost/qvm/deduce_vec.hpp>
#include <boost/qvm/enable_if.hpp>
#include <boost/qvm/assert.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        struct _x_;
        struct _y_;
        struct _z_;
        struct _w_;
        struct _b_;
        struct _g_;
        struct _r_;
        struct _a_;
        struct _0_;
        struct _1_;

        namespace
        qvm_detail
            {
            template <int A,class Next=void> struct swizzle_idx { static int const value=A; typedef Next next; };

            template <class Tag> struct swizzle_tag;
            template <> struct swizzle_tag<_x_> { static int const value=0; };
            template <> struct swizzle_tag<_y_> { static int const value=1; };
            template <> struct swizzle_tag<_z_> { static int const value=2; };
            template <> struct swizzle_tag<_w_> { static int const value=3; };
            template <> struct swizzle_tag<_b_> { static int const value=0; };
            template <> struct swizzle_tag<_g_> { static int const value=1; };
            template <> struct swizzle_tag<_r_> { static int const value=2; };
            template <> struct swizzle_tag<_a_> { static int const value=3; };
            template <> struct swizzle_tag<_0_> { static int const value=-1; };
            template <> struct swizzle_tag<_1_> { static int const value=-2; };

            template <class S,int V>
            struct
            const_value
                {
                static
                BOOST_QVM_INLINE_TRIVIAL
                S
                value()
                    {
                    BOOST_QVM_ASSERT(0);
                    return S();
                    }
                };

            template <class S>
            struct
            const_value<S,swizzle_tag<_0_>::value>
                {
                static
                BOOST_QVM_INLINE_TRIVIAL
                S
                value()
                    {
                    return scalar_traits<S>::value(0);
                    }
                };

            template <class S>
            struct
            const_value<S,swizzle_tag<_1_>::value>
                {
                static
                BOOST_QVM_INLINE_TRIVIAL
                S
                value()
                    {
                    return scalar_traits<S>::value(1);
                    }
                };

            template <int Index,bool Neg=(Index<0)>
            struct neg_zero;

            template <int Index>
            struct
            neg_zero<Index,true>
                {
                static int const value=0;
                };

            template <int Index>
            struct
            neg_zero<Index,false>
                {
                static int const value=Index;
                };

            template <class SwizzleList,int Index,int C=0>
            struct
            swizzle
                {
                static int const value=swizzle<typename SwizzleList::next,Index,C+1>::value;
                };

            template <class SwizzleList,int Match>
            struct
            swizzle<SwizzleList,Match,Match>
                {
                static int const value=SwizzleList::value;
                };

            template <int Index,int C>
            struct swizzle<void,Index,C>;

            template <class SwizzleList,int C=0>
            struct
            swizzle_list_length
                {
                static int const value=swizzle_list_length<typename SwizzleList::next,C+1>::value;
                };

            template <int C>
            struct
            swizzle_list_length<void,C>
                {
                static int const value=C;
                };


            template <class SwizzleList,int D>
            struct
            validate_swizzle_list
                {
                static bool const value =
                    ((SwizzleList::value)<D) && //don't touch extra (), MSVC parsing bug.
                    validate_swizzle_list<typename SwizzleList::next,D>::value;
                };

            template <int D>
            struct
            validate_swizzle_list<void,D>
                {
                static bool const value=true;
                };

            template <class OriginalType,class SwizzleList>
            class
            swizzle_
                {
                swizzle_( swizzle_ const & );
                swizzle_ & operator=( swizzle_ const & );
                ~swizzle_();

                BOOST_QVM_STATIC_ASSERT((validate_swizzle_list<SwizzleList,vec_traits<OriginalType>::dim>::value));

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                swizzle_ &
                operator=( T const & x )
                    {
                    assign(*this,x);
                    return *this;
                    }

                template <class R>
                BOOST_QVM_INLINE_TRIVIAL
                operator R() const
                    {
                    R r;
                    assign(r,*this);
                    return r;
                    }
                };
            }

        template <class OriginalVector,class SwizzleList>
        struct
        vec_traits< qvm_detail::swizzle_<OriginalVector,SwizzleList> >
            {
            typedef qvm_detail::swizzle_<OriginalVector,SwizzleList> this_vector;
            typedef typename vec_traits<OriginalVector>::scalar_type scalar_type;
            static int const dim=qvm_detail::swizzle_list_length<SwizzleList>::value;

            template <int I>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_vector const & x )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<dim);
                int const v=qvm_detail::swizzle<SwizzleList,I>::value;
                BOOST_QVM_STATIC_ASSERT(v<vec_traits<OriginalVector>::dim);
                return v>=0?
                    vec_traits<OriginalVector>::template r<qvm_detail::neg_zero<v>::value>(reinterpret_cast<OriginalVector const &>(x)) :
                    qvm_detail::const_value<scalar_type,v>::value();
                }

            template <int I>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            w( this_vector & x )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<dim);
                int const v=qvm_detail::swizzle<SwizzleList,I>::value;
                BOOST_QVM_STATIC_ASSERT(v>=0);
                BOOST_QVM_STATIC_ASSERT(v<vec_traits<OriginalVector>::dim);
                return vec_traits<OriginalVector>::template w<v>(reinterpret_cast<OriginalVector &>(x));
                }
            };

        template <class OriginalVector,class SwizzleList,int D>
        struct
        deduce_vec<qvm_detail::swizzle_<OriginalVector,SwizzleList>,D>
            {
            typedef vec<typename vec_traits<OriginalVector>::scalar_type,D> type;
            };

        template <class OriginalVector,class SwizzleList,int D>
        struct
        deduce_vec2<qvm_detail::swizzle_<OriginalVector,SwizzleList>,qvm_detail::swizzle_<OriginalVector,SwizzleList>,D>
            {
            typedef vec<typename vec_traits<OriginalVector>::scalar_type,D> type;
            };

        template <class OriginalVector,int A,class Next>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > const &>::type
        operator,( OriginalVector const & a, qvm_detail::swizzle_idx<A,Next> )
            {
            return reinterpret_cast<qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > const &>(a);
            }

        template <class OriginalVector,int A,class Next>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > &>::type
        operator,( OriginalVector & a, qvm_detail::swizzle_idx<A,Next> )
            {
            return reinterpret_cast<qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > &>(a);
            }

        template <class OriginalVector,int A>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            typename vec_traits<OriginalVector>::scalar_type>::type
        operator,( OriginalVector const & a, qvm_detail::swizzle_idx<A> )
            {
            BOOST_QVM_STATIC_ASSERT(A>=0);
            BOOST_QVM_STATIC_ASSERT(A<vec_traits<OriginalVector>::dim);
            return vec_traits<OriginalVector>::template r<A>(a);
            }

        template <class OriginalVector,int A>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            typename vec_traits<OriginalVector>::scalar_type &>::type
        operator,( OriginalVector & a, qvm_detail::swizzle_idx<A> )
            {
            BOOST_QVM_STATIC_ASSERT(A>=0);
            BOOST_QVM_STATIC_ASSERT(A<vec_traits<OriginalVector>::dim);
            return vec_traits<OriginalVector>::template w<A>(a);
            }

        template <class OriginalVector,int A,class Next>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > const &>::type
        operator,( OriginalVector const & a, qvm_detail::swizzle_idx<A,Next> (*)() )
            {
            return reinterpret_cast<qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > const &>(a);
            }

        template <class OriginalVector,int A,class Next>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > &>::type
        operator,( OriginalVector & a, qvm_detail::swizzle_idx<A,Next> (*)() )
            {
            return reinterpret_cast<qvm_detail::swizzle_<OriginalVector,qvm_detail::swizzle_idx<A,Next> > &>(a);
            }

        template <class OriginalVector,int A>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            typename vec_traits<OriginalVector>::scalar_type>::type
        operator,( OriginalVector const & a, qvm_detail::swizzle_idx<A> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(A>=0);
            BOOST_QVM_STATIC_ASSERT(A<vec_traits<OriginalVector>::dim);
            return vec_traits<OriginalVector>::template r<A>(a);
            }

        template <class OriginalVector,int A>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_v<OriginalVector>::value,
            typename vec_traits<OriginalVector>::scalar_type &>::type
        operator,( OriginalVector & a, qvm_detail::swizzle_idx<A> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(A>=0);
            BOOST_QVM_STATIC_ASSERT(A<vec_traits<OriginalVector>::dim);
            return vec_traits<OriginalVector>::template w<A>(a);
            }
        }
    }

#endif
