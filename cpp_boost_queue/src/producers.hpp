#pragma once
#include <boost/atomic.hpp>
boost::atomic_int producer_count(0);
const int producer_thread_count = 4;
