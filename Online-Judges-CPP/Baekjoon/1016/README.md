# Square-free Numbers
## Solution
<details>
<summary><b>SPOILERS</b></summary>

Find the primes from 1 to sqrt(max_range) with sieve of Eratosthenes.

### Note
* Be careful while allocating the vector for the primes, since the maximum range is very big! Do not set the vector size to the maximum range. Instead, try to play with just maximum 1,000,000 slots. For example, suppose that `min` = 1,000,000,000,000 and `max` = 1,000,001,000,000. If we allocate a vector with size = `max`, the compiler will meet a `bad_alloc` error. (It takes too much memory.) Instead, we should think `min` as the start index, 0, and `max` as the end index. Map the numbers between them to the vector indices. In the example, if the vector name is `vec`, we can think `min` is vec.at(0), a number 1,000,000,000,012 is at `vec.at(12)`, and the `max` is vec.at(1,000,000).

</details>
