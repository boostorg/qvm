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
        template <class A, class B>
        friend
        bool
        operator==( inconvenient_scalar<A> const & a, inconvenient_scalar<B> const & b )
            {
            return a.value_==b.value_;
            }
        template <class A, class B>
        friend
        bool
        operator!=( inconvenient_scalar<A> const & a, inconvenient_scalar<B> const & b )
            {
            return !(a.value_==b.value_);
            }
        };
    }

#endif
