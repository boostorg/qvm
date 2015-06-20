//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_4F915D9ED30A11DF962186E3DFD72085
#define UUID_4F915D9ED30A11DF962186E3DFD72085

#include <boost/qvm/m2.hpp>
#include <boost/qvm/m3.hpp>
#include <boost/qvm/m4.hpp>
#include <boost/qvm/math.hpp>
#include <boost/qvm/detail/determinant_impl.hpp>
#include <boost/qvm/detail/cofactor_impl.hpp>
#include <boost/qvm/detail/transp_impl.hpp>
#include <boost/qvm/s_traits.hpp>
#include <string>

namespace
boost
    {
    namespace
    qvm
        {
        ////////////////////////////////////////////////

        namespace
        qvm_to_string_detail
            {
            template <class T>
            std::string to_string( T const & x );
            }

        namespace
        qvm_detail
            {
            template <int R,int C>
            struct
            to_string_m_defined
                {
                static bool const value=false;
                };

            template <int I,int SizeMinusOne>
            struct
            to_string_matrix_elements
                {
                template <class A>
                static
                std::string
                f( A const & a )
                    {
                    using namespace qvm_to_string_detail;
                    return
                        ( (I%m_traits<A>::cols)==0 ? '(' : ',' ) +
                        to_string(m_traits<A>::template r<I/m_traits<A>::cols,I%m_traits<A>::cols>(a)) +
                        ( (I%m_traits<A>::cols)==m_traits<A>::cols-1 ? ")" : "" ) +
                        to_string_matrix_elements<I+1,SizeMinusOne>::f(a);
                    }
                };

            template <int SizeMinusOne>
            struct
            to_string_matrix_elements<SizeMinusOne,SizeMinusOne>
                {
                template <class A>
                static
                std::string
                f( A const & a )
                    {
                    using namespace qvm_to_string_detail;
                    return
                        ( (SizeMinusOne%m_traits<A>::cols)==0 ? '(' : ',' ) +
                        to_string(m_traits<A>::template r<SizeMinusOne/m_traits<A>::cols,SizeMinusOne%m_traits<A>::cols>(a)) +
                        ')';
                    }
                };
            }

        template <class A>
        inline
        typename boost::enable_if_c<
            is_m<A>::value  &&
            !qvm_detail::to_string_m_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            std::string>::type
        to_string( A const & a )
            {
            return "("+qvm_detail::to_string_matrix_elements<0,m_traits<A>::rows*m_traits<A>::cols-1>::f(a)+')';
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            assign_mm_defined
                {
                static bool const value=false;
                };

            template <int I,int N>
            struct
            copy_matrix_elements
                {
                template <class A,class B>
                static
                BOOST_QVM_INLINE_CRITICAL
                void
                f( A & a, B const & b )
                    {
                    m_traits<A>::template w<I/m_traits<A>::cols,I%m_traits<A>::cols>(a) =
                        m_traits<B>::template r<I/m_traits<B>::cols,I%m_traits<B>::cols>(b);
                    copy_matrix_elements<I+1,N>::f(a,b);
                    }
                };

            template <int N>
            struct
            copy_matrix_elements<N,N>
                {
                template <class A,class B>
                static
                BOOST_QVM_INLINE_CRITICAL
                void
                f( A & a, B const & b )
                    {
                    }
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_TRIVIAL
        typename boost::enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::assign_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            A &>::type
        assign( A & a, B const & b )
            {
            qvm_detail::copy_matrix_elements<0,m_traits<A>::rows*m_traits<A>::cols>::f(a,b);
            return a;
            }

        ////////////////////////////////////////////////

        template <class A,class B,class Cmp>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols,
            bool>::type
        cmp( A const & a, B const & b, Cmp f )
            {
            typedef typename deduce_s<
                typename m_traits<A>::scalar_type,
                typename m_traits<B>::scalar_type>::type T;
            int const rows=m_traits<A>::rows;
            int const cols=m_traits<A>::cols;
            T m1[rows][cols]; assign(m1,a);
            T m2[rows][cols]; assign(m2,b);
            for( int i=0; i!=rows; ++i )
                for( int j=0; j!=cols; ++j )
                    if( !f(m1[i][j],m2[i][j]) )
                        return false;
            return true;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            make_m_defined
                {
                static bool const value=false;
                };
            }

        template <class R,class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_m<R>::value && is_m<A>::value &&
            m_traits<R>::rows==m_traits<A>::rows &&
            m_traits<R>::cols==m_traits<A>::cols &&
            !qvm_detail::make_m_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            R>::type
        make( A const & a )
            {
            R r; assign(r,a);
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int D>
            struct
            determinant_defined
                {
                static bool const value=false;
                };
            }

        template <class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows==m_traits<A>::cols &&
            !qvm_detail::determinant_defined<m_traits<A>::rows>::value,
            typename m_traits<A>::scalar_type>::type
        determinant( A const & a )
            {
            return qvm_detail::determinant_impl(a);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class T,int Dim>
            class
            identity_m_
                {
                identity_m_( identity_m_ const & );
                identity_m_ & operator=( identity_m_ const & );
                ~identity_m_();

                public:

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

        template <class T,int Dim>
        struct
        m_traits< qvm_detail::identity_m_<T,Dim> >
            {
            typedef qvm_detail::identity_m_<T,Dim> this_matrix;
            typedef T scalar_type;
            static int const rows=Dim;
            static int const cols=Dim;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_ASSERT(&x==0);
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<Dim);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<Dim);
                return s_traits<scalar_type>::value(Row==Col);
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(&x==0);
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<Dim);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<Dim);
                return s_traits<scalar_type>::value(row==col);
                }
            };

        template <class T,int Dim>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::identity_m_<T,Dim> const &
        identity_m()
            {
            return *(qvm_detail::identity_m_<T,Dim> const *)0;
            }

        template <class A>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        set_identity( A & a )
            {
            assign(a,identity_m<typename m_traits<A>::scalar_type,m_traits<A>::rows>());
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class T>
            struct
            projection_
                {
                T const _00;
                T const _11;
                T const _22;
                T const _23;
                T const _32;

                BOOST_QVM_INLINE_TRIVIAL
                projection_( T _00, T _11, T _22, T _23, T _32 ):
                    _00(_00),
                    _11(_11),
                    _22(_22),
                    _23(_23),
                    _32(_32)
                    {
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

            template <int Row,int Col>
            struct
            projection_get
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( projection_<T> const & )
                    {
                    return s_traits<T>::value(0);
                    };
                };

            template <> struct projection_get<0,0> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( projection_<T> const & m ) { return m._00; }; };
            template <> struct projection_get<1,1> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( projection_<T> const & m ) { return m._11; }; };
            template <> struct projection_get<2,2> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( projection_<T> const & m ) { return m._22; }; };
            template <> struct projection_get<2,3> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( projection_<T> const & m ) { return m._23; }; };
            template <> struct projection_get<3,2> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( projection_<T> const & m ) { return m._32; }; };
            }

        template <class T>
        struct
        m_traits< qvm_detail::projection_<T> >
            {
            typedef qvm_detail::projection_<T> this_matrix;
            typedef T scalar_type;
            static int const rows=4;
            static int const cols=4;

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
                return qvm_detail::projection_get<Row,Col>::get(x);
                }
            };

        template <class T>
        qvm_detail::projection_<T>
        BOOST_QVM_INLINE_OPERATIONS
        perspective_lh( T fov_y, T aspect_ratio, T z_near, T z_far )
            {
            T const one = s_traits<T>::value(1);
            T const ys = one/tan<T>(fov_y/s_traits<T>::value(2));
            T const xs = ys/aspect_ratio;
            T const zd = z_far-z_near;
            T const z1 = z_far/zd;
            T const z2 = -z_near*z1;
            return qvm_detail::projection_<T>(xs,ys,z1,z2,one);
            }

        template <class T>
        qvm_detail::projection_<T>
        BOOST_QVM_INLINE_OPERATIONS
        perspective_rh( T fov_y, T aspect_ratio, T z_near, T z_far )
            {
            T const one = s_traits<T>::value(1);
            T const ys = one/tan<T>(fov_y/s_traits<T>::value(2));
            T const xs = ys/aspect_ratio;
            T const zd = z_near-z_far;
            T const z1 = z_far/zd;
            T const z2 = z_near*z1;
            return qvm_detail::projection_<T>(xs,ys,z1,z2,-one);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class OriginalType,class Scalar>
            class
            matrix_scalar_cast_
                {
                matrix_scalar_cast_( matrix_scalar_cast_ const & );
                matrix_scalar_cast_ & operator=( matrix_scalar_cast_ const & );
                ~matrix_scalar_cast_();

                public:

                template <class T>
                BOOST_QVM_INLINE_TRIVIAL
                matrix_scalar_cast_ &
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

            template <bool> struct scalar_cast_matrix_filter { };
            template <> struct scalar_cast_matrix_filter<true> { typedef int type; };
            }

        template <class OriginalType,class Scalar>
        struct
        m_traits< qvm_detail::matrix_scalar_cast_<OriginalType,Scalar> >
            {
            typedef Scalar scalar_type;
            typedef qvm_detail::matrix_scalar_cast_<OriginalType,Scalar> this_matrix;
            static int const rows=m_traits<OriginalType>::rows;
            static int const cols=m_traits<OriginalType>::cols;

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
                return scalar_type(m_traits<OriginalType>::template r<Row,Col>(reinterpret_cast<OriginalType const &>(x)));
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
                return scalar_type(m_traits<OriginalType>::ir(col,row,reinterpret_cast<OriginalType const &>(x)));
                }
            };

        template <class OriginalType,class Scalar,int R,int C>
        struct
        deduce_m<qvm_detail::matrix_scalar_cast_<OriginalType,Scalar>,R,C>
            {
            typedef mat<Scalar,R,C> type;
            };

        template <class Scalar,class T>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::matrix_scalar_cast_<T,Scalar> const &
        scalar_cast( T const & x, typename qvm_detail::scalar_cast_matrix_filter<is_m<T>::value>::type=0 )
            {
            return reinterpret_cast<qvm_detail::matrix_scalar_cast_<T,Scalar> const &>(x);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            div_eq_ms_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_s<B>::value &&
            !qvm_detail::div_eq_ms_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            A &>::type
        operator/=( A & a, B b )
            {
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<A>::iw(i,j,a)/=b;
            return a;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            div_ms_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value && is_s<B>::value &&
            !qvm_detail::div_ms_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            deduce_m<A> >::type
        operator/( A const & a, B b )
            {
            typedef typename deduce_m<A>::type R;
            R r;
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<R>::iw(i,j,r)=m_traits<A>::ir(i,j,a)/b;
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            eq_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::eq_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            bool>::type
        operator==( A const & a, B const & b )
            {
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    if( m_traits<A>::ir(i,j,a)!=m_traits<B>::ir(i,j,b) )
                        return false;
            return true;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int D>
            struct
            inverse_m_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_TRIVIAL
        typename lazy_enable_if_c<
            is_m<A>::value && is_s<B>::value &&
            m_traits<A>::rows==m_traits<A>::cols &&
            !qvm_detail::inverse_m_defined<m_traits<A>::rows>::value,
            deduce_m<A> >::type
        inverse( A const & a, B det )
            {
            typedef typename m_traits<A>::scalar_type T;
            BOOST_QVM_ASSERT(det!=s_traits<T>::value(0));
            T f=s_traits<T>::value(1)/det;
            typedef typename deduce_m<A>::type cofactor_return_type;
            cofactor_return_type c=qvm_detail::cofactor_impl(a);
            return reinterpret_cast<qvm_detail::transp_<cofactor_return_type> const &>(c) * f;
            }

        template <class A>
        BOOST_QVM_INLINE_TRIVIAL
        typename lazy_enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows==m_traits<A>::cols &&
            !qvm_detail::inverse_m_defined<m_traits<A>::rows>::value,
            deduce_m<A> >::type
        inverse( A const & a )
            {
            typedef typename m_traits<A>::scalar_type T;
            T det=determinant(a);
            if( det==s_traits<T>::value(0) )
                BOOST_THROW_EXCEPTION(zero_determinant_error());
            return inverse(a,det);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            minus_eq_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::minus_eq_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            A &>::type
        operator-=( A & a, B const & b )
            {
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<A>::iw(i,j,a)-=m_traits<B>::ir(i,j,b);
            return a;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            minus_m_defined
                {
                static bool const value=false;
                };
            }

        template <class A>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value &&
            !qvm_detail::minus_m_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            deduce_m<A> >::type
        operator-( A const & a )
            {
            typedef typename deduce_m<A>::type R;
            R r;
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<R>::iw(i,j,r)=-m_traits<A>::ir(i,j,a);
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            minus_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::minus_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            deduce_m2<A,B,m_traits<A>::rows,m_traits<A>::cols> >::type
        operator-( A const & a, B const & b )
            {
            typedef typename deduce_m2<A,B,m_traits<A>::rows,m_traits<A>::cols>::type R;
            R r;
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<R>::iw(i,j,r)=m_traits<A>::ir(i,j,a)-m_traits<B>::ir(i,j,b);
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int D>
            struct
            mul_eq_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            is_m<B>::value &&
            m_traits<A>::rows==m_traits<A>::cols &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::mul_eq_mm_defined<m_traits<A>::rows>::value,
            A &>::type
        operator*=( A & r, B const & b )
            {
            typedef typename m_traits<A>::scalar_type Ta;
            Ta a[m_traits<A>::rows][m_traits<A>::cols];
            for( int i=0; i<m_traits<A>::rows; ++i )
                for( int j=0; j<m_traits<B>::cols; ++j )
                    a[i][j]=m_traits<A>::ir(i,j,r);
            for( int i=0; i<m_traits<A>::rows; ++i )
                for( int j=0; j<m_traits<B>::cols; ++j )
                    {
                    Ta x(s_traits<Ta>::value(0));
                    for( int k=0; k<m_traits<A>::cols; ++k )
                        x += a[i][k]*m_traits<B>::ir(k,j,b);
                    m_traits<A>::iw(i,j,r) = x;
                    }
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            mul_eq_ms_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_s<B>::value &&
            !qvm_detail::mul_eq_ms_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            A &>::type
        operator*=( A & a, B b )
            {
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<A>::iw(i,j,a)*=b;
            return a;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int R,int CR,int C>
            struct
            mul_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::cols==m_traits<B>::rows &&
            !qvm_detail::mul_mm_defined<m_traits<A>::rows,m_traits<A>::cols,m_traits<B>::cols>::value,
            deduce_m2<A,B,m_traits<A>::rows,m_traits<B>::cols> >::type
        operator*( A const & a, B const & b )
            {
            typedef typename deduce_m2<A,B,m_traits<A>::rows,m_traits<B>::cols>::type R;
            R r;
            for( int i=0; i<m_traits<A>::rows; ++i )
                for( int j=0; j<m_traits<B>::cols; ++j )
                    {
                    typedef typename m_traits<A>::scalar_type Ta;
                    Ta x(s_traits<Ta>::value(0));
                    for( int k=0; k<m_traits<A>::cols; ++k )
                        x += m_traits<A>::ir(i,k,a)*m_traits<B>::ir(k,j,b);
                    m_traits<R>::iw(i,j,r) = x;
                    }
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            mul_ms_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value && is_s<B>::value &&
            !qvm_detail::mul_ms_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            deduce_m<A> >::type
        operator*( A const & a, B b )
            {
            typedef typename deduce_m<A>::type R;
            R r;
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<R>::iw(i,j,r)=m_traits<A>::ir(i,j,a)*b;
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            neq_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::neq_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            bool>::type
        operator!=( A const & a, B const & b )
            {
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    if( m_traits<A>::ir(i,j,a)!=m_traits<B>::ir(i,j,b) )
                        return true;
            return false;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            plus_eq_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::plus_eq_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            A &>::type
        operator+=( A & a, B const & b )
            {
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<A>::iw(i,j,a)+=m_traits<B>::ir(i,j,b);
            return a;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int M,int N>
            struct
            plus_mm_defined
                {
                static bool const value=false;
                };
            }

        template <class A,class B>
        BOOST_QVM_INLINE_OPERATIONS
        typename lazy_enable_if_c<
            is_m<A>::value && is_m<B>::value &&
            m_traits<A>::rows==m_traits<B>::rows &&
            m_traits<A>::cols==m_traits<B>::cols &&
            !qvm_detail::plus_mm_defined<m_traits<A>::rows,m_traits<A>::cols>::value,
            deduce_m2<A,B,m_traits<A>::rows,m_traits<A>::cols> >::type
        operator+( A const & a, B const & b )
            {
            typedef typename deduce_m2<A,B,m_traits<A>::rows,m_traits<A>::cols>::type R;
            R r;
            for( int i=0; i!=m_traits<A>::rows; ++i )
                for( int j=0; j!=m_traits<A>::cols; ++j )
                    m_traits<R>::iw(i,j,r)=m_traits<A>::ir(i,j,a)+m_traits<B>::ir(i,j,b);
            return r;
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class T>
            class
            mref_
                {
                mref_( mref_ const & );
                mref_ & operator=( mref_ const & );
                ~mref_();

                public:

                template <class R>
                BOOST_QVM_INLINE_TRIVIAL
                mref_ &
                operator=( R const & x )
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

        template <class M>
        struct
        m_traits< qvm_detail::mref_<M> >
            {
            typedef typename m_traits<M>::scalar_type scalar_type;
            typedef qvm_detail::mref_<M> this_matrix;
            static int const rows=m_traits<M>::rows;
            static int const cols=m_traits<M>::cols;

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
                return m_traits<M>::template r<Row,Col>(reinterpret_cast<M const &>(x));
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
                return m_traits<M>::template w<Row,Col>(reinterpret_cast<M &>(x));
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
                return m_traits<M>::ir(row,col,reinterpret_cast<M const &>(x));
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
                return m_traits<M>::iw(row,col,reinterpret_cast<M &>(x));
                }
            };

        template <class M,int R,int C>
        struct
        deduce_m<qvm_detail::mref_<M>,R,C>
            {
            typedef mat<typename m_traits<M>::scalar_type,R,C> type;
            };

        template <class M>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_m<M>::value,
            qvm_detail::mref_<M> const &>::type
        mref( M const & a )
            {
            return reinterpret_cast<qvm_detail::mref_<M> const &>(a);
            }

        template <class M>
        BOOST_QVM_INLINE_TRIVIAL
        typename enable_if_c<
            is_m<M>::value,
            qvm_detail::mref_<M> &>::type
        mref( M & a )
            {
            return reinterpret_cast<qvm_detail::mref_<M> &>(a);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <class T,int Rows,int Cols>
            class
            zero_m_
                {
                zero_m_( zero_m_ const & );
                zero_m_ & operator=( zero_m_ const & );
                ~zero_m_();

                public:

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

        template <class T,int Rows,int Cols>
        struct
        m_traits< qvm_detail::zero_m_<T,Rows,Cols> >
            {
            typedef qvm_detail::zero_m_<T,Rows,Cols> this_matrix;
            typedef T scalar_type;
            static int const rows=Rows;
            static int const cols=Cols;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_ASSERT(&x==0);
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<Rows);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<Cols);
                return s_traits<scalar_type>::value(0);
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(&x==0);
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<rows);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<cols);
                return s_traits<scalar_type>::value(0);
                }
            };

        template <class T,int Rows,int Cols,int R,int C>
        struct
        deduce_m<qvm_detail::zero_m_<T,Rows,Cols>,R,C>
            {
            typedef mat<T,R,C> type;
            };

        template <class T,int Rows,int Cols>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::zero_m_<T,Rows,Cols> const &
        zero_m()
            {
            return *(qvm_detail::zero_m_<T,Rows,Cols> const *)0;
            }

        template <class T,int Dim>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::zero_m_<T,Dim,Dim> const &
        zero_m()
            {
            return *(qvm_detail::zero_m_<T,Dim,Dim> const *)0;
            }

        template <class A>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value,
            void>::type
        set_zero( A & a )
            {
            assign(a,zero_m<typename m_traits<A>::scalar_type,m_traits<A>::rows,m_traits<A>::cols>());
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int D,class V>
            struct
            rot_m_
                {
                typedef typename v_traits<V>::scalar_type scalar_type;
                scalar_type a[3][3];

                template <class Angle>
                BOOST_QVM_INLINE
                rot_m_( V const & axis, Angle angle )
                    {
                    scalar_type const x=v_traits<V>::template r<0>(axis);
                    scalar_type const y=v_traits<V>::template r<1>(axis);
                    scalar_type const z=v_traits<V>::template r<2>(axis);
                    scalar_type const m2=x*x+y*y+z*z;
                    if( m2==s_traits<scalar_type>::value(0) )
                        BOOST_THROW_EXCEPTION(zero_magnitude_error());
                    scalar_type const s = sin<Angle>(angle);
                    scalar_type const c = cos<Angle>(angle);
                    scalar_type const x2 = x*x;
                    scalar_type const y2 = y*y;
                    scalar_type const z2 = z*z;
                    scalar_type const xy = x*y;
                    scalar_type const xz = x*z;
                    scalar_type const yz = y*z;
                    scalar_type const xs = x*s;
                    scalar_type const ys = y*s;
                    scalar_type const zs = z*s;
                    scalar_type const one = s_traits<scalar_type>::value(1);
                    scalar_type const c1 = one-c;
                    a[0][0] = x2+(one-x2)*c;
                    a[0][1] = xy*c1-zs;
                    a[0][2] = xz*(one-c)+ys;
                    a[1][0] = xy*c1+zs;
                    a[1][1] = y2+(one-y2)*c;
                    a[1][2] = yz*c1-xs;
                    a[2][0] = xz*c1-ys;
                    a[2][1] = yz*c1+xs;
                    a[2][2] = z2+(one-z2)*c;
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

            template <int Row,int Col>
            struct
            rot_m_get
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const (&)[3][3] )
                    {
                    return s_traits<T>::value(Row==Col);
                    };
                };

            template <> struct rot_m_get<0,0> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[0][0]; }; };
            template <> struct rot_m_get<0,1> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[0][1]; }; };
            template <> struct rot_m_get<0,2> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[0][2]; }; };
            template <> struct rot_m_get<1,0> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[1][0]; }; };
            template <> struct rot_m_get<1,1> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[1][1]; }; };
            template <> struct rot_m_get<1,2> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[1][2]; }; };
            template <> struct rot_m_get<2,0> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[2][0]; }; };
            template <> struct rot_m_get<2,1> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[2][1]; }; };
            template <> struct rot_m_get<2,2> { template <class T> static BOOST_QVM_INLINE_CRITICAL T get( T const (&a)[3][3] ) { return a[2][2]; }; };
            }

        template <class M>
        struct m_traits;

        template <int D,class V>
        struct
        m_traits< qvm_detail::rot_m_<D,V> >
            {
            typedef qvm_detail::rot_m_<D,V> this_matrix;
            typedef typename this_matrix::scalar_type scalar_type;
            static int const rows=D;
            static int const cols=D;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Row<D);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Col<D);
                return qvm_detail::rot_m_get<Row,Col>::get(x.a);
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(row<D);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(col<D);
                return row<3 && col<3?
                    x.a[row][col] :
                    s_traits<scalar_type>::value(row==col);
                }
            };

        template <int Dim,class A,class Angle>
        BOOST_QVM_INLINE
        typename enable_if_c<
            is_v<A>::value && v_traits<A>::dim==3,
            qvm_detail::rot_m_<Dim,A> >::type
        rot_m( A const & axis, Angle angle )
            {
            return qvm_detail::rot_m_<Dim,A>(axis,angle);
            }

        template <class A,class B,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows==m_traits<A>::cols &&
            m_traits<A>::rows>=3 &&
            is_v<B>::value && v_traits<B>::dim==3,
            void>::type
        set_rot( A & a, B const & axis, Angle angle )
            {
            assign(a,rot_m<m_traits<A>::rows>(axis,angle));
            }

        template <class A,class B,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows==m_traits<A>::cols &&
            m_traits<A>::rows>=3 &&
            is_v<B>::value && v_traits<B>::dim==3,
            void>::type
        rotate( A & a, B const & axis, Angle angle )
            {
            a *= rot_m<m_traits<A>::rows>(axis,angle);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int Dim,class Angle>
            struct
            rotx_m_
                {
                BOOST_QVM_INLINE_TRIVIAL
                rotx_m_()
                    {
                    }

                template <class R>
                BOOST_QVM_INLINE_TRIVIAL
                operator R() const
                    {
                    R r;
                    assign(r,*this);
                    return r;
                    }

                private:

                rotx_m_( rotx_m_ const & );
                rotx_m_ & operator=( rotx_m_ const & );
                ~rotx_m_();
                };

            template <int Row,int Col>
            struct
            rotx_m_get
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & )
                    {
                    return s_traits<T>::value(Row==Col);
                    };
                };

            template <>
            struct
            rotx_m_get<1,1>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return cos<T>(angle);
                    };
                };

            template <>
            struct
            rotx_m_get<1,2>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return -sin<T>(angle);
                    };
                };

            template <>
            struct
            rotx_m_get<2,1>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return sin<T>(angle);
                    };
                };

            template <>
            struct
            rotx_m_get<2,2>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return cos<T>(angle);
                    };
                };
            }

        template <int Dim,class Angle>
        struct
        m_traits< qvm_detail::rotx_m_<Dim,Angle> >
            {
            typedef qvm_detail::rotx_m_<Dim,Angle> this_matrix;
            typedef Angle scalar_type;
            static int const rows=Dim;
            static int const cols=Dim;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Row<Dim);
                BOOST_QVM_STATIC_ASSERT(Col<Dim);
                return qvm_detail::rotx_m_get<Row,Col>::get(reinterpret_cast<Angle const &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(row<Dim);
                BOOST_QVM_ASSERT(col<Dim);
                Angle const & a=reinterpret_cast<Angle const &>(x);
                if( row==1 )
                    {
                    if( col==1 )
                        return cos<scalar_type>(a);
                    if( col==2 )
                        return -sin<scalar_type>(a);
                    }
                if( row==2 )
                    {
                    if( col==1 )
                        return sin<scalar_type>(a);
                    if( col==2 )
                        return cos<scalar_type>(a);
                    }
                return s_traits<scalar_type>::value(row==col);
                }
            };

        template <int Dim,class Angle>
        struct
        deduce_m<qvm_detail::rotx_m_<Dim,Angle>,Dim,Dim>
            {
            typedef mat<Angle,Dim,Dim> type;
            };

        template <int Dim,class Angle>
        struct
        deduce_m2<qvm_detail::rotx_m_<Dim,Angle>,qvm_detail::rotx_m_<Dim,Angle>,Dim,Dim>
            {
            typedef mat<Angle,Dim,Dim> type;
            };

        template <int Dim,class Angle>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::rotx_m_<Dim,Angle> const &
        rotx_m( Angle const & angle )
            {
            BOOST_QVM_STATIC_ASSERT(Dim>=3);
            return reinterpret_cast<qvm_detail::rotx_m_<Dim,Angle> const &>(angle);
            }

        template <class A,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows>=3 &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        set_rotx( A & a, Angle angle )
            {
            assign(a,rotx_m<m_traits<A>::rows>(angle));
            }

        template <class A,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows>=3 &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        rotate_x( A & a, Angle angle )
            {
            a *= rotx_m<m_traits<A>::rows>(angle);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int Dim,class Angle>
            struct
            roty_m_
                {
                BOOST_QVM_INLINE_TRIVIAL
                roty_m_()
                    {
                    }

                template <class R>
                BOOST_QVM_INLINE_TRIVIAL
                operator R() const
                    {
                    R r;
                    assign(r,*this);
                    return r;
                    }

                private:

                roty_m_( roty_m_ const & );
                roty_m_ & operator=( roty_m_ const & );
                ~roty_m_();
                };

            template <int Row,int Col>
            struct
            roty_m_get
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & )
                    {
                    return s_traits<T>::value(Row==Col);
                    };
                };

            template <>
            struct
            roty_m_get<0,0>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return cos<T>(angle);
                    };
                };

            template <>
            struct
            roty_m_get<0,2>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return sin<T>(angle);
                    };
                };

            template <>
            struct
            roty_m_get<2,0>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return -sin<T>(angle);
                    };
                };

            template <>
            struct
            roty_m_get<2,2>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return cos<T>(angle);
                    };
                };
            }

        template <int Dim,class Angle>
        struct
        m_traits< qvm_detail::roty_m_<Dim,Angle> >
            {
            typedef qvm_detail::roty_m_<Dim,Angle> this_matrix;
            typedef Angle scalar_type;
            static int const rows=Dim;
            static int const cols=Dim;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Row<Dim);
                BOOST_QVM_STATIC_ASSERT(Col<Dim);
                return qvm_detail::roty_m_get<Row,Col>::get(reinterpret_cast<Angle const &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(row<Dim);
                BOOST_QVM_ASSERT(col<Dim);
                Angle const & a=reinterpret_cast<Angle const &>(x);
                if( row==0 )
                    {
                    if( col==0 )
                        return cos<scalar_type>(a);
                    if( col==2 )
                        return sin<scalar_type>(a);
                    }
                if( row==2 )
                    {
                    if( col==0 )
                        return -sin<scalar_type>(a);
                    if( col==2 )
                        return cos<scalar_type>(a);
                    }
                return s_traits<scalar_type>::value(row==col);
                }
            };

        template <int Dim,class Angle>
        struct
        deduce_m<qvm_detail::roty_m_<Dim,Angle>,Dim,Dim>
            {
            typedef mat<Angle,Dim,Dim> type;
            };

        template <int Dim,class Angle>
        struct
        deduce_m2<qvm_detail::roty_m_<Dim,Angle>,qvm_detail::roty_m_<Dim,Angle>,Dim,Dim>
            {
            typedef mat<Angle,Dim,Dim> type;
            };

        template <int Dim,class Angle>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::roty_m_<Dim,Angle> const &
        roty_m( Angle const & angle )
            {
            BOOST_QVM_STATIC_ASSERT(Dim>=3);
            return reinterpret_cast<qvm_detail::roty_m_<Dim,Angle> const &>(angle);
            }

        template <class A,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows>=2 &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        set_roty( A & a, Angle angle )
            {
            assign(a,roty_m<m_traits<A>::rows>(angle));
            }

        template <class A,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows>=3 &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        rotate_y( A & a, Angle angle )
            {
            a *= roty_m<m_traits<A>::rows>(angle);
            }

        ////////////////////////////////////////////////

        namespace
        qvm_detail
            {
            template <int Dim,class Angle>
            struct
            rotz_m_
                {
                BOOST_QVM_INLINE_TRIVIAL
                rotz_m_()
                    {
                    }

                template <class R>
                BOOST_QVM_INLINE_TRIVIAL
                operator R() const
                    {
                    R r;
                    assign(r,*this);
                    return r;
                    }

                private:

                rotz_m_( rotz_m_ const & );
                rotz_m_ & operator=( rotz_m_ const & );
                ~rotz_m_();
                };

            template <int Row,int Col>
            struct
            rotz_m_get
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & )
                    {
                    return s_traits<T>::value(Row==Col);
                    };
                };

            template <>
            struct
            rotz_m_get<0,0>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return cos<T>(angle);
                    };
                };

            template <>
            struct
            rotz_m_get<0,1>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return -sin<T>(angle);
                    };
                };

            template <>
            struct
            rotz_m_get<1,0>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return sin<T>(angle);
                    };
                };

            template <>
            struct
            rotz_m_get<1,1>
                {
                template <class T>
                static
                BOOST_QVM_INLINE_CRITICAL
                T
                get( T const & angle )
                    {
                    return cos<T>(angle);
                    };
                };
            }

        template <int Dim,class Angle>
        struct
        m_traits< qvm_detail::rotz_m_<Dim,Angle> >
            {
            typedef qvm_detail::rotz_m_<Dim,Angle> this_matrix;
            typedef Angle scalar_type;
            static int const rows=Dim;
            static int const cols=Dim;

            template <int Row,int Col>
            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            r( this_matrix const & x )
                {
                BOOST_QVM_STATIC_ASSERT(Row>=0);
                BOOST_QVM_STATIC_ASSERT(Col>=0);
                BOOST_QVM_STATIC_ASSERT(Row<Dim);
                BOOST_QVM_STATIC_ASSERT(Col<Dim);
                return qvm_detail::rotz_m_get<Row,Col>::get(reinterpret_cast<Angle const &>(x));
                }

            static
            BOOST_QVM_INLINE_CRITICAL
            scalar_type
            ir( int row, int col, this_matrix const & x )
                {
                BOOST_QVM_ASSERT(row>=0);
                BOOST_QVM_ASSERT(col>=0);
                BOOST_QVM_ASSERT(row<Dim);
                BOOST_QVM_ASSERT(col<Dim);
                Angle const & a=reinterpret_cast<Angle const &>(x);
                if( row==0 )
                    {
                    if( col==0 )
                        return cos<scalar_type>(a);
                    if( col==1 )
                        return -sin<scalar_type>(a);
                    }
                if( row==1 )
                    {
                    if( col==0 )
                        return sin<scalar_type>(a);
                    if( col==1 )
                        return cos<scalar_type>(a);
                    }
                return s_traits<scalar_type>::value(row==col);
                }
            };

        template <int Dim,class Angle>
        struct
        deduce_m<qvm_detail::rotz_m_<Dim,Angle>,Dim,Dim>
            {
            typedef mat<Angle,Dim,Dim> type;
            };

        template <int Dim,class Angle,int R,int C>
        struct
        deduce_m2<qvm_detail::rotz_m_<Dim,Angle>,qvm_detail::rotz_m_<Dim,Angle>,R,C>
            {
            typedef mat<Angle,R,C> type;
            };

        template <int Dim,class Angle>
        BOOST_QVM_INLINE_TRIVIAL
        qvm_detail::rotz_m_<Dim,Angle> const &
        rotz_m( Angle const & angle )
            {
            BOOST_QVM_STATIC_ASSERT(Dim>=2);
            return reinterpret_cast<qvm_detail::rotz_m_<Dim,Angle> const &>(angle);
            }

        template <class A,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows>=2 &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        set_rotz( A & a, Angle angle )
            {
            assign(a,rotz_m<m_traits<A>::rows>(angle));
            }

        template <class A,class Angle>
        BOOST_QVM_INLINE_OPERATIONS
        typename enable_if_c<
            is_m<A>::value &&
            m_traits<A>::rows>=2 &&
            m_traits<A>::rows==m_traits<A>::cols,
            void>::type
        rotate_z( A & a, Angle angle )
            {
            a *= rotz_m<m_traits<A>::rows>(angle);
            }

        ////////////////////////////////////////////////

        namespace
        sfinae
            {
            using ::boost::qvm::to_string;
            using ::boost::qvm::assign;
            using ::boost::qvm::determinant;
            using ::boost::qvm::cmp;
            using ::boost::qvm::make;
            using ::boost::qvm::set_identity;
            using ::boost::qvm::set_zero;
            using ::boost::qvm::scalar_cast;
            using ::boost::qvm::operator/=;
            using ::boost::qvm::operator/;
            using ::boost::qvm::operator==;
            using ::boost::qvm::operator-=;
            using ::boost::qvm::operator-;
            using ::boost::qvm::operator*=;
            using ::boost::qvm::operator*;
            using ::boost::qvm::operator!=;
            using ::boost::qvm::operator+=;
            using ::boost::qvm::operator+;
            using ::boost::qvm::inverse;
            using ::boost::qvm::mref;
            using ::boost::qvm::rot_m;
            using ::boost::qvm::set_rot;
            using ::boost::qvm::rotate;
            using ::boost::qvm::set_rotx;
            using ::boost::qvm::rotate_x;
            using ::boost::qvm::set_roty;
            using ::boost::qvm::rotate_y;
            using ::boost::qvm::set_rotz;
            using ::boost::qvm::rotate_z;
            }

        ////////////////////////////////////////////////
        }
    }

#endif
