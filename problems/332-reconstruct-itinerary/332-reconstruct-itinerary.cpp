#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>> &tickets)
    {
        for (auto ticket : tickets)
        {
            // 相当于建立一个邻接表，记录起点终点对，并记录票数，因为同一类型的票可能有多个
            ticketsMap[ticket[0]][ticket[1]] += 1;
        }

        result.push_back("JFK");

        backtrace(tickets.size());

        return result;
    }

    bool backtrace(int ticketNums)
    {
        if (result.size() == ticketNums + 1)
        {
            return true;
        }

        auto lastPlace = result.back();

        for (auto &ticket : ticketsMap[lastPlace])
        {
            const string &airport = ticket.first;
            int &count = ticket.second;

            if (count > 0)
            {
                --count;

                result.push_back(airport);

                if (backtrace(ticketNums))
                {
                    return true;
                }

                result.pop_back();

                ++count;
            }
        }

        return false;
    }

    unordered_map<string, map<string, int>> ticketsMap;

    vector<string> result;
};