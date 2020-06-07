from numpy import arange


def fun1(x, y, z):
    return x**2 + y**2 + z**2


def fun2(x, y, z):
    return x


# other functions...


# can be altered:
lim_down = -2.0
lim_up = 2.0
step = 1.0
fun = fun1


gen_range = arange(lim_down, lim_up + step, step)

with open('data.txt', 'w') as file:
    for x in gen_range:
        for y in gen_range:
            for z in gen_range:
                fun_val = fun(x, y, z)
                file.write(f'{x} {y} {z} {fun_val}\n')
