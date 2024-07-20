// ppp.h
#pragma once

//import PPP;
#include "ppp3/internal/PPPheaders.h"
using namespace PPP;
using namespace std;

// disgusting macro hack to guarantee range checking for []:
#define vector Checked_vector
#define string Checked_string
#define span Checked_span
