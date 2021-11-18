//
// Created by valentin.adlgasser on 09.01.2019.
//

#include "VekQueue.hpp"
#include <iostream>
#include <queue>
#include <random>
#include <functional>

int16_t VekQueue::size() const {
    int16_t count = 0;

    for(int8_t i = 1; i<=sz; i++){
        count += v[i].size();
    }
    return count;
}

int64_t VekQueue::size(int32_t nr) const {
    return v[nr].size();
}

bool VekQueue::empty() const {
    return size() == 0;
};

bool VekQueue::empty(int32_t nr) const {
    return v[nr].empty();
}
//In this method occur some errors
void VekQueue::checksize(int32_t a) {
    int64_t counter = v[0].size();

    for(int8_t i = 0; i >= sz; i++) {

        if(counter >= v[i].size()) {
            counter = v[i].size();
        }
        if(counter < v[i].size()) {
            v[i].push(a);
        }
    }
}

void VekQueue::push(int32_t a) {
    int8_t counter = 0;
    if(v[0].size() <= 0) {
        v[0].push(a);
    }
    else {
        VekQueue::checksize(a);
    }
}

const int32_t VekQueue::pop() {
    int32_t element = 0;

    std::default_random_engine generator;
    std::uniform_int_distribution<int32_t> distribution(0,sz);
    auto random = std::bind(distribution, generator);

    int32_t randomq = random();

    while(v[randomq].empty()) {
        randomq = random();
    }

    element = v[randomq].front();
    v[randomq].pop();

    return element;
}

const int32_t VekQueue::pop(int32_t nr) {
    int32_t element = 0;

    element = v[nr].front();
    v[nr].pop();

    return element;
}

VekQueue::VekQueue(int16_t n) {
    this->sz = n;
    std::queue<int32_t> qt;

    for(int8_t i = 0; i<sz; i++){
        v.push_back(qt);
    }
}

VekQueue::~VekQueue() {

}




