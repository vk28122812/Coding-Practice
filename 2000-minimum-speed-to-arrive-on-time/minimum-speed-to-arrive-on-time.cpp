class Solution {
public:
    bool isPossible(vector<int>& dist, double hour, int mid) {
        double hr = 0;
        for (int i = 0; i < dist.size(); i++) {
            double time = double(dist[i]) / double(mid);

            if (i < (dist.size() - 1)) {
                hr += ceil(time);

            } else {

                hr += time;
            }
        }
        return hr <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int low = 1, high = 1e8;

        int ans = -1;
        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (isPossible(dist, hour, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};