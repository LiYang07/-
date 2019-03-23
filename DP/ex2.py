
def FindGreatestSumOfSubArray(array):
        f = array[0]
        res = array[0]
        for i in range(1,len(array)):
            f = max(f+array[i],array[i])
            res = max(res,f)
        return res
a=[6,-3,-2,7,-15,1,2,2]
print(FindGreatestSumOfSubArray(a))