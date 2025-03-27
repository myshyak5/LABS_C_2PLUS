#include <iostream>

class Parallelogram
{
    private:
        double _a, _b, _h;
    public:
        Parallelogram(double a, double b, double h): _a(a), _b(b), _h(h) {}
        double getPerimeter()
        {
            return 2 * (_a + _b);
        }
        double getSquare()
        {
            return _a * _h;
        }
};
int main()
{
    double a, b, h;
    std::cin >> a >> b >> h;

    Parallelogram par1(a, b, h);
    std::cout << "Perimetr: " << par1.getPerimeter() << std::endl;
    std::cout << "Square: " << par1.getSquare() << std::endl;

    return 0;
}
