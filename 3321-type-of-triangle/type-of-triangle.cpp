class Solution {
public:
    string triangleType(vector<int>& tri) {
        if(tri[0] + tri[1] <= tri[2] ||
            tri[1] + tri[2] <= tri[0] ||
            tri[2] + tri[0] <= tri[1] )return "none";
        if(tri[0]==tri[1] && tri[0]==tri[2])return "equilateral";
        else if(tri[0]==tri[1] || tri[0]==tri[2] || tri[1]==tri[2])return "isosceles";
        return "scalene";

    }
};