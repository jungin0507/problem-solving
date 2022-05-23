  // for (int i = 0; i < N; ++i) {
  //   if (res[i]) ++sz1;
  //   if (res2[i]) ++sz2;
  // }
  // if (!sz1 && !sz2) {
  //   cout << 0 << "\n";
  //   return;
  // } else if (!sz1 && sz2 == 1) {
  //   cout << 1 << "\n";
  //   cout << 0 << "\n";
  //   cout << 0 << "\n";
  //   return;
  // }
  // string s1 = "";
  // ll limit = 100;
  // for (int i = N - 1; i >= 0; --i) {
  //   if (!res[i]) continue;
  //   s1 += string(min(limit, res[i]), '0' + i);
  //   limit -= min(limit, res[i]);
  // }
  // string s2 = "";
  // limit = 100;
  // for (int i = N - 1; i >= 0; --i) {
  //   if (!res2[i]) continue;
  //   s2 += string(min(limit, res2[i]), '0' + i);
  //   limit -= min(limit, res2[i]);
  // }
  // cout << max(sz1, sz2) << "\n";