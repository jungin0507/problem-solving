    auto COUNT = [](int mask) -> int {
      int ret = 0;
      while (mask) {
        ret += mask % 2;
        mask >>= 1;
      }
      return ret;
    };
    cout << F[COUNT(bit)][bit] << "\n";