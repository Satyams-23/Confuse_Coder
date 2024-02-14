# Given an array of integers nums and an integer target, return the indices of the two numbers that add up to the target.

# nums = [2,7,11,15], target = 22   

# Output: [1,3] 

# ///////Worst CASE SCENARIO////////  O(n^2)  ///////Worst CASE SCENARIO////////  

# def func(nums, target):
#     for i in range(len(nums)):

#         for j in range(i+1, len(nums)):
#             if nums[i] + nums[j] == target:
#                 return [i, j]  
        
# # 2 + 7 = 9 //22
# # 2 + 11 = 13 //22    
# # 2 + 15 = 17 //22    
# # 7 + 11 = 18 //22 
# # 7 + 15 = 22 //22 correct answer 
            
# nums = [2,7,11,15]
# target = 22   
# print(func(nums, target)) 


# ///////Best CASE SCENARIO////////  O(n)  ///////Best CASE SCENARIO//////// 

#nums = [2,7,11,15], target = 22

def func(nums, target):    
    D = {}  
    for i ,num in enumerate(nums): # enumerate() method adds a counter to an iterable and returns it in a form of enumerate object. 
        complement = target - num
        if complement in D:
            return [D[complement], i]  
        D[num] = i 


D ={2:0, 7:1, 11:2, 15:3}    
        
nums = [2,7,11,15]
target = 22

print(func(nums, target))

# time complexity is O(n) because the time taken to search for the complement in the dictionary is O(1)



