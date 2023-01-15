#include <iostream>
#include <vector>

int main()
{
    int n; std::cin >> n;
    // На всякий случай пусть будет больше памяти для суммы, т.к. большие числа
    unsigned long long sum = n * (n + 1) / 2;
    
    // Если сумма не делится на 3 - очевидно, ничего не выйдет
    if (sum % 3 != 0) std::cout << -1;
    else
    {
        std::vector<int> one, two, three;
        // goal1 = goal2 - сумма, которую нужно набрать в каждом множестве.
        // Мы не будем что-либо считать для третьего множества, т.к. каждое число
        // должно быть хоть где-то, и если i не будет подходить для 1 и 2, то
        // оно точно подойдет для 3 множества. Так мы сэкономим немного ресурсов.
        int goal1, goal2 = goal1 = sum / 3;
        
        // Идём с конца - только так множества отберутся так, как нам надо
        for (int i = n; i > 0; i--)
        {
            if (i <= goal1) one.push_back(i), goal1 -= i;
            else if (i <= goal2) two.push_back(i), goal2 -= i;
            else three.push_back(i);
        }
        
        // Вывод векторов (множеств)
        std::cout << one.size() << '\n';
        for (int& x : one) std::cout << x << ' ';
        std::cout << '\n' << '\n';
        
        std::cout << two.size() << '\n';
        for (int& x : two) std::cout << x << ' ';
        std::cout << '\n' << '\n';
        
        std::cout << three.size() << '\n';
        for (int& x : three) std::cout << x << ' ';
        std::cout << '\n' << '\n';
    }

    return 0;
}