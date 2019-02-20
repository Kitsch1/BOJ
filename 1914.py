def sq_calculate(a,b):
    ans = 1
    sq_num = a
    sq_cnt = b
    while sq_cnt > 0:
        if sq_cnt % 2 == 1:
            sq_cnt -= 1
            ans *= sq_num
        sq_num *= sq_num
        sq_cnt /= 2
    return ans

def hanoi(start,dest,n):
    if n == 1:
        print("%d %d"%(start,dest))
        return
    hanoi(start,6-start-dest,n-1)
    print("%d %d"%(start,dest))
    hanoi(6-start-dest,dest,n-1)

if __name__ == "__main__":
    n = int(input())
    print(sq_calculate(2,n)-1)
    if n <= 20:
        hanoi(1,3,n)
