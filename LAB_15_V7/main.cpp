#include <iostream>

class MyVector {
  private:
    int* m_arr;
    size_t m_size;
    size_t m_cap;
    void NewTmp(size_t cap) {
      int* tmp = new int[cap];
      std::copy(m_arr, m_arr + m_size, tmp);
      delete[] m_arr;
      m_arr = tmp;
      m_cap = cap;
    }
  public:
    MyVector(): m_arr(nullptr), m_size(0), m_cap(0) {}
    MyVector(size_t size, int value): m_arr(new int[size]), m_cap(size), m_size(size) {
      std::fill(m_arr, m_arr + size, value);
    }
    MyVector(const MyVector& other): m_size(other.m_size), m_cap(other.m_cap) {
      m_arr = new int[m_cap];
      std::copy(other.m_arr, other.m_arr + other.m_size, m_arr);
    }
    ~MyVector() {
      delete[] m_arr;
    }
    MyVector& operator=(const MyVector& other) {
      if (this != &other) {
        m_size = other.m_size;
        m_cap = other.m_cap;
        int* tmp = new int[m_cap];
        std::copy(other.m_arr, other.m_arr + other.m_size, m_arr);
        delete[] m_arr;
        m_arr = tmp;
      }
      return *this;
    }
    void resize(size_t cap) {
      reserve(cap);
      m_size = cap;
    }
    void reserve(size_t cap) {
      if (m_cap < cap) {
        NewTmp(cap);
      }
    }
    void shrink_to_fit() {
      NewTmp(m_size);
    }
    int& front() {
      if (m_size == 0) {
        throw;
      }
      return m_arr[0];
    }
    int& back() {
      if (m_size == 0) {
        throw;
      }
      return m_arr[m_size - 1];
    }
    size_t size() {
      return m_size;
    }
    bool empty() {
      return (m_size == 0);
    }
    size_t capacity() {
      return m_cap;
    }
    void push_back(int value) {
      if (m_size == m_cap) {
        reserve((m_cap + 1) * 2);
      }
      m_arr[m_size] = value;
      m_size++;
    }
    void insert(size_t index, int value) {
      if (m_size == m_cap) {
        reserve((m_cap + 1) * 2);
      }
      for (size_t i = m_size; i > index; i--) { 
        m_arr[i] = m_arr[i - 1];
      }
      m_arr[index] = value;
      m_size++;
    }
    void erase(size_t index) {
      for (size_t i = index; i < m_size - 1; i++) {
        m_arr[i] = m_arr[i + 1];
      }
      m_size--;
    }
    int& operator[](size_t index) {
      if (m_size == 0) {
        throw;
      }
      return m_arr[index];
    }
};

int main() {
  MyVector mas;
  //mas.reserve(2000);
  for (int i = 0; i < 100; i++) {
    mas.push_back(i);
    std::cout << mas.size() << " " << mas.capacity() << std::endl;
  }
  mas.shrink_to_fit();
  std::cout << mas.size() << " " << mas.capacity() << std::endl;
  std::cout << mas.empty() << std::endl;
  std::cout << mas.size() << std::endl;
  std::cout << mas.front() << " " << mas.back() << std::endl;
  mas.insert(0, 12);
  std::cout << mas[0] << std::endl;
  mas.resize(6);
  for (int i = 0; i < mas.size(); i++) {
    std::cout << mas[i] << " ";
  }
  std::cout << std::endl;
  mas.erase(4);
  for (int i = 0; i < mas.size(); i++) {
    std::cout << mas[i] << " ";
  }
  return 0;
}