lst=[]
lst1=[]
n=int(input("Enter the size of the list:"))
for i in range(0,n):
    num=int(input())
    lst.append(num)
while(1):
    print("\nMENU")
    print("1.Length of a list.")
    print("2.Sort the list.")
    print("3.Maximam element in a list.")
    print("4.Minimum element in a list.")
    print("5.Reverse a list.")
    print("6.Pop.")
    print("7.Append")
    print("8.Number of occurence of a value.")
    print("9.Extend a list.")
    print("10.Insert at a particular position.")
    print("11.Remove a particular element.")
    print("12.Remove all the element in the list.")
    print("13.Exit.")
    ch=int(input("Enter your choice:"))
    if ch==1:
        print("The length of the list is: ",len(lst))
    elif ch==2:
        print("Before sorting: ",lst)
        lst.sort()
        print("Sorted list is: ",lst)
    elif ch==3:
        print("The Maximam element in the list is: ",max(lst))
    elif ch==4:
        print("The Maximam element in the list is: ",min(lst))
    elif ch==5:
        print("Before reversing.",lst)
        lst.reverse()
        print("The reversed list is: ",lst)
    elif ch==6:
        print("The poped element is: ",lst.pop())
    elif ch==7:
        app=int(input("Enter the element to be appended: "))
        lst.append(app)
        print("The list after appending is: ",lst)
    elif ch==8:
        ct=int(input("Enter the value to be counted: "))
        print("Number of times ",ct," occurred is: ", lst.count(ct))
    elif ch==9:
        n1=int(input("Enter number of elements : "))
        print("Enter the elements:")
        for i in range(0, n1):
            num1=int(input())
            lst1.append(num1)
        lst.extend(lst1)
        print("The extended list is: ",lst)
    elif ch==10:
        pos=int(input("Enter the position at which the element has to be added:"))
        ele=int(input("Enter the element to be inserted."))
        lst.insert(pos-1,ele)
        print("The list after adding",ele,"at position",pos,"is: ",lst)
    elif ch==11:
        rm=int(input("Enter a element to be deleted."))
        if(rm in lst):
            lst.remove(rm)
            print("The list is: ",lst)
        else:
            print("\n\nElement not present.")
    elif ch==12:
        lst.clear()
        print("After deletion the list looks like: ",lst)
    elif ch==13:
        print("\nProgram End!!!")
        break;
    else:
        print("Invalid Input")