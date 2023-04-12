#pragma once

#include "IQueue.hpp"

#define MAX_TAM 1000

template<typename T>
class ArrayQueue : public IQueue<T> {
private:
    int head;
    int tail;
    int size;
    T itens[MAX_TAM];

public:
    ArrayQueue() {
        this->size = 0;
        this->head = 0;
        this->tail = 0;
    }

    ~ArrayQueue() { }

    int get_size() {
        return this->size;
    }

    bool is_empty() override {
        return this->size == 0;
    }

    void enqueue(T item) override {
        if (size == MAX_TAM) {
            throw "Queue is full!";
        }
        itens[tail] = item;
        tail = (tail + 1) % MAX_TAM;
        this->size++;
    }

    T dequeue() override {
        if (is_empty()) {
            throw "Queue os empty!";
        }

        T aux = itens[head];
        this->head = (head + 1) % MAX_TAM;
        this->size--;
        return aux;
    }

    void clear() override {
        this->size = 0;
        this->head = 0;
        this->tail = 0;
    }
};
