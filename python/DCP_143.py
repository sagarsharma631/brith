#   AUTHOR - SAGAR SHARMA
#
#   For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].

def swap(my_list,first,second):
    if(my_list[first] == my_list[second]):
        return
    my_list[first] = my_list[first] + my_list[second]
    my_list[second] = my_list[first] - my_list[second]
    my_list[first] = my_list[first] - my_list[second]
    return

def DutchNationalFlag(elem,pivot):
    swapIndex = 0
    item = 0
    # first parse towards left to right
    while(item < len(elem)):
        if(my_list[item] >= pivot):
            pass
        else:
            swap(my_list,swapIndex,item)
            swapIndex += 1
        item += 1
            
    
    # second parse from right to left
    swapIndex = len(elem) - 1
    item = len(elem) - 1;
    while(my_list[item] >= pivot):
        if(my_list[item] > pivot):
            swap(my_list,swapIndex,item)
            swapIndex -= 1
        item -= 1
            
my_list = [9,12,3,5,14,10,10]

DutchNationalFlag(my_list,10)

print(my_list)
    
    
