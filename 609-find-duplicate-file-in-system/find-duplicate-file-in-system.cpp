class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        
        unordered_map<string,vector<string>> mp;

        for(string&p : paths){
            string dir = "";

            int idx = 0;

            while(idx<p.size() && p[idx] != ' '){
                dir.push_back(p[idx]);
                idx++;
            }

            idx++;

            while(idx<p.size()){
                string fileName = "";
                while(idx<p.size() && p[idx] != '(' ){
                    fileName.push_back(p[idx]);
                    idx++;
                }

                idx++;

                string content = "";
                while(idx<p.size() && p[idx] != ')'){
                    content.push_back(p[idx]);
                    idx++;
                }
                idx+=2;
                mp[content].push_back(dir+"/"+fileName);
            }
        }
        vector<vector<string>> ans;
        for(auto i:mp){
            if(i.second.size()>1){ans.push_back(i.second);}
        }
        return ans;
    }
};