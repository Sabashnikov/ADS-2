// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"


double pown(double value, uint16_t n) {
  double value2 = value;
  for (uint16_t i = 2; i <= n; ++i) {
    value *= value2;
  }
  return value;
}

uint64_t fact(uint16_t n) {
  if (n == 1) {
    return 1;
  } else {
    return fact(n-1) * n;
  }
}

double calcItem(double x, uint16_t n) {
  return (pown(x, n)) / (fact(n));
}

double expn(double x, uint16_t count) {
  double e = 1;
  for (uint16_t i = 1; i < count; ++i) {
    e += calcItem(x, i);
  }
  return e;
}

double sinn(double x, uint16_t count) {
  double sin = x;
  for (uint16_t i = 3; i <= count*2; i+=2) {
    if (i == 3) {
      sin -= calcItem(x, i);
      continue;
    }
    sin += calcItem(x, i);
  }
  return sin;
}

double cosn(double x, uint16_t count) {
  double cos = 1;
  for (uint16_t i = 2; i < count*2; i += 2) {
    if (i == 2) {
      cos -= calcItem(x, i);
      continue;
    }
    cos += calcItem(x, i);
  }
  return cos;
}
