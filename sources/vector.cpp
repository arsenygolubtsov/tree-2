#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
    int *elements_ = nullptr;
    std::size_t size_ = 0;
    std::size_t capacity_ = 0;
}

vector_t::vector_t(vector_t const & other)
{
    size_ = other.size_;
    capacity_ = other.capacity_;
    elements_ = new int[capacity_];
    for(std::size_t i = 0; i < size_; ++i){
        elements_[i] = other.elements_[i];
    }
}

vector_t & vector_t::operator =(vector_t const & other)
{
    if(this != &other){
        delete [] elements_;
        size_ = other.size_;
        capacity_ = other.capacity_;
        elements_ = new int[capacity_];
        for(std::size_t i = 0; i < size_; ++i){
            elements_[i] = other.elements_[i];
        }
    }
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
bool success = true;
    if(size_ == other.size_ && capacity_ == other.capacity_){
        for(std::size_t i = 0; i < size_; ++i){
            if(elements_[i] != other.elements_[i]){
                success = false; break;
            }
        }
    }
	return success;
}

vector_t::~vector_t()
{
    delete[] elements_;
}

std::size_t vector_t::size() const
{
    return 0;
}

std::size_t vector_t::capacity() const
{
    return elements_[0];
}

void vector_t::push_back(int value)
{
    if(capacity_ == 0){
        capacity_ = 1;
        size_ = 1;
        elements_ = new int[capacity_];
        elements_[0] = value;
    }
    else{
        if(size_ == capacity_){
            int *massive;
            massive = new int[size_];
            for(std::size_t i = 0; i < size_; ++i){
                massive[i] = elements_[i];
            }
            delete [] elements_;
            capacity_ = 2 * capacity_;
            elements_ = new int[capacity_];
            for(std::size_t i = 0; i < size_; ++i){
                elements_[i] = massive[i];
            }
            delete [] massive;
            elements_[size_] = value;
            size_ ++;
        }
        else{
            elements_[size_] = value;
            size_ ++;
        }
    }
}

void vector_t::pop_back()
{
    size_ --;
    if(size_ == 0 || size_ * 4 == capacity_){
        int *massive;
        massive = new int[size_];
        for(std::size_t i = 0; i < size_; ++i){
            massive[i] = elements_[i];
        }
        delete [] elements_;
        capacity_ = capacity_ / 2;
        elements_ = new int[capacity_];
        for(std::size_t i = 0; i < size_; ++i){
            elements_[i] = massive[i];
        }
        delete [] massive;
    }        
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[0];
}

int vector_t::operator [](std::size_t index) const
{
	return 0;
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	bool success = true;
	if (lhs == rhs) {
		success = !success;
	}
	return success;
}
