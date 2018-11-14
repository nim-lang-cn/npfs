proc toStr*(a: openArray[byte]): string =
    result = newString len a
    for idx, val in a:
      result[idx] = char val
