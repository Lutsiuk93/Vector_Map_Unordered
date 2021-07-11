#include <iostream>
#include <random>
#include <array>
#include <map>
#include <unordered_map>
#include <chrono>

std::chrono::duration<int64_t, std::nano> toVector(const std::vector<int>& V)
    {
    std::vector<int> V1;

    auto start = std::chrono::system_clock::now();
    for (int number : V)
        {
        V1.push_back(number);
        }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<int64_t, std::nano> time = end - start;
    return time;

    }

std::chrono::duration<int64_t, std::nano> toMap(const std::vector<int>& V)
    {
    std::map<int, int> M;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < V.size(); i++)
        {
        if (V[i] == 1)
            {
            M[i] = V[i];
            }
        }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<int64_t, std::nano> time = end - start;
    return time;
    }

std::chrono::duration<int64_t, std::nano> toUMap(const std::vector<int>& V)
    {
    std::unordered_map<int, int> M;

    auto start = std::chrono::system_clock::now();
    for (int i = 0; i < V.size(); i++)
        {
        if (V[i] == 1)
            {
            M[i] = V[i];
            }
        }
    auto end = std::chrono::system_clock::now();

    std::chrono::duration<int64_t, std::nano> time = end - start;
    return time;
    }

int main()
    {
    std::vector<int> V;
    double count_0 = 500;
    double count_1 = 500;

    for (int i = 0; i <= count_0; i++)
        {
        V.push_back(0);
        };
    for (int i = 0; i <= count_1; i++)
        {
        V.push_back(1);
        }

    while (true)
        {
        //or (toUMap(V).count() < toVector(V).count())
        if (toMap(V).count() < toVector(V).count())
            {
            std::cout << "1 - " << count_1 / count_0 * 100 << "%" << " count_0 : " << count_0 << " count_1 : " << count_1;
            return 0;

            }
        else
            {
            V.push_back(0);
            count_0++;
            }
        }
    }