#include <iostream>
#include <map>

// Будем использовать разложение на простые делители
// n = П(p{i}^k{i}), n_of_divs = П(k{i}+1)
int countDivs(int n)
{
    // Возьмем первые 24 простых делителя в надежде, что этого точно будет достаточно
    int primes[24] = {2, 3, 5, 7, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    std::map<int, int> primeDivs;  // <Делитель, его степень>
    while (n != 1)
    {
        bool found = false;
        for (int& prime : primes)
        {
            if (n % prime == 0)
            {
                ++primeDivs[prime];
                n /= prime;
                found = true;
                break;
            }
        }
        // Если прошли весь цикл и ничего не нашли, то скорее всего это
        // простое число, а значит, у него всего 2 делителя и нам оно не нужно
        // в любом случае.
        if (!found) return -1;
    }

    int res = 1;
    for (auto& item : primeDivs)
        res *= item.second + 1;

    return res;
}


int main()
{
    int n; std::cin >> n;
    if (n == 1 || n == 2) std::cout << n << '\n' << n;
    else
    {
        int maxN, maxDivs = 0;
        for (int i = 3; i <= n; i++)
        {
            int iDivs = countDivs(i);
            if (iDivs >= maxDivs) maxDivs = iDivs, maxN = i;
        }
        std::cout << maxN << '\n' << maxDivs;
    }

    return 0;
}