# Arrays
# All the elements in an array are of the same data type.  
# the element starts with index 0  num = [1,2,3,4,5,6,7,8,9,10]  
# 0 to 9
#homogeneous data type  - array
#heterogeneous data type - list or tuple

#example of array   
 
fruits = ["apple", "banana", "cherry", "orange", "kiwi", "melon", "mango"]  
numbers = [1,2,3,4,5,6,7,8,9,10] 


print(numbers[5])   
print(fruits[5])    

# Array mutable 

fruits[2] = "grapes" 

print(fruits[2])

Marks = [10,20,30,40,50,60,70,80,90,100]

Total = sum(Marks)
print(Total)

Average = Total/len(Marks)  

print(Average)
=======
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
    D = {}  # empty dictionary 
    for i ,num in enumerate(nums): # enumerate means to get the index and the value of the array  
        complement = target - num
        if complement in D:
            return [D[complement], i]  
        D[num] = i 


D ={2:0, 7:1, 11:2, 15:3}    
        
nums = [2,7,11,15]
target = 22

print(func(nums, target))

# time complexity is O(n) because the time taken to search for the complement in the dictionary is O(1)



