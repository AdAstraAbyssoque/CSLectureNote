#kind of python code to show the Modualization
#11_24_1.py
def find_max_index(l):
    max_index = 0  # Initialize max_index to 0 instead of l[0]
    for i in range(0, len(l)):
        if l[i] > l[max_index]:  # Compare with l[max_index] instead of max_index
            max_index = i
    return max_index

def max_sort_recursive(l):
    if len(l) == 1:
        return l
    max_index = find_max_index(l)
    l[0], l[max_index] = l[max_index], l[0]
    return l[:1] + max_sort_recursive(l[1:])

sample_list = [1, 3, 2, 4, 5]
print(find_max_index(sample_list))
print(max_sort_recursive(sample_list))