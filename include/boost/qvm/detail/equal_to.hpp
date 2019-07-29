//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.
//Copyright (c) 2019 agate-pris

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_F15A0813A3634D14B38D6764E121EABE
#define UUID_F15A0813A3634D14B38D6764E121EABE

#include <boost/config.hpp>
#include <boost/qvm/inline.hpp>

#include <utility>

namespace
boost
    {
    namespace
    qvm
        {
        namespace
        qvm_detail
            {
            // C++2a compatible equal_to as much as possible in C++11. Even in
            // C++03, it can compare with types T and U.
            template <class T = void>
            struct equal_to
                {
#if defined(BOOST_NO_CXX11_TRAILING_RESULT_TYPES) || \
    defined(BOOST_NO_CXX11_DECLTYPE_N3276) || \
    defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
                typedef T first_argument_type;
                typedef T second_argument_type;
                typedef bool result_type;
#endif

                BOOST_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
                bool
                operator()(T const & x, T const & y) const
                    {
                    return x == y;
                    }
                };

            // C++2a compatible equal_to as much as possible in C++11. Even in
            // C++03, it can compare with types T and U.
            template <>
            struct equal_to<void>
                {
#if defined(BOOST_NO_CXX11_TRAILING_RESULT_TYPES) || \
    defined(BOOST_NO_CXX11_DECLTYPE_N3276)
#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
                template <class T, class U>
                BOOST_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
                bool
                operator()(T const & t, U const & u) const
                    {
                    return t == u;
                    }
                };
#else
                template <class T, class U>
                BOOST_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
                bool
                operator()(T && t, U && u) const
                    {
                    return std::forward<T>(t) == std::forward<U>(u);
                    }
                };
#endif
#else
#if defined(BOOST_NO_CXX11_RVALUE_REFERENCES)
                template <class T, class U>
                BOOST_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
                auto
                operator()(T const & t, U const & u) const
                    -> decltype(t == u)
                    {
                    return t == u;
                    }
                };
#endif
                template <class T, class U>
                BOOST_CONSTEXPR BOOST_QVM_INLINE_CRITICAL
                auto
                operator()(T && t, U && u) const
                    -> decltype(std::forward<T>(t) == std::forward<U>(u))
                    {
                    return std::forward<T>(t) == std::forward<U>(u);
                    }
                };
                using is_transparent = void;
#endif
            }
        }
    }

#endif
