

def is_prime(num):
    ulimit = int(num**0.5) + 1
    prime = True
    if num <= 1:
        prime = False
    elif num == 2:
        prime = True
    elif num % 2 == 0:
        prime = False
    else:
        for i in range(3,ulimit,2):
            if num % i == 0:
                prime = False
                break
    return prime

largest_prime_of = 600851475143
itr = 2
while largest_prime_of > 1:
    if is_prime(itr):
        while largest_prime_of % itr == 0:
            largest_prime_of /= itr
    itr += 1
print(itr - 1)