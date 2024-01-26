#include "ulliststr.h"
#include <stdexcept>

#define ARRSIZE 10

ULListStr::ULListStr()
{
  head_ = nullptr;
  tail_ = nullptr;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

size_t ULListStr::size() const
{
  return size_;
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

void ULListStr::addBack(const std::string& val)
{
  if (empty()) {
    head_ = new Item();
    head_->val[0] = val;
    head_->first = 0;
    head_->last = 1;
    tail_ = head_;
  } else {
    if (tail_->last < ARRSIZE) {
      tail_->val[tail_->last] = val;
      ++tail_->last;
    } else {
      Item* newItem = new Item();
      newItem->val[0] = val;
      newItem->first = 0;
      newItem->last = 1;
      tail_->next = newItem;
      newItem->prev = tail_;
      tail_ = newItem;
    }
  }
  ++size_;
}

void ULListStr::push_back(const std::string& val)
{
  addBack(val);
}

void ULListStr::pop_back()
{
  if (empty()) {
    throw std::out_of_range("pop_back() on an empty list");
  }

  --size_;

  if (tail_->last > tail_->first + 1) {
    --tail_->last;
  } else {
    if (tail_ == head_ && head_->last - head_->first == 1) {
      delete head_;
      head_ = tail_ = nullptr;
      return;
    }

    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = nullptr;
  }
}

void ULListStr::push_front(const std::string& val)
{
  if (empty() || head_->first == 0) {
    Item* newItem = new Item();
    newItem->val[ARRSIZE - 1] = val;
    newItem->first = ARRSIZE - 1;
    newItem->last = ARRSIZE;
    
    if (empty()) {
      head_ = tail_ = newItem;
    } else {
      newItem->next = head_;
      head_->prev = newItem;
      head_ = newItem;
    }
  } else {
    --(head_->first);
    head_->val[head_->first] = val;
  }

  ++size_;
}


void ULListStr::pop_front()
{
  if (empty()) {
    throw std::out_of_range("pop_front() on an empty list");
  }

  --size_;

  if (head_->first + 1 < head_->last) {
    ++(head_->first);
  } else {
    Item* temp = head_->next;
    delete head_;
    head_ = temp;

    if (head_ != nullptr) {
      head_->prev = nullptr;
    } else {
      tail_ = nullptr;
    }
  }
}

std::string const & ULListStr::back() const
{
  if (empty()) {
    throw std::out_of_range("back() on an empty list");
  }
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const
{
  if (empty()) {
    throw std::out_of_range("front() on an empty list");
  }
  return head_->val[head_->first];
}

void ULListStr::set(size_t pos, const std::string& val)
{
  std::string* ptr = getValAtLoc(pos);
  if (ptr == nullptr) {
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t pos)
{
  std::string* ptr = getValAtLoc(pos);
  if (ptr == nullptr) {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t pos) const
{
  std::string* ptr = getValAtLoc(pos);
  if (ptr == nullptr) {
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while (head_ != nullptr) {
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = nullptr;
  size_ = 0;
}

std::string* ULListStr::getValAtLoc(size_t loc) const
{
  if (loc >= size_) {
    return nullptr;
  }

  Item* curr = head_;
  size_t remaining = loc;

  while (remaining >= curr->last - curr->first) {
    remaining -= curr->last - curr->first;
    curr = curr->next;
  }

  return &(curr->val[curr->first + remaining]);
}
