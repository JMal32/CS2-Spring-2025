# Explanation of why we use the specific syntax we do for timings

Your professor's preference for explicit type declarations over `auto` makes sense from an educational perspective. Here's why he might prefer the explicit approach:

```cpp
high_resolution_clock::time_point start = high_resolution_clock::now();
```

rather than:

```cpp
auto start = high_resolution_clock::now();
```

1. **Educational clarity**: Explicitly writing out the types helps students understand exactly what they're working with. It makes the complex chrono library type system more visible and learnable.

2. **Self-documenting code**: The explicit type declaration serves as built-in documentation, showing readers exactly what type start and end are without having to infer it.

3. **Teaching proper C++ fundamentals**: Understanding type systems is fundamental to C++. While `auto` is convenient, professors often want students to fully grasp the underlying types before using shortcuts.

4. **Avoiding type confusion**: When learning, explicit types prevent misunderstandings about what's actually being stored or returned.

5. **Consistency with traditional C++ style**: Many academic environments prefer more traditional C++ approaches, which historically favored explicit typing.

Both approaches produce the same result, but the explicit approach helps reinforce your understanding of the chrono library's structure and types, which is valuable when learning C++.
