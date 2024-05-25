First run a dfs on the tree. Suppose Root node is 1.   
- `dp[p] =  number of people on node p`  
- How to calculate dp[p]?
first we will put all the dp value of child of parent in  vector, sort them(ie. greedily process)

Current_total_people = 1.<br>
for(auto child : parent) <br>
    `if (Current_total_people >= dp[child])     Current_total_people+= dp[child]; `  // basically they can move to parent node <br>
    `else  make_root_node = child_node;`    // they can not move to parent node. so we don't have any option other than making this child node as a root node and run dfs again.

