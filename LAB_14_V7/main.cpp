#include <iostream>
#include <string>

class BigInt {
  private:
    std::string m_value = "0";
    size_t m_size = 1;
  public:
    BigInt() = default;
    BigInt(const std::string& num) : m_value(num), m_size(num.length()) {
      std::reverse(m_value.begin(), m_value.end());
    }
    BigInt& operator+=(const BigInt& other) {
      size_t max_size = std::max(m_size, other.m_size);
      std::string result(max_size + 1, '0');
      bool carry = 0;
      for (size_t i = 0; i < max_size; i++) {
        int sum = carry;
        if (i < m_size)
        {
          sum += (m_value[i] - '0');
        }
        if (i < other.m_size)
        {
          sum += (other.m_value[i] - '0');
        }
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
      }
      result[result.length() - 1] = carry + '0';
      while (result.length() > 1 && result[result.length() - 1] == '0') {
        result.pop_back();
      }
      m_size = result.length();
      m_value = result;
      return *this;
    }
    BigInt operator+(const BigInt& other) {
      BigInt result(*this);
      result += other;
      return result;
    }
    BigInt& operator*=(const BigInt& other) {
      size_t result_size = m_size + other.m_size;
      std::string result(result_size, '0');
      for (size_t i = 0; i < m_size; i++) {
        int carry = 0;
        for (size_t j = 0; j < other.m_size; j++) {
          int product = (m_value[i] - '0') * (other.m_value[j] - '0') + carry + (result[i + j] - '0');
          carry = product / 10;
          result[i + j] = (product % 10) + '0';
        }
        result[i + other.m_size] += carry;
      }
      while (result.length() > 1 && result[result.length() - 1] == '0') {
        result.pop_back();
      }
      m_size = result.length();
      m_value = result;
      return *this;
    }
    BigInt operator*(const BigInt& other) {
      BigInt result(*this);
      result *= other;
      return result;
    }
    bool operator<(const BigInt& other) {
      if (m_size != other.m_size) {
        return m_size < other.m_size;
      }
      for (int i = m_size - 1; i >= 0; i--)
      {
        if (m_value[i] != other.m_value[i]) {
          return m_value[i] < other.m_value[i];
        }
      }
      return false;
    }
    bool operator>(const BigInt& other) {
      if (m_size != other.m_size) {
        return m_size > other.m_size;
      }
      for (int i = m_size - 1; i >= 0; i--)
      {
        if (m_value[i] != other.m_value[i]) {
          return m_value[i] > other.m_value[i];
        }
      }
      return false;
    }
    bool operator>=(const BigInt& other) {
      return !(*this < other);
    }
    bool operator<=(const BigInt& other) {
      return !(*this > other);
    }
    bool operator==(const BigInt& other) {
      return !(*this > other) && !(*this < other);
    }
    bool operator!=(const BigInt& other) {
      return !(*this==other);
    }
    friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
  };
std::istream& operator>>(std::istream& in, BigInt& other) {
  std::string s;
  in >> s;
  other = BigInt(s);
  return in;
}
std::ostream& operator<<(std::ostream& out, const BigInt& other) {
  for (int i = other.m_size - 1; i >= 0; i--) {
    out << other.m_value[i];
  }
  return out;
}
int main() {
  BigInt x, y;
  std::cin >> x >> y;

  BigInt z_plus = x + y;
  BigInt z_mult = x * y;

  std::cout << "Sum: " << z_plus << std::endl;
  std::cout << "Product: " << z_mult << std::endl;

  if (x < y) {
    std::cout << "x < y" << std::endl;
  }
  if (x > y) {
    std::cout << "x > y" << std::endl;
  }
  if (x <= y) {
    std::cout << "x <= y" << std::endl;
  }
  if (x >= y) {
    std::cout << "x >= y" << std::endl;
  }
  if (x == y) {
    std::cout << "x == y" << std::endl;
  }
  if (x != y) {
    std::cout << "x != y" << std::endl;
  }
  return 0;
}
