#include <iostream>
#include <vector>
using namespace std;

// Problem : Lumberjack Mirko needs to chop down M metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Mirko is only allowed to cut a single row of trees.

// Mirko‟s machine works as follows: Mirko sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Mirko then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Mirko raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Mirko will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).

// Mirko is ecologically minded, so he doesn‟t want to cut off more wood than necessary. That‟s why he wants to set his sawblade as high as possible. Help Mirko find the maximum integer height of the sawblade that still allows him to cut off at least M metres of wood.

// Input
// The first line of input contains two space-separated positive integers, N (the number of trees, 1 ≤ N ≤ 1 000 000) and M (Mirko‟s required wood amount, 1 ≤ M ≤ 2 000 000 000).

// The second line of input contains N space-separated positive integers less than 1 000 000 000, the heights of each tree (in metres). The sum of all heights will exceed M, thus Mirko will always be able to obtain the required amount of wood.

// Output
// The first and only line of output must contain the required height setting.


// Approach: Binary search, search space is 0 to heigh of max tree. check if mid is solution, if yes store and look for greater value (low=mid+1) else value is tooo high and not sufficient wood is cut, therfore do high = mid-1.
// Approach for issolution() : store amount of wood. traverse entire array. check if wood can be cut from given tree i.e. arr[i]>mid, if yes, cut the tree by wood+=arr[i]-mid if wood reaches necessary amount(m or greater) returnn true. at end of for loop, if nothing occurs return false.


bool issolution(vector<int> &trees, int n, int m,int mid){
    int wood=0;
    for(int i=0;i<n;i++){
        if(trees[i]>mid){
            wood+=trees[i]-mid;
            if(wood>=m){
                return true;
            }
        }
    }
    return false;
}

int maxheightcut(vector<int> &trees, int n, int m){
    int low = 0;
    int high= -1;
    int ans = -1;
    for(int i=0;i<n;i++){
        if (trees[i]>high)
        high = trees[i];
    }
    int mid = low + (high-low)/2;
    while(low<=high){
        if(issolution(trees,n,m,mid)){
            ans= mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
        mid = low + (high-low)/2;
    }
    return ans;
}

int main(){
    int n; //number of trees
    int m; //wood required
    cin>>n;
    cin>>m;
    vector<int> trees;
    for (int i=0; i<n; i++){
        int tree;
        cin >> tree;
        trees.push_back(tree);
    }
    cout<< maxheightcut(trees,n,m);
}