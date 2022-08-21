/*
    2383. Minimum Hours of Training to Win a Competition :-

    LINK:   https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
*/

#include <iostream>
#include <vector>
using namespace std;

/*
    2383. Minimum Hours of Training to Win a Competition :-

    LINK:   https://leetcode.com/problems/minimum-hours-of-training-to-win-a-competition/
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int> &energy, vector<int> &experience)
    {
        int n = energy.size();

        // To Calculate Additional Energy
        int additionalEnergy = 0;

        for (int i = 0; i < n; i++)
        {
            if (initialEnergy <= energy[i])
            {
                additionalEnergy = additionalEnergy + energy[i] - initialEnergy + 1;
                initialEnergy = energy[i] + 1;
            }

            initialEnergy = initialEnergy - energy[i];
        }

        // To Calculate Additional Experience
        int additionalExperience = 0;

        for (int i = 0; i < n; i++)
        {
            if (initialExperience <= experience[i])
            {
                additionalExperience = additionalExperience + experience[i] - initialExperience + 1;
                initialExperience = experience[i] + 1;
            }

            initialExperience = initialExperience + experience[i];
        }

        int totalAdditionalHours = (additionalEnergy + additionalExperience);
        return totalAdditionalHours;
    }
};