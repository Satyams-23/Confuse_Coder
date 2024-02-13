# sum of array

def sum(arr):
    n = len(arr)
    sum = 0
    for i in range(n):
        sum = sum + arr[i]
    return sum




arr = [1, 2, 3, 4, 5]
print(sum(arr))


# Rotate Array by k steps

def rotate_array(nums, k):
    n = len(nums)
    k %= n 
    # To handle cases where k is larger than the array length
    
    # Reverse the entire array
    reverse(nums, 0, n - 1)
    # 7, 6, 5, 4, 3, 2, 1 
    
    # Reverse the first k elements
    reverse(nums, 0, k - 1)
    # 5, 6, 7, 4, 3, 2, 1   
    
    # # Reverse the remaining elements
    reverse(nums, k, n - 1)
    # 5, 6, 7, 1, 2, 3, 4   

def reverse(nums, start, end):
    while start < end:
        # Swap the first and last elements
        nums[start], nums[end] = nums[end], nums[start]

        start += 1
        end -= 1
        



# Example usage:
nums = [1, 2, 3, 4, 5, 6, 7]
# nums = [5, 6, 7, 1, 2, 3, 4 ]
rotate_array(nums, 3)
print(nums)



# def func(arr)   :
#     n = len(arr)
#     for i in range(n):
#         for j in range(i+1, n):
#             if(arr[i] == arr[j]):
#                 print( i, j)
#                 return 

# arr = [1, 2, 4, 4, 5,5]
# func(arr)
# print("done")


