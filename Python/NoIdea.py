'''
There is an array of  integers. There are also  disjoint sets,  and , each containing integers. You like all the integers in set  and dislike all the integers in set . Your initial happiness is . For each  integer in the array, if , you add  to your happiness. If , you add  to your happiness. Otherwise, your happiness does not change. Output your final happiness at the end.
Note: Since  and  are sets, they have no repeated elements. However, the array might contain duplicate elements.

Constraints

Input Format
The first line contains integers  and  separated by a space.
The second line contains  integers, the elements of the array.
The third and fourth lines contain  integers,  and , respectively.

Output Format
Output a single integer, your total happiness.

Sample Input
3 2
1 5 3
3 1
5 7
Sample Output
1
Explanation
You gain  unit of happiness for elements  and  in set . You lose  unit for  in set . The element  in set  does not exist in the array so it is not included in the calculation.
Hence, the total happiness is 1.
'''

x = input().split()
arr_len = x[0]
set_len = x[1]
arr_i = input().split()
arr_i = list(map(int,arr_i))
a = input().split()
a = list(map(int,a))
a = set(a)
b = input().split()
b = list(map(int,b))
b = set(b)
c = a.union(b)
arr_i = (i for i in arr_i if i in c)
count = 0
for i in arr_i:
    if i in a and i not in b:
        count = count + 1
    if i in b and i not in a:
        count = count - 1
print(count)