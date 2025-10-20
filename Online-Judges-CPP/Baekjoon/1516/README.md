# Game Development
## Solution
<details>
<summary><b>SPOILERS</b></summary>
Use topological sorting to calculate the minimum time for every structure to build.

We can think the relations among structures as a graph.
Assume that a structure `X` needs the time `x` to be built when the condition is met, and a structure `Y` needs the time `y` to be built when the condition is met.
And assume that `Y` is dependent on `X`.
Then we can make `X` and `Y` as nodes in a graph, where `X` points to `Y`.

$$
X -> Y
$$

And we can think of the relationship between the time to build `X` from the initial `y'` and the time to build `Y` from the initial `y'` like this:

$$
y' = x' + y
$$

Finally, when we let `y'_{\min}` the minimum time to build `Y` from the initial, we can define it with the minimum time to build `X` from the initial, `x'_{\min}`. 

$$
y'_{\min} = x'_{\min} + y
$$
</details>
