class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) 
    {
        queue<int> Q;
        stack<int> St;
        int cnt = 0;
        int n = students.size(),m=sandwiches.size();
        for(int i = 0;i < n; i++){
            Q.push(students[i]);
        }
        int i = 0; 
        while (Q.size() > 0 && cnt != Q.size())
        {
            if(Q.front() == sandwiches[i]){
                cnt = 0;
                Q.pop();
                i++;
            }
            else{
                Q.push(Q.front());
                Q.pop();
                cnt++;
            }
        }
        return Q.size();
    }
};