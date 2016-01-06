//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/vec_traits.hpp>
#include <boost/qvm/swizzle3.hpp>

template <int D> struct my_vec { };

namespace
boost
    {
    namespace
    qvm
        {
        template <int D>
        struct
        vec_traits< my_vec<D> >
            {
            typedef int scalar_type;
            static int const dim=D;
            template <int I> static int r( my_vec<D> const & );
            template <int I> static int & w( my_vec<D> & );
            };
        }
    }

int
main()
    {
    using namespace boost::qvm;
    my_vec<1>(),XXY;
    return 1;
    }
