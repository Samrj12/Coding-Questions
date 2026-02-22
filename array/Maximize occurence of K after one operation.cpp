int maxFound(vector<int> &nums, int k)
    {
        int totalKs = 0;
        for (int i : nums)
            if (i == k)
                totalKs++;

        unordered_map<int, int> currentGain;
        // minBalance[x] = the lowest balance[x] has ever reached
        unordered_map<int, int> kAtLastSeen;

        int currK = 0;
        int mxGain = 0;

        for (int i : nums)
        {
            if (i == k)
            {
                currK++;
            }
            else
            {
                int ksPassed = currK - kAtLastSeen[i];
                currentGain[i] = max(0, currentGain[i] - ksPassed) + 1;
                kAtLastSeen[i] = currK;
                mxGain = max(mxGain, currentGain[i]);
            }
        }
        return currK + mxGain;
    }
