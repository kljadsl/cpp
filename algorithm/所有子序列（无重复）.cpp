#include<iostream>
#include<set>
#include<string>
using namespace std;
void helper(string &s,int index,set<string> &ans,string path){
    if(index == s.size()){
        ans.insert(path);
        return;
    }
    string no = path;
    helper(s,index+1,ans,no);
    string yes = path + s[index];
    helper(s,index+1,ans,yes);
}

int main(){
    string str("aaaa");
    set<string> res;
    string path("");
    helper(str,0,res,path);
    for(auto s : res){
        cout << s << endl;
    }
    return 0;
}
