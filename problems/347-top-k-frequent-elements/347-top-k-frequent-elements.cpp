#include <vector>
#include <algorithm>
#include <queue>
#include <concepts>
#include <iostream>

#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        if (nums.size() == 1)
        {
            return {nums[0]};
        }

        sort(nums.begin(), nums.end());

        int count = 1;

        priority_queue<pair<int, int>> pq;

        int i;
        for (i = 1; i < nums.size();)
        {
            if (nums[i] != nums[i - 1])
            {
                pq.push({count, nums[i - 1]});

                count = 1;

                ++i;
            }
            else
            {
                while (i < nums.size() && nums[i] == nums[i - 1])
                {
                    ++count;
                    ++i;
                }
            }
        }

        if (i == nums.size())
        {
            pq.push({count, nums[i - 1]});
        }

        vector<int> resul;

        for (int i = 0; i < k; ++i)
        {
            resul.push_back(pq.top().second);
            pq.pop();
        }

        return resul;
    }
};

class Solution2
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap;

        for (auto const &n : nums)
        {
            umap[n]++;
        }

        vector<pair<int, int>> vec(umap.begin(), umap.end());

        sort(vec.begin(), vec.end(), [](auto const &a, auto const &b)
             { return a.second > b.second; });

        vector<int> result;
        result.reserve(k);
        for (int i = 0; i < k; ++i)
        {
            result.push_back(vec[i].first);
        }
        return result;
    }

    template <
        std::random_access_iterator Iter,
        class Compare>
        requires std::sortable<Iter, Compare>
    static void sort(Iter first, Iter last, Compare comp)
    {
        if (first >= last - 1)
        {
            return;
        }

        Iter i = first, j = last - 1;

        while (i < j)
        {
            while (i < j && !comp(*j, *first))
            {
                --j;
            }

            while (i < j && comp(*i, *first))
            {
                ++i;
            }

            iter_swap(i, j);
        }

        iter_swap(i, first);

        sort(first, i, comp);
        sort(i + 1, last, comp);
    }
};

int main(int argc, char const *argv[])
{
    Solution2 slo;

    vector<int> nums{1, 2, 1, 2, 1, 2, 3, 1, 3, 2};

    auto result = slo.topKFrequent(nums, 2);

    for_each(result.begin(), result.end(), [](int a){
        cout << a << ' ';
    });
    return 0;
}
