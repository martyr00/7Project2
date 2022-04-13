#include <iostream>
#include <cmath>

using namespace std;

double calc(double x, int n) {
    double s = 0.0;
    double a = 1.0;
    double b = 1.0;
    while (n > 0) {
        n -= 1;
        s += a;
        a = -a * x * x / ((2 * b) * (b * 2 + 1));
        b++;
    }
    return s;
}

double calcY(double x, int n, double e) {
    double res = 0.0;
    int f = 0;
    double a = 1.0,
         count = 0.0,
         b = 1.0;

    while (n > 0) {
        n -= 1;
        f++;
        if (abs(a / f) > e) {
            a = -a * x * x / ((2 * b) * ( 2 * b + 1));
            count++;
            res += a;
            b++;
        }
    }

    std::cout << "The sum terms: " << count << " " << res << std::endl;
}

double calcL(double x) {
    if (x == 0.0) {
        std::cout << "None" << std::endl;
     } else {
        double res = (sin(x) / x);
        std::cout << "Result left side: " << res << std::endl;
    }

}

int main() {
    double x;
    int n;
    double e;

    cin >> x >> n >> e;

    double sum_slog = calc(x, n);
    std::cout << "The sum of all terms: " << sum_slog << std::endl;
    calcY(x, n, e);
    calcL(x);
}
