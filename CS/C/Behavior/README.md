# Behavior
## Summary
| | **Well-defined** | **Implementation**<br>**-defined** | **Unspecified** | **Undefined** |
| :-: | :-: | :-: | :-: | :-: |
| Compiler must do something | O | O | O | X |
| Compiler must document it | O | O | X | X |
| Improves the portability? | O | X | X | X |

## Well-defined Behavior
**Well-defined behavior** is the behavior strictly conforming to the C/C++ standard. It is neither IB, UsB, nor UB.
It is ideally portable without change, and has the strongest guarantees to their users.

## Implementation-defined Behavior
**Implementation-defined behavior(IB)** is the behavior that must be documented by the *particular* compiler/platform, according to the standard, and it must do something precisely.

### Examples
* The mapping result of `reinterpret_cast`. It usually does not modify the address. However, since the "mapping" is an IB, a compiler can make it different if the compiler documented it.
* The size of integral types in bytes. The C/C++ standard does not specify it, and it does not matter if it is 2, 4, or 8. Nevertheless, a compiler must document it.
* The `>>` operator on a negative number.

## Unspecified Behavior
**Unspecified behavior(UsB)** is the behavior a compiler must do something on it, similar to IB. It does not have to be documented by it, though.

## Undefined Behavior
**Undefined behavior(UB)** is the thing a compiler can do whatever on, including crashing or giving unpredictable results.

"Why the standard does not mandate implementations to handle these annoying UBs?": Not checking possibility of UBs brings quite a lot of optimization, and extensibility on C/C++.

### Example
* Dereferencing the null pointer.
* The pointer arithmetic resulting in the out-of-bounds of an array.
