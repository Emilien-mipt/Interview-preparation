import copy

'''
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
'''

def binary_search(nums, target):
    left, right = 0, len(nums)-1
    while left <= right:
        mid = left + (right-left)//2
        if nums[mid] == target:
            return mid
        elif nums[mid] > target:
            right = mid-1
        else:
            left = mid+1
    return -1

def remove_element_1(nums, val):
    """
    :type nums: List[int]
    :type val: int
    :rtype: int
    """
    i = 0
    while i < len(nums):
        if nums[i] == val:
            nums.remove(nums[i])
        else:
            i+=1
    return len(nums)

def remove_element_2(nums, val):
    while True:
        try:
            nums.remove(val)
        except:
            break
    return len(nums)

def remove_element_3(nums, val):
    while True:
        ind = binary_search(nums, val)
        print("INDEX: ", ind)
        if ind < 0:
            break
        else:
            nums.remove(val)
    return len(nums)
            
        


def main():
    a = [] 
    n = int(input())  # number of elements in the list
    for i in range(n):  
        new_element = int(input())  # input an element
        a.append(new_element)  # add it to the list
    b = copy.deepcopy(a)
    c = copy.deepcopy(a)
    assert(a == b == c)
    value = int(input()) # value to remove
    print("array after filling: ", a, b, c)
    result_a = remove_element_1(a, value)
    result_b = remove_element_2(b, value)
    result_c = remove_element_3(c, value)
    assert(result_a == result_b == result_c)
    print("array after value removing: ", a, b, c)
    print(result_a)
    print(result_b)
    print(result_c)

if __name__ == "__main__":
    main()
