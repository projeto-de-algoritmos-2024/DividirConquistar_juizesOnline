#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return aux1(nums, 0, nums.size() - 1);
    }

    int aux1(vector<int> &nums, int esq, int dir)
    {
        if (esq == dir)
            return nums[esq];

        int meio = esq + (dir - esq) / 2;
        int esqMax = aux1(nums, esq, meio);
        int dirMax = aux1(nums, meio + 1, dir);
        int meioMax = aux2(nums, esq, meio, dir);

        return max({esqMax, dirMax, meioMax});
    }

    int aux2(vector<int> &nums, int esq, int meio, int dir)
    {
        int somaEsq = INT_MIN;
        int soma = 0;
        for (int i = meio; i >= esq; i--)
        {
            soma += nums[i];
            if (soma > somaEsq)
            {
                somaEsq = soma;
            }
        }

        int somaDir = INT_MIN;
        soma = 0;
        for (int i = meio + 1; i <= dir; i++)
        {
            soma += nums[i];
            if (soma > somaDir)
            {
                somaDir = soma;
            }
        }

        return somaEsq + somaDir;
    }
};
