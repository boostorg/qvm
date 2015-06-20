//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/qvm.hpp>
#include <boost/qvm/quat.hpp>
#include <boost/qvm/vec.hpp>
#include <boost/qvm/mat.hpp>

namespace
my_stuff
    {
    struct
    mat
        {
        float a[3][3];
        };

    struct
    vec
        {
        float a[3];
        };

    struct
    quat
        {
        float a[4];
        };
    }

namespace
boost
    {
    namespace
    qvm
        {
        template <>
        struct
        m_traits<my_stuff::mat>
            {
            typedef float scalar_type;
            static int const rows=3;
            static int const cols=3;

            template <int R,int C>
            static
            scalar_type &
            w( my_stuff::mat & m )
                {
                BOOST_QVM_STATIC_ASSERT(R>=0);
                BOOST_QVM_STATIC_ASSERT(R<rows);
                BOOST_QVM_STATIC_ASSERT(C>=0);
                BOOST_QVM_STATIC_ASSERT(C<cols);
                return m.a[R][C];
                }

            template <int R,int C>
            static
            scalar_type
            r( my_stuff::mat const & m )
                {
                BOOST_QVM_STATIC_ASSERT(R>=0);
                BOOST_QVM_STATIC_ASSERT(R<rows);
                BOOST_QVM_STATIC_ASSERT(C>=0);
                BOOST_QVM_STATIC_ASSERT(C<cols);
                return m.a[R][C];
                }

            static
            inline
            scalar_type &
            iw( int r, int c, my_stuff::mat & m )
                {
                BOOST_QVM_ASSERT(r>=0);
                BOOST_QVM_ASSERT(r<rows);
                BOOST_QVM_ASSERT(c>=0);
                BOOST_QVM_ASSERT(c<cols);
                return m.a[r][c];
                }

            static
            inline
            scalar_type
            ir( int r, int c, my_stuff::mat const & m )
                {
                BOOST_QVM_ASSERT(r>=0);
                BOOST_QVM_ASSERT(r<rows);
                BOOST_QVM_ASSERT(c>=0);
                BOOST_QVM_ASSERT(c<cols);
                return m.a[r][c];
                }
            };

        template <>
        struct
        v_traits<my_stuff::vec>
            {
            static int const dim=3;
            typedef float scalar_type;

            template <int I>
            static
            scalar_type &
            w( my_stuff::vec & m )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<dim);
                return m.a[I];
                }

            template <int I>
            static
            scalar_type
            r( my_stuff::vec const & m )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<dim);
                return m.a[I];
                }

            static
            inline
            scalar_type &
            iw( int i, my_stuff::vec & m )
                {
                BOOST_QVM_ASSERT(i>=0);
                BOOST_QVM_ASSERT(i<dim);
                return m.a[i];
                }

            static
            inline
            scalar_type
            ir( int i, my_stuff::vec const & m )
                {
                BOOST_QVM_ASSERT(i>=0);
                BOOST_QVM_ASSERT(i<dim);
                return m.a[i];
                }
            };

        template <>
        struct
        q_traits<my_stuff::quat>
            {
            typedef float scalar_type;

            template <int I>
            static
            scalar_type &
            w( my_stuff::quat & m )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<4);
                return m.a[I];
                }

            template <int I>
            static
            scalar_type
            r( my_stuff::quat const & m )
                {
                BOOST_QVM_STATIC_ASSERT(I>=0);
                BOOST_QVM_STATIC_ASSERT(I<4);
                return m.a[I];
                }
            };
        }
    }

namespace
my_stuff
    {
    mat &
    operator/=( mat & x, float y )
        {
        return boost::qvm::operator/=(x,y);
        }

    vec &
    operator/=( vec & x, float y )
        {
        return boost::qvm::operator/=(x,y);
        }

    quat &
    operator/=( quat & x, float y )
        {
        return boost::qvm::operator/=(x,y);
        }

    mat &
    operator*=( mat & x, float y )
        {
        return boost::qvm::operator*=(x,y);
        }

    vec &
    operator*=( vec & x, float y )
        {
        return boost::qvm::operator*=(x,y);
        }

    quat &
    operator*=( quat & x, float y )
        {
        return boost::qvm::operator*=(x,y);
        }

    mat
    operator/( mat const & x, float y )
        {
        return boost::qvm::operator/(x,y);
        }

    vec
    operator/( vec const & x, float y )
        {
        return boost::qvm::operator/(x,y);
        }

    quat
    operator/( quat const & x, float y )
        {
        return boost::qvm::operator/(x,y);
        }

    mat
    operator*( mat const & x, float y )
        {
        return boost::qvm::operator*(x,y);
        }

    vec
    operator*( vec const & x, float y )
        {
        return boost::qvm::operator*(x,y);
        }

    quat
    operator*( quat const & x, float y )
        {
        return boost::qvm::operator*(x,y);
        }

    mat &
    operator*=( mat & x, mat const & y )
        {
        return boost::qvm::operator*=(x,y);
        }

    mat
    operator*=( mat const & x, mat const & y )
        {
        return boost::qvm::operator*(x,y);
        }

    vec
    operator*( mat const & x, vec const & y )
        {
        return boost::qvm::operator*(x,y);
        }

    vec
    operator*( quat const & x, vec const & y )
        {
        return boost::qvm::operator*(x,y);
        }

    vec
    operator*( vec const & x, mat const & y )
        {
        return boost::qvm::operator*(x,y);
        }

    bool
    operator==( mat const & x, mat const & y )
        {
        return boost::qvm::operator==(x,y);
        }

    bool
    operator!=( mat const & x, mat const & y )
        {
        return boost::qvm::operator!=(x,y);
        }

    bool
    operator==( vec const & x, vec const & y )
        {
        return boost::qvm::operator==(x,y);
        }

    bool
    operator!=( vec const & x, vec const & y )
        {
        return boost::qvm::operator!=(x,y);
        }

    bool
    operator==( quat const & x, quat const & y )
        {
        return boost::qvm::operator==(x,y);
        }

    bool
    operator!=( quat const & x, quat const & y )
        {
        return boost::qvm::operator!=(x,y);
        }
    }

int
main()
    {
    using namespace boost::qvm::sfinae;
    using namespace my_stuff;
    typedef boost::qvm::mat<double,3,3> mat2;
    typedef boost::qvm::vec<double,3> vec2;
    typedef boost::qvm::quat<double> quat2;

    mat ma1,mb1;
    vec va1, vb1;
    quat qa1, qb1;
    mat2 ma2, mb2;
    vec2 va2, vb2;
    quat2 qa2, qb2;

    ma1/=2;
    va1/=2;
    qa1/=2;
    ma2/=2;
    va2/=2;
    qa2/=2;

    ma1*=2;
    va1*=2;
    qa1*=2;
    ma2*=2;
    va2*=2;
    qa2*=2;

    mb1=ma1/2;
    vb1=va1/2;
    qb1=qb1/2;
    mb2=make<mat2>(ma1/2);
    vb2=make<vec2>(va1/2);
    qb2=make<quat2>(qa1/2);
    mb1=scalar_cast<float>(ma2/2);
    vb1=scalar_cast<float>(va2/2);
    qb1=scalar_cast<float>(qa2/2);

    mb1=ma1*2;
    vb1=va1*2;
    qb1=qa1*2;
    mb2=make<mat2>(ma1*2);
    vb2=make<vec2>(va1*2);
    qb2=make<quat2>(qa1*2);
    mb1=scalar_cast<float>(ma2*2);
    vb1=scalar_cast<float>(va2*2);
    qb1=scalar_cast<float>(qa2*2);

    ma1*=mb1;
    ma1*=scalar_cast<float>(ma2);
    ma2*=ma1;

    va1=ma1*va1;
    va1=qa1*va1;
    va1=scalar_cast<float>(ma2*va1);
    va1=scalar_cast<float>(ma1*va2);
    va1=scalar_cast<float>(ma2*va2);
    va1=scalar_cast<float>(qa2*va1);
    va1=scalar_cast<float>(qa1*va2);
    va1=scalar_cast<float>(qa2*va2);

    va2=make<vec2>(ma1*va1);
    va2=make<vec2>(qa1*va1);
    va2=ma2*va1;
    va2=ma1*va2;
    va2=ma2*va2;
    va2=qa2*va1;
    va2=qa1*va2;
    va2=qa2*va2;

    va1=va1*ma1;
    va1=scalar_cast<float>(va1*ma2);
    va1=scalar_cast<float>(va2*ma1);
    va1=scalar_cast<float>(va2*ma2);

    va2=make<vec2>(va1*ma1);
    va2=va1*ma2;
    va2=va2*ma1;
    va2=va2*ma2;

    ma1==mb1;
    ma1==ma2;
    ma2==ma1;

    ma1!=mb1;
    ma1!=ma2;
    ma2!=ma1;

    va1==vb1;
    va1==va2;
    va2==va1;

    va1!=vb1;
    va1!=va2;
    va2!=va1;

    qa1==qb1;
    qa1==qa2;
    qa2==qa1;

    qa1!=qb1;
    qa1!=qa2;
    qa2!=qa1;

    return 0;
    }
