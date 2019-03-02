if __name__ == "__main__":
    n=int(input())
    for i in range(n):
        l_size = int(input())
        lst = input().split()
        cnt = 0
        for sheep in lst:
            if sheep == "sheep":
                cnt += 1
        print("Case %d: This list contains %d sheep."%(i+1,cnt))
        print()