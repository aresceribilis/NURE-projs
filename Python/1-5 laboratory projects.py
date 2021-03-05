# Num 9
# asd

ls2 = ''
ls1 = input()
while True:
    if ls1.isalpha():
        break
    else:
        ls1 = input()

i = 0
while i < len(ls1):
    ls_tmp = ls1[ls1.find(ls1[i]):ls1.rfind(ls1[i]) + 1]
    ls2 += (ls1[i]+str(len(ls_tmp)))
    i += len(ls_tmp)

if len(ls2) < len(ls1):
    print(ls2)
else:
    print(ls1)

# Num 12
# 9 6 8 7 4 5 3 1 2
ls = input().split()
while True:
    if (''.join(ls)).isdigit() and len(''.join(ls)) != 0:
        break
    else:
        ls = input().split()
print(ls)
print()

"""
tmp = ls.index(min(ls))
ls[0], ls[tmp] = ls[tmp], ls[0]
print(ls)
print()

tmp = ls[0]
ls = ls[1:]
print(ls)
print()

ls.sort()
print(ls)
ls.reverse()
print(ls)    
print()

ls.insert(0, tmp)
print(ls)
"""

ls.sort()
print(ls)
ls.reverse()
print(ls)
ls.insert(0, ls[-1])
print(ls)
ls.pop()
print(ls)
print()



def normal_function():
    print("Classic function:")
    print("       &           ")
    print("     *   *         ")
    print("   &        &      ")
    print("*              *   ")
    print("&                 &")
    print("*                 *")
    print("&      &          &")
    print("*    *   *        *")
    print("&  &      &       &")
    print("*          * & * &*\n")
def normal_function_v2(a,b):
    print("Parametric function:")
    print("       "+a+"           ")
    print("     "+b+"   "+b+"         ")
    print("   "+a+"        "+a+"      ")
    print(b+"              "+b+"   ")
    print(a+"                 "+a)
    print(b+"                 "+b)
    print(a+"      "+a+"          "+a)
    print(b+"    "+b+"   "+b+"        "+b)
    print(a+"  "+a+"      "+a+"       "+a)
    print(b+"          "+b+" "+a+" "+b+" "+a+b+"\n")
anonimus_function =(lambda a,b: "Anonimus function:\n       "+a+"           \n     "+b+"   "+b+"         \n   "+a+"        "+a+"      \n"+b+"              "+b+"   \n"+a+"                 "+a+"\n"+b+"                 "+b+"\n"+a+"      "+a+"          "+a+"\n"+b+"    "+b+"   "+b+"        "+b+"\n"+a+"  "+a+"      "+a+"       "+a+"\n"+b+"          "+b+" "+a+" "+b+" "+a+b+"\n")
def decorator_function1(a,b):
    def decorator_function2():
        print("Decorator function:")
        print("       "+a+"           ")
        print("     "+b+"   "+b+"         ")
        print("   "+a+"        "+a+"      ")
        print(b+"              "+b+"   ")
        print(a+"                 "+a)
        print(b+"                 "+b)
        print(a+"      "+a+"          "+a)
        print(b+"    "+b+"   "+b+"        "+b)
        print(a+"  "+a+"      "+a+"       "+a)
        print(b+"          "+b+" "+a+" "+b+" "+a+b+"\n")
        return decorator_function2
normal_function()
normal_function_v2(a = "&", b = "*")
print(anonimus_function(a = "&", b = "*"))
some_function = decorator_function1(a = "&", b = "*")
some_function
print()



arr = []
with open(r"E:\tree\python\works\pz3_before.txt", "w") as file: 
    file.write("dungeon_master\nslave\nboy_next_door\nlather_man\n")
with open(r"E:\tree\python\works\pz3_before.txt", "r") as file:
    for i in file:
        arr.append(i.rstrip('\n'))
#for i in arr:
#    print(i)
with open(r"E:\tree\python\works\pz3_after.txt", "w") as file:
    for i in arr:
        file.write(i.capitalize()+"\n")
print()



class Plant_type:
    type_name = ""
class Plant_name:
    plant_name = ""
class Habitat(Plant_type, Plant_name):
    habitat_name = ""
    def __init__(this, first, second, third):
        this.type_name = first
        this.plant_name = second
        this.habitat_name = third
    def type_sorting(*param):
        arr=[]
        for value in param:
            arr.append(value.type_name)
        arr.sort()
        print("We sorted objects by plant's type:\n")
        for value in arr:
            for value2 in param:
                if(value == value2.type_name):
                     print("Type: "+value2.type_name+"; Plant name: "+value2.plant_name+"; Habitat name: "+value2.habitat_name)
                     break
        print("\n")
    def plant_name_sorting(*param):
        arr=[]
        for value in param:
            arr.append(value.plant_name)
        arr.sort()
        print("We sorted objects by plant's name:\n")
        for value in arr:
            for value2 in param:
                if(value == value2.plant_name):
                     print("Type: "+value2.type_name+"; Plant name: "+value2.plant_name+"; Habitat name: "+value2.habitat_name)
                     break
        print("\n")
    def habitat_name_sorting(*param):
        arr=[]
        for value in param:
            arr.append(value.habitat_name)
        arr.sort()
        print("We sorted objects by habitat's name:\n")
        for value in arr:
            for value2 in param:
                if(value == value2.habitat_name):
                     print("Type: "+value2.type_name+"; Plant name: "+value2.plant_name+"; Habitat name: "+value2.habitat_name)
                     break
        print("\n")
    def __del__(this):
        del this.type_name
        del this.plant_name
        del this.habitat_name
group1 = Habitat("Зимнее", "Кактус","Пустыни")
group2 = Habitat("Летнее", "Ромашка","Европа")
group3 = Habitat("Осеннее", "Подснежник","Северная Америка")
group1.type_sorting(group2,group3)
group1.plant_name_sorting(group2,group3)
group1.habitat_name_sorting(group2,group3)
print()



class MyError(Exception):
    exception_name = ""
    def __init__(self, name):
        self.exception_name = name
    def show(self):
        print("\nMistake showed by class.")
        print(self.exception_name)
print("ИТУ-19-2")
print("Куренков")
print("Богдан")
print("Михайлович")
x=5
try:
    while 1:
        print(x*"*")
        x-=1
        if(x < 1):
            raise MyError("You reached the end of row. The cicle is finished!\n")
except MyError as error:
    error.show()
#for i in range(0,5):
#    print((5-i)*"A")
print("****")
print("*")
print("****")
print("*")
print("****")
print(9*2+7)
print(2/3*1/4)
try:
    print("Enter a number: ", end="")
    a = int(input())
except:
    print("You have to enter numbers!\nOkay. For now, a = 1.\n")
    a = 1
b = 10
print("a/b = ", end="")
print(a/b)
string = "first second third"
print(string)
print((string.split(' '))[1][1] + (string.split(' '))[0][-1])