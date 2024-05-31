import math
# import time

# var1 = time.time()

A = list(map(float,input().split()))
pie = list(map(float,input().split()))
T = int(input())
Y = []
for x in range(0,T):
    i = float(input())
    Y.append(i)

mulst = [0.0,0.0]
varlst= [1.0,1.0]
alpha0 = [0.0]*(T+1)
alpha1 = [1.0]*(T+1)
beta0 = [1.0]*(T+1)
beta1 = [1.0]*(T+1)
Gamma0 = [0.0]*(T+1)
Gamma1 = [0.0]*(T+1)
Eeta00 = [0.0]*(T+1)
Eeta01 = [0.0]*(T+1)
Eeta10 = [0.0]*(T+1)
Eeta11 = [0.0]*(T+1)
precision = 1e-8

# lst[0] = a00 => Transition from bull to bull                a01 => Transition from bull to bear
#          a10 => Transition from bear to bull                a11 => Transition from bear to bear
# pie[0] = pi0                   pie[1] = pi1

def numr_eeta(i,j):
    ans = 0
    if i == 0 and j == 0:
        for k in range(1,T):
            ans += Eeta00[k]
    
    if i == 0 and j == 1:
        for k in range(1,T):
            ans += Eeta01[k]

    if i == 1 and j == 0:
        for k in range(1,T):
            ans += Eeta10[k]

    if i == 1 and j == 1:
        for k in range(1,T):
            ans += Eeta11[k]

    return ans

def deno_eeta(i,n):
    ans = 0
    if i == 0:
        for k in range(1,n+1):
            # print(alpha1[k])
            ans += Gamma0[k]

    else:
        for k in range(1,n+1):
            ans += Gamma1[k]

    return ans

def num_mu(i):
    ans = 0
    if i == 0:
        for k in range(T):
            ans += Gamma0[k]*Y[k-1]

    else:
        for k in range(T):
            ans += Gamma1[k]*Y[k-1]
    
    return ans

def numr_sigma(i):
    ans = 0
    if i == 0:
        for k in range(1,T+1):
            ans += ((Y[k-1] - mulst[0])**2)*Gamma0[k]

    if i == 1:
        for k in range(1,T+1):
            ans += ((Y[k-1] - mulst[1])**2)*Gamma1[k]

    return ans 

def normal(x,mu,var):
    return (math.exp(-0.5*((x - mu)**2)/(var)))/(math.sqrt(var)*(math.sqrt(2*math.pi)))

def Sum(t,i):
    ans = 0
    if i == 0:
        ans += alpha0[t]*A[0]
        ans += alpha1[t]*A[2]

    else:
        ans += alpha0[t]*A[1]
        ans += alpha1[t]*A[3]

    return ans

def alpha(t,i):
    if (t == 1 and i == 0):
        alpha0[1] = pie[0]*normal(Y[t-1],mulst[0],varlst[0])

    elif t == 1 and i == 1:
        alpha1[1] = pie[1]*normal(Y[t-1],mulst[1],varlst[1])

    elif t!=1 and i==0:
        alpha0[t] = normal(Y[t-1],mulst[0],varlst[0])*(Sum(t-1,i))
    
    elif t!=1 and i==1:
        alpha1[t] = normal(Y[t-1],mulst[1],varlst[1])*(Sum(t-1,i))

def beta(t,i):
    ans = 0
    if t == T:
        ans = 1

    else:
        if i == 0:
            ans += beta0[t+1]*A[0]*normal(Y[t],mulst[0],varlst[0])
            ans += beta1[t+1]*A[1]*normal(Y[t],mulst[1],varlst[1])

        else:
            ans += beta1[t+1]*A[2]*normal(Y[t],mulst[0],varlst[0])
            ans += beta0[t+1]*A[3]*normal(Y[t],mulst[1],varlst[1])

    return ans

def gamma(t,i):
    if i == 0:
        Gamma0[t] = (alpha0[t]*beta0[t])/(alpha0[t]*beta0[t] + alpha1[t]*beta1[t])
        # print(Gamma0[i])

    else:
        Gamma1[t] = (alpha1[t]*beta1[t])/(alpha0[t]*beta0[t] + alpha1[t]*beta1[t])

def eeta(i,j,t):
    if i == 0 and j == 0:
        Eeta00[t] = alpha0[t]*A[0]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0])/(alpha1[t]*A[3]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha1[t]*A[2]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]) + alpha0[t]*A[1]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha0[t]*A[0]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]))

    elif i == 0 and j == 1:
        Eeta01[t] = alpha0[t]*A[1]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1])/(alpha1[t]*A[3]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha1[t]*A[2]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]) + alpha0[t]*A[1]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha0[t]*A[0]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]))
    
    elif i == 1 and j == 0:
        Eeta10[t] = alpha1[t]*A[2]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0])/(alpha1[t]*A[3]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha1[t]*A[2]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]) + alpha0[t]*A[1]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha0[t]*A[0]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]))
    
    elif i == 1 and j == 1:
        Eeta11[t] = alpha1[t]*A[3]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1])/(alpha1[t]*A[3]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha1[t]*A[2]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]) + alpha0[t]*A[1]*beta1[t+1]*normal(Y[t],mulst[1],varlst[1]) + alpha0[t]*A[0]*beta0[t+1]*normal(Y[t],mulst[0],varlst[0]))

def pi_star():
    lst = [Gamma0[1],Gamma1[1]]
    return lst

def aij_star(i,j):
    Nr = numr_eeta(i,j)
    Dr = deno_eeta(i,T-1)
    return Nr/Dr

def mu_star(i):
    Nr = num_mu(i)
    Dr = deno_eeta(i,T)
    mulst[i] = Nr/Dr
    
def var_star(i):
    Nr = numr_sigma(i)
    Dr = deno_eeta(i,T)
    varlst[i] = Nr/Dr

mu = mulst[len(mulst)-1]
mu1= 0
var= varlst[len(varlst)-1]
var1= 0
A00 = A[0]
a00 = 0
A01 = A[1]
a01 = 0
A10 = A[2]
a10 = 0
A11 = A[3]
a11 = 0
Pi0 = pie[0]
pi0 = 0
Pi1 = pie[1]
pi1 = 0

while (abs(mu - mu1) + abs(var - var1) + abs(A00 - a00) + abs(A01 - a01) + abs(A10 - a10) + abs(A11 - a11) + abs(Pi0 - pi0) + abs(Pi1 - pi1)) > precision:
    mu  = mulst[len(mulst)-1]
    var = varlst[len(varlst)-1]
    A00 = A[0]
    A01 = A[1]
    A10 = A[2]
    A11 = A[3]
    Pi0 = pie[0]
    Pi1 = pie[1]

    for i in range(1,T+1):
        alpha(i,0)
        alpha(i,1)

    for i in range(T,0,-1):
        beta0[i] = beta(i,0)
        beta1[i] = beta(i,1)

    for i in range(1,T+1):
        gamma(i,0)
        gamma(i,1)

    for i in range(1,T):
        eeta(0,0,i)
        eeta(0,1,i)
        eeta(1,0,i)
        eeta(1,1,i)

    pie = pi_star()

    A[0] = aij_star(0,0)
    A[1] = aij_star(0,1)
    A[2] = aij_star(1,0)
    A[3] = aij_star(1,1)

    mu_star(0)
    mu_star(1)

    var_star(0)
    var_star(1)

    mu1 = mulst[len(mulst)-1]
    var1= varlst[len(varlst)-1]
    a00 = A[0]
    a01 = A[1]
    a10 = A[2]
    a11 = A[3]
    pi0 = pie[0]
    pi1 = pie[1]

Bear = 0
Bull = 0

if mulst[0] > mulst[1]:
    Bear = 1
    Bull = 0

else:
    Bear = 0
    Bull = 1

for k in range(T):
    if  Gamma0[k+1] < Gamma1[k+1]:
        if Bear == 1:
            print("Bear")
        else:
            print("Bull")

    else:
        if Bear == 0:
            print("Bear")
        else:
            print("Bull")  

# var2 = time.time()
# print(var2-var1)
