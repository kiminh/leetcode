# leetcode
My leetcode solutions

# �����ѵ

* һ��Ҫ�ɹ��ܾ���ϸ��Ϊ����������һ������˼·�Ƚ����������߿�����ĳЩ�����ֱ��returnֵ��
* ����������ʽ��һ�����У���������룺���Ρ����桢̰����һ�㲻������������Ϊ�ܷ�ʱ�䣬ջ���п��������


# ����

�ܶ���Ŀ��ʵ����һ��������+��֦���Ĺ��̣���ʵ������һ���ǳ�ͨ�õķ������κ�һ�����Ż����͵���Ŀ����ʵ������ͨ�������������ֻ�Ƕ��ڼ򵥵ı���������˵�������ռ��Ƿǳ��޴��������һ�����޵Ŀռ䣬��ν�ġ��Ż�����ʵ���Ƕ������ռ���й����ܽᣬ��������￪ʼ�ѣ�����������ʲô����Щ�ӿռ��ǿ����ų����ⲻ��Ҫ�����ġ�

����ʶ����Ҫ�������ӿռ�ļ�����������֦��ͨ��������Щ�ӿռ䣬��ʵ������Ч�ʵ�Ŀ�ġ���ʵ�ںܶ������У�����Ľ�ռ���Ȼ�󣬵������ڸ���Լ����������Ҫ�����Ŀ���ֻ�����к�Сһ���֡�

��������������⣬���ǿ������ȹ۲�ϵͳ�еı����м����������2���Ļ���������һ����άƽ��ľ����н�������������������Ļ���������һ����ά�ռ�ĳ������н���������

����������أ��ܶ�������Ǿ��εĶ������������Ķ��㡣

����11�⣬Ѱ�����װˮ���������Ŀ����Ѱ��2�����ӣ�ʹ��װˮ���������ϵͳ�еı�������2����ÿ��������ȡֵ��Χ��n��Ҳ���ǽ�ռ���һ��n*n�Ķ�ά�ռ䡣������Ҫ�������ά�ռ��������������������ϸ�۲죬���ǿ��Է��ְ�l��r�Ե�����ʵ��һ���ظ������⣬������ռ����СΪԭ����һ�룬�پ����۲죬�Ϳ����ҵ�������·���ɼ�֦�ķ�����


# ��̬�滮

��̬�滮һ����һά���滮���Ͷ�ά���滮��

## һά����
����һά������Ҫ�ص�����һ�������Ͻ��е�������i��item��״̬����ǰ1������ǰn��Ԫ�ص�״̬��أ�ͨ��ȡmin��max����bool���ó���

����˼·��
* ����˼·-��׺������
* �ҽ�β˼·-���ҽ�β��������¯����������

### ���仯����������

* [303. Range Sum Query - Immutable](https://leetcode.com/problems/range-sum-query-immutable/)
Ƶ����ȡ����ͣ������һ���ۼӺ����У���ʱ�����һ�¾Ϳ����ˡ�

### [338. Counting Bits](https://leetcode.com/problems/counting-bits/)

bit���㣬�����ǰ����������һ���ǰ�ǰһ�����ֵ����һ��bit������1�����Ծ���res[i-1]+1
�����ǰ��ż�������Լ���bit1�ĸ������϶����Լ�����һλ�γɵ����ֵ�bit1����һ���ġ�

### [357. Count Numbers with Unique Digits](https://leetcode.com/problems/count-numbers-with-unique-digits/)
����n��˵��10^n�����nλ������n-1λ������Ѿ�������ˣ��Ǿ�ֻʣ�¼���nλ�������
Ҳ����9 * 9 * 8 * 7....��ô�����

### ��������ֵ( �ҽ�β����������������¯��)
����һ�����У���������������һ�������У�ʹ������������ڸ��������������ŵ�

 * [53. Maximum Subarray](https://leetcode.com/problems/maximum-subarray/)
 * [152. Maximum Product Subarray](https://leetcode.com/problems/maximum-product-subarray/) ע�⸺��������������Ҫһ��min_res��һ��max_res�����յĽ������������������е�һ�֡�
    - nums[ k ]�����¿�ʼ����¯��
    - nums[ k ] * max_res[ k - 1 ]
    - nums[ k ] * min_res[ k - 1 ]

* [300. Longest Increasing Subsequence](https://leetcode.com/problems/longest-increasing-subsequence/)
��Ȼ�������i��β�Ļ�����Ҫ����֮ǰ���б�iС�ģ����Թ��ɵ������У�������������ܹ��ɶ೤������n�����ϵ�i��������n+1��ѡ��һ�����ģ�����res[i]�Ľ����

* [368. Largest Divisible Subset](https://leetcode.com/problems/largest-divisible-subset/)
������Ȼ�����ÿ��i������[ i-1, 0 ]������Ԫ�أ�������������Ǿͼ����������������ϣ����ȡ�������棬���res[i]��ֵ�����������Ǹ���

������������Ҫͨ��2�������:

* ��һ������������s[ k ]��β�������е����Ž⣬ע�⣺��˼����������е����һ��Ԫ��һ��Ҫ��s[ k ]
* �ڶ�������������0��1��2��3��...n��β�Ľ��У���max����min���Ӷ��õ�ԭʼ��������ս⡣

### [55. Jump Game](https://leetcode.com/problems/jump-game/)

### [121. Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
121.���ȶ�������в�֣�����������������sum�����Ӵ������䶯̬�滮��˼�����������ÿһ��Ԫ��Ϊ��β�Ĵ������������sum(һ��Ҫ�������Ԫ��)��������һ����������Ԫ�ء�

### [70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/)
����Ŀ

### [91. Decode Ways](https://leetcode.com/problems/decode-ways/)
�����Ŀ�ȱȽ�����˼��������Ҫע��100��0��Щ���

### [343. Integer Break](https://leetcode.com/problems/integer-break/)
���ֲ�֣�ʹ�ó˻���󡣽ⷨ�ǣ�ÿ�����ֶ��ܲ��Ϊ(1,n-1)(2,n-2)(3,n-3)...(L,R)
�������ֵ��������������е�һ�֣� 
- L * R    
- L�� * R
- L * R��
- L�� * R�� 

### [198. House Robber](https://leetcode.com/problems/house-robber/)
���ǵ�ǰ��ң�max(��������)

### [337. House Robber III](https://leetcode.com/problems/house-robber-iii/)
ԭ���ֻ࣬������i��Ҫ���ʵ�i+1���i+2�����Ϣ������ÿ�εݹ鷵��ʱҲͬʱЯ���Լ���һ�����Ϣ��

### [96. Unique Binary Search Trees](https://leetcode.com/problems/unique-binary-search-trees/)
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

### ����˼·����׺�����󷨣�

* [139. Word Break](https://leetcode.com/problems/word-break/)
��Ȼ��ʹ��n-1��n-2��n-3��n-4...������ʾn��
res[ n ]��ʾĿ���ַ���s[ 0 : n ]�ǲ���yes���ٸ����ӣ��������֪��s[ 0 : n-k]��yes�ģ�ǡ��s[n-k+1 : n]�պ����ֵ�����һ�����ʣ���ôs[ 0 : n ]����yes�ġ�������������res[ n ]��ʱ�򣬱����ֵ��������е�word�����s[ 0 : n]�պ���wordΪ��׺����ǡ������ǰ��s[0 : n - len(word) - 1]��yes�ģ���ôres[ n ]����yes�ģ�����Ĭ����no��

* [279. Perfect Squares](https://leetcode.com/problems/perfect-squares/)
 ��Ȼʹ�á���׺����������ͨ������1��4��9��16��ƽ�����֣��㷨������Ҫ������

* [322. Coin Change](https://leetcode.com/problems/coin-change/)
��Ҫ����һ��amount�������Ҫ��Ӳ��i�ĵ�i���������Ϊ���һ����Ҫ�ţ����Բ����ǲ��ŵ������
amount���Ǳ�����������


## ��ά����


# permutation����

����������ɼ�����


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

[222.Count Complete Tree Nodes](https://leetcode.com/problems/count-complete-tree-nodes)
[116.Populating Next Right Pointers in Each Node](https://leetcode.com/problems/populating-next-right-pointers-in-each-node)
[117.Populating Next Right Pointers in Each Node II](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii)
[199.Binary Tree Right Side View](https://leetcode.com/problems/binary-tree-right-side-view/)
����222�Ƚ�ֱ��һЩ����������������Ƚϼ�ӣ�������Ȼ�����˲��������˼�롣

## ˫��ͬʱ����



# ��ϣ

��ϣ˼��Ҳ���㷨�е�һ����Ҫ˼�롣��ϣ����ҪӦ����2���棺������ܺ͹��ࡣ

ͨ����������Ĺ�ϣ�����Կ����ռ���ͬ���͵����ݡ����͵���Ŀ���磺

* [49.Group Anagrams](https://leetcode.com/problems/group-anagrams/)


# �б�

# ����

# ջ

������Ŀ����������Сֵ��ջ��ʵ��[155.Min Stack](https://leetcode.com/problems/min-stack/)

����ջʵ��һ������[232. Implement Queue using Stacks](https://leetcode.com/problems/implement-queue-using-stacks/)����Ҫ�õ�����ջ��һ������push������һ������pop��ִ��push������ʱ�����ȼ��Ŀǰ�Ƿ����push״̬��������ǵĻ����͵���Ϊpush״̬��Ȼ����push����pop��ʱ��Ҳ��ͬ��

��������ʵ��һ��ջ[225. Implement Stack using Queues](https://leetcode.com/problems/implement-stack-using-queues/)����Ҫ�õ��������У������������������������У��л�����ʱ����Ҫcurrent = (current + 1) % 2



# λͼ

������ݵķ�Χ�����޵ģ������ʹ��λͼ��

* [187.Repeated DNA Sequences](https://leetcode.com/problems/repeated-dna-sequences)
* [78. Subsets](https://leetcode.com/problems/subsets/)
ʹ��λͼ����ʾ�Ӽ���һ�����õķ�������ȥ�ع��ܶ����ˡ�

# �������С����

����Ƚ��鷳

* [46.Permutations](https://leetcode.com/problems/permutations/)
* [78.Subsets](https://leetcode.com/problems/subsets/)


# ����

�ܶ����Ż����⣬��ʵֻҪ��Ŀ�꼯�Ͻ������򣬾ͻ��м���ѭ��

һ��������ַ������򷽷�ģʽ [179. Largest Number](https://leetcode.com/problems/largest-number/)

[524. Longest Word in Dictionary through Deleting](https://leetcode.com/problems/longest-word-in-dictionary-through-deleting/)

# ̰��

̰���㷨�ĳ��ù��������ȶ���priority_queue����Ϊʱ�̶�Ҫȡ��ǰ�����Ž�

unsolved[1353. Maximum Number of Events That Can Be Attended](https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/)

����Ŀ�������








