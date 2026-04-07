class Robot {
    int w, h;
    int curr = 0;
    int totalSteps;
    bool moved = false;

    vector<vector<int>> path;

public:
    Robot(int width, int height) {
        w = width;
        h = height;

        // Special case: single cell
        if (w == 1 && h == 1) {
            path.push_back({0, 0, 0});
            totalSteps = 1;
            return;
        }

        totalSteps = 2 * (w + h) - 4;

        // Bottom row (East)
        for (int i = 0; i < w; i++) {
            path.push_back({0, i, 0});
        }

        // Right column (North)
        for (int i = 1; i < h; i++) {
            path.push_back({1, w - 1, i});
        }

        // Top row (West)
        for (int i = w - 2; i >= 0; i--) {
            path.push_back({2, i, h - 1});
        }

        // Left column (South)
        for (int i = h - 2; i > 0; i--) {
            path.push_back({3, 0, i});
        }
    }

    void step(int num) {
        if (totalSteps == 1) return;

        moved = true;
        curr = (curr + num) % totalSteps;
    }

    vector<int> getPos() {
        return {path[curr][1], path[curr][2]};
    }

    string getDir() {
        // Special case: at origin AFTER movement
        if (moved && curr == 0) return "South";

        int d = path[curr][0];
        if (d == 0) return "East";
        if (d == 1) return "North";
        if (d == 2) return "West";
        return "South";
    }
};