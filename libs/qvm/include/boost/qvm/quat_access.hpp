//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_8AC84A2217C411E0A7AF3A1BDFD72085
#define UUID_8AC84A2217C411E0A7AF3A1BDFD72085

#include <boost/qvm/inline.hpp>
#include <boost/qvm/quat_traits.hpp>
#include <boost/qvm/static_assert.hpp>
#include <boost/qvm/enable_if.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        ////////////////////////////////////////////////

        template <class Tag>
        struct
        quaternion_access_tag
            {
            };

        template <int I>
        struct vector_access_tag;

        namespace
        qvm_detail
            {
            struct _s_;
            struct _v_;
            
            template <class Q>
            struct
            quat_v_
                {
                template <class R>
                operator R() const
                    {
                    R r;
                    assign(r,*this);
                    return r;
                    }

                private:

                quat_v_( quat_v_ const & );
                quat_v_ const & operator=( quat_v_ const & );
                ~quat_v_();
                };
            }

        template <class V>
        struct vec_traits;

        template <class Q>
        struct
        vec_traits< qvm_detail::quat_v_<Q> >
            {
            static int const dim=3;
            typedef typename quat_traits<Q>::scalar_type scalar_type;

            template <int I>
            BOOST_QVM_INLINE_CRITICAL
            static
            scalar_type
            r( qvm_detail::quat_v_<Q> const & q )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<dim);
                return quat_traits<Q>::template r<I+1>( reinterpret_cast<Q const &>(q) );
                }

            template <int I>
            BOOST_QVM_INLINE_CRITICAL
            static
            scalar_type &
            w( qvm_detail::quat_v_<Q> & q )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<dim);
                return quat_traits<Q>::template w<I+1>( reinterpret_cast<Q &>(q) );
                }
            };

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            qvm_detail::quat_v_<Q> const &>::type
        operator,( Q const & a, quaternion_access_tag<qvm_detail::_v_> (*)() )
            {
            return reinterpret_cast<qvm_detail::quat_v_<Q> const &>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            qvm_detail::quat_v_<Q> &>::type
        operator,( Q & a, quaternion_access_tag<qvm_detail::_v_> (*)() )
            {
            return reinterpret_cast<qvm_detail::quat_v_<Q> &>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            qvm_detail::quat_v_<Q> const &>::type
        operator,( Q const & a, quaternion_access_tag<qvm_detail::_v_> )
            {
            return reinterpret_cast<qvm_detail::quat_v_<Q> const &>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            qvm_detail::quat_v_<Q> &>::type
        operator,( Q & a, quaternion_access_tag<qvm_detail::_v_> )
            {
            return reinterpret_cast<qvm_detail::quat_v_<Q> &>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type>::type
        operator,( Q const & a, quaternion_access_tag<qvm_detail::_s_> (*)() )
            {
            return quat_traits<Q>::template r<0>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type &>::type
        operator,( Q & a, quaternion_access_tag<qvm_detail::_s_> (*)() )
            {
            return quat_traits<Q>::template w<0>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type>::type
        operator,( Q const & a, quaternion_access_tag<qvm_detail::_s_> )
            {
            return quat_traits<Q>::template r<0>(a);
            }

        template <class Q>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type &>::type
        operator,( Q & a, quaternion_access_tag<qvm_detail::_s_> )
            {
            return quat_traits<Q>::template w<0>(a);
            }

        template <class Q,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type>::type
        operator,( Q const & a, vector_access_tag<I> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<3);
            return quat_traits<Q>::template r<I+1>(a);
            }

        template <class Q,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type &>::type
        operator,( Q & a, vector_access_tag<I> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<3);
            return quat_traits<Q>::template w<I+1>(a);
            }

        template <class Q,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type>::type
        operator,( Q const & a, vector_access_tag<I> )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<3);
            return quat_traits<Q>::template r<I+1>(a);
            }

        template <class Q,int I>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_quat<Q>::value,
            typename quat_traits<Q>::scalar_type &>::type
        operator,( Q & a, vector_access_tag<I> )
            {
            BOOST_QVM_STATIC_ASSERT(I>=0);
            BOOST_QVM_STATIC_ASSERT(I<3);
            return quat_traits<Q>::template w<I+1>(a);
            }

        BOOST_QVM_INLINE_TRIVIAL quaternion_access_tag<qvm_detail::_v_> V() { return quaternion_access_tag<qvm_detail::_v_>(); }
        BOOST_QVM_INLINE_TRIVIAL quaternion_access_tag<qvm_detail::_s_> S() { return quaternion_access_tag<qvm_detail::_s_>(); }

        ////////////////////////////////////////////////

        namespace
        sfinae
            {
            using ::boost::qvm::operator,;
            }

        ////////////////////////////////////////////////
        }
    }

#endif
