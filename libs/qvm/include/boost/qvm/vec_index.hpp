//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_7FF8E2E00E5411E2AB79F7FE6188709B
#define UUID_7FF8E2E00E5411E2AB79F7FE6188709B

#include <boost/qvm/vec_traits.hpp>
#include <boost/qvm/inline.hpp>
#include <boost/qvm/enable_if.hpp>
#include <boost/qvm/error.hpp>
#include <boost/exception/info.hpp>

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
            template <int D>
            struct
            v_index_read_defined
                {
                static bool const value=false;
                };

            template <int I,int N>
            struct
            vector_r
                {
                template <class A>
                static
                BOOST_QVM_INLINE_CRITICAL
                typename vec_traits<A>::scalar_type
                ir( A const & a, int i )
                    {
                    return I==i?
                        vec_traits<A>::template r<I>(a) :
                        vector_r<I+1,N>::ir(a,i);
                    }
                };

            template <int N>
            struct
            vector_r<N,N>
                {
                template <class A>
                static
                BOOST_QVM_INLINE_TRIVIAL
                typename vec_traits<A>::scalar_type
                ir( A const &, int i )
                    {
                    typedef char dim_[vec_traits<A>::dim];
                    BOOST_THROW_EXCEPTION(vector_index_out_of_bounds_error() << vector_index(i) << vector_size(sizeof(dim_)));
                    }
                };
            }

        template <class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename boost::enable_if_c<
            is_vec<A>::value &&
            !qvm_detail::v_index_read_defined<vec_traits<A>::dim>::value,
            typename vec_traits<A>::scalar_type>::type
        v_index_read( A const & a, int i )
            {
            return qvm_detail::vector_r<0,vec_traits<A>::dim>::ir(a,i);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int D>
            struct
            v_index_write_defined
                {
                static bool const value=false;
                };

            template <int I,int N>
            struct
            vector_w
                {
                template <class A>
                static
                BOOST_QVM_INLINE_CRITICAL
                typename vec_traits<A>::scalar_type &
                iw( A & a, int i )
                    {
                    return I==i?
                        vec_traits<A>::template w<I>(a) :
                        vector_w<I+1,N>::iw(a,i);
                    }
                };

            template <int N>
            struct
            vector_w<N,N>
                {
                template <class A>
                static
                BOOST_QVM_INLINE_TRIVIAL
                typename vec_traits<A>::scalar_type &
                iw( A const &, int i )
                    {
                    typedef char dim_[vec_traits<A>::dim];
                    BOOST_THROW_EXCEPTION(vector_index_out_of_bounds_error() << vector_index(i) << vector_size(sizeof(dim_)));
                    }
                };
            }

        template <class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename boost::enable_if_c<
            is_vec<A>::value &&
            !qvm_detail::v_index_write_defined<vec_traits<A>::dim>::value,
            typename vec_traits<A>::scalar_type &>::type
        v_index_write( A & a, int i )
            {
            return qvm_detail::vector_w<0,vec_traits<A>::dim>::iw(a,i);
            }

        ////////////////////////////////////////////////

        namespace
        sfinae
            {
            using ::boost::qvm::v_index_read;
            using ::boost::qvm::v_index_write;
            }

        ////////////////////////////////////////////////
        }
    }

#endif
