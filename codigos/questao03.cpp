#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void mergeAndCount(vector<pair<int, int>> &nums, vector<int> &contagem, int esq, int meio, int dir)
    {
        vector<pair<int, int>> aux(dir - esq + 1);
        int e = esq;
        int m = meio + 1;
        int i = 0;
        int contaMenor = 0;

        while (e <= meio && m <= dir)
        {
            if (nums[e].first <= nums[m].first)
            {
                contagem[nums[e].second] += contaMenor;
                aux[i++] = nums[e++];
            }
            else
            {
                contaMenor++;
                aux[i++] = nums[m++];
            }
        }

        while (e <= meio)
        {
            contagem[nums[e].second] += contaMenor;
            aux[i++] = nums[e++];
        }

        while (m <= dir)
        {
            aux[i++] = nums[m++];
        }

        for (int j = 0; j < aux.size(); j++)
        {
            nums[esq + j] = aux[j];
        }
    }

    void mergeSort(vector<pair<int, int>> &nums, vector<int> &contagem, int esq, int dir)
    {
        if (esq >= dir)
            return;
        int meio = esq + (dir - esq) / 2;

        mergeSort(nums, contagem, esq, meio);
        mergeSort(nums, contagem, meio + 1, dir);
        mergeAndCount(nums, contagem, esq, meio, dir);
    }

    vector<int> countSmaller(vector<int> &nums)
    {
        int n = nums.size();
        vector<pair<int, int>> valorIndice;

        for (int i = 0; i < n; i++)
        {
            valorIndice.emplace_back(nums[i], i);
        }

        vector<int> contagem(n, 0);

        mergeSort(valorIndice, contagem, 0, n - 1);

        return contagem;
    }
};