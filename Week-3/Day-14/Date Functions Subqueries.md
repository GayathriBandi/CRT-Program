# 📅 Day 14 Notes - Date Functions, Date Conversion & Subqueries

---

## 🔹 DATE FUNCTIONS in SQL

These functions work with `DATE` or `TIMESTAMP` types.

### 📌 Common Date Functions:

```sql
-- Get current system date
SELECT SYSDATE FROM dual;

-- Add 10 days to current date
SELECT SYSDATE + 10 AS future_date FROM dual;

-- Find difference between two dates
SELECT hiredate, SYSDATE - hiredate AS days_worked FROM emp;

-- Extract year, month, day
SELECT EXTRACT(YEAR FROM SYSDATE) AS year,
       EXTRACT(MONTH FROM SYSDATE) AS month,
       EXTRACT(DAY FROM SYSDATE) AS day
FROM dual;
```

---

## 🔹 DATE CONVERSION FUNCTIONS

Used to convert strings to dates or vice versa using `TO_DATE`, `TO_CHAR`, etc.

### 📌 TO_DATE() – Convert string to DATE
```sql
SELECT TO_DATE('17-JUL-2025', 'DD-MON-YYYY') AS converted_date FROM dual;
```

### 📌 TO_CHAR() – Convert DATE to string format
```sql
SELECT TO_CHAR(SYSDATE, 'YYYY-MM-DD') AS formatted_date FROM dual;
SELECT TO_CHAR(SYSDATE, 'Month DD, YYYY') AS pretty_format FROM dual;
```

---

## 🔹 SUBQUERIES

Subqueries are queries inside another query. They can be used in `SELECT`, `FROM`, or `WHERE` clauses.

### ✅ Types of Subqueries:

---

### 1️⃣ **Single Row Subquery**

Returns **one row** and **one column**.

```sql
-- Find employees who earn more than the average salary
SELECT ename, sal
FROM emp
WHERE sal > (SELECT AVG(sal) FROM emp);
```

---

### 2️⃣ **Multiple Row Subquery**

Returns **multiple rows**.

```sql
-- Find employees whose salary equals any of the salaries in department 10
SELECT ename, sal
FROM emp
WHERE sal IN (SELECT sal FROM emp WHERE deptno = 10);
```

---

### 3️⃣ **Multiple Column Subquery**

Returns **multiple columns**.

```sql
-- Find employees who have same job and salary as SMITH
SELECT ename, job, sal
FROM emp
WHERE (job, sal) IN (SELECT job, sal FROM emp WHERE ename = 'SMITH');
```

---

## 🔁 SUBQUERY IN FROM CLAUSE (Inline View)

```sql
-- List employees and their rank based on salary
SELECT ename, sal, RANK() OVER (ORDER BY sal DESC) AS salary_rank
FROM (SELECT ename, sal FROM emp WHERE deptno = 20);
```

---

## ⚡ MULTIPLE SUBQUERIES EXAMPLE

```sql
-- 1. Employees earning more than avg salary
SELECT ename
FROM emp
WHERE sal > (SELECT AVG(sal) FROM emp);

-- 2. Employees who have same job as employee 'JONES'
SELECT ename, job
FROM emp
WHERE job = (SELECT job FROM emp WHERE ename = 'JONES');

-- 3. Employees in same department as 'SCOTT'
SELECT ename
FROM emp
WHERE deptno = (SELECT deptno FROM emp WHERE ename = 'SCOTT');

-- 4. Employees earning salary same as anyone in dept 30
SELECT ename, sal
FROM emp
WHERE sal IN (SELECT sal FROM emp WHERE deptno = 30);

-- 5. Employees with same job and salary as 'FORD'
SELECT ename
FROM emp
WHERE (job, sal) IN (SELECT job, sal FROM emp WHERE ename = 'FORD');
```

---

## 📌 Summary

| Concept             | Description                            |
|---------------------|----------------------------------------|
| `SYSDATE`           | Current system date                    |
| `TO_DATE()`         | String → Date                          |
| `TO_CHAR()`         | Date → Formatted String                |
| `Subquery`          | Query inside another query             |
| `Single Row`        | Returns one row                        |
| `Multiple Row`      | Returns multiple rows                  |
| `Multiple Column`   | Returns multiple columns (e.g., tuples)|

---

> 🧠 **Tip**: Always use `IN`, `ANY`, or `EXISTS` for multiple row subqueries, and avoid `=` in such cases.

