//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_3EDF999CA1C011DEBA5C8DA956D89593
#define UUID_3EDF999CA1C011DEBA5C8DA956D89593

#include <boost/qvm/inline.hpp>
#include <boost/qvm/deduce_m.hpp>
#include <boost/qvm/v_traits.hpp>
#include <boost/qvm/assert.hpp>
#include <boost/qvm/enable_if.hpp>

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
            template <class OriginalVector>
            class
            col_m_
                {
                col_m_( col_m_ const & );
                col_m_ & operator=( col_m_ const & );
                ~col_m_();

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                col_m_ &
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

        template <class OriginalVector>
        struct
        m_traits< qvm_detail::col_m_<OriginalVector> >
            {
            typedef qvm_detail::col_m_<OriginalVector> this_matrix;
            typedef typename v_traits<OriginalVector>::scalar_type scalar_type;
            static int const rows=v_traits<OriginalVector>::dim;
            static int const cols=1;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Col==0);
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<rows);
                return v_traits<OriginalVector>::template r<Row>(reinterpret_cast<OriginalVector const &>(x));
                }

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            w( this_matrix & x )
                {
                BOOST_QVM_STATIC_ASSERT(Col==0);
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<rows);
                return v_traits<OriginalVector>::template w<Row>(reinterpret_cast<OriginalVector &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(col==0);
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                return v_traits<OriginalVector>::ir(row,reinterpret_cast<OriginalVector const &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            iw( int row, int col, this_matrix & x )
                {
                BOOST_QVM_ASSERT(col==0);
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                return v_traits<OriginalVector>::iw(row,reinterpret_cast<OriginalVector &>(x));
                }
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m<qvm_detail::col_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m2<qvm_detail::col_m_<OriginalVector>,qvm_detail::col_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::col_m_<A> const &>::type
        BOOST_QVM_INLINE_TRIVIAL
        col_m( A const & a )
            {
            return reinterpret_cast<typename qvm_detail::col_m_<A> const &>(a);
            }

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::col_m_<A> &>::type
        BOOST_QVM_INLINE_TRIVIAL
        col_m( A & a )
            {
            return reinterpret_cast<typename qvm_detail::col_m_<A> &>(a);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class OriginalVector>
            class
            row_m_
                {
                row_m_( row_m_ const & );
                row_m_ & operator=( row_m_ const & );
                ~row_m_();

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                row_m_ &
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

        template <class OriginalVector>
        struct
        m_traits< qvm_detail::row_m_<OriginalVector> >
            {
            typedef qvm_detail::row_m_<OriginalVector> this_matrix;
            typedef typename v_traits<OriginalVector>::scalar_type scalar_type;
            static int const rows=1;
            static int const cols=v_traits<OriginalVector>::dim;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row==0);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<cols);
                return v_traits<OriginalVector>::template r<Col>(reinterpret_cast<OriginalVector const &>(x));
                }

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            w( this_matrix & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row==0);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<cols);
                return v_traits<OriginalVector>::template w<Col>(reinterpret_cast<OriginalVector &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row==0);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<cols);
                return v_traits<OriginalVector>::ir(col,reinterpret_cast<OriginalVector const &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            iw( int row, int col, this_matrix & x )
                {
                BOOST_QVM_ASSERT(row==0);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<cols);
                return v_traits<OriginalVector>::iw(col,reinterpret_cast<OriginalVector &>(x));
                }
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m<qvm_detail::row_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m2<qvm_detail::row_m_<OriginalVector>,qvm_detail::row_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::row_m_<A> const &>::type
        BOOST_QVM_INLINE_TRIVIAL
        row_m( A const & a )
            {
            return reinterpret_cast<typename qvm_detail::row_m_<A> const &>(a);
            }

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::row_m_<A> &>::type
        BOOST_QVM_INLINE_TRIVIAL
        row_m( A & a )
            {
            return reinterpret_cast<typename qvm_detail::row_m_<A> &>(a);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class OriginalVector>
            class
            trans_m_
                {
                trans_m_( trans_m_ const & );
                trans_m_ & operator=( trans_m_ const & );
                ~trans_m_();

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                trans_m_ &
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

            template <class M,int Row,int Col,bool TransCol=(Col==m_traits<M>::cols-1)>
            struct read_trans_mat;

            template <class OriginalVector,int Row,int Col,bool TransCol>
            struct
            read_trans_mat<trans_m_<OriginalVector>,Row,Col,TransCol>
                {
                static
                BOOST_QVM_INLINE_CRITICAL
                typename m_traits< trans_m_<OriginalVector> >::scalar_type
                f( trans_m_<OriginalVector> const & )
                    {
                    return s_traits<typename m_traits< trans_m_<OriginalVector> >::scalar_type>::value(0);
                    }
                };

            template <class OriginalVector,int D>
            struct
            read_trans_mat<trans_m_<OriginalVector>,D,D,false>
                {
                static
                BOOST_QVM_INLINE_CRITICAL
                typename m_traits< trans_m_<OriginalVector> >::scalar_type
                f( trans_m_<OriginalVector> const & )
                    {
                    return s_traits<typename m_traits< trans_m_<OriginalVector> >::scalar_type>::value(1);
                    }
                };

            template <class OriginalVector,int D>
            struct
            read_trans_mat<trans_m_<OriginalVector>,D,D,true>
                {
                static
                BOOST_QVM_INLINE_CRITICAL
                typename m_traits< trans_m_<OriginalVector> >::scalar_type
                f( trans_m_<OriginalVector> const & )
                    {
                    return s_traits<typename m_traits< trans_m_<OriginalVector> >::scalar_type>::value(1);
                    }
                };

            template <class OriginalVector,int Row,int Col>
            struct
            read_trans_mat<trans_m_<OriginalVector>,Row,Col,true>
                {
                static
                BOOST_QVM_INLINE_CRITICAL
                typename m_traits< trans_m_<OriginalVector> >::scalar_type
                f( trans_m_<OriginalVector> const & x )
                    {
                    return v_traits<OriginalVector>::template r<Row>(reinterpret_cast<OriginalVector const &>(x));
                    }
                };
            }

        template <class OriginalVector>
        struct
        m_traits< qvm_detail::trans_m_<OriginalVector> >
            {
            typedef qvm_detail::trans_m_<OriginalVector> this_matrix;
            typedef typename v_traits<OriginalVector>::scalar_type scalar_type;
            static int const rows=v_traits<OriginalVector>::dim+1;
            static int const cols=v_traits<OriginalVector>::dim+1;

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
                return qvm_detail::read_trans_mat<qvm_detail::trans_m_<OriginalVector>,Row,Col>::f(x);
                }

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            w( this_matrix & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<rows);
                BOOST_QVM_STATIC_ASSERT(Col==cols-1);
                BOOST_QVM_STATIC_ASSERT(Col!=Row);
                return v_traits<OriginalVector>::template w<Row>(reinterpret_cast<OriginalVector &>(x));
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
                return
                    row==col?
                        s_traits<scalar_type>::value(1):
                        (col==cols-1?
                            v_traits<OriginalVector>::ir(row,reinterpret_cast<OriginalVector const &>(x)):
                            s_traits<scalar_type>::value(0));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            iw( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                BOOST_QVM_ASSERT(col==cols-1);
                BOOST_QVM_ASSERT(col!=row);
                return v_traits<OriginalVector>::iw(row,reinterpret_cast<OriginalVector &>(x));
                }
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m<qvm_detail::trans_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m2<qvm_detail::trans_m_<OriginalVector>,qvm_detail::trans_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::trans_m_<A> const &>::type
        BOOST_QVM_INLINE_TRIVIAL
        trans_m( A const & a )
            {
            return reinterpret_cast<typename qvm_detail::trans_m_<A> const &>(a);
            }

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::trans_m_<A> &>::type
        BOOST_QVM_INLINE_TRIVIAL
        trans_m( A & a )
            {
            return reinterpret_cast<typename qvm_detail::trans_m_<A> &>(a);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class OriginalVector>
            class
            diag_m_
                {
                diag_m_( diag_m_ const & );
                diag_m_ & operator=( diag_m_ const & );
                ~diag_m_();

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                diag_m_ &
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

        template <class OriginalVector>
        struct
        m_traits< qvm_detail::diag_m_<OriginalVector> >
            {
            typedef qvm_detail::diag_m_<OriginalVector> this_matrix;
            typedef typename v_traits<OriginalVector>::scalar_type scalar_type;
            static int const rows=v_traits<OriginalVector>::dim;
            static int const cols=v_traits<OriginalVector>::dim;

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
                return Row==Col?v_traits<OriginalVector>::template r<Row>(reinterpret_cast<OriginalVector const &>(x)):s_traits<scalar_type>::value(0);
                }

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            w( this_matrix & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<rows);
                BOOST_QVM_STATIC_ASSERT(Row==Col);
                return v_traits<OriginalVector>::template w<Row>(reinterpret_cast<OriginalVector &>(x));
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
                return row==col?v_traits<OriginalVector>::ir(row,reinterpret_cast<OriginalVector const &>(x)):s_traits<scalar_type>::value(0);
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type &
            iw( int row, int col, this_matrix & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                BOOST_QVM_ASSERT(row==col);
                return v_traits<OriginalVector>::iw(row,reinterpret_cast<OriginalVector &>(x));
                }
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m<qvm_detail::diag_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class OriginalVector,int R,int C>
        struct
        deduce_m2<qvm_detail::diag_m_<OriginalVector>,qvm_detail::diag_m_<OriginalVector>,R,C>
            {
            typedef mat<typename v_traits<OriginalVector>::scalar_type,R,C> type;
            };

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::diag_m_<A> const &>::type
        BOOST_QVM_INLINE_TRIVIAL
        diag_m( A const & a )
            {
            return reinterpret_cast<typename qvm_detail::diag_m_<A> const &>(a);
            }

        template <class A>
        typename boost::enable_if_c<
            is_v<A>::value,
            qvm_detail::diag_m_<A> &>::type
        BOOST_QVM_INLINE_TRIVIAL
        diag_m( A & a )
            {
            return reinterpret_cast<typename qvm_detail::diag_m_<A> &>(a);
            }

        ////////////////////////////////////////////////
        }
    }

#endif
