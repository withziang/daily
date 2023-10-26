#include <iostream>
#include <vector>
#include <limits>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        
        //create a dictionary, compare every two points, the dumb way wins

        map<float,int> dict1;
        const int n = points.size();
        int strike = 0;
        if (n < 3) return n;
        float slope;

        for (int x = 0; x< n; x++){
            for (int y= x+1; y<n; y++){
                //since we are only comparing from the same i point, we just need the slope
                // if they have same x-axis, y=k line
                if (points[y][0]-points[x][0] == 0){
                    slope = numeric_limits<float>::infinity(); 
                }else{
                    slope = static_cast<float>((points[y][1]-points[x][1])/(points[y][0]-points[x][0]));
                }
                if (dict1.find(slope) != dict1.end()){
                    dict1[slope]++;

                }else{
                    dict1[slope] =2;
                }
            }
            //check the highest, update strike and clean the dictionary
            for (const auto & i: dict1){
                if (i.second > strike){strike = i.second;}
            }

            dict1.clear();
        }


        return strike;
    }
};
class Solution2 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 9*9 matrix 

        //verify colomn 
        vector <int> usednumber;

        for (int i = 0; i< 9; i++){
            for (int j=0;j< 9;j++){
                if (board[j][i] == '.'){
                    continue;
                }else if (  count(usednumber.begin(),usednumber.end(),board[j][i]) >= 1 ){   //in the vector
                    return false;
                }else{
                    usednumber.push_back(board[j][i]);
                }
                cout << board[j][i] << " ";
            }
            usednumber.clear();
        }
        cout << endl;
        //verify row
        for (int i = 0; i< 9; i++){
            for (int j=0; j< 9;j++){
                if (board[i][j] == '.'){
                    continue;
                }else if (count(usednumber.begin(),usednumber.end(),board[i][j]) >= 1){   //in the vector
                    return false;
                }else{
                    usednumber.push_back(board[i][j]);
                }
                cout << board[i][j] << " ";
            }
            usednumber.clear(); 
        }
         cout << endl;
        //for every section
        for (int x=0; x<3; x++){
            for (int y=0; y < 3; y++){ //3*3 
                for (int i = x*3; i < x*3 + 3; i++ ){
                    for (int j = y*3; j < y*3 +3; j++){
                        if (board[i][j] == '.'){
                            continue;
                        }else if (count(usednumber.begin(),usednumber.end(),board[i][j]) >= 1){   //in the vector
                            return false;
                        }else{
                            usednumber.push_back(board[i][j]);
                        }
                        cout << board[i][j] << " ";
                    }
                }

                usednumber.clear();
            }
        }


        return true;

    }
};
class Solution3 {
public:
    int candy(vector<int>& ratings) {
        //using from the left to right and right to the left 
        vector <int> candy_list(ratings.size(),1); //initalize a list, everyone starts with 1 

        //from the left to right <<<<<
     
        for (int i = 1; i< ratings.size();i++){
            if (ratings[i] > ratings[i-1] && candy_list[i] <= candy_list[i-1]){
                candy_list[i] = candy_list[i-1] + 1;
            }
        }

        for (auto i:candy_list){
            cout << i << " ";
        }
        cout << endl;
       //from the right to left   >>>>>

        for (int i = 0; i< ratings.size()-1;i++){
            if (ratings[i] > ratings[i+1] && candy_list[i] <= candy_list[i+1]){
                candy_list[i] = candy_list[i+1] + 1;
            }
        }
     
        for (auto i:candy_list){
            cout << i << " ";
        }
        cout << endl;
        int outcome = accumulate(candy_list.begin(),candy_list.end(),0);
        return outcome;     
    }
};
class Solution4 {
public:
    bool check_if_perfect_square(int i,int j){
        double y = sqrt(i*(double)j);
        return y == (int) y;
    }

    long long maximumSum(vector<int>& nums) {
        
        //distinct equivilant class
        //assign each number to its equivalent class 
        //after assignment, delete the number from the nums 
        vector <unsigned long int> outcome;
        unsigned long int final_outcome;
        
        //for the indices list {1, 2, ..., n}
        vector <int> indice;
        int x = 1;
        //generate(ls, ls.begin(),ls.end(), [&x](){return x++;});
        while (x < nums.size()+1){
            indice.push_back(x);
            x++;
        }
        cout << "indice list:" << "\n";
        for (auto i: indice){
            cout << i << " ";
        }

        //find every class, the sum of every class, store them in the outcome list 
        unsigned long int sum; //to append to the outcome 

        while(! indice.empty()){
            sum = 0;
            int leader = indice[0];
            for (auto it = indice.begin() + 1; it != indice.end();){  
                if (check_if_perfect_square(leader, *it)){ //they are in the same class
                    sum += (unsigned long int) nums[*it];   //nums start at 1
                    indice.erase(it); //erase current position 
                }else{
                    ++it;
                }
            }
            //finally add leader to the sum class, delete leader
            sum += (unsigned long int) nums[leader];
            indice.erase(indice.begin());

            //append sum to the outcome
            outcome.push_back(sum);
        }

        //find the max of the list outcome 
        final_outcome = *max_element(outcome.begin(),outcome.end());

        cout << "outcome list:" << "\n";
        for (auto i: outcome){
            cout << i << " ";
        }
        return final_outcome;
       
    }

};

class Solution5 {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector <char> visited_char;

        int strike =1;

        vector <int> all_strike;
        all_strike.push_back(strike);

        visited_char.push_back(s[0]);

        for (int i = 1; i< s.size();i++){
            if (find(visited_char.begin(),visited_char.end(),s[i]) == visited_char.end()){
                strike++;
                visited_char.push_back(s[i]);
                cout << strike << "asd"<< endl;
            }else{
                all_strike.push_back(strike);
                cout << strike << endl;
                strike = 1;
                visited_char.clear();
                visited_char.push_back(s[i]);
            }
        }
        cout << strike << endl;
        strike = *max_element(all_strike.begin(),all_strike.end());
        return strike;
    }
};



class Solution6 {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        vector <string> output;
        for(auto a: words1){
            if (  find(output.begin(),output.end(),a) == output.end()){
                output.push_back(a); 
            }else{
                output.erase( find(output.begin(),output.end(),a)); //duplication 
            }
        }
        for (auto a: output){
            cout << a << " ";
        }
        for(auto a: output){
            if ( find(words2.begin(),words2.end(),a) == words2.end() && output.size() != 0){
                output.erase(find(output.begin(),output.end(),a));
            }
        }
        return output.size();
    }
};



class Solution7 {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        //the smart way
        //find the smallest number always, find the lost right side and left side, compare them, the least side gets converts all to small
        //then find the next smallest number in the interval do the same thing, till you are left with one element 
        
        long long outcome;
        
        if (maxHeights.size()==1) return maxHeights[0];
        
        //the interval in which we need to investigate 
        auto upper_bound = maxHeights.end()-1;
        auto lower_bound = maxHeights.begin();
        
        //the left hand side and right hand side for comparison, these are negative
        
        long long left_side;
        long long right_side;
        
        
        long long a = 0;
        long long b = 0;
        
        //index on the smallest number in range
        auto current_min = min_element(lower_bound,upper_bound +1);
        
        while (upper_bound - lower_bound > 0){
            current_min = min_element(lower_bound,upper_bound +1);
            a = 0;
            b = 0;
            //compute each side
            for (auto it=lower_bound;it<current_min;it++){
                a += *it;
            }
            
            for (auto it=current_min+1;it<upper_bound +1;it++){
                b += *it;
            }
            
            left_side = a - (*current_min) * (current_min - lower_bound);
            right_side = b - (*current_min) * (upper_bound - current_min);
            
            cout << a <<b<<left_side<<" " << right_side << endl;

            //compare them
            if (left_side > right_side){  //they are negative numbers
                outcome += (*current_min) * (current_min - lower_bound +1);
                lower_bound = current_min +1;
            }else{
                outcome += (*current_min) * (upper_bound - current_min +1);
                upper_bound = current_min;
            }
        }
        
        
        outcome += *upper_bound;  //the peak
        
       
        return outcome;
    }
};




class Solution8 {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) 
    {
        int n = maxHeights.size();
        //===================================================================================================
        //PREVIOUS SMALLER ELEMENT USING STACK
        stack<int>st;
        vector<int>prevSmaller(n, -1); //stores the "index" of previous Smaller Element
        for (int i = 0; i < n; i++)
        {
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i])
            {
                st.pop(); 
            }
            
            if (!st.empty())
                prevSmaller[i] = st.top();
            st.push(i);
        }
        //=======================================================================================================
        //NEXT SMALLER ELEMENT USING STACK
        vector<int>nextSmaller(n, n);  //stores the "index" of next Smaller Elements
        st = stack<int>(); //new Stack
        for (int i = n - 1; i >= 0; i--)
        {
            while(!st.empty() && maxHeights[st.top()] >= maxHeights[i])
            {
                st.pop();
            }
            if (!st.empty())
                nextSmaller[i] = st.top();
            st.push(i);
        }
        //=========================================================================================================
        vector<long long>leftSum(n, 0);
        leftSum[0] = maxHeights[0];
        for (int i = 1; i < n; i++)
        {
            int prevSmallerIdx = prevSmaller[i];
            int equalCount = i - prevSmallerIdx; 
            //all elements from [prevSmallerIdx + 1] to [i] will be set to "maxHeights[i]"
            
            leftSum[i] = leftSum[i] + ((long long)equalCount * maxHeights[i]);
            
            if (prevSmallerIdx != -1) //smallest than everything before 
                leftSum[i] += leftSum[prevSmallerIdx];
        }
        //========================================================================================================
        vector<long long>rightSum(n, 0);
        rightSum[n - 1] = maxHeights[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int nextSmallerIdx = nextSmaller[i];
            int equalCount = nextSmallerIdx - i;
            //all elements from [i] to [nextSmallerIdx - 1] will be set to "maxHeights[i]"
            
            rightSum[i] = rightSum[i] + ((long long)equalCount * maxHeights[i]);
            
            if (nextSmallerIdx != n)
                rightSum[i] += rightSum[nextSmallerIdx]; 
        }
        //=============================================================================================================
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long totalSum = leftSum[i] + rightSum[i] - maxHeights[i];
            ans = max(ans, totalSum); //every point as peak

        }
        //===============================================================================================================
        return ans;
    }
};

class Solution9 {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        vector <bool> mybool(s.size(),false);
        mybool[0] = true;

        for (int i =0; i< s.size();i++ ){
            for (int j =0; j <= i; j++){
                if (find(wordDict.begin(),wordDict.end(),s.substr(j,i-j+1)) != wordDict.end()){
                    cout << s.substr(j,i-j+1) <<" "<< "i:"<< i<<" "<< "j:"<< j << endl;
                    if (mybool[j]){
                        mybool[i+1] = true;
                        break;
                    }
                }
            }
        }

        return mybool[s.size()];
    }
};

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution10 {
private:
    int depth;

public:
    void eachnode(TreeNode* node, int current_depth){

        int x = current_depth;
        if (node -> left == NULL && node -> right == NULL){
            cout <<"node: "<< node << " "<< "current_depth: " << current_depth << " " << "depth: "<< this->depth <<endl;
            return;
        } 
        if (node -> left != NULL){
            int x = current_depth +1;
            if (x > this->depth) this->depth = x;
      
            eachnode(node->left,x);
        }

        current_depth = x;
        if (node ->right != NULL){
            int y = current_depth +1;
            if (y > this->depth) this->depth = y;

            eachnode(node-> right,y);
        }
        
    }


    int maxDepth(TreeNode* root) {
       
        if (root == NULL) return 0;
        this->depth = 1;
        eachnode(root,1);
        return this->depth;

        
    }
};


class Solution11 {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        
        vector <string> output;
        for(auto a: words1){
            auto x = find(output.begin(),output.end(),a);
            if ( x == output.end()){
                output.push_back(a); 
            }else{
                output.erase(x); //duplication 
            }
        }

        for(auto a: output){
            cout << a << " ";

        }
        cout << output.size();
        for(auto a: output){
            auto x = find(words2.begin(),words2.end(),a);
            if ( x == words2.end() && output.size() != 0){
                output.erase(x);
            }
        }
        return output.size();
    }
};



class Solution12 {

private:
    int count = 0;
    vector <pair<int,int>> visited_node; //store i,j

    bool isNewIsland(int i, int j, vector<vector<char>>& grid){

        vector <pair<int,int>> eightPoint;


        for (int x = -1; x<2; x++){
            for (int y = -1; y<2;y++){
                if (x==-1 && y==-1)continue;
                if (x==1 && y ==1)continue;
                if (x==1 && y == -1)continue;
                if (x==-1 && y ==1) continue;
                if ( 0 <= i+x && i+x < grid.size() && 0 <= j+y && j+y < grid[0].size()){
                    if (grid[i+x][j+y] == '1')eightPoint.push_back(make_pair(i+x,j+y));
                }
            }
        }
        for (auto a:eightPoint){
            cout << a.first << ' ' << a.second << ",  ";
        }

        cout << endl;
        return all_of(eightPoint.begin(),eightPoint.end(), [&](pair<int,int>&a){return find(visited_node.begin(),visited_node.end(),a) == visited_node.end(); }  );
    }

public:

    

    int numIslands(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size();i++){
            for(int j = 0; j< grid[0].size();j++){
                if (grid[i][j] == '1'){
                    if (isNewIsland(i,j,grid)){
                        count ++;
                    }
                    visited_node.push_back(make_pair(i,j));
                    cout << visited_node.size() <<" " <<count<< endl;
                    cout << endl;
                }
            }
        }
        return count;
    }
};



class Solution13 {
public:
    void primeSearch(int a, vector <int>& b){
        if (a % 2 == 0)b.push_back(2);
        while (a % 2 == 0){
            a = a / 2;
        }
        
        for (int i =3 ; i <= a;i += 2){
            if (a % i == 0){
                b.push_back(i);
            }
            while (a % i == 0){
                a = a / i;
            }
        }
    }


    int findValidSplit(vector<int>& nums) {
        //split every number into a prime list [prime,prime,prime   ,prime,prime,prime,prime,prime]
        //potential position i, every element before i, cannot appear after i 
        //record all the occurence, when you reach another occurence, update the i'
        //if you reach the last element, while i is not at the last element, return i 

        unordered_map <int, bool> leftSidePrimes;

        unordered_map <int, bool> rightSidePrimes;

        int output = 0;   //the separation index

        //auto inLeftList = [leftSidePrimes](int a){return leftSidePrimes.find(a) != leftSidePrimes.end();}; //return true if if there is one 
        //auto inRightList = [rightSidePrimes](int a){return rightSidePrimes.find(a) != rightSidePrimes.end();};


        //add the first element in leftSidePrimes
        vector <int> insertlist;
        primeSearch(nums[0], insertlist);
        for (auto a: insertlist){
            leftSidePrimes.insert(make_pair(a, true));
        }
        insertlist.clear();

        //element i find in map1 = > add to map1 and everything in map2
        //find in map2 => add to map2
        //completely new element => to map2

        for (int i = 1; i < nums.size(); i++){
            primeSearch(nums[i], insertlist);
            
            if (any_of(insertlist.begin(), insertlist.end(), [leftSidePrimes](int a){return leftSidePrimes.find(a) != leftSidePrimes.end();} )   ){
                for (auto a: insertlist){
                    leftSidePrimes.insert(make_pair(a,true));
                }
                //add right to left and clear right
                leftSidePrimes.insert(rightSidePrimes.begin(), rightSidePrimes.end()); //we do not care about key disappear, one instance is enough
                rightSidePrimes.clear();
                output = i;
            }else{
                for (auto a: insertlist){
                    rightSidePrimes.insert(make_pair(a,true));
                }
            }
            cout << i << " ";
            cout << "leftSidePrimes: ";
            for (auto a: leftSidePrimes){
                cout << a.first << " ";
            }
            cout << "rightSidePrimes: ";
            for (auto a: rightSidePrimes){
                cout << a.first << " ";
            }
            cout << endl;
            insertlist.clear();
        }
        //possible outcome, i in somewhere [0,size-2] rightlist has 1 list, this list does not appear in leftlist
        //                  i == size -1, at size-2, right list clears, ///// 
        if (output == nums.size()-1) return -1;
        return output;

    }
};




class Solution14 {
public:
    unsigned long long mod = 1e9+7;
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        //when you visit every room(unless the last one), there will be a first time and at least a second time 
        //depend on how back the next visit gives you, the day will get longer 
        // if the i = nextroom[i], then just +1, go the next 
        //when you at i, every room in front of i, you have visited even number amount of time 

        //last day does not count, idealy be [0,1,2,3,4....], the difference will add extra time, difference of 1 will add 2 days
        // difference of 1 consecutively will add [0,1,1,2,4.....]  +2+ 2+2 (+2+2+2)....

        // a non-accumulative list [2,2,2+4,2+2+2+4,]  sum of this list -1 +1(last day visit)
        //difference of 2, days +4   [0,1,0,1,2......]
        //difference of 2 two times: +4 (+2 +2+4) (+2 +2+4 +)
    
        vector <unsigned long long> partial_sum(nextVisit.size(),0);

        partial_sum[1] = 2;

        for(int i= 2;i< partial_sum.size();i++){
            partial_sum[i] = (partial_sum[i-1]*2 + 2 - partial_sum[nextVisit[i-1]] + mod) % mod;
        }

        for (auto a: partial_sum){
            cout << a << " ";
        }

        return partial_sum[partial_sum.size()-1];
    }
};
class Solution15 {
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit)
    {
        int n=nextVisit.size();
        vector<long long>dp(n,0);
        long long mod=1e9+7;
        for (int i=1;i<n;i++)
        {
            if(nextVisit[i-1]==i-1)
            dp[i]=(dp[i-1]+2+mod)%mod;
            else{
                dp[i]=(dp[i-1]+2+dp[i-1]-dp[nextVisit[i-1]]+mod)%mod;
            }
        }
        for (int i = 0; i< dp.size();i++){
            cout << dp[i]<< " ";
        }
        return dp[n-1];
    }
};







int main(){

}