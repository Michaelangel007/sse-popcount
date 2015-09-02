========================================================================
                           SIMD popcount
========================================================================

Sample programs for my article http://0x80.pl/articles/sse-popcount.html

Introduction
------------------------------------------------------------------------

Subdirectory **original** contains code from 2008 --- it is 32-bit
and GCC-centric. The **root directory** contains fresh C++11 code,
written with intrinsics and tested on 64-bit machine.

As usual type ``make`` to compile programs, then you can invoke:

* ``verify`` --- program tests if all non-lookup implementations counts
  bits properly.
* ``speed`` --- program tests different implementations of popcount
  procedure; please read help to find all options (run the program
  without arguments).

You can also run ``make run`` to run ``speed`` for all available
implementations.


Available implementations in new version
------------------------------------------------------------------------

There are following procedures:

* ``sse-lookup`` --- pshufb version described in the article.
* ``lookup-8`` --- lookup table of type ``std::uint8_t[256]``.
* ``lookup-64`` --- lookup table of type ``std::uint64_t[256]``,
  LUT is 8 times larger, but we avoid extending 8 to 64 bits.
* ``bit-parallel`` --- well know bit parallel method.
* ``bit-parallel-optimized`` --- in this variant counting
  on packed bytes is performed exactly in the same way
  as described in the article: this gives **50% speedup**.
* ``sse-bit-parallel`` --- SSE implementation of
  ``bit-parallel-optimized``


Results from core i5, program compiled by GCC 4.9.2::

    running cpu                           time = 0.127574 s
    running sse-lookup                    time = 0.147006 s
    running sse-bit-parallel              time = 0.208366 s
    running bit-parallel-optimized        time = 0.447463 s
    running bit-parallel                  time = 0.683336 s
    running lookup-8                      time = 0.668823 s
    running lookup-64                     time = 0.687057 s

Results from i7::

    Clang
    running cpu                           ...reference result = 3999936000, time =   0.055046 s
    running sse-lookup                    ...reference result = 3999936000, time =   0.098277 s
    running sse-bit-parallel              ...reference result = 3999936000, time =   0.111080 s
    running bit-parallel-optimized        ...reference result = 3999936000, time =   0.000261 s
    running bit-parallel                  ...reference result = 3999936000, time =   0.000359 s
    running lookup-8                      ...reference result = 3999936000, time =   0.362899 s
    running lookup-64                     ...reference result = 3999936000, time =   0.326885 s
    running lookup-3                      ...reference result = 3999936000, time =   1.408825 s
    running lookup-4                      ...reference result = 3999936000, time =   0.801271 s
    running lookup-7                      ...reference result = 3999936000, time =   0.662352 s

    GCC
    running cpu                           ...reference result = 3999936000, time =   0.053749 s
    running sse-lookup                    ...reference result = 3999936000, time =   0.097490 s
    running sse-bit-parallel              ...reference result = 3999936000, time =   0.107081 s
    running bit-parallel-optimized        ...reference result = 3999936000, time =   0.000250 s
    running bit-parallel                  ...reference result = 3999936000, time =   0.000371 s
    running lookup-8                      ...reference result = 3999936000, time =   0.372160 s
    running lookup-64                     ...reference result = 3999936000, time =   0.328134 s
    running lookup-3                      ...reference result = 3999936000, time =   1.429192 s
    running lookup-4                      ...reference result = 3999936000, time =   0.792507 s
    running lookup-7                      ...reference result = 3999936000, time =   0.645930 s

References:

* http://wm.ite.pl/articles/sse-popcount.html

