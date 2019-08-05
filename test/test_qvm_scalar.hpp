//Copyright (c) 2008-2016 Emil Dotchevski and Reverge Studios, Inc.
//Copyright (c) 2019 agate-pris

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef UUID_F0B34CB08687439DA6046DBFB7C674DD
#define UUID_F0B34CB08687439DA6046DBFB7C674DD

#include <boost/utility/enable_if.hpp>

namespace
test_qvm
    {
    // Non default constructible scalar.
    template <class T>
    class
    inconvenient_scalar
        {
        template <class U>
        friend class inconvenient_scalar;

        T value_;

        public:

        explicit inconvenient_scalar( T const & value ):
            value_(value)
            {
            }
        void
        set( T const & value )
            {
            value_ = value;
            }
        template <class U>
        bool
        operator==( inconvenient_scalar<U> const & b ) const
            {
            return this->value_==b.value_;
            }
        template <class U>
        bool
        operator!=( inconvenient_scalar<U> const & b ) const
            {
            return !(*this==b);
            }
        };
    }

#endif
