#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

bool canCompleteAllCourses(int n, vector<vector<int> > pre){
    unordered_map<int, vector<int> > graph;
    queue<int> sources;
    vector<int> inDegree(n, 0);
    for(auto coursePair : pre){
        graph[coursePair[1]].push_back(coursePair[0]);
        inDegree.at(coursePair[0])++;
    }
    for(int index = 0; index < n; index++){
        if(inDegree.at(index) == 0){
            sources.push(index);
        }
    }
    int visited = 0;
    while(!sources.empty()){
        int currCourse = sources.front();
        sources.pop();
        visited++;
        for(auto child:graph[currCourse]){
            if(--inDegree.at(child) == 0){
                sources.push(child);
            }
        }
    }
    return n == visited;
}

int main(){
    int n = 4;
    vector<vector<int> > prerequisites {
        {1,0},
        {1,2},
        {2,3},
    };
    if(canCompleteAllCourses(n, prerequisites)){
        cout<<"Yaay!"<<endl;
    }else{
        cout<<"Duh!"<<endl;
    }
    return 0;
}