//DISCLAIMER : 
// I was not able to learn sufficient rust needed to implement the given question 
// so I am submitting the c++ code that I wrote.  
// My most of the time got spent in understanding the syntax itself and its application in the real - world
//Please do try to consider my application

#include<iostream>
#include<vector>
using namespace std;
int bonus1(int arr[10][6],int over){
    for(int i=0;i<6;i++){
        if(arr[over][i]<4) {
            return 0;
        }
    }
    return 1;
}
int bonus2(int arr[10][6],int over){
    if((arr[over][0]==6 && arr[over][1]==6)){
        return 2;
    }
    return 0;
}
int bonus3(int arr[10][6],int over){
    if((arr[over][4]==6 && arr[over][5]==6)){
        return 3;
    }
    return 0;
}

int maiden(int arr[10][6],int over){
    for(int i=0;i<6;i++){
        if(arr[over][i]!=0) return 0;
    }
    return 4;
}
int main(){
    int overs[10][6];
    int max[10];
    int score=0;
    for(int i=0;i<10;i++){
        max[i]=0;
        for(int j=0;j<6;j++){
            cin>>overs[i][j];
            score+=overs[i][j];
            if(overs[i][j]>max[i])max[i]=overs[i][j];
        }
    }
    int bonus[10]={0};
    vector<int> v;
    for(int i=0;i<10;i++){
        if(maiden(overs,i)==3){
            bonus[i]=3;
            bonus[i+1]=0;
            i++;
        }
        else if(max[i]>4){
        if(bonus1(overs,i)==1){
            bonus[i]=1;

        }
        else{
            bonus[i]=bonus2(overs,i)+bonus3(overs,i);
        }
        }
        switch(bonus[i]){
            case 1:{
                for(int j=i+1;j<i+3&&j<10;j++){
                    for(int k=0;k<6;k++){
                    score+=overs[j][k];
                    }
                    v.push_back(j);
                }
                break;   
            }

            case 2:{
                v.push_back(0-i);
                for(int j=3;j<6;j++){
                    score+=overs[i][j];
                }
                break;
            }
            case 3:{
                for(int j=0;j<6 && i!=9;j++){
                    score+=overs[i+1][j];
                    v.push_back(i+1);
                }
                
                break;
            }
            case 5:{
               for(int j=3;j<6;j++){
                    score+=overs[i][j];
                }
                for(int j=0;j<6 && i!=9;j++){
                    score+=overs[i+1][j];
                    v.push_back(i+1);
                }
                v.push_back(0-i);
                
                break;
            }
        }
    }
    for(int i=0;i<10;i++){
        int flag=0;
        for(int j=0;j<v.size();j++){
            if(v[j]==i){
                flag=1;
                break;
            }
        }
        for(int j=0;j<6;j++){
            if(flag==1){
                if(overs[i][j]>=4)cout<<"*"<<overs[i][j]<<"x2 ";
                else{
                    cout<<' '<<overs[i][j]<<"x2 ";
                }
            }
            else{
                if(overs[i][j]>=4)cout<<"*"<<overs[i][j]<<" ";
                else{
                    cout<<' '<<overs[i][j]<<" ";
                }
            }
       
        }
        cout<<'\n';
    }
    if(bonus[8]==1|| bonus[9]==3){
        int extraOver[6];
        for(int i=0;i<6;i++){
           cin>>extraOver[i];
           score+=2*extraOver[i];
           if(extraOver[i]>=4)cout<<"*"<<extraOver[i]<<"x2 ";
           else cout<<' '<<extraOver[i]<<"x2 ";
        }
        cout<<'\n';
    }
    else if(bonus[9]==1){
        int extra1[6],extra2[6];
        for(int i=0;i<6;i++){
           cin>>extra1[i];
           score+=2*extra1[i];
           if(extra1[i]>=4)cout<<"*"<<extra1[i]<<"x2 ";
           else cout<<' '<<extra1[i]<<"x2 ";
        }
        cout<<'\n';
        for(int i=0;i<6;i++){
           cin>>extra2[i];
           score+=2*extra2[i];
           if(extra2[i]>=4)cout<<"*"<<extra2[i]<<"x2 ";
           else cout<<' '<<extra2[i]<<"x2 ";
        }

       cout<<'\n';
    }
    cout<<score<<'\n';
    return 0;
}
