#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 2897
// Optimized logic batch 1290
// Optimized logic batch 7769
// Optimized logic batch 8028
// Optimized logic batch 5413
// Optimized logic batch 7776
// Optimized logic batch 4131
// Optimized logic batch 7311
// Optimized logic batch 4261
// Optimized logic batch 7977
// Optimized logic batch 7472
// Optimized logic batch 6886
// Optimized logic batch 6220
// Optimized logic batch 2122
// Optimized logic batch 2194
// Optimized logic batch 6323
// Optimized logic batch 2320
// Optimized logic batch 8143
// Optimized logic batch 1362