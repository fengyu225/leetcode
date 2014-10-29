def knapsack(val,wt,w):
    # duplicate allowed
    sz = len(val)  
    arr = [0 for i in range(w+1)]
    for i in range(1,w+1,1):
        temp = 0
        for idx,a_wt in enumerate(wt):
            if i>=a_wt:
                temp = max(temp,arr[i-a_wt]+val[idx])
        arr[i] = temp
    print arr
    return max(arr)

print knapsack([60,100,120], [10,20,30], 50)
