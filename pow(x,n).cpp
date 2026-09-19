/*Описание задачи:
Необходимо реализовать функцию myPow(x, n), которая вычисляет число x в степени n. 
Функция должна поддерживать положительные, отрицательные и нулевые значения степени.
Решение:
вместо обычного умножения самого на себя n раз, дабы ускорить процесс, показатель 
степени уменьшается каждый раз в два раза, в случае когда степень не четная, 
основание умножается на результат, каждую итерацию основание возводится в квадрат и степень уменьшается в два раза
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long exponent = n;
    bool isNegative = exponent < 0;

    if (isNegative) {
        exponent = -exponent;
    }

    double result = 1.0;

    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= x;
        }

        x *= x;
        exponent /= 2;
    }

    if (isNegative) {
        result = 1.0 / result;
    }

    return result;
    }
};
