# Square-free Numbers
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Find the primes from 1 to sqrt(max_range) with sieve of Eratosthenes.

### Note
* Be careful while allocating the vector for the primes, since the maximum range is very big! Do not set the vector size to the maximum range. Instead, try to play with just maximum 1,000,000 slots. For example, suppose that `min` = 1,000,000,000,000 and `max` = 1,000,001,000,000. If we allocate a vector with size = `max`, the compiler will complaint about an error.

</details>
