/*
    题目：
        数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
        例如输入一个长度为9的数组[1,2,3,2,2,2,5,4,2]。由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。
        你可以假设数组是非空的，并且给定的数组总是存在多数元素。1<=数组长度<=50000。
    思路：
        摩尔投票法： 核心理念为 票数正负抵消 。此方法时间和空间复杂度分别为 O(N)O(N) 和 O(1)O(1) ，为本题的最佳解法。
        设输入数组nums的众数为x，数组长度为n。
        推论一： 若记众数的票数为+1 ，非众数的票数为−1 ，则一定有所有数字的票数和>0。
        推论二： 若数组的前a个数字的票数和=0，则数组剩余(n−a)个数字的票数和一定仍>0 ，即后(n−a)个数字的众数仍为x。
*/

int MoreThanHalfNum_Solution(vector<int> numbers){
    int x = 0;
    int votes = 0;
    for(int num : numbers){
        if(votes == 0)
            x = num;
        votes += num == x ? 1 : -1;
    }
    return x;
}