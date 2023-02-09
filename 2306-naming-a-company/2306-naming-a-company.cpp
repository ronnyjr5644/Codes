class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        //naive
//         set<string>st(ideas.begin(),ideas.end());
//        vector<string>idea(st.begin(),st.end());
        
//         vector<pair<string,string>>res;
//         for(int i=0;i<idea.size();i++){
//             for(int j=i+1;j<idea.size();j++){
//                 if(i==j){
//                     continue;
//                 }
//                 else{
//                     res.push_back(make_pair(idea[i],idea[j]));
                    
//                 }
//             }
//         }
    
//         int x=0;
//        for(auto it:res){
//             string a=it.first;
//            string b=it.second;
//            string c;
//            c=c+b[0];
//            string d;
//            d=d+a[0];
//            for(int i=1;i<a.size();i++){
//                c=c+a[i];
//            }
//            for(int i=1;i<b.size();i++){
//                d=d+b[i];
//            }
           
          
              
//            int counter1=0;
//            int counter2=0;
//            for(int i=0;i<idea.size();i++){
//                if(idea[i]==c){
//                    counter1=1;
//                }
//                if(idea[i]==d){
//                    counter2=1;
//                }
//            }
//            if(counter2==0 && counter1==0){
              
//                x++;
//                x++;
//            }
//        }
//         return x;
        vector<unordered_set<string>> groups(26);
        for (auto &idea : ideas)
            groups[idea[0] - 'a'].insert(idea.substr(1));
        
        long long numOfNames = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = i + 1; j < 26; ++j) {
                int numOfSuffixes = 0;
                for (auto &idea : groups[i])
                    numOfSuffixes += groups[j].count(idea);
                
                numOfNames += 2LL * (groups[i].size() - numOfSuffixes) * (groups[j].size() - numOfSuffixes);
            }
        }

        return numOfNames;
    }
};