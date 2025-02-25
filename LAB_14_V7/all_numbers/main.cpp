#include <iostream>
#include <string>

class BigInt {
private:
  std::string m_value;
  size_t m_size;
  bool m_sign;
public:
  BigInt() : m_value("0"), m_size(1), m_sign(true) {}
  BigInt(const std::string& num) {
    if (num[0] == '-') {
      m_sign = false;
      m_value = num.substr(1);
    }
    else {
      m_sign = true;
      m_value = num;
    }
    m_size = m_value.length();
    std::reverse(m_value.begin(), m_value.end());
  }
  BigInt& operator+=(const BigInt& other) {
    if (m_value == "0") {
      *this = other;
      return *this;
    }
    if (other.m_value == "0") {
      return *this;
    }
    if (m_sign == other.m_sign) {
      size_t max_size = std::max(m_size, other.m_size);
      std::string result(max_size + 1, '0');
      bool carry = 0;
      for (size_t i = 0; i < max_size; i++) {
        int sum = carry;
        if (i < m_size) {
          sum += (m_value[i] - '0');
        }
        if (i < other.m_size) {
          sum += (other.m_value[i] - '0');
        }
        result[i] = (sum % 10) + '0';
        carry = sum / 10;
      }
      result[result.length() - 1] = carry + '0';
      while (result.length() > 1 && result[result.length() - 1] == '0') {
        result.pop_back();
      }
      m_value = result;
      m_size = result.length();
    }
    else {
      BigInt h_result(other);
      if (!m_sign) {
        m_sign = true;
        h_result -= *this;
        *this = h_result;
      }
      else {
        h_result.m_sign = true;
        *this -= h_result;
      }
    }
    return *this;
  }
  BigInt operator+(const BigInt& other) {
    BigInt result(*this);
    result += other;
    return result;
  }
  BigInt& operator-=(const BigInt& other) {
    if (m_value == "0") {
      *this = other;
      m_sign = !other.m_sign;
      return *this;
    }
    if (other.m_value == "0") {
      return *this;
    }
    if (m_sign == other.m_sign) {
      BigInt big(*this);
      BigInt small(other);
      if (big < small) {
        std::swap(big, small);
      }
      size_t max_size = std::max(small.m_size, big.m_size);
      std::string result(max_size, '0');
      bool carry = 0;
      for (size_t i = 0; i < max_size; i++) {
        int sub = 0 - carry;
        if (i < small.m_size) {
          sub -= (small.m_value[i] - '0');
        }
        if (i < big.m_size) {
          sub += (big.m_value[i] - '0');
        }
        if (sub < 0) {
          sub += 10;
          carry = 1;
        }
        else {
          carry = 0;
        }
        result[i] = (sub % 10) + '0';
      }
      if (*this < other) {
        m_sign = false;
      }
      while (result.length() > 1 && result[result.length() - 1] == '0') {
        result.pop_back();
      }
      m_value = result;
      m_size = result.length();
    }
    return *this;
  }
  BigInt& operator*=(const BigInt& other) {
    if (m_value == "0" || other.m_value == "0") {
      *this = BigInt("0");
      return *this;
    }
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
    m_value = result;
    m_size = result.length();
    m_sign = (m_sign == other.m_sign);
    return *this;
  }
  BigInt operator*(const BigInt& other) {
    BigInt result(*this);
    result *= other;
    return result;
  }
  bool operator<(const BigInt& other) {
    if (m_sign != other.m_sign) {
      return !m_sign;
    }
    if ((m_size != other.m_size) && !m_sign) {
      return (m_size > other.m_size);
    }
    else if ((m_size != other.m_size) && m_sign) {
      return (m_size < other.m_size);
    }
    for (int i = m_size - 1; i >= 0; i--) {
      if ((m_value[i] != other.m_value[i]) && !m_sign) {
        return (m_value[i] > other.m_value[i]);
      }
      else if ((m_value[i] != other.m_value[i]) && m_sign) {
        return (m_value[i] < other.m_value[i]);
      }
    }
    return false;
  }
  bool operator>(const BigInt& other) {
    if (m_sign != other.m_sign) {
      return m_sign;
    }
    if ((m_size != other.m_size) && !m_sign) {
      return (m_size < other.m_size);
    }
    else if ((m_size != other.m_size) && m_sign) {
      return (m_size > other.m_size);
    }
    for (int i = m_size - 1; i >= 0; i--) {
      if ((m_value[i] != other.m_value[i]) && !m_sign) {
        return (m_value[i] < other.m_value[i]);
      }
      else if ((m_value[i] != other.m_value[i]) && m_sign){
        return (m_value[i] > other.m_value[i]);
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
    return !(*this == other);
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
  if (!other.m_sign) {
    out << "-";
  }
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