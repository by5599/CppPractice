#ifndef LEETCODE_211REMOVEDUPLICATESFROMSORTEDARRAY_H_INCLUDED
#define LEETCODE_211REMOVEDUPLICATESFROMSORTEDARRAY_H_INCLUDED

class Solution
{
public:
    static int removeDuplicates(int A[], int n)
    {
        if (n == 0) return 0;
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (A[index] != A[i])
            {
                A[++index] = A[i];
            }
        }
        return index + 1;
    }
};

#endif // LEETCODE_211REMOVEDUPLICATESFROMSORTEDARRAY_H_INCLUDED
