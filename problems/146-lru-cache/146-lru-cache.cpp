
#include <algorithm>
#include <condition_variable>
#include <cstdint>
#include <cstring>
#include <future>
#include <list>
#include <mutex>
#include <queue>
#include <thread>
#include <unordered_map>
#include <vector>

using namespace std;

class DlinkListNode {
public:
  DlinkListNode *prev;
  DlinkListNode *next;

  int key;
  int val;

  DlinkListNode() : key(0), val(0), prev(nullptr), next(nullptr) {}
  DlinkListNode(int key, int val)
      : key(key), val(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
public:
  int m_capacity;
  int m_size;

  unordered_map<int, DlinkListNode *> cache;

  DlinkListNode *head, *tail;

  LRUCache(int capacity) : m_capacity(capacity), m_size(0) {
    head = new DlinkListNode();
    tail = new DlinkListNode();

    head->next = tail;
    tail->prev = head;
  }

  int get(int key) {
    if (cache.find(key) == cache.end()) {
      return -1;
    }

    moveTohead(key);

    return cache[key]->val;
  }

  void put(int key, int value) {
    if (cache.find(key) != cache.end()) {
      auto node = cache[key];

      node->val = value;

      moveTohead(key);

      return;
    }

    addTohead(key, value);
    ++m_size;

    if (m_size > m_capacity) {
      DlinkListNode *old = removeTail();

      cache.erase(old->key);

      delete old;

      --m_size;
    }
  }

  DlinkListNode *removeTail() {
    DlinkListNode *node = tail->prev;

    node->prev->next = node->next;
    node->next->prev = node->prev;

    return node;
  }

  void addTohead(int key, int value) {
    DlinkListNode *newnode = new DlinkListNode(key, value);

    cache[key] = newnode;

    newnode->next = head->next;
    newnode->prev = head;

    head->next->prev = newnode;
    head->next = newnode;
  }

  DlinkListNode *removeNode(int key) {
    DlinkListNode *node = cache[key];

    node->prev->next = node->next;
    node->next->prev = node->prev;

    node->next = nullptr;
    node->prev = nullptr;

    return node;
  }

  void moveTohead(int key) {
    auto node = removeNode(key);

    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
  }
};


class Data {
public:
  int len;
  string data_;
};


void serialize(vector<Data> vec, char * buffer) {
  int total = 0;

  for (auto const &d : vec) {
    total += sizeof(int32_t);
    total += d.len;
  }

  buffer = new char[total];

  char *ptr = buffer;

  for (auto const &d :  vec) {
    memcpy(ptr, (int32_t)d.len, sizeof(uint32_t));
    ptr += sizeof(uint32_t);
    memcpy(void *dst, const void *src, size_t n)
  }
}
