# Game Development
## Solution
<details>
<summary><b>SPOILERS</b></summary>
Use topological sorting to calculate the minimum time for every structure to build.

We can think the relations among structures as a graph.
Assume that a structure `X` needs the time `x` to be built when the condition is met, and a structure `Y` needs the time `y` to be built when the condition is met.
And assume that `Y` is dependent on `X`.
Then we can make `X` and `Y` as nodes in a graph, where `X` points to `Y`.

X -> Y

Then we can think of the time to need to Y as 
</details>
