#include "TaskQueue.hpp"

bool TaskQueue::pop(T& out)
{
    std::lock_guard<std::mutex> lock{ m_mutex };
    if (m_queue.empty() || !m_valid) {
        return false;
    }
    out = std::move(m_queue.front());
    m_queue.pop();
    return true;
}