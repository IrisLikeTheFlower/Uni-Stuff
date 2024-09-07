a=2+4
print(a)
print("hi")

if 1>0:
    print("x")
else:
    print("y")
if 1>6:
    print("x")
else:
    print("y")
    
if 1>0 and 5<6:
    print("x")
else:
    print("y")
if 1>0 and 5>6:
    print("x")
else:
    print("y")
    

for i in range(5):
    print(i)
    
    

def my_func(x,y):
    c=x+y
    print(c)
    return c
    


r=my_func(2,7)
print(r)
    
    
    
def factorial_for(x):
    if x <= 0:
        return 1
    c=1
    for i in range(1, x+1):
        c*=i
    return c
def factorial_rec(x):
    if x<=0:
        return 1
    return x*factorial_rec(x-1)



f_f = factorial_for(5)
f_r = factorial_rec(6)
print(f_f, f_r)



a=[1,2,3]
print(a)
a.append(4)
print(a)
print("len",len(a))
a[1]=5
print(a)
k = a[2]
a.insert(1,2)
print(a)
del a[2]
print(a)
