#include <iostream>
#include <stdexcept>

template<typename T, unsigned short N, unsigned short M>
class Matrix {
private:
  T m_arr[3][3];
  unsigned short m_N;
  unsigned short m_M;
  void MatrixFill() {
    for (unsigned short i = 0; i < 3; i++) {
      for (unsigned short j = 0; j < 3; j++) {
        (*this)(i, j) = T();
      }
    }
  }
public:
  Matrix(): m_N(N), m_M(M) {
    MatrixFill();
  }
  template<unsigned short OTHER_N, unsigned short OTHER_M>
  Matrix(const Matrix<T, OTHER_N, OTHER_M>& other): m_N(OTHER_N), m_M(OTHER_M) {
    MatrixFill();
    for (unsigned short i = 0; i < 3; i++) {
      for (unsigned short j = 0; j < 3; j++) {
        (*this)(i, j) = other(i, j);
      }
    }
  }
  template<unsigned short OTHER_N, unsigned short OTHER_M>
  Matrix& operator=(const Matrix<T, OTHER_N, OTHER_M>& other) {
    MatrixFill();
    if (this != &other) {
      for (unsigned short i = 0; i < 3; i++) {
        for (unsigned short j = 0; j < 3; j++) {
          (*this)(i, j) = other(i, j);
        }
      }
    }
    m_N = OTHER_N;
    m_M = OTHER_M;
    return *this;
  }
  Matrix& operator+=(const Matrix& other) {
    for (unsigned short i = 0; i < 3; i++) {
      for (unsigned short j = 0; j < 3; j++) {
        (*this)(i, j) += other(i, j);
      }
    }
    return *this;
  }
  Matrix operator+(const Matrix& other) {
    Matrix result(*this);
    result += other;
    return result;
  }
  template<unsigned short OTHER_M>
  Matrix& operator*=(const Matrix<T, M, OTHER_M>& other) {
    Matrix<T, N, OTHER_M> result;
    for (unsigned short i = 0; i < N; i++) {
      for (unsigned short j = 0; j < OTHER_M; j++) {
        for (unsigned short k = 0; k < M; k++) {
          result(i, j) += (*this)(i, k) * other(k, j);
        }
      }
    }
    for (unsigned short i = 0; i < 3; i++) {
      for (unsigned short j = 0; j < 3; j++) {
        (*this)(i, j) = result(i, j);
      }
    }
    m_M = OTHER_M;
    return *this;
  }
  template<unsigned short OTHER_M>
  Matrix operator*(const Matrix<T, M, OTHER_M>& other) {
    Matrix result(*this);
    result *= other;
    return result;
  }
  Matrix& operator++() {
    for (unsigned short i = 0; i < N; i++) {
      for (unsigned short j = 0; j < M; j++) {
        (*this)(i, j)++;
      }
    }
    return *this;
  }
  T& operator()(unsigned short row, unsigned short col) {
    return m_arr[row][col];
  }
  const T& operator()(unsigned short row, unsigned short col) const {
    return m_arr[row][col];
  }
  T det() {
    if constexpr(N == M) {
      if (N == 1) {
        return m_arr[0][0];
      }
      else if (N == 2) {
        return m_arr[0][0] * m_arr[1][1] - m_arr[0][1] * m_arr[1][0];
      }
      else if (N == 3) {
        return m_arr[0][0] * (m_arr[1][1] * m_arr[2][2] - m_arr[1][2] * m_arr[2][1]) -
        m_arr[0][1] * (m_arr[1][0] * m_arr[2][2] - m_arr[1][2] * m_arr[2][0]) +
        m_arr[0][2] * (m_arr[1][0] * m_arr[2][1] - m_arr[1][1] * m_arr[2][0]);
      }
    }
    else {
      throw std::invalid_argument("detMatrix is unavailable");
    }
  }
  friend std::istream& operator>>(std::istream& in, Matrix& other) {
    for (unsigned short i = 0; i < N; i++) {
      for (unsigned short j = 0; j < M; j++) {
        in >> other.m_arr[i][j];
      }
    }
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const Matrix& other) {
    for (unsigned short i = 0; i < other.m_N; i++) {
      for (unsigned short j = 0; j < other.m_M; j++) {
        out << other.m_arr[i][j] << " ";
      }
      out << "\n";
    }
    return out;
  }
};
int main() {
  Matrix<int, 3, 2> mx1;
  std::cin >> mx1;
  std::cout << mx1 << std::endl;
  Matrix<int, 2, 2> mx3;
  std::cin >> mx3;
  std::cout << mx3 << std::endl;
  Matrix<int, 3, 2> mx2;
  mx2 = mx1;
  std::cout << ++mx2 << std::endl;
  try {
    // std::cout << mx1 + mx3 << std::endl;
    // mx1 += mx3;
    std::cout << mx1 * mx3 << std::endl;
    mx1 *= mx3;
    std::cout << mx1 << std::endl;
    std::cout << mx1(0, 0) << std::endl;
    std::cout << mx1.det() << std::endl;
  }
  catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
