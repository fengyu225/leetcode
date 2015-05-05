
class Solution:
    # @param prices, a list of integer
    # @return an integer
    def maxProfit(self, prices):
        if len(prices) == 0:
            return 0
        left_small = [-1 for i in range(len(prices))]
        right_large = [-1 for i in range(len(prices))]
        left_small[0] = 0
        right_large[len(prices)-1] = len(prices)-1
        for i in range(1,len(prices)):
            left_small[i] = left_small[i-1] if prices[i]>=prices[left_small[i-1]] else i
            j = len(prices)-1-i
            right_large[j] = right_large[j+1] if prices[j]<=prices[right_large[j+1]] else j
        return max(prices[right_large[i]]-prices[left_small[i]] for i in range(len(prices)))

if __name__ == "__main__":
    print Solution().maxProfit([1,2,1,5,10])
