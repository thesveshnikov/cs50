def factorial(n):
    result = 1
    for i in range(1, n + 1):
        result *= i
    return result

def factorial(n):
    if n == 0:
        return 1
    return n * factorial(n - 1)
