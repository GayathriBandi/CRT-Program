# 📚 Day 25
**Topics Covered:**
- SQL Views (Definition, Types, Examples)
- PL/SQL (Structure, Syntax, Example)
- Sequences (Usage, Syntax, Example)

---

## ✅ SQL VIEWS

### 🔹 What is a View?
A **view** is a virtual table based on the result-set of an SQL query. It doesn't store data physically, but derives data from one or more tables.

### 🔹 Syntax:
```sql
CREATE VIEW view_name AS
SELECT column1, column2, ...
FROM table_name
WHERE condition;
```

### 🔹 Types of Views:
1. **Simple View** – Based on a single table, no group functions.
2. **Complex View** – Can be based on multiple tables, may include group functions, joins, etc.
3. **Materialized View** – Stores the query result physically, used for performance.
4. **Inline View** – A subquery in the FROM clause of a SELECT statement.
5. **Updatable View** – A view that allows INSERT, UPDATE, DELETE.
6. **Read-only View** – View that restricts DML operations.

### 🔹 Examples:
```sql
-- Simple View
CREATE VIEW emp_view AS
SELECT emp_id, emp_name, dept_id FROM employees;

-- Complex View with JOIN
CREATE VIEW emp_dept_view AS
SELECT e.emp_name, d.dept_name
FROM employees e
JOIN departments d ON e.dept_id = d.dept_id;

-- View with WHERE clause
CREATE VIEW high_salary_view AS
SELECT emp_name, salary FROM employees
WHERE salary > 50000;

-- Dropping a View
DROP VIEW emp_view;
```

---

## ✅ PL/SQL (Procedural Language/SQL)

### 🔹 What is PL/SQL?
PL/SQL is Oracle's procedural extension to SQL. It allows use of loops, conditions, variables, and error handling in database programming.

### 🔹 Structure:
```sql
DECLARE
   -- variable declarations
BEGIN
   -- executable statements
EXCEPTION
   -- exception handling
END;
```

### 🔹 Example Program:
```sql
DECLARE
   v_name employees.emp_name%TYPE;
BEGIN
   SELECT emp_name INTO v_name FROM employees WHERE emp_id = 101;
   DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_name);
EXCEPTION
   WHEN NO_DATA_FOUND THEN
      DBMS_OUTPUT.PUT_LINE('No employee found');
END;
```

### 🔹 Conditional Statement Example:
```sql
DECLARE
   salary NUMBER := 60000;
BEGIN
   IF salary > 50000 THEN
      DBMS_OUTPUT.PUT_LINE('High salary');
   ELSE
      DBMS_OUTPUT.PUT_LINE('Average salary');
   END IF;
END;
```

---

## ✅ SEQUENCES

### 🔹 What is a Sequence?
A **sequence** is a database object used to generate unique numbers automatically, often used for primary keys.

### 🔹 Syntax:
```sql
CREATE SEQUENCE seq_name
START WITH 1
INCREMENT BY 1
MAXVALUE 999999
CYCLE|NOCYCLE
CACHE 20;
```

### 🔹 Example:
```sql
-- Create Sequence
CREATE SEQUENCE emp_seq
START WITH 1001
INCREMENT BY 1
NOCACHE;

-- Using Sequence in Insert
INSERT INTO employees(emp_id, emp_name)
VALUES(emp_seq.NEXTVAL, 'John Doe');

-- View Current and Next Values
SELECT emp_seq.CURRVAL, emp_seq.NEXTVAL FROM dual;

-- Drop Sequence
DROP SEQUENCE emp_seq;
```

---

