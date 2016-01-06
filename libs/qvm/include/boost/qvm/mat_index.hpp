//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_90273D9C0E5911E281B7981F6288709B
#define UUID_90273D9C0E5911E281B7981F6288709B

#include <boost/qvm/mat_traits.hpp>
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
            template <int R,int C>
            struct
            mat_index_read_defined
                {
                static bool const value=false;
                };

            template <int I,int N>
            struct
            matrix_r
                {
                template <class A>
                static
                BOOST_QVM_INLINE_CRITICAL
                typename mat_traits<A>::scalar_type
                ir( A const & a, int r, int c )
                    {
                    return (I/mat_traits<A>::cols)==r && (I%mat_traits<A>::cols)==c?
                        mat_traits<A>::template r<I/mat_traits<A>::cols,I%mat_traits<A>::cols>(a) :
                        matrix_r<I+1,N>::ir(a,r,c);
                    }
                };

            template <int N>
            struct
            matrix_r<N,N>
                {
                template <class A>
                static
                BOOST_QVM_INLINE_TRIVIAL
                typename mat_traits<A>::scalar_type
                ir( A const &, int r, int c )
                    {
                    typedef char rows_[mat_traits<A>::rows];
                    typedef char cols_[mat_traits<A>::cols];
                    BOOST_THROW_EXCEPTION(matrix_index_out_of_bounds_error() << matrix_row(r) << matrix_col(c) << matrix_num_rows(sizeof(rows_)) << matrix_num_cols(sizeof(cols_)));
                    }
                };
            }

        template <class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename boost::enable_if_c<
            is_mat<A>::value &&
            !qvm_detail::mat_index_read_defined<mat_traits<A>::rows,mat_traits<A>::cols>::value,
            typename mat_traits<A>::scalar_type>::type
        mat_index_read( A const & a, int r, int c )
            {
            return qvm_detail::matrix_r<0,mat_traits<A>::rows*mat_traits<A>::cols>::ir(a,r,c);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int R,int C>
            struct
            mat_index_write_defined
                {
                static bool const value=false;
                };

            template <int I,int N>
            struct
            matrix_w
                {
                template <class A>
                static
                BOOST_QVM_INLINE_CRITICAL
               typename mat_traits<A>::scalar_type &
                iw( A & a, int r, int c )
                    {
                    return (I/mat_traits<A>::cols)==r && (I%mat_traits<A>::cols)==c?
                        mat_traits<A>::template w<I/mat_traits<A>::cols,I%mat_traits<A>::cols>(a) :
                        matrix_w<I+1,N>::iw(a,r,c);
                    }
                };

            template <int N>
            struct
            matrix_w<N,N>
                {
                template <class A>
                static
                BOOST_QVM_INLINE_TRIVIAL
                typename mat_traits<A>::scalar_type &
                iw( A const &, int r, int c )
                    {
                    typedef char rows_[mat_traits<A>::rows];
                    typedef char cols_[mat_traits<A>::cols];
                    BOOST_THROW_EXCEPTION(matrix_index_out_of_bounds_error() << matrix_row(r) << matrix_col(c) << matrix_num_rows(sizeof(rows_)) << matrix_num_cols(sizeof(cols_)));
                    }
                };
            }

        template <class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename boost::enable_if_c<
            is_mat<A>::value &&
            !qvm_detail::mat_index_write_defined<mat_traits<A>::rows,mat_traits<A>::cols>::value,
            typename mat_traits<A>::scalar_type &>::type
        mat_index_write( A & a, int r, int c )
            {
            return qvm_detail::matrix_w<0,mat_traits<A>::rows*mat_traits<A>::cols>::iw(a,r,c);
            }

        ////////////////////////////////////////////////

        namespace
        sfinae
            {
            using ::boost::qvm::mat_index_read;
            using ::boost::qvm::mat_index_write;
            }

        ////////////////////////////////////////////////
        }
    }

#endif
