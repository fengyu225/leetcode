def wiggleSort(nums):
    nums.sort()
    half = len(nums[::2])
    nums[::2], nums[1::2] = nums[:half][::-1], nums[half:][::-1]

if __name__ == "__main__":
    nums = [1,3,2,2,2,1,1,3,1,1,2]
    wiggleSort(nums)
    print nums