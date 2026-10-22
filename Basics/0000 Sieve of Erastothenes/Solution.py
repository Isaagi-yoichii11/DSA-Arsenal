def sieve_of_eratosthenes(number : int) -> list :
    # if number <= 1 :
    #     return []
    
    primes = [True] * (number + 1)
    
    p = 2
    
    primes[0] = False
    primes[1] = False
    
    while p * p <= number:
        if primes[p]:
            for i in range(p*p,number+1,p):
                primes[i] = False
        
        p +=1
        
    res = []
    
    for p in range(2, number +1):
        if primes[p]:
            res.append(p)
            
    return res


if __name__ == "__main__":
    ans =  sieve_of_eratosthenes(number = 68)
    
    print(ans)

                
    
                