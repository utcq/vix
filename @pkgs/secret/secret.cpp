#include <iostream>
#include <random>
#include "secret.h"

int seed(int MIN, int MAX) {
  std::random_device rd;
  std::default_random_engine eng(rd());
  std::uniform_int_distribution<int> distr(MIN, MAX);
  return distr(eng);
}

