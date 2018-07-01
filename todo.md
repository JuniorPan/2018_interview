# todo

- 1
一排有N个位置，一个机器人在最开始停留在P位置上，如果 p==O位置，下一分钟机器人一定向右移动到1位置；如果p==N-1， 下一分钟机器人一定向左移动到N-2位置。如果P在0和N-1之间， 下一分钟机器人一定会向左或者向右移动。求K分钟的时候，机 器人到达T位置有多少种走法。  
函数为：int f(int N, int P, int K, int T)，返回值为走法 的数量。(暴力递归转动态规划)

- 2
给定一个整型数组arr，代表数值不同的纸牌排成一条线。玩家 A和玩家B依次拿走每张纸牌，规定玩家A先拿，玩家B后拿，但 是每个玩家每次只能拿走最左或最右的纸牌，玩家A和玩家B都 绝顶聪明。请返回最后获胜者的分数。(暴力递归转动态规划)

- 3 
小易非常喜欢拥有以下性质的数列:
数列的长度为n 2、数列中的每个数都在1到k之间(包括1和k) 3、对于位置相邻的两个数A和B(A在B前),都满足(A <= B)或(A mod B != 0)(满足其一即可) 例如,当n = 4, k = 7 那么{1,7,7,2},它的长度是4,所有数字也在1到7范围内,并且满 足第三条性质,所以小易是喜欢这个数列的 但是小易不喜欢{4,4,4,2}这个数列。小易给出n和k,希望你能 帮他求出有多少个是他会喜欢的数列。输入描述:  
输入包括两个整数n和k(1 ≤ n ≤ 10, 1 ≤ k ≤ 10^5)  
输出描述: 输出一个整数,即满足要求的数列个数,因为答案可能很大,输出 对1,000,000,007取模的结果。  
输入例子1: 2 2  
输出例子1: 3  (暴力递归转动态规划)

- 4
过年的时候地主给长工发工钱，地主打算切开一根金条，按照 长工的工作量每人分一部分。只有金匠才能切开金条，每切一 次，金匠要收金条长度个铜币，比如长度为15的金条切开一次 要收15个铜币。地主希望找到一种切分方法，使得完成切分后 能给金匠最少的铜币。 举例说明，比如金条长30，需要分给4位长工，每人分到的分别 为6，7，8，9。一种切分方式是先切成15和15，然后再分别切 分成6和9，7和8，此时地主需要给金匠铜币数最少，一共60个。

- 5
https://leetcode.com/problems/ipo/description/

- 6
https://leetcode.com/problems/burst-balloons/description/

- 7 
两个单链表相交的一系列问题

- 8
复制含有随机指针节点的链表

- 9
P为给定的二维平面整数点集。定义 P 中某点x，如果x满足 P 中任意点都不在 x 的右上方区域内（横纵坐标都大于x），则称 其为“最大的”。求出所有“最大的”点的集合。（所有点的 横坐标和纵坐标都不重复, 坐标轴范围在[0, 1e9) 内） 如下图：实心点为满足条件的点的集合。

- 10
给定一个数组序列, 需要求选出一个区间, 使得该区间是所有 区间中经过如下计算的值最大的一个： 区间中的最小数 * 区间所有数的和 最后程序输出经过计算后的最大值即可，不需要输出具体的区 间。如给定序列 [6 2 1]则根据上述公式, 可得到所有可以选 定各个区间的计算值:(单调栈的应用)

# Leetcode 待解决问题 

-
[39. Combination Sum](https://leetcode.com/problems/combination-sum/description/)  
[45. Jump Game II](https://leetcode.com/problems/jump-game-ii/description/) 
[46.permutations](https://leetcode.com/problems/permutations/description/)  
[69. Sqrt(x)](https://leetcode.com/problems/sqrtx/description/)  
[97. Interleaving String](https://leetcode.com/problems/interleaving-string/description/)  
[114. Flatten Binary Tree to Linked List](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/)  
[115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/description/)  
[124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/description/)  
[131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/description/)  
[132. Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)  
[151. Reverse Words in a String](https://leetcode.com/problems/reverse-words-in-a-string/description/)  
[152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/description/)  
[173. Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/)
[229. Majority Element II](https://leetcode.com/problems/majority-element-ii/description/)  
[257. Binary Tree Paths](https://leetcode.com/problems/binary-tree-paths/description/)  
[297. Serialize and Deserialize Binary Tree](https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/)    
[315. Count of Smaller Numbers After Self](https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/)  
[329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/description/)  
[337. House Robber III](https://leetcode.com/problems/house-robber-iii/description/)
[403.frog-jump](https://leetcode.com/problems/frog-jump/description/)  
[404. Sum of Left Leaves](https://leetcode.com/problems/sum-of-left-leaves/description/)   
[415. Add Strings](https://leetcode.com/problems/add-strings/description/)  
[416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)   
[417. Pacific Atlantic Water Flow](https://leetcode.com/problems/pacific-atlantic-water-flow/description/)  
[437. Path Sum III](https://leetcode.com/problems/path-sum-iii/description/)   
[450. Delete Node in a BST](https://leetcode.com/problems/delete-node-in-a-bst/description/)  
[467. Unique Substrings in Wraparound String](https://leetcode.com/problems/unique-substrings-in-wraparound-string/)    
[494. Target Sum](https://leetcode.com/problems/target-sum/description/)  
[508. Most Frequent Subtree Sum](https://leetcode.com/problems/most-frequent-subtree-sum/description/)
[516. Longest Palindromic Subsequence](https://leetcode.com/problems/longest-palindromic-subsequence/description/)  
[560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/description/)  
[576. Out of Boundary Paths](https://leetcode.com/submissions/detail/154021975/)  
[646. Maximum Length of Pair Chain](https://leetcode.com/problems/maximum-length-of-pair-chain/description/)  
[647. Palindromic Substrings](https://leetcode.com/problems/palindromic-substrings/description/)  
[652. Find Duplicate Subtrees](https://leetcode.com/problems/find-duplicate-subtrees/description/)  
[688. Knight Probability in Chessboard](https://leetcode.com/submissions/detail/154023237/)   
[695. Max Area of Island](https://leetcode.com/problems/max-area-of-island/description/)  
[712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/)  
[827. Making A Large Island](https://leetcode.com/submissions/detail/153847279/)
