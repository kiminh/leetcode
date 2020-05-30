# �����ѵ

* һ��Ҫ�ɹ��ܾ���ϸ��Ϊ����������һ������˼·�Ƚ����������߿�����ĳЩ�����ֱ��returnֵ��
* ����������ʽ��һ�����У���������룺���Ρ����桢̰����һ�㲻������������Ϊ�ܷ�ʱ�䣬ջ���п��������

# ��Ƶhard
LRU Cache
Meidan of Two Sorted Arrays
Trapping Rain Water
Integer to English Words
Regular Expression Matching
Merge K Sorted Lists
Remove Invalid Parentheses
Serialize and Deserialize Binary Tree
Minimum Window Substring

# C++ STL�г���������ʱ�临�Ӷ�

* map, set, multimap, and multiset ���������������ú����ʵ�֣��������ƽ���������һ�֡���ͬ������ʱ�临�ӶȽ���Ϊ:
	- ����:O(logN)
	- �鿴:O(logN)
	- ɾ��:O(logN)

* hash_map, hash_set, hash_multimap, and hash_multiset ���������������ù�ϣ��ʵ�֣���ͬ������ʱ�临�Ӷ�Ϊ��
	- ����:O(1)������O(N)��
	- �鿴:O(1)������O(N)��
	- ɾ��:O(1)������O(N)��

# �漼����

* [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/)�ο�[My short c++ solution, O(1) space, and O(n) time](https://leetcode.com/problems/first-missing-positive/discuss/17071/My-short-c%2B%2B-solution-O(1)-space-and-O(n)-time),��2��ѭ����Ҳû��֤�����̣���֪���Բ��ԡ�

* [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/)��������ʱ�򣬲����˶�̬�滮��ʵ�ָ��������ʵ������Ծ���ң������˲����ٶȡ�[leetcode84.png](./images/leetcode84.png)

# ����

�ܶ���Ŀ��ʵ����һ��������+��֦���Ĺ��̣���ʵ������һ���ǳ�ͨ�õķ������κ�һ�����Ż����͵���Ŀ����ʵ������ͨ�������������ֻ�Ƕ��ڼ򵥵ı���������˵�������ռ��Ƿǳ��޴��������һ�����޵Ŀռ䣬��ν�ġ��Ż�����ʵ���Ƕ������ռ���й����ܽᣬ��������￪ʼ�ѣ�����������ʲô����Щ�ӿռ��ǿ����ų����ⲻ��Ҫ�����ġ�

����ʶ����Ҫ�������ӿռ�ļ�����������֦��ͨ��������Щ�ӿռ䣬��ʵ������Ч�ʵ�Ŀ�ġ���ʵ�ںܶ������У�����Ľ�ռ���Ȼ�󣬵������ڸ���Լ����������Ҫ�����Ŀ���ֻ�����к�Сһ���֡�

��������������⣬���ǿ������ȹ۲�ϵͳ�еı����м����������2���Ļ���������һ����άƽ��ľ����н�������������������Ļ���������һ����ά�ռ�ĳ������н���������

����������أ��ܶ�������Ǿ��εĶ������������Ķ��㡣

����11�⣬Ѱ�����װˮ���������Ŀ����Ѱ��2�����ӣ�ʹ��װˮ���������ϵͳ�еı�������2����ÿ��������ȡֵ��Χ��n��Ҳ���ǽ�ռ���һ��n*n�Ķ�ά�ռ䡣������Ҫ�������ά�ռ��������������������ϸ�۲죬���ǿ��Է��ְ�l��r�Ե�����ʵ��һ���ظ������⣬������ռ����СΪԭ����һ�룬�پ����۲죬�Ϳ����ҵ�������·���ɼ�֦�ķ�����

# ����

## �ܽ�

* �����������飬�Ϳ���������ַ���������һ�����ַ���ģ��

```cpp
00 function binary_search(A, n, T) is
01     L := 0
02     R := n ? 1
03     while L �� R do
04         m := floor((L + R) / 2)
05         if A[m] < T then
06             L := m + 1
07         else if A[m] > T then
08             R := m - 1
09         else:
10             return m
11     return unsuccessful
```

���ַ��ļ����ؼ��㣺

* �����߽磺�����߽�һ����`[)`������`[]`������ǿ���Ƽ�`[]`����Ϊ�����������mid������Խ�硣

* ������ԭ��
	- ����ҵ�target������ѭ���оͻ��˳���
	- ����Ҳ���������ߵ�ѭ���⣬��ʱ�˿̣�left��right��״̬һ����`]``target``[`������rightָ����Ǳ�targetС�������������ģ���leftָ����Ǳ�target�������������С�ġ���һ������á�`][`�����������������������Խб�����ԭ��

* [34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

��������

* [74. Search a 2D Matrix](https://leetcode.com/problems/search-a-2d-matrix/)

�����������ص㿼���Ҳ�������������챳������

## Ksum����

Ksum��������[Subset sum problem](https://en.wikipedia.org/wiki/Subset_sum_problem)�����һ�����������`Subset sum problem`�Ļ�����������ö�̬�滮�ķ�������⡣�䱾����һ���򻯵�01�������⣬ֻ����û�����Ż���Ҫ��ֻ��Ҫ�պð�����ΪN�ı����������ɡ�
�ڻ�������֮�ϣ����ܻ����һЩ�µ�Լ����
* Ҫ���ʹ��K����Ʒ������Ksum����
* ��Ʒ�Ƿ����ظ������Ҫ��û���ظ�

* [1. Two Sum](https://leetcode.com/problems/two-sum/)
	- ����1:ʹ�ù�ϣ,��������е����
	- ����2:˫ָ��,ֻ�����һ�����
* [15. 3Sum](https://leetcode.com/problems/3sum/)
	- ����һ���⼴�ɣ�Ԫ�����ظ�
	- �������н⣬Ԫ�����ظ�
	- ����һ���⼴�ɣ�Ԫ�����ظ�
	- �������н⣬Ԫ�����ظ�





# ����

* [51. N-Queens](https://leetcode.com/problems/n-queens/)
N�ʺ����⣬���ݼ��ɡ�
* [79. Word Search](https://leetcode.com/problems/word-search/)

# �ַ���

# ��̬�滮

��̬�滮�Ļ���������
��̬�滮��˼·�� ***�������Ѿ�֪����Ŀǰ�����Ž⣬��ô�������Ŀǰ�����������һ������ô���ͨ��Ŀǰ�����Ž�������Ӻ��µ����Ž��أ�***

* ���ҽ�β�����һ�������Գ�һ�ɴ�
* ��ǰ����n����
* ����˼·-��׺������
* �Ӳ������

������̬�滮����ʱ����Ҫע�⣺
* ���ȿ��Ǳ߽磬����еı߽絥Ԫ��һ��Ҫ������forѭ����д������˼·������

## Top50��̬�滮����
from [https://blog.usejournal.com/top-50-dynamic-programming-practice-problems-4208fed71aa3](https://blog.usejournal.com/top-50-dynamic-programming-practice-problems-4208fed71aa3)

* [Longest Common Subsequence | Introduction & LCS Length](https://leetcode.com/problems/longest-common-subsequence/)
* Longest Common Subsequence | Finding all LCS
* [Longest Common Substring problem](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)
* Longest Palindromic Subsequence using Dynamic Programming
* Longest Repeated Subsequence Problem
* Implement Diff Utility
* Shortest Common Supersequence | Introduction & SCS Length
* Shortest Common Supersequence | Finding all SCS
* Longest Increasing Subsequence using Dynamic Programming
* Longest Bitonic Subsequence
* Increasing Subsequence with Maximum Sum
* The Levenshtein distance (Edit distance) problem
* Find size of largest square sub-matrix of 1��s present in given binary matrix
* Matrix Chain Multiplication using Dynamic Programming
* Find the minimum cost to reach last cell of the matrix from its first cell
* Find longest sequence formed by adjacent numbers in the matrix
* Count number of paths in a matrix with given cost to reach destination cell
* 0�C1 Knapsack problem
* Maximize the Value of an Expression
* Partition problem | Dynamic Programming Solution
* Subset Sum Problem
* Minimum Sum Partition Problem
* Find all N-digit binary strings without any consecutive 1��s
* Rod Cutting Problem
* Maximum Product Rod Cutting
* Coin change-making problem (unlimited supply of coins)
* Coin Change Problem (Total number of ways to get the denomination of coins)
* Longest Alternating Subsequence Problem
* Count number of times a pattern appears in given string as a subsequence
* Collect maximum points in a matrix by satisfying given constraints
* Count total possible combinations of N-digit numbers in a mobile keypad
* Find Optimal Cost to Construct Binary Search Tree
* Word Break Problem | Dynamic Programming
* Word Break Problem | Using Trie Data Structure
* Total possible solutions to linear equation of k variables
* Wildcard Pattern Matching
* Find Probability that a Person is Alive after Taking N steps on an Island
* Calculate sum of all elements in a sub-matrix in constant time
* Find Maximum Sum Submatrix in a given matrix
* Find Maximum Sum Submatrix present in a given matrix
* Find maximum sum of subsequence with no adjacent elements
* Maximum Subarray Problem (Kadane��s algorithm)
* Single-Source Shortest Paths �� Bellman Ford Algorithm
* All-Pairs Shortest Paths �� Floyd Warshall Algorithm
* Pots of Gold Game using Dynamic Programming
* Find minimum cuts needed for palindromic partition of a string
* Maximum Length Snake Sequence
* 3-Partition Problem
* Calculate size of the largest plus of 1��s in binary matrix
* Check if given string is interleaving of two other given strings



### ���仯����������

* [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
Ƶ����ȡ����ͣ������һ���ۼӺ����У���ʱ�����һ�¾Ϳ����ˡ�

* [304. Range Sum Query 2D - Immutable](https://leetcode.com/problems/range-sum-query-2d-immutable/) ����һ���򵥱���¼�㷨����ǰ���

* [746. Min Cost Climbing Stairs](https://leetcode.com/problems/min-cost-climbing-stairs/) 
����Ŀ���������

* [650. 2 Keys Keyboard](https://leetcode.com/problems/2-keys-keyboard/)

���nΪ��������ôֻ��ͨ����A�������ٸ���n-1�����γ�n��A������һ����Ҫn�β�����

���nΪ�������Ϳ���ͨ�������ʽ������n��A������12��������ͨ��3�β�������3����ͨ��4�β��������帴��AAA��ճ��3��������12��A��Ҳ����12���κ�һ������A��B����һ�ֺϷ����еĲ������ȿ���������A��ͨ��һ�θ���B-1��ճ������n��Ҳ����������B��ͨ��1�θ���A-1��ճ������n���������ַ�ʽ��ã������Ҫ����һ��ȡmin������60��˵��

```
init  dp[60] = 60
check dp[60] = dp[2] + 30 = 2 + 30 = 32
check dp[60] = 2 + dp[30] = 2 + 10 = 12
check dp[60] = dp[3] + 20 = 3 + 20 = 23
check dp[60] = 3 + dp[20] = 3 + 9 = 12
check dp[60] = dp[4] + 15 = 4 + 15 = 19
check dp[60] = 4 + dp[15] = 4 + 8 = 12
check dp[60] = dp[5] + 12 = 5 + 12 = 17
check dp[60] = 5 + dp[12] = 5 + 7 = 12
check dp[60] = dp[6] + 10 = 5 + 10 = 15
check dp[60] = 6 + dp[10] = 6 + 7 = 13
```

* [124. Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)DFS+��̬�滮
	- dfs�������ÿ���ڵ�ġ�����Ϊ��β�������ֵ����������Դ
		- ֻ�����Լ�
		- ������+���Լ�
		- ������+���Լ�
	- ���ͬʱ����Ҫʱ�̸���һ�����ս������������Դ
		- ����Ϊ��β�����ֵ
		- l��β+���Լ�+r��β���ɵ�·��


* [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/) `��Ƶhard`
	- ģ��˼·�����Ҳ����һ��ʼ��˼·��������һ��һ������ӵĹ��̣�ÿ������Ҳһ����λһ����λ���ޡ������Ӹ߶�Ϊ0����λʱ������ˮ������dp[ i-1 ][ ��ߵ�λ ]��ÿ������һ����λ����Ҫ��ѯ�Լ���������ͬ�ȸ߶ȵĵ�λ�ж�Զ���Ӷ����������λ���������������廹�м����Ż��ĵط���
	- ��ˮ˼·������Solution����ı���˼·����һ����ȫ��һ����˼·������Ƕ��ǣ�***����ÿ�������Ϸ�����ܶ�����ˮ***��������˼·�͸��Ӽ��ˡ�������һ�α���ÿ�����ӵĶ�ˮ���������ӡ�����ÿ�����ӵĶ�ˮ����ȡ����������������ߵ��������Ҳ���ߵ����ӣ���2�������бȽϵ͵ģ����������ˮλ��������ˮλ��ȥ���ӵĸ߶ȣ�����������ӵĶ�ˮ����
	- ��ˮ˼·�Ż�����Ȼ�Ǽ��㶥ˮ��������ÿ����һ������ʱ�󣬼���left_max��right_max�Ƕ�ҪO(n)ɨһ�Ρ�����ط�����ͨ��dp˼��һ����������еġ��ȴ������������left_max���ٴ��ҵ������right_max


### ��������ֵ( �ҽ�β�����һ������������¯��)
����һ�����У���������������һ�������У�ʹ������������ڸ��������������ŵ�

* [718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)������Ӵ������ҽ�β�󷨣�

* [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)
	- ���A[ i ] = B[ j ], i��j֮ǰ�Ľ���϶���dp[ i-1 ][ j-1 ] + 1
	- ����Ļ�������dp[ i-1 ][ j ]��dp[ i ][ j-1 ]����������е����ֵ��

* [14. Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/) �����ǰ׺��ʹ��Trie�����

* [792. Number of Matching Subsequences](https://leetcode.com/problems/number-of-matching-subsequences/) �ж��ǲ���������

* [209. Minimum Size Subarray Sum](https://leetcode.com/problems/minimum-size-subarray-sum/) ������Ѿ�֪����nums[0..i]������̵��Ӵ�������k����ô�����֪��nums[0..i+1]����̵��Ӵ��ء��¼���ĵ�i�����֣���������¯�����Լ��ʹ���s�������߸�ǰ������һ�����ؼ���������һ���Ļ�����Ҫ��ǰ��೤���ַ������һ���أ������Ҫ����O(1)ʱ���ڲ鵽��ǰ��k���������һ���ܴﵽ��Ч����[209������](./images/leetcode209.png)

* [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
* [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) ע�⸺��������������Ҫһ��min_res��һ��max_res�����յĽ������������������е�һ�֡�
   - nums[ k ]�����¿�ʼ����¯��
   - nums[ k ] * max_res[ k - 1 ]
   - nums[ k ] * min_res[ k - 1 ]

* [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
��Ȼ�������i��β�Ļ�����Ҫ����֮ǰ���б�iС�ģ����Թ��ɵ������У�������������ܹ��ɶ೤������n�����ϵ�i��������n+1��ѡ��һ�����ģ�����res[i]�Ľ����

* [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
������Ȼ�����ÿ��i������[ i-1, 0 ]������Ԫ�أ�������������Ǿͼ����������������ϣ����ȡ�������棬���res[i]��ֵ�����������Ǹ���

* [673. Number of Longest Increasing Subsequence](https://leetcode.com/problems/number-of-longest-increasing-subsequence/)

���������������������⡣�����Ŀ�������棬Ҫ��¼һ������ĸ�������

* [674. Longest Continuous Increasing Subsequence](https://leetcode.com/problems/longest-continuous-increasing-subsequence/)

`�����������` ��`������Ӵ�`�Ա�һ�£��ᷢ��ʲô��
�ִ���Ϊ�������ģ�����ֻ��Ҫ��飬����¯����Ǹ�i-1���һ����
������������Ϊû����������Ҫ�󣬲���Ҫ�����Ƿ��ܺ�i-1���һ�������ÿ����ܲ��ܺ�i-2��i-3��i-4...0�ȵ����һ���ܴﵽ���õ�Ч����

* ������Ӵ�

```golang
func findLengthOfLCIS(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	result := make([]int, len(nums))
	result[0] = 1
	for i := 1; i < len(result); i++ {
		result[i] = 1
		for t := i - 1; t >= 0; t-- {
			if nums[i] > nums[t] {
				if result[t]+1 > result[i] {
					result[i] = result[t] + 1
				}
			}
		}
	}
	max := 0
	for _, v := range result {
		if v > max {
			max = v
		}
	}
	return max
}
```

* [740. Delete and Earn](https://leetcode.com/problems/delete-and-earn/)

����ֱ�۵��������⣬���ǿ���ת��Ϊ��������
���Ȱ����е��������򣬲��ҵõ�ÿ�����ֵ�sum�÷֡�
û�г��ֵ����ְ���0������
Ȼ�������ת��Ϊ�ˣ����������ڵ����֣���������ţ�
�ⷨ��Ȼ�����û���õ�i������result[ i ]����result[ i-1 ],������ˣ�����result[ i-2 ] + value[ i ]


* [801. Minimum Swaps To Make Sequences Increasing](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/) �ص���A��B�������鳤����ͬ������ֻ�ܽ�����ͬλ�õ�Ԫ�ء�����

```
0   1   2   3   4
------------------
0   1   6   8   10
0   4   4   5   9
```
��ʵ˼·��һ���ģ����ǹ̶���β�󷨡�����Ҫ�����`i`��β��������⣬��Ҫ�����`�������i`��β��������⡣����һ����������ӣ���i==2ʱ��Ҫ�����6��4��β�Ľ⣬Ҳ����AB�⣬ҲҪ�����4��6��β�Ľ⣬Ҳ����BA�⡣

��ô��AB���أ����A[ i ]��B[ i ]���ǵ����ģ���ô������ȻAB[ i ] ����ȡֵAB[ i-1 ]��
���A[ i ]��B[ i ]�����B[ i-1 ]��A[ i-1 ]�ǵ����ģ���ô����ȡֵBA[ i-1 ]
�������ս����min(AB[ i-1 ], BA[ i-1 ])

��BA���ԭ����ʵ����ͬ�ģ�ֻ������Ϊ��BA�⣬���������Ѿ�swap��һ�Σ����Խ����
min(ends_with_AB[ i-1 ]+1, ends_with_BA[ i-1 ]+1)

������������Ҫͨ��2�������:

* ��һ������������s[ k ]��β�������е����Ž⣬ע�⣺��˼����������е����һ��Ԫ��һ��Ҫ��s[ k ]
* �ڶ�������������0��1��2��3��...n��β�Ľ��У���max����min���Ӷ��õ�ԭʼ��������ս⡣

* [416. Partition Equal Subset Sum](https://leetcode.com/problems/partition-equal-subset-sum/)

�Ƿ��ܰ�һ�����Ϸֳ�����sum��ͬ�ļ��ϣ����ԭʼ���ϵ�sum���ܱ�2�������Ǳ�Ȼ�ǲ��еġ�
����ܱ�2��������ôֻ��˵�п��ܣ����ڵ�����ͱ���ˣ��ܷ�Ӽ����������������֣��պú�Ϊtarget = sum/2��
����˼·�������ģ�����Ѿ�֪���˴�nums[ 0 .. i-1 ]��ЩԪ�ؿ������target, ��ô�����ȷ��nums[ 0 .. i ]�ܷ�����أ�
��ʵ�����������
- ���nums[ i ]�պþ���target����ô�϶����ܹ���ɵģ�����ֻ��Ҫ����ǰ�����еģ�ֻ��Ҫһ�����־�����ɡ�
- ���nums[ 0 .. i-1 ]����ɣ���ônums[ 0 .. i ]�϶�������ɵģ����˲���nums[ i ]
- ����������Ƚϸ��ӣ����nums[ i ]����target-nums[ i ]�������target����nums[ 0 .. i-1 ]�պ������target-nums[ i ]���Ǿ������ˡ����ԣ�����Ҫ�����nums[ 0 .. i-1 ]�Ƿ������1-target֮����������

* [55. Jump Game](https://leetcode.com/problems/jump-game/)
* [45. Jump Game II](https://leetcode.com/problems/jump-game-ii/)dp�㷨��O(n^2)�����Ǻ�����

* [403. Frog Jump](https://leetcode.com/problems/frog-jump/)
���������䶯����Ŀ�����������Ѿ�֪���˿���������i��ʯͷ����ô���ȷ���ܷ�������i+1��ʯͷ�أ�
��������������i��ʯͷ�ķ�����������i-1��һ�����ķ���������i��ʯͷ���ӵ�1�鵽��i�顢�ӵ�2�鵽��i�顣�����ӵ�i-1�鵽��i�顣��Ȼ�����������е���������������ģ����ǽ���¼��Щ������������������Ҽ�¼�������Ĳ�����

���ˣ�������Щ��Ϣ�����Ǿ����ƶϳ��Ƿ��ܴ�i����i+1�ˡ�ֻ��Ҫö�ٴ�1�������������������2�������������������3���������������������ֻҪһ����������������������

* [413. Arithmetic Slices](https://leetcode.com/problems/arithmetic-slices/)
�Ƚϼ򵥵Ķ�̬�滮��dp[ i ] == dp[ i-1 ] + 1���ҽ���dp[ i ]\dp[ i-1 ]\dp[ i-2 ]�ܹ��ɵȲ�����

### �Ӵ�ѡ������

��������Ŀ����������һ����������ѡ����1������n������ĳ���������Ҳ��ص����Ӵ���ʹ����Щ�Ӵ���ĳЩ���������š�

* [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) ��һ������ѡ��һ���Ӵ���ʹ������Ӵ�����β������ڲ����������һ�����͡�
	- ˼·1�����ȶ�������в�֣�����������������sum�����Ӵ������䶯̬�滮��˼�����������ÿһ��Ԫ��Ϊ��β�Ĵ������������sum(һ��Ҫ�������Ԫ��)��������һ����������Ԫ�ء�������ִ��ο�[53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
	- ˼·2: �������һ��mins��mins[ i ]��ʾi�Լ�i֮ǰ��С�����֡���������dp[ i ] = prices[ i ] - mins[ i-1 ]

* [122. Best Time to Buy and Sell Stock II](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) ��һ������ѡ�����Ӵ���ʹ����Щ�Ӵ�����β��֮������ڲ�������ϲ��޴����������͡�
	- ˼·1: ���ô�`��ǰ����n����`��ʱ�临�Ӷ�ΪO(n)��������õķ�����
	- ˼·2: ��ʵ��������ڿ�����������������ֱ�ӽ���������д���0��������Ӽ��ɻ�ȡ���յĽ����

* [123. Best Time to Buy and Sell Stock III](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/)�ڲ�����������ȡ2�Σ������͡������Ƚϸ��ӣ����Բο���ƪ����[Best Time To Buy & Sell Stocks On Leetcode �� The Ultimate Guide](https://medium.com/algorithms-and-leetcode/best-time-to-buy-sell-stocks-on-leetcode-the-ultimate-guide-ce420259b323)

	- ˼·1 ����Ȼ��������2�Σ���ô���Կ��԰��������л���Ϊ2�����֣�һ����n+1�ֻ��ַ����������һ�β��������ڵ�һ�����֣��ڶ��β��������ڵڶ����֣���ô��n+1�ֻ��ַ������Ը�����������ˡ�����������������ܿ������dp[ l : r ]�����Ų����������Ҫ��дһ����ά���ÿ����Ԫ����ⷽ������ʵ����121���˼·��������������ʱ�临�Ӷ���O(n^3)�ռ临�Ӷ���O(n^2)�����˼·��Ϊ�ռ临�Ӷ�̫�ߣ����Թ��������һ��case��
 
## ����

* [5. Longest Palindromic Substring](https://leetcode.com/problems/longest-palindromic-substring/)
	- �м�һ�ֳ����Ĵ������Լ�����ת����������ִ������һ��������ĳ����k��k����ת����ô�������LCS�Ͳ��ǻ���
    - ��ȷ����������̬�滮:������dp[ i ][ j ]ʱ�����s[ i ] == s[ j ]����dp[ i+1 ][j-1]==true����ôdp[ i ][ j ] = true <img align="right" width="20%" src="./images/leetcode5.jpg">

* [131. Palindrome Partitioning](https://leetcode.com/problems/palindrome-partitioning/)

* [132. Palindrome Partitioning II](https://leetcode.com/problems/palindrome-partitioning-ii/)
����ǰs[0:i]�Ѿ�������ˣ���ô����һ����ĸ�Ļ��������Լ���Ϊһ�����ģ������Ļ�������s[0:i-1]���з�������ڼ��ϰ��Լ������г�һ����
���ߣ��Լ�������ǰ1����ǰ2�����������һ����ǰ��������ɻ��ģ��������ǰk�����һ���Ļ������Ǿ���Ҫ�õ���ǰ������ݡ� 

* [214. Shortest Palindrome](https://leetcode.com/problems/shortest-palindrome/)˼·�ǰ���5���dp˼�룬������Ļ����Ӵ�����s[0]��ͷ�ġ�Ȼ��ͼ��ˡ�������Ҫ���ڴ��Ż����������顣

### ����˼·����׺�����󷨣�

01�����������Ҫ˼·��ö����Ʒ�Ϳռ䣬�Ӷ�Ѱ������cost
```
F[0,0...V] <- 0
for i <- 0 to N // ö����Ʒ
    for v <- Ci to V  // ö�ٿռ�
        F[i,v] <- max{F[i - 1, v], F[i - 1, v - Ci] + Wi}
```
```
F[0,0...V] <- 0
for v <- Ci to V  // ö�ٿռ�
    for i <- 0 to N // ö����Ʒ
        F[i,v] <- max{F[v, i-1], F[v - Ci, i - 1] + Wi}
```

* [474. Ones and Zeroes](https://leetcode.com/problems/ones-and-zeroes/)
����01��������ı��֡�ÿ���ַ�������һ����Ʒ���������Ϊ1������������0�ĸ�����1�ĸ����������ַ�����0��1��˳��������ν�ģ��������ǰ�ÿ���ַ����Ĵ��۶�ת��Ϊcnt_of_zero&cnt_of_one������pair�ԡ�
���ڴ��ۿռ䣬�����Ŀ�Ĵ��ۿռ���Ҫһ��2ά�ȵı�m[ cnt_of_zero ][ cnt_of_one ]��ǧ��Ҫ���԰ɶ�ά�Ĵ��ۿռ�ת��Ϊһά�Ժ��ñ�׼01����ģ�����ף�������Ҫ��`ʣ���ֵ`ת����ȥ��������Ҫ�õ�map���ٶȻ�������ᳬʱ��

* [139. Word Break](https://leetcode.com/problems/word-break/)
��Ȼ��ʹ��n-1��n-2��n-3��n-4...������ʾn��
res[ n ]��ʾĿ���ַ���s[ 0 : n ]�ǲ���yes���ٸ����ӣ��������֪��s[ 0 : n-k]��yes�ģ�ǡ��s[n-k+1 : n]�պ����ֵ�����һ�����ʣ���ôs[ 0 : n ]����yes�ġ�������������res[ n ]��ʱ�򣬱����ֵ��������е�word�����s[ 0 : n]�պ���wordΪ��׺����ǡ������ǰ��s[0 : n - len(word) - 1]��yes�ģ���ôres[ n ]����yes�ģ�����Ĭ����no��

* [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)
 ��Ȼʹ�á���׺����������ͨ������1��4��9��16��ƽ�����֣��㷨������Ҫ������

* [322. Coin Change](https://leetcode.com/problems/coin-change/)
��Ҫ����һ��amount�������Ҫ��Ӳ��i�ĵ�i���������Ϊ���һ����Ҫ�ţ����Բ����ǲ��ŵ������
amount���Ǳ�����������

* [397. Integer Replacement](https://leetcode.com/problems/integer-replacement/)
���������еĿ����õ�������Ŀ����Ҫ�õ����档�����Ŀ������Խ�������ǻ����������㷨���죬��Ϊi/2��������Ƕ����������ܿ����������1

* [718. Maximum Length of Repeated Subarray](https://leetcode.com/problems/maximum-length-of-repeated-subarray/) ������Ӵ������䶯̬�滮����д2ά���������е�A [ i ]��B [ j ],result[ i ][ j ] ������A [ i ]��B [ j ]��β�����ַ���A [ x:i ]��B [ y:j ]��󹫹��ص������A [ i ] = B [ j ],��֤result[ i ][ j ]����Ϊ1���ٽ�һ�������result[ i - 1 ][ j - 1 ]�������0�Ļ������൱������֮ǰ��Ч�����ã���result[ i ][ j ] = result[ i - 1 ][ j - 1 ] + 1

* [39. Combination Sum](https://leetcode.com/problems/combination-sum/)

��n���������һ��sum��ÿ�����ֿ��������޴Ρ�����������һ�����ޱ������⡣
�ڼ����ἰVʱ��1����Ҫ���㵱����k��1�Ρ���2�Ρ���3�Ρ������ȵȡ��ѵ���·����¼��

* [40. Combination Sum II](https://leetcode.com/problems/combination-sum-ii/)
39���01�����汾������ȥ�رȽ��鷳��


## ��ά����

* [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) ���·�������������һ���ȽϾ���Ķ�ά·����̬�滮���⣬���ǱȽ�������ǣ������Ŀ���ߵķ������ϡ��¡����ң����������¡����Բ�����ԭʼ�������⣬���ܰ���˳����⡣��ȷ�Ľ��������һֱˢ��result��ֱ��ĳ��ˢ��result��û�и���Ϊֹ��


* [62. Unique Paths](https://leetcode.com/problems/unique-paths/)
* [63. Unique Paths II](https://leetcode.com/problems/unique-paths-ii/)

## ��������

���������˼·���ǡ���ǰ�����������ԡ���

* [91. Decode Ways](https://leetcode.com/problems/decode-ways/)�����Ŀ�ȱȽ�����˼��������Ҫע��100��0��Щ���

* [93. Restore IP Addresses](https://leetcode.com/problems/restore-ip-addresses/)


### δ��������

* [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

bit���㣬�����ǰ����������һ���ǰ�ǰһ�����ֵ����һ��bit������1�����Ծ���res[i-1]+1
�����ǰ��ż�������Լ���bit1�ĸ������϶����Լ�����һλ�γɵ����ֵ�bit1����һ���ġ�

* [357. Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/)
����n��˵��10^n�����nλ������n-1λ������Ѿ�������ˣ��Ǿ�ֻʣ�¼���nλ�������
Ҳ����9 * 9 * 8 * 7....��ô�����

* [494. Target Sum](https://leetcode.com/problems/target-sum/)

�ⷨ��Ȼ�������ȷ��dp[ : n-1 ]�Ļ������ټ����N��Ԫ�أ������ܷ�ͨ��ǰ�����������������⡣
�����Ķ���֮�����������������ⲻ�̶���������ռ�ܴ� ������Ŀ�������������Ĺ�ģ��С��
dp[ 0 : i ][num] = dp[0 : i-1][num - item[i]] + dp[0 : i-1][num + item[i]]

* [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
����Ŀ


* [343. Integer Break](https://leetcode.com/problems/integer-break/)
���ֲ�֣�ʹ�ó˻���󡣽ⷨ�ǣ�ÿ�����ֶ��ܲ��Ϊ(1,n-1)(2,n-2)(3,n-3)...(L,R)
�������ֵ��������������е�һ�֣� 
	- L * R    
	- L�� * R
	- L * R��
	- L�� * R�� 

* [198. House Robber](https://leetcode.com/problems/house-robber/)
���ǵ�ǰ��ң�max(��������)

* [337. House Robber III](https://leetcode.com/problems/house-robber-iii/)
ԭ���ֻ࣬������i��Ҫ���ʵ�i+1���i+2�����Ϣ������ÿ�εݹ鷵��ʱҲͬʱЯ���Լ���һ�����Ϣ��

* [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
�����Ļ��ֱȽϸ��ӡ����ǵ�����{1 ~ n}���ɵ�BST�ĸ��������ڶ�̬�滮�ģ����Ǳ���ͨ��{1 ~ n-1}��{1 ~ n-2}��{1 ~ n-3}�����{1 ~ n}��

```
   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
```

����n=3��˵����������ϸ�����Է��ִ�1-3��ÿһ���ڵ㶼������Ϊroot�ڵ㡣
��ȷ��root�ڵ��Ժ������L���ڵ㣬�ұ���R���ڵ㣬����L��R�Ĺ�ϵ��`L + R = n-1`��
������ߵ����нڵ��������ģ�������res[ L ]�������ͬ���ұ�Ҳ��������R������������res[ R ]�������
��ô���������Ϊrootʱ�򣬾���res[ L ] * res[ R ]�������

* ��root = 1ʱ�������root - 1 = 0���ڵ㣬�ұ���n - root = 2���ڵ㣬������res[ 0 ] * res[ 2 ] = 2�������
* ��root = 2ʱ�������root - 1 = 1���ڵ㣬�ұ���n - root = 1���ڵ㣬������res[ 1 ] * res[ 1 ] = 1�������
* ��root = 3ʱ�������root - 1 = 2���ڵ㣬�ұ���n - root = 0���ڵ㣬������res[ 2 ] * res[ 0 ] = 2�������

����һ���� 2 + 1 + 2 = 5�������
��ʵ�����Ŀ�����ǿ���������


* [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/)
�����һ��ʼ�ö�ά����������i-j�Ƿ�Ϊƥ��ģ�Ȼ�����������󡣷����ö�ά������ڴ泬����map��ʱ�䳬��

ԭ�������˼·�ǣ�
```
if s[i]=='(' the dp[i] must be 0.
else if s[i] == ')', there is two case:

case 1: s[i-1] == '('
in this case ,the s[:i] must be like -------().

if ------- is not formated ,dp[i] must be 2,
or if ------- is formated, there will be dp[i] = 2 + dp[i-2]

case 2: s[i-1] == ')'
In this case, the s[:i] must be like xy--------).
If "--------" is formated and y is '(', the dp[i] must be length(--------)+2, just dp[i] = dp[i-1] + 2

Also if substring endswith x is not zero , the dp[i] can be long to
dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]
```

* [72. Edit Distance](https://leetcode.com/problems/edit-distance/)[ ��Ƶhard ]��Ҫ��˼·����д2ά�����Ϊ�����dp[i][j]��ʱ������������ʵ�i��j��2���ַ��պ���ͬ������Ҫ�༭��ֱ������dp[i-1][j-1]������Ļ�����Ҫ�༭���༭�����ַ���
	- ��ϣ��������dp[i-1][j-1]����word1[i]�滻Ϊword2[j]��������ʹ����һ���滻����������dp[i][j] = dp[i-1][j-1] + 1
	- ��ϣ��������dp[i-1][j]����word1[0:i-1]��word2[0:j]�Ļ����ϣ���word1[i]����ַ�ɾ��������dp[i][j] = dp[i-1][j] + 1
	- ��ϣ��������dp[i][j-1]��word1[0:i]��word2[0:j-1]�Ļ����ϣ���Ҫ����һ���ַ�word2[j]��dp[i][j] = dp[i][j-1] + 1
��������������У����ִ������٣���ȡ���֡� �����Ŀ�ǱȽϼ򵥵ı༭��������������滻��ɾ�������ӵĴ��۲�ͬ�Ļ�����ô��������ļ���Ҳ��һ����

* [97. Interleaving String](https://leetcode.com/problems/interleaving-string/) �����Ҳ���ַ����������⡣��72���е㹲֮ͬ������Ҫ�ǵ�˼·�ǣ����dp[a][b][c]��֪����ô���ǵ�C����һ���ַ�
	- �������ַ���A[a]��ͬ������A[0:a-1]��B[0:b]�����C[c-1]����������������c��һ���ַ���C���ǿ��Ա���ʾ�ġ�
	- �������ַ���B[b]��ͬ������A[0:a]��B[0:b-1]�����C[c-1]����������������c��һ���ַ���C���ǿ��Ա���ʾ�ġ�
�������ɲο�[leetcode97.png](./images/leetcode97.png)��ע�⣬Ҫ�Ȱѱ߽�������д����������dp��ʱ��Ͳ��ÿ��Ǳ߽���


* [329. Longest Increasing Path in a Matrix](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/) ���·�������������һ���ȽϾ���Ķ�ά·����̬�滮���⣬���ǱȽ�������ǣ������Ŀ���ߵķ������ϡ��¡����ң����������¡����Բ�����ԭʼ�������⣬���ܰ���˳����⡣��ȷ�Ľ��������һֱˢ��result��ֱ��ĳ��ˢ��result��û�и���Ϊֹ��

* [1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

- ���A[ i ] = B[ j ], i��j֮ǰ�Ľ���϶���dp[ i-1 ][ j-1 ] + 1
- ����Ļ�������dp[ i-1 ][ j ]��dp[ i ][ j-1 ]����������е����ֵ��





# ͼ�ı���

130. Surrounded Regions


# �ֵ��� Trie

�ֵ������������ǿ��Կ��ٵĲ���Ͳ����ַ��������ҿ��԰����ֵ�˳������ַ�����ȱ����ռ�õĿռ�Ƚϴ�

211��һ���ֵ��������ı��Σ���֧��ģ��������ʵ�ַ����ǰ����еĿ��ܶ�����һ�¡�

* [211.Add and Search Word - Data structure design](https://leetcode.com/problems/add-and-search-word-data-structure-design/)

# ����

insert and find strings in O(L) Ҫ��������BST��Hash
����ֱ�����ֵ�˳��������д�
���Ժܿ����ǰ׺���������뷨�Զ���ɹ���

# ����

�ȽϷ��ڴ棬��Ϊÿ��node����һ������Ϊ26�����顣

# ������

�������Ŀ���ȽϹ̶�����Ҫ������һЩ��
* ������
* ������ȱ���
* ������ȱ��� && �������
* ˫��ͬʱ����
* ����������BST

�ڽ������ʱ������Ѱ��һ������Ĵ��Ƿ��еݹ�����ʣ�����[101.Symmetric Tree](https://leetcode.com/problems/symmetric-tree)


## ������ȱ���

��������õ������а���preorder��inorder��postorder���ֱ���������ÿ�ֱ��������ַ�Ϊ�ݹ������ѭ���������͵�����ģʽ�ı�����
����͵���������Щ��Ŀ������ֱ�ӿ����ⷽ�����ݡ�

* [94.Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal)

* [144.Binary Tree Preorder Traversal](https://leetcode.com/problems/binary-tree-preorder-traversal)

* [145.Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal)

* [173.Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator)

## ������ȱ���

������ȱ���Ҳ�а������,[102.Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal)�����Ŀ��ֱ�Ӷ԰�������Ŀ��졣
����������ĺܶ���Ŀ��һ����Ҫ�ܹ�ʶ��ÿһ��ĵ�һ���ڵ�����һ���ڵ㣬��Ҫ����Щʱ����һЩ�ر�ļ�¼���߲������ܽ�����⡣
���͵������У�

* [222.Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes)

* [116.Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node)

* [117.Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii)

* [199.Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)

����222�Ƚ�ֱ��һЩ����������������Ƚϼ�ӣ�������Ȼ�����˲��������˼�롣

## ˫��ͬʱ����

## ����

* [331. Verify Preorder Serialization of a Binary Tree](https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/)

�ѽ�������������һ�Σ�����м䲻�����⣬�������listΪ�գ�����ǰ����������


# �ַ���

* [43. Multiply Strings](https://leetcode.com/problems/multiply-strings/)ģ�������˷���ûʲô��


# ��ϣ

��ϣ˼��Ҳ���㷨�е�һ����Ҫ˼�롣��ϣ����ҪӦ����2���棺������ܺ͹��ࡣ

ͨ����������Ĺ�ϣ�����Կ����ռ���ͬ���͵����ݡ����͵���Ŀ���磺

* [49.Group Anagrams](https://leetcode.com/problems/group-anagrams/)

* [128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) ��Ҫ�����ж�һ�������ǲ����ڼ����С�


# ����

�����������Ŀ��һ��Ҫ�������`�ӳ�ָ��`

* [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)������ת��������߽�

* [141. Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)����ָ��

* [142. Linked List Cycle II](https://leetcode.com/problems/linked-list-cycle-ii/)
<img width="60%" src="./images/leetcode142.png">

* [21. Merge Two Sorted Lists](https://leetcode.com/problems/merge-two-sorted-lists/)���б�鲢��ֱ�ӹ����б����㣬���������һ��root

* [148. Sort List](https://leetcode.com/problems/sort-list/)�б�Ĺ鲢�������ʹ��һ��root�ڵ��������б�
	- TopButtom:�ݹ�
    - ButtomTop:ѭ��

* [61. Rotate List](https://leetcode.com/problems/rotate-list/)ע��һЩ�߽����

* [83. Remove Duplicates from Sorted List](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

* [82. Remove Duplicates from Sorted List II](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

* [92. Reverse Linked List II](https://leetcode.com/problems/reverse-linked-list-ii/)��ת�б���ռ�ɱ����


* [25. Reverse Nodes in k-Group](https://leetcode.com/problems/reverse-nodes-in-k-group/)ʹ��ReverseBetween�����ɱ�������׾�ʵ����

* [160. Intersection of Two Linked Lists](https://leetcode.com/problems/intersection-of-two-linked-lists/)`�漼����`,ע��һЩ�߽����������A��B�������ཻ����������һ���ǿ�

![leetcode92](./images/leetcode160.png)

* [206. Reverse Linked List](https://leetcode.com/problems/reverse-linked-list/)

## ����ת

* �жϷ�ת
	- �ж��Ƿ���Ҫ��ת���ڸ��������rootʱ����root�����ٴ���һ�����Ͻڵ�ʱ������Ҫ��ת���ҵ���ת������һ���ڵ�ʱ����תѭ��ִ��0�Ρ�
		- root == nil || root.Next == nil || root.Next.Next == nil ��ִ�з�ת

* ����ָ�룬��ת�����ʼ�� <img align="right" width="20%" src="./images/linkedlist.png">
	- `left`:		root
	- `right`:		root.Next.Next	[ ��Ҫ���� ]
	- `new_tail`:	root.Next
	- `new_head`:	root.Next		[ ��Ҫ���� ]
	- `prev`:		root.Next		[ ��Ҫ���� ]
	- `cur`:		root.Next.Next	[ ��Ҫ���� ]


* `prev`, `cur`���ȱ���
	- tprev, tcur := prev, cur
	- prev, cur := cur, cur.Next

����ת��һ��״̬����

![leetcode92](./images/leetcode92.png)

�����������Ŀ��һ��Ҫ�������`�ӳ�ָ��`

* [24. Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)
������ת��������߽�

# ����

# ջ

* [155.Min Stack](https://leetcode.com/problems/min-stack/)
������Ŀ����������Сֵ��ջ��ʵ��

* [232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)
����ջʵ��һ�����У���Ҫ�õ�����ջ��һ������push������һ������pop��ִ��push������ʱ�����ȼ��Ŀǰ�Ƿ����push״̬��������ǵĻ����͵���Ϊpush״̬��Ȼ����push����pop��ʱ��Ҳ��ͬ��

* [225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)
��������ʵ��һ��ջ����Ҫ�õ��������У������������������������У��л�����ʱ����Ҫcurrent = (current + 1) % 2

* [150. Evaluate Reverse Polish Notation](https://leetcode.com/problems/evaluate-reverse-polish-notation/)

�����沨��ʽ��ʹ�õݹ���򵥣�����ʹ��ջ+�������ٶȱȽϿ졣

* [394. Decode String](https://leetcode.com/problems/decode-string/)
�ظ�ѹ�����ַ������룬�õ�ջ��switch case��.

* [735. Asteroid Collision](https://leetcode.com/problems/asteroid-collision/)

ģ����Ŀ��ûɶ��˼����Ҫ�ǿ�˼·



# λͼ

������ݵķ�Χ�����޵ģ������ʹ��λͼ��

* [187.Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences)


* [136. Single Number](https://leetcode.com/problems/single-number/)

Explanation:
```
r = 7 ^ 3 ^ 5 ^ 4 ^ 5 ^ 3 ^ 4
```
Since XOR is associative and commutative, above expression can be written as:
```
r = 7 ^ (3 ^ 3) ^ (4 ^ 4) ^ (5 ^ 5)
  = 7 ^ 0 ^ 0 ^ 0
  = 7 ^ 0
  = 7
```

* [389. Find the Difference](https://leetcode.com/problems/find-the-difference/)

ԭ��ͬ�ϣ�����һ�Σ��ظ��Ķ�xor�����ˡ�

* [268. Missing Number](https://leetcode.com/problems/missing-number/)
ԭ��ͬ�ϣ�Ѱ�����

* [190. Reverse Bits](https://leetcode.com/problems/reverse-bits/)
��תbit���Ƚϼ�

* [393. UTF-8 Validation](https://leetcode.com/problems/utf-8-validation/)
�ж��Ƿ�����UTF-8�ַ�����ԭ��Ƚϼ�𣬵���ע��߽�����.

# �������С���ϡ��Ӽ�

![pcs](images/Permutations-combinations-subsets.png)

* [77. Combinations](https://leetcode.com/problems/combinations/)������ϣ����ۻ��󷨿��Խ�������ǱȽ�������Ϊ�����k=10�Ľ������Ҫ��k=10֮ǰ��9��8��7��6.������Ҫ��һ�Ρ��Ƿ���next_combination

* [46.Permutations](https://leetcode.com/problems/permutations/)һ��������ȫ���У������μ�[Generating Permutations and Combinations.pdf](./pdf/Generating-Permutations.pdf),Next Permutation��Ҳ���Խ��

* [47. Permutations II](https://leetcode.com/problems/permutations-ii/)���ظ�Ԫ�أ�����Ҫ��ȥ�أ�Next Permutation��ԭ��֧��ȥ��

* [31. Next Permutation](https://leetcode.com/problems/next-permutation/)Next Permutation�󷨡��������������ģ���ô���ڡ���С�ġ����С�����ģ����Ȼ��������������������λ���Ҳ࿪ʼ���������iλ�Ѿ��Ǵ�����������ˣ�˵����iλ�Ѿ�������iȫ���У���ô���ҵ�ȫ�ֵ���һ���ȵ�ǰ�����С���У���ֻ�ܴ�i�Ҳ��ҵ�һ����С�ĵ��Ǳ�i-1λ������֣�ȡ�滻��i-1λ����ʱ�˿��൱�ڡ���λ��������i�������i������λҲҪ��תһ�£��Ӷ��ﵽ��Сֵ���Ͼ�ǰ���λ�ˣ���

����һ�£�����permutation�Ĺ��̣��Ǵ�123456�𽥱仯Ϊ654321�Ĺ��̣��ɵ������ݼ������ݼ�˳���ֵ�����ģ���Ϊ�������ֶ��ڸ�λ�����ǽ��б仯��ʱ�����ȳ��Խ��Ҳ��Ϊ�ݼ������У�Ȼ���������ţ�ֱ���������ж���ɵݼ��ġ�
���ԣ���һ������Ѱ���Ҳ�ĵݼ����еĿ�ʼ��(����������)��Ҳ�С���λ�㡱���ҵ��Ժ�������Ҳ�������ǵݼ��ģ��Ѿ�������ˣ����ʱ������ֻ�ܡ���λ�������ǽ�λ��ʱ����Ҫ�ó���λ���Լ���λ���Ҳ��һ�����������н�λ�����ĸ��أ��ñȽ�λ��ǰһ�����ִ����������������С�ģ��������ܱ�֤������С��Ȼ��ѽ�λ���Լ��Ҳ����������

* [60. Permutation Sequence](https://leetcode.com/problems/permutation-sequence/)���������Ŀһ����ֻ�����¸�ϰ��һ��

* [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)
***To enumerate something, generally we would like to express it as a sum of disjoint subsets that are easier to count.***
�����������ö�٣���ôһ����˵������Ҫ���ǵķ�������һЩ��������Ĳ��鼯�ĺ�����ʾ��```closure number```

* [78. Subsets](https://leetcode.com/problems/subsets/)

ʹ��λͼ����ʾ�Ӽ���һ�����õķ�������ȥ�ع��ܶ����ˡ����Ǹ�����ķ��������������ǳ����ǣ��Ͳ����ˡ�
��ȷ�ķ�ʽ��ʹ��`�ۻ���Ϸ�`��ÿ�����Ԫ�ص�ʱ�򣬶��������Ѿ��еĳɹ����һ�£�Ҳ��ӽ�ȥ�������γ����յĽ����

* [90. Subsets II](https://leetcode.com/problems/subsets-ii/)
78���������ظ�Ԫ�ء�
����������1��2��2��3��3��
ͬ�����Ǳ�������Ԫ�أ�ÿ��Ԫ�ض��ܶ�result����diff������
��ͬ���ǣ�������Ԫ�����ϸ�Ԫ�ز�ͬ������78���еĽⷨ�����������ȫ����
�����ͬ�Ļ�����ʵ��û��Ҫ�ں�ǰ�����ҵ�������ˣ���Ϊ��һ��Ԫ���Ѿ����ˡ�
��ʱ�˿̣�ֻ��Ҫ����һ��Ԫ�ز�����diff������ϣ��γ�������

# ����

�ܶ����Ż����⣬��ʵֻҪ��Ŀ�꼯�Ͻ������򣬾ͻ��м���ѭ��

һ��������ַ������򷽷�ģʽ [179. Largest Number](https://leetcode.com/problems/largest-number/)

[524. Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

# ̰��

̰���㷨�ĳ��ù��������ȶ���priority_queue����Ϊʱ�̶�Ҫȡ��ǰ�����Ž�

unsolved[1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

����Ŀ�������

# ����

## Catalan Number

![Catalan1.png](./images/catala1.png)

* [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
catalan����ı��棬�ܹ���n��Ԫ�أ�ÿһ��Ԫ�ض����Ե���root�ڵ㣬ʣ�µ�n-1��Ԫ���У���߷���i�����ұ߷���n-1-i����

* [22. Generate Parentheses](https://leetcode.com/problems/generate-parentheses/)

���Գ���Ϊcatalan��ģ�ͣ��κ�һ��n>0�����⣬�����Ա��Ϊ`(����)����`


# ��

* [23. Merge k Sorted Lists](https://leetcode.com/problems/merge-k-sorted-lists/solution/)

�����㷨��ÿ��ȡͷ�ڵ㲢������Сֵ������Ҫά��һ��ͷ�ڵ���Сֵ�ļ��ϡ����������Ļ�������ʱ�临�Ӷ�o(1)����������Сֵ��ʱ�临�Ӷ���O(n)������������ȶ��У�����Ȼ�����ʱ�������O(lgN)����ѡ����Сֵ��ʱ�临�Ӷ�Ҳ��O(lgN)�����ͻ��ܶࡣ











