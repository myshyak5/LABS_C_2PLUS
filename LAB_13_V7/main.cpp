#include <iostream>

class Parallelogram
{
    private:
        int _a, _b;
    public:
        Parallelogram(int a, int b): _a(a), _b(b) {}
        int getPerimeter()
        {
            return 2 * (_a + _b);
        }
        int getSquare()
        {
            return _a * _b;
        }
};
int main()
{
    int a, b;
    std::cin >> a >> b;

    Parallelogram par1(a, b);
    std::cout << "Perimetr: " << par1.getPerimeter() << std::endl;
    std::cout << "Square: " << par1.getSquare() << std::endl;

    return 0;
}