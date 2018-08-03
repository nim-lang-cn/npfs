# Stint
# Copyright 2018 Status Research & Development GmbH
# Licensed under either of
#
#  * Apache License, version 2.0, ([LICENSE-APACHE](LICENSE-APACHE) or http://www.apache.org/licenses/LICENSE-2.0)
#  * MIT license ([LICENSE-MIT](LICENSE-MIT) or http://opensource.org/licenses/MIT)
#
# at your option. This file may not be copied, modified, or distributed except according to those terms.

import  ./datatypes, ./conversion, stdlib_bitops, as_words
export stdlib_bitops

# We reuse bitops from Nim standard lib, and expand it for multi-precision int.
# MpInt rely on no undefined behaviour as often we scan 0. (if 1 is stored in a uint128 for example)
# Also countLeadingZeroBits must return the size of the type and not 0 like in the stdlib

func countLeadingZeroBits*(n: UintImpl): int {.inline.} =
  ## Returns the number of leading zero bits in integer.

  const maxHalfRepr = getSize(n) div 2

  let hi_clz = n.hi.countLeadingZeroBits

  result =  if hi_clz == maxHalfRepr:
              n.lo.countLeadingZeroBits + maxHalfRepr
            else: hi_clz

func isMsbSet*[T: SomeInteger](n: T): bool {.inline.}=
  ## Returns the most significant bit of an integer.
  const msb_pos = sizeof(T) * 8 - 1
  result = bool(n.toUint shr msb_pos)

func isMsbSet*(n: UintImpl or IntImpl): bool {.inline.}=
  ## Returns the most significant bit of an arbitrary precision integer.
  result = isMsbSet most_significant_word(n)
