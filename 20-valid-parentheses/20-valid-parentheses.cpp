class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for(int i=1;i<s.size();i++){
            //cout<<"Noice"<<endl;
            if(s[i]==')'){
                if(!st.empty()&&st.top()=='(') st.pop();
                else st.push(s[i]);
            }else if(s[i]=='}'){
                if(!st.empty()&&st.top()=='{') st.pop();
                else st.push(s[i]);
            }else if(s[i]==']'){
                if(!st.empty()&&st.top()=='[') st.pop();
                else st.push(s[i]);
            }else{
                st.push(s[i]);
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};