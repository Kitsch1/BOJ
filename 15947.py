if __name__ == "__main__":
    baby_suk = ['baby','sukhwan','tu','tu','very','cute','tu','tu','in','bed','tu','tu','baby','sukhwan']
    n=int(input())
    word_idx = n % 14
    tu_phase = n // 14
    if baby_suk[word_idx - 1] == 'tu':
        if word_idx % 4 == 3:
            if tu_phase >= 3:
                print(baby_suk[word_idx-1],end="")
                print("+ru*",end="")
                print(tu_phase+2)
            else:
                print(baby_suk[word_idx-1],end="")
                for i in range(tu_phase+2):
                    print("ru",end="")
                print()
        else:
            if tu_phase >= 4:
                print(baby_suk[word_idx-1],end="")
                print("+ru*",end="")
                print(tu_phase+1)
            else:
                print(baby_suk[word_idx-1],end="")
                for i in range(tu_phase+1):
                    print("ru",end="")
                print()
    else:
        print(baby_suk[word_idx-1])