//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_47B1D1217B411E08424FA0ADFD72085
#define UUID_47B1D1217B411E08424FA0ADFD72085

#include <boost/qvm/mat_traits.hpp>
#include <boost/qvm/inline.hpp>
#include <boost/qvm/static_assert.hpp>

namespace
boost
    {
    namespace
    qvm
        {
        ////////////////////////////////////////////////

        template <int R,int C>
        struct
        matrix_access_tag
            {
            };

        template <class M,int R,int C>
        BOOST_QVM_INLINE_TRIVIAL
        typename mat_traits<M>::scalar_type &
        operator,( M & a, matrix_access_tag<R,C> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(R>=0);
            BOOST_QVM_STATIC_ASSERT(R<mat_traits<M>::rows);
            BOOST_QVM_STATIC_ASSERT(C>=0);
            BOOST_QVM_STATIC_ASSERT(C<mat_traits<M>::cols);
            return mat_traits<M>::template write_element<R,C>(a);
            }

        template <class M,int R,int C>
        BOOST_QVM_INLINE_TRIVIAL
        typename mat_traits<M>::scalar_type
        operator,( M const & a, matrix_access_tag<R,C> (*)() )
            {
            BOOST_QVM_STATIC_ASSERT(R>=0);
            BOOST_QVM_STATIC_ASSERT(R<mat_traits<M>::rows);
            BOOST_QVM_STATIC_ASSERT(C>=0);
            BOOST_QVM_STATIC_ASSERT(C<mat_traits<M>::cols);
            return mat_traits<M>::template read_element<R,C>(a);
            }

        template <class M,int R,int C>
        BOOST_QVM_INLINE_TRIVIAL
        typename mat_traits<M>::scalar_type &
        operator,( M & a, matrix_access_tag<R,C> )
            {
            BOOST_QVM_STATIC_ASSERT(R>=0);
            BOOST_QVM_STATIC_ASSERT(R<mat_traits<M>::rows);
            BOOST_QVM_STATIC_ASSERT(C>=0);
            BOOST_QVM_STATIC_ASSERT(C<mat_traits<M>::cols);
            return mat_traits<M>::template write_element<R,C>(a);
            }

        template <class M,int R,int C>
        BOOST_QVM_INLINE_TRIVIAL
        typename mat_traits<M>::scalar_type
        operator,( M const & a, matrix_access_tag<R,C> )
            {
            BOOST_QVM_STATIC_ASSERT(R>=0);
            BOOST_QVM_STATIC_ASSERT(R<mat_traits<M>::rows);
            BOOST_QVM_STATIC_ASSERT(C>=0);
            BOOST_QVM_STATIC_ASSERT(C<mat_traits<M>::cols);
            return mat_traits<M>::template read_element<R,C>(a);
            }

        template <int R,int C>
        BOOST_QVM_INLINE_TRIVIAL
        matrix_access_tag<R,C>
        A()
            {
            return matrix_access_tag<R,C>();
            }

        ////////////////////////////////////////////////

        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,0> A00() { return matrix_access_tag<0,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,1> A01() { return matrix_access_tag<0,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,2> A02() { return matrix_access_tag<0,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,3> A03() { return matrix_access_tag<0,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,4> A04() { return matrix_access_tag<0,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,5> A05() { return matrix_access_tag<0,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,6> A06() { return matrix_access_tag<0,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,7> A07() { return matrix_access_tag<0,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,8> A08() { return matrix_access_tag<0,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<0,9> A09() { return matrix_access_tag<0,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,0> A10() { return matrix_access_tag<1,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,1> A11() { return matrix_access_tag<1,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,2> A12() { return matrix_access_tag<1,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,3> A13() { return matrix_access_tag<1,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,4> A14() { return matrix_access_tag<1,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,5> A15() { return matrix_access_tag<1,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,6> A16() { return matrix_access_tag<1,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,7> A17() { return matrix_access_tag<1,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,8> A18() { return matrix_access_tag<1,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<1,9> A19() { return matrix_access_tag<1,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,0> A20() { return matrix_access_tag<2,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,1> A21() { return matrix_access_tag<2,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,2> A22() { return matrix_access_tag<2,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,3> A23() { return matrix_access_tag<2,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,4> A24() { return matrix_access_tag<2,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,5> A25() { return matrix_access_tag<2,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,6> A26() { return matrix_access_tag<2,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,7> A27() { return matrix_access_tag<2,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,8> A28() { return matrix_access_tag<2,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<2,9> A29() { return matrix_access_tag<2,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,0> A30() { return matrix_access_tag<3,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,1> A31() { return matrix_access_tag<3,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,2> A32() { return matrix_access_tag<3,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,3> A33() { return matrix_access_tag<3,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,4> A34() { return matrix_access_tag<3,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,5> A35() { return matrix_access_tag<3,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,6> A36() { return matrix_access_tag<3,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,7> A37() { return matrix_access_tag<3,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,8> A38() { return matrix_access_tag<3,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<3,9> A39() { return matrix_access_tag<3,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,0> A40() { return matrix_access_tag<4,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,1> A41() { return matrix_access_tag<4,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,2> A42() { return matrix_access_tag<4,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,3> A43() { return matrix_access_tag<4,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,4> A44() { return matrix_access_tag<4,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,5> A45() { return matrix_access_tag<4,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,6> A46() { return matrix_access_tag<4,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,7> A47() { return matrix_access_tag<4,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,8> A48() { return matrix_access_tag<4,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<4,9> A49() { return matrix_access_tag<4,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,0> A50() { return matrix_access_tag<5,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,1> A51() { return matrix_access_tag<5,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,2> A52() { return matrix_access_tag<5,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,3> A53() { return matrix_access_tag<5,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,4> A54() { return matrix_access_tag<5,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,5> A55() { return matrix_access_tag<5,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,6> A56() { return matrix_access_tag<5,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,7> A57() { return matrix_access_tag<5,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,8> A58() { return matrix_access_tag<5,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<5,9> A59() { return matrix_access_tag<5,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,0> A60() { return matrix_access_tag<6,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,1> A61() { return matrix_access_tag<6,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,2> A62() { return matrix_access_tag<6,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,3> A63() { return matrix_access_tag<6,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,4> A64() { return matrix_access_tag<6,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,5> A65() { return matrix_access_tag<6,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,6> A66() { return matrix_access_tag<6,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,7> A67() { return matrix_access_tag<6,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,8> A68() { return matrix_access_tag<6,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<6,9> A69() { return matrix_access_tag<6,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,0> A70() { return matrix_access_tag<7,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,1> A71() { return matrix_access_tag<7,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,2> A72() { return matrix_access_tag<7,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,3> A73() { return matrix_access_tag<7,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,4> A74() { return matrix_access_tag<7,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,5> A75() { return matrix_access_tag<7,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,6> A76() { return matrix_access_tag<7,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,7> A77() { return matrix_access_tag<7,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,8> A78() { return matrix_access_tag<7,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<7,9> A79() { return matrix_access_tag<7,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,0> A80() { return matrix_access_tag<8,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,1> A81() { return matrix_access_tag<8,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,2> A82() { return matrix_access_tag<8,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,3> A83() { return matrix_access_tag<8,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,4> A84() { return matrix_access_tag<8,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,5> A85() { return matrix_access_tag<8,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,6> A86() { return matrix_access_tag<8,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,7> A87() { return matrix_access_tag<8,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,8> A88() { return matrix_access_tag<8,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<8,9> A89() { return matrix_access_tag<8,9>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,0> A90() { return matrix_access_tag<9,0>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,1> A91() { return matrix_access_tag<9,1>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,2> A92() { return matrix_access_tag<9,2>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,3> A93() { return matrix_access_tag<9,3>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,4> A94() { return matrix_access_tag<9,4>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,5> A95() { return matrix_access_tag<9,5>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,6> A96() { return matrix_access_tag<9,6>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,7> A97() { return matrix_access_tag<9,7>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,8> A98() { return matrix_access_tag<9,8>(); }
        BOOST_QVM_INLINE_TRIVIAL matrix_access_tag<9,9> A99() { return matrix_access_tag<9,9>(); }

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
