#ifndef UUID_F0B34CB08687439DA6046DBFB7C674DD
#define UUID_F0B34CB08687439DA6046DBFB7C674DD

#include <boost/utility/enable_if.hpp>

namespace
test_qvm
    {
    // Non default constructible, non copy constructible, non move
    // constructible, non copy assignable, non move assignable scalar.
    template <class T>
    class
    inconvenient_scalar
        {
        T value;
    public:
        inconvenient_scalar( T const & a )
            : value(a)
            {
            }
        T const & const_deref() const { return value;                          }
        T const & deref      () const { return const_deref();                  }
        T       & deref      ()       { return const_cast<T &>(const_deref()); }
        T         get        () const { return const_deref();                  }
        void set( T const & a )
            {
            deref() = a;
            }
        template <class U>
        bool operator==( inconvenient_scalar<U> const & b )
            {
            return deref() == b.deref();
            }
        template <class U>
        bool operator!=( inconvenient_scalar<U> const & b )
            {
            return deref() != b.deref();
            }
        };
    }

#endif
