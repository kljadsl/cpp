#include<iostream>
#include<vector>
#include<string>
using namespace std;
void helper(string &s,int index,vector<string> &ans,string path){
    if(index == s.size()){
        ans.push_back(path);
        return;
    }
    string no = path;
    helper(s,index+1,ans,no);
    string yes = path + s[index];
    helper(s,index+1,ans,yes);
}

int main(){
    string str("abcd");
    vector<string> res;
    string path("");
    helper(str,0,res,path);
    for(auto s : res){
        cout << s << endl;
    }
    return 0;
}
