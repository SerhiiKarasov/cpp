#pragma once

#include <boost/atomic.hpp>
const int iterations = 10000000;
const int consumer_thread_count = 4;
boost::atomic_int consumer_count(0);
boost::atomic<bool> done(false);
