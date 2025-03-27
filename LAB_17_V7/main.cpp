#include <iostream>

template <typename T = bool>
class VectorBool {
  private:
    uint8_t* m_arr;
    size_t m_bit;
    size_t m_cap;
    void NewTmp(size_t cap) {
      uint8_t* tmp = new uint8_t[cap];
      std::copy(m_arr, m_arr + ((m_bit + 7) / 8), tmp);
      delete[] m_arr;
      m_arr = tmp;
      m_cap = cap;
    }
    void set_bit(T value, size_t bit) {
      if (value) {
        m_arr[bit / 8] |= (1 << (bit % 8));
      }
      else {
        m_arr[bit / 8] &= ~(1 << (bit % 8));
      }
    }
  public:
    VectorBool(): m_arr(nullptr), m_bit(0), m_cap(0) {}
    VectorBool(size_t bit, T value): m_arr(new uint8_t[bit]), m_bit(bit), m_cap((bit + 7) / 8) {
      for (size_t i = 0; i < bit; i++) {
        if (value) {
          m_arr[i / 8] |= (1 << (i % 8));
        }
      }
    }
    ~VectorBool() {
      delete[] m_arr;
    }
    void push_back(T value) {
      if (m_bit >= (m_cap * 8)) {
        NewTmp((m_cap + 1) * 2);
      }
      set_bit(value, m_bit);
      m_bit++;
    }
    size_t size() {
      return m_bit;
    }
    void insert(size_t index, T value) {
      if (m_bit >= (m_cap * 8)) {
        NewTmp((m_cap + 1) * 2);
      }
      for (size_t i = m_bit; i > index; i--) {
        set_bit(((m_arr[(i - 1) / 8] & (1 << ((i - 1) % 8))) != 0), i);
      }
      set_bit(value, index);
      m_bit++;
    }
    void erase(size_t index) {
      for (size_t i = index; i < m_bit - 1; i++) {
        set_bit(((m_arr[(i + 1) / 8] & (1 << ((i + 1) % 8))) != 0), i);
      }
      m_bit--;
    }
    bool operator[](size_t index) {
      return (m_arr[index / 8] & (1 << (index % 8))) != 0;
    }
};
int main() {
  VectorBool<> vb;

  vb.push_back(true);
  vb.push_back(false);
  vb.push_back(false);
  vb.push_back(true);
  vb.push_back(false);
  for (size_t i = 0; i < vb.size(); i++) {
    std::cout << vb[i] << std::endl;
  }
  std::cout << std::endl;
  vb.insert(1, true);
  vb.insert(2, true);
  vb.erase(4);
  for (size_t i = 0; i < vb.size(); i++) {
    std::cout << vb[i] << std::endl;
  }

  return 0;
}