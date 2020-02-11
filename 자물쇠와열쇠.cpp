#include <string>
#include <vector>
#include <iostream>
using namespace std;
bool func(vector<vector<int>> lock)
{
    for(int i=lock.size()/3;i<lock.size()*2/3;i++)
    {
        for(int j=lock.size()/3;j<lock.size()*2/3;j++)
            if(lock[i][j]!=1)
                return false;
    }
    return true;
}
bool isPossible(vector<vector<int>> key,vector<vector<int>> lock)
{
    for(int i=lock.size()/3-key.size()+1;i<lock.size()-key.size();i++)
    {
        for(int j=lock.size()/3-key.size()+1;j<lock.size()-key.size();j++)
        {
            vector<vector<int>> lock_cpy = lock;
            for(int k=0;k<key.size();k++){
                for(int f=0;f<key.size();f++){
                    lock_cpy[i+k][j+f]+=key[k][f];}}
            if(func(lock_cpy))
                return true;
        }
    }
    return false;
}
vector<vector<int>> makeKey(vector<vector<int>> key)
{
    vector<vector<int>> new_key;
    for(int i=0;i<key.size();i++)
    {
        new_key.push_back(vector<int>());
        for(int j=key.size()-1;j>=0;j--)
        {
            new_key[i].push_back(key[j].at(i));
        }
    }
    return new_key;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    vector<vector<int>> key2,key3,key4,new_lock;
    key2=makeKey(key);
    key3=makeKey(key2);
    key4=makeKey(key3);
    for(int i=0;i<lock.size()*3;i++)
    {
        new_lock.push_back(vector<int>());
        for(int j=0;j<lock.size()*3;j++)
        {
            new_lock[i].push_back(0);
        }
    }

    for(int i=0;i<lock.size();i++)
    {
        for(int j=0;j<lock.size();j++)
        {
            new_lock[lock.size()+i][lock.size()+j]=lock[i][j];
        }
    }
    if(isPossible(key,new_lock)||isPossible(key2,new_lock)||isPossible(key3,new_lock)||isPossible(key4,new_lock))
        return true;

    return false;
}
