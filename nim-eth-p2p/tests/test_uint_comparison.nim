# Stint
# Copyright 2018 Status Research & Development GmbH
# Licensed under either of
#
#  * Apache License, version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
#  * MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)
#
# at your option. This file may not be copied, modified, or distributed except according to those terms.

import ../stint, unittest

suite "Testing unsigned int comparison operators":
  let
    a = 10'i16.stuint(16)
    b = 15'i16.stuint(16)
    c = 150'u16
    d = 4.stuint(128) shl 64
    e = 4.stuint(128)
    f = 4.stuint(128) shl 65

  test "< operator":
    check:
      a < b
      not (a + b < b)
      not (a + a + a < b + b)
      not (a * b < cast[StUint[16]](c))
      e < d
      d < f

  test "<= operator":
    check:
      a <= b
      not (a + b <= b)
      a + a + a <= b + b
      a * b <= cast[StUint[16]](c)
      e <= d
      d <= f

  test "> operator":
    check:
      b > a
      not (b > a + b)
      not (b + b > a + a + a)
      not (cast[StUint[16]](c) > a * b)
      d > e
      f > d

  test ">= operator":
    check:
      b >= a
      not (b >= a + b)
      b + b >= a + a + a
      cast[StUint[16]](c) >= a * b
      d >= e
      f >= d

  test "isOdd/isEven":
    check:
      a.isEven
      not a.isOdd
      b.isOdd
      not b.isEven
      c.isEven
      not c.isOdd
