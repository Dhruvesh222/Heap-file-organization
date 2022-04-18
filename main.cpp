#include<bits/stdc++.h>
using namespace std;
int size_of_page;
vector<pair<vector<int>,int>> file;
void insert(int size,int key){
    for(auto it=file.begin();it!=file.end();it++){
        if(size+4<=it->second){
            it->first[0]++;
            it->second -= (size+4);
            it->first.push_back(key);
            return ;
        }
    }
    vector<int> v;
    v.push_back(1);
    v.push_back(key);
    file.push_back(make_pair(v,size_of_page-4-size-16));
}
void status(){
    cout<<file.size()<<" ";
    for(auto it=file.begin();it!=file.end();it++){
        cout<<it->first[0]<<" ";
    }
    cout<<"\n";
}
void search(int key){
    int n = file.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<=file[i].first[0];j++){
            if(file[i].first[j]==key){
                cout<<i<<" "<<j-1<<endl;
                return ;
            }
        }
    }
    cout<<-1<<" "<<-1<<endl;
    return ;
}
int main(){
    cin>>size_of_page;
    int size,key;
    int choice;
    cin>>choice;
    while(choice!=4){
        if(choice==1){
            cin>>size>>key;
            insert(size,key);
        }else if(choice==2){
            status();
        }else if(choice==3){
            cin>>key;
            search(key);
        }
        cin>>choice;
    }

    return 0;
}
