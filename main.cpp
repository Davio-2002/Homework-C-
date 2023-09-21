#include <iostream>
#include <vector>

using vec_t = std::vector<int>;
using pair_t = std::pair<int, int>;

auto calculatePrefixSum(const vec_t& arr) -> vec_t {
    int n = arr.size();
    vec_t prefix_sum(n, 0);

    prefix_sum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefix_sum[i] = prefix_sum[i - 1] + arr[i];
    }

    return prefix_sum;
}

auto getRangeSum(const vec_t& vec, const std::vector<pair_t>& queries) -> vec_t {
    vec_t prefixSum{calculatePrefixSum(vec)};
    vec_t final_sum{};
    for(const auto& query : queries)
    {
        if (query.first == 0)
        {
            final_sum.push_back(prefixSum.at(query.second));
        } else {
            final_sum.push_back(prefixSum.at(query.second) - prefixSum.at(query.first - 1));
        }
    }
    return final_sum;
}

int main() {
    vec_t arr{1, 4, 5, 6, 8, 6, 10};
    std::vector<pair_t> ranges = {
        {1, 3},
        {1, 5},
        {2, 4},
        {0, 3}
    };

    vec_t finalSum = getRangeSum(arr, ranges);

    for(vec_t::iterator it = finalSum.begin(); it != finalSum.end(); ++it)
    {
        std::cout << *it << " ";
    }

    return 0;
}
