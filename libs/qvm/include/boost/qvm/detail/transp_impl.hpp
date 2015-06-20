//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_B3B8081A277711E09E007F2DDFD72085
#define UUID_B3B8081A277711E09E007F2DDFD72085

#include <boost/qvm/deduce_m.hpp>
#include <boost/qvm/static_assert.hpp>
#include <boost/qvm/assert.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        namespace
        qvm_detail
            {
            template <class OriginalMatrix>
            class
            transp_
                {
                transp_( transp_ const & );
                transp_ & operator=( transp_ const & );
                ~transp_();

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                transp_ &
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

        template <class OriginalMatrix>
        struct
        m_traits< qvm_detail::transp_<OriginalMatrix> >
            {
            typedef typename m_traits<OriginalMatrix>::scalar_type scalar_type;
            typedef qvm_detail::transp_<OriginalMatrix> this_matrix;
            static int const rows=m_traits<OriginalMatrix>::cols;
            static int const cols=m_traits<OriginalMatrix>::rows;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<rows);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<cols);
                return m_traits<OriginalMatrix>::template r<Col,Row>(reinterpret_cast<OriginalMatrix const &>(x));
                }

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            w( this_matrix & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<rows);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<cols);
                return m_traits<OriginalMatrix>::template w<Col,Row>(reinterpret_cast<OriginalMatrix &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<cols);
                return m_traits<OriginalMatrix>::ir(col,row,reinterpret_cast<OriginalMatrix const &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            iw( int row, int col, this_matrix & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<cols);
                return m_traits<OriginalMatrix>::iw(col,row,reinterpret_cast<OriginalMatrix &>(x));
                }
            };

        template <class OriginalMatrix,int R,int C>
        struct
        deduce_m<qvm_detail::transp_<OriginalMatrix>,R,C>
            {
            typedef mat<typename m_traits<OriginalMatrix>::scalar_type,R,C> type;
            };

        template <class OriginalMatrix,int R,int C>
        struct
        deduce_m2<qvm_detail::transp_<OriginalMatrix>,qvm_detail::transp_<OriginalMatrix>,R,C>
            {
            typedef mat<typename m_traits<OriginalMatrix>::scalar_type,R,C> type;
            };
        }
    }

#endif
