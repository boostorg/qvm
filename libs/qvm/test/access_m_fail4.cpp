//Copyright (c) 2008-2013 Emil Dotchevski and Reverge Studios, Inc.

//Distributed under the Boost Software License, Version 1.0. (See accompanying
//file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/qvm/m_access.hpp>

template <int R,int C> struct my_mat { };

namespace
boost
    {
    namespace
    qvm
        {
        template <int R,int C>
        struct
        m_traits< my_mat<R,C> >
            {
            typedef int scalar_type;
            static int const rows=R;
            static int const cols=C;
            template <int Row,int Col> static int r( my_mat<R,C> const & );
            template <int Row,int Col> static int & w( my_mat<R,C> & );
            };
        }
    }

int
main()
    {
    using namespace boost::qvm;
    my_mat<1,1> m;
    (m,A11());
    return 1;
    }
