#include <iostream>

class BigInt {
	private:
		char m_value[1001] = {0};
		unsigned short m_size = 0;
	public:
		BigInt() = default;
		BigInt(const std::string& num) {
			m_size = num.length();
			for (int i = 0; i < m_size; i++) {
				m_value[i] = num[m_size - i - 1];
			}
		}
		BigInt& operator+=(const BigInt& other) {
			unsigned short max_size = std::max(m_size, other.m_size);
			bool carry = 0;
			for (unsigned short i = 0; i < max_size || carry; i++) {
				if (i == m_size) {
					m_size++;
				}
				int sum = carry;
				if (i < m_size) {
					sum += (m_value[i] - '0');
				}
				if (i < other.m_size) {
					sum += (other.m_value[i] - '0');
				}
				m_value[i] = (sum % 10) + '0';
				carry = sum / 10;
			}
			return *this;
		}
		BigInt operator+(const BigInt& other) {
			BigInt result(*this);
			result += other;
			return result;
		}
		BigInt& operator*=(const BigInt& other) {
			BigInt result;
			result.m_size = m_size + other.m_size;
			for (unsigned short i = 0; i < m_size; i++) {
				unsigned short carry = 0;
				for (unsigned short j = 0; j < other.m_size || carry; j++) {
					int product = (m_value[i] - '0') * (other.m_value[j] - '0') + carry;
					if ((i + j) >= result.m_size) {
						result.m_size++;
					}
					product += (result.m_value[i + j] - '0');
					result.m_value[i + j] = (product % 10) + '0';
					carry = product / 10;
				}
			}
			while (result.m_size > 1 && result.m_value[result.m_size - 1] == '0') {
				result.m_size--;
			}
			*this = result;
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
	BigInt x;
	BigInt y;
	std::cin >> x >> y;

	// x += y;
	// x *= y;
	BigInt z_plus = x + y;
	BigInt z_mult = x * y;
	std::cout << z_plus << std::endl;
	std::cout << z_mult << std::endl;
	// if (x < y) {
	// 	std::cout << "less" << std::endl;
	// }
	// if (x > y) {
	// 	std::cout << "bigger" << std::endl;
	// }
	// if (x == y) {
	// 	std::cout << "equals" << std::endl;
	// }
	// if (x != y) {
	// 	std::cout << "not equals" << std::endl;
	// }
	return 0;
}