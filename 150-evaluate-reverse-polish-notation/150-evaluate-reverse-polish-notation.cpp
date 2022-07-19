class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        
        for(int i=0;i<tokens.size();i++){
            int res=0;
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int a=stoi(st.top());
                st.pop();
                int b=stoi(st.top());
                st.pop();
                if(tokens[i]=="+") res+=((a)+(b));
                else if(tokens[i]=="-") res=((b)-(a));
                else if(tokens[i]=="*") res=((a)*(b));
                else if(tokens[i]=="/") res=((b)/(a));
                st.push(to_string(res));
            }else{
                st.push(tokens[i]);
            }
            
        }
        
        return stoi(st.top());
    }
};