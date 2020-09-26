/*//Ncode
// #include<bits/stdc++.h>
// using namespace std;
// struct Tang{
//     bool grade;
//     bool live;
//     int Cap;
// };

// int main(){
//     int T,n,m,step,temp,flag;
//     int clk;
//     Tang *p;
//     int *count;
//     cin>>T;
//     while(T--){
//         cin>>n>>m;
//         clk=0;
//         p=new Tang[n];
//         count=new int[m];

//         temp=n;
//         step=0;
//         for(int stepp=0;stepp<n;stepp++){
//             cin>>flag>>p[step].Cap;
//             if(flag) p[step].grade=true;
//             if(!flag) p[step].grade=false;
//             p[step].live=true;
//             step++;
//         }

//         temp=m;
//         step=0;
//         while(temp--){
//             cin>>count[step];
//             step++;
//         }

//         temp=n;
//         step=0;
//         while(temp--){
//             for(int i=clk;i>=0;i--){
//                 if(i==0) continue;
//                 for(int j=i-1;j>=0;j--){
//                     if(p[j].live && p[j].grade!=p[i].grade && p[j].Cap < p[i].Cap) 
//                         p[j].live= false; //标记前面的人清除
//                     }
//                 }
//             }

//             if(clk==count[step]-1) {
//                 for(int i=0;i<clk;i++){
//                     p[i].Cap++;
//                 }
//                 step++;
//             }//发功
//             clk++;
//         }
//         temp=0;
//         for(int i=0;i<n;i++){
//             if(p[i].live) temp++;
//         }
//     cout<<temp<<endl;
// }
*/
//Leecode
// #include<bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     // vector<int> twoSum(vector<int>& nums, int target) {
//     //     map<int , int>p;
//     //     map<int , int>::iterator it;
//     //     int Msize=nums.size();
//     //     for(int i=0;i<Msize;i++){
//     //         // p.insert(i,sums[i]);
//     //         p.insert(pair<int,int>(i,nums[i]));
//     //     }    
//     //     for(int j=0;j<Msize;j++){
//     //         it=p.find(target-nums[j]);
//     //         // ptarget-nums[j]
//     //         return {it->first,it->second};
//     //     }
//     // }
//     vector<int> twoSum(vector<int>& nums, int target) {
//     }
// };
