// Given a list of activities with their start and end times, select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Activity
{
    int start, end;
};

bool compareActivities(const Activity &a1, const Activity &a2)
{
    return a1.end < a2.end;
}

int maximumActivities(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compareActivities);

    int count = 1;
    int currentEnd = activities[0].end;

    for (int i = 1; i < activities.size(); ++i)
    {
        if (activities[i].start >= currentEnd)
        {
            count++;
            currentEnd = activities[i].end;
        }
    }

    return count;
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    cout << "Enter the start and end times of each activity: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> activities[i].start >> activities[i].end;
    }

    cout << "Maximum number of activities that can be performed: " << maximumActivities(activities);

    return 0;
}