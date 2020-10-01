def solve(s, st):
    for i in range(len(s)):
        if(s[i] == '(' or s[i] == '{' or s[i] == '['):
            st.append(s[i])
        elif(len(st) > 0):
            if(s[i] == '}' and st[-1] == '{'):
                del st[-1]
            elif(s[i] == ')' and st[-1] == '('):
                del st[-1]
            elif(s[i] == ']' and st[-1] == '['):
                del st[-1]
        else: return -1

    return len(st)

s = input()
st = []

if(solve(s, st) == 0): print("yes")
else: print("no")