//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/q_access.hpp>
#include <boost/qvm/v_access.hpp>

struct my_quat { };

namespace
boost
    {
    namespace
    qvm
        {
        template <>
        struct
        q_traits<my_quat>
            {
            typedef int scalar_type;
            template <int I> static int r( my_quat const & );
            template <int I> static int & w( my_quat & );
            };
        }
    }

int
main()
    {
    using namespace boost::qvm;
    my_quat const q=my_quat();
    q,V,A<3>();
    return 1;
    }
