#include <vector>
#include <queue>
#include <cstdint>

class VekQueue {

private:
    std::vector<std::queue<int32_t> > v;

    int16_t sz = 0;                //Number of queues

    void checksize(int32_t a);  //Used to check in which Queue should be pushed

public:
    virtual ~VekQueue();

    VekQueue(int16_t n);

    int16_t size() const;   //Number of all elements

    int64_t size(int32_t nr) const; //Number of ellements of a specific queue

    bool empty() const; //Checks if everything is empty

    bool empty(int32_t nr) const;   //Checks if one specific queue is empty

    void push(int32_t a);    //Hot-Potato-Algorithmus.

    const int32_t pop();           //Destroys the first element of a random queue

    const int32_t pop(int32_t nr);  //Destroys the first element of a specific queue
};