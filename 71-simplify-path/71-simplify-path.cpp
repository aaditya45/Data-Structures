class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        for(int i=0;i<path.size();i++){
            if(path[i]=='/') continue;
            string s="";
            while(i<path.size()&&path[i]!='/'){
                s+=path[i];
                i++;
            }
            if(s==".."){
                if(!st.empty()) st.pop();
            }else if(s=="."){
                
            }else{
                st.push(s);
            }
        }
        string res="";
        if(st.empty()) return "/";
        while(!st.empty()){
            // res+='/';
            // res+=st.top();
            res.insert(0,"/"+st.top());
            st.pop();
        }
        return res;
    }
};