import math

def solve():
    A, B = map(int, input().split())
    
    # GCDを計算
    gcd = math.gcd(A, B)
    
    # LCM = A * B / GCD(A, B)
    # オーバーフローを避けるため、A / GCD を先に計算
    A_div_gcd = A // gcd
    
    # A_div_gcd * B が 10^18 を超えるかチェック
    if A_div_gcd > 10**18 // B:
        print("Large")
    else:
        lcm = A_div_gcd * B
        print(lcm)

solve()