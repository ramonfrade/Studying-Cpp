// PPPheaders.h
#pragma once

#include <iostream>
#include <random>
#include <span>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include <fstream>
#include <iomanip>

#include <algorithm>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <stdint.h>
#include <unordered_map>

#define PPP_EXPORT
#include "ppp3/internal/PPP_support.h"

using namespace std;
using namespace PPP;

// disgusting macro hack to get a range checking:
#define vector Checked_vector
#define string Checked_string
#define span Checked_span
