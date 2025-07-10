# 📘 CRT Program - Stacks: Infix, Postfix, and Prefix

Welcome to this session of the CRT Program where we dive into **Stacks** and their applications in expression conversion and evaluation.

---

## 🧱 What is a Stack?

A **Stack** is a linear data structure that follows the **LIFO** (Last In First Out) principle.  
It supports two primary operations:
- `push(x)` – Add an element to the top.
- `pop()` – Remove the top element.

Stacks are widely used in parsing expressions like **Infix**, **Postfix**, and **Prefix**.

---

## 🧮 Types of Expressions

### 🔹 Infix Expression
- Operators are **written between operands**.
- **Example:** `A + B * C`
- **Needs parentheses** to indicate order.

### 🔹 Postfix Expression (Reverse Polish Notation)
- Operators are **written after operands**.
- **Example:** `A B C * +`
- No parentheses needed.

### 🔹 Prefix Expression (Polish Notation)
- Operators are **written before operands**.
- **Example:** `+ A * B C`
- No parentheses needed.

---

## 🧠 Rules for Conversion

| From → To   | Direction | Algorithm Uses Stack? | Reversal Needed? |
|-------------|-----------|------------------------|-------------------|
| Infix → Postfix | Left to Right | ✅ Yes | ❌ No |
| Infix → Prefix  | Right to Left | ✅ Yes | ✅ Yes (Reverse twice) |
| Postfix → Infix | Left to Right | ✅ Yes | ❌ No |
| Prefix → Infix  | Right to Left | ✅ Yes | ❌ No |

---

## 🧮 Operator Precedence & Associativity

| Operator | Precedence | Associativity   |
|----------|------------|-----------------|
| `^`      | 3          | Right to Left   |
| `*` `/`  | 2          | Left to Right   |
| `+` `-`  | 1          | Left to Right   |

- Higher precedence operators are evaluated first.
- When precedence is the same, associativity is used to break ties.

---

## 🔁 Sample Problem: Infix → Postfix

**Input:** `A + B * C`  
**Steps:**
- `*` has higher precedence than `+`, so `B * C` is done first.
- Result: `A B C * +`

**Output:** `A B C * +`

---

## 🔁 Sample Problem: Infix → Prefix

**Input:** `A + B * C`  
**Steps:**
- Same as above.
- Prefix: `+ A * B C`

**Output:** `+ A * B C`

---

