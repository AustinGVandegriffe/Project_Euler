x = 0
y = 1

sm = 0
while y < 4000000:
    t_ = y
    y = x + y
    x = t_
    if y % 2 == 0:
        sm += y

print(sm)