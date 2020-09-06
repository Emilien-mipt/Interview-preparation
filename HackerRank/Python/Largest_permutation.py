def fill_dict(arr):
	output_dict = {}
	for i in range(len(arr)):
		output_dict[arr[i]] = i
	return output_dict

def largestPermutation(k, n, arr):
    pos = fill_dict(arr)
    
    for i in range(n): 
        # If k is exhausted then break the loop 
        if k == 0: 
            break
  
        # If element is already largest then no need to swap 
        if (arr[i] == n-i): 
            continue
  
        # Find position of i'th largest value, n-i 
        temp = pos[n-i] 
  
        # Swap the elements position 
        pos[arr[i]] = pos[n-i] 
        pos[n-i] = i 
  
        # Swap the ith largest value with the value at  
        # ith place 
        arr[temp], arr[i] = arr[i], arr[temp] 
  
        # Decrement K after swap 
        k = k-1
    return arr

if __name__ == '__main__':
	n = int(input())
    k = int(input()) 
    arr = [int(i) for i in input().split()]    

    result = largestPermutation(k, arr)

    print(result)
