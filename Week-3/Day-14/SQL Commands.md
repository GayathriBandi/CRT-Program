# 📘 Day 14

---

## 🔁 Multi-Valued Dependency (MVD)

### 📌 Definition:
A **multi-valued dependency** occurs when one attribute in a table **determines multiple independent values** of another attribute.

### ✅ Example:

Consider a table:

| StudentID | Course   | Hobby     |
|-----------|----------|-----------|
| 1         | DBMS     | Cricket   |
| 1         | DBMS     | Music     |
| 1         | Java     | Cricket   |
| 1         | Java     | Music     |

This shows that:
- A student can take multiple courses
- A student can have multiple hobbies
- Courses and hobbies are **independent**

### 💡 Syntax Representation:
```
StudentID →→ Course  
StudentID →→ Hobby
```

---

## 🧱 SQL Clauses

### 🔹 DDL (Data Definition Language)

Used to define and manage database structure.

| Command    | Description                    |
|------------|--------------------------------|
| `CREATE`   | Creates a new table or object  |
| `ALTER`    | Modifies an existing structure |
| `DROP`     | Deletes an object              |
| `TRUNCATE` | Deletes all rows from table    |
| `RENAME`   | Renames an object              |

#### 🧪 Examples:
```sql
-- Create table
CREATE TABLE Employee (
    ID INT PRIMARY KEY,
    Name VARCHAR(50),
    Salary INT
);

-- Alter table
ALTER TABLE Employee ADD Age INT;

-- Drop table
DROP TABLE Employee;

-- Truncate table
TRUNCATE TABLE Employee;

-- Rename table
RENAME Employee TO Staff;
```

---

### 🔸 DML (Data Manipulation Language)

Used for managing data within tables.

| Command   | Description                |
|-----------|----------------------------|
| `INSERT`  | Adds data into table       |
| `UPDATE`  | Modifies existing data     |
| `DELETE`  | Removes specific data      |

#### 🧪 Examples:
```sql
-- Insert data
INSERT INTO Employee (ID, Name, Salary) VALUES (1, 'John', 50000);

-- Update data
UPDATE Employee SET Salary = 60000 WHERE ID = 1;

-- Delete data
DELETE FROM Employee WHERE ID = 1;
```

---

### 🔒 DCL (Data Control Language)

Controls permissions in the database.

| Command     | Description                  |
|-------------|------------------------------|
| `GRANT`     | Gives permission to user     |
| `REVOKE`    | Takes back permission        |

#### 🧪 Examples:
```sql
-- Grant select permission
GRANT SELECT ON Employee TO user_name;

-- Revoke permission
REVOKE SELECT ON Employee FROM user_name;
```

---

### 🔄 TCL (Transaction Control Language)

Used to manage transactions.

| Command     | Description                            |
|-------------|----------------------------------------|
| `COMMIT`    | Saves all changes made by transaction  |
| `ROLLBACK`  | Undoes changes since last COMMIT       |
| `SAVEPOINT` | Sets a point to rollback to later      |

#### 🧪 Examples:
```sql
BEGIN;

UPDATE Employee SET Salary = 60000 WHERE ID = 2;

-- Savepoint
SAVEPOINT sp1;

UPDATE Employee SET Salary = 70000 WHERE ID = 3;

-- Rollback to savepoint
ROLLBACK TO sp1;

-- Commit the changes
COMMIT;
```

---

## 🧮 NVL() Function

### 📌 Purpose:
Used to replace `NULL` with a default value.

### 🔠 Syntax:
```sql
NVL(column_name, replacement_value)
```

#### 🧪 Example:
```sql
SELECT Name, NVL(Salary, 0) AS Salary FROM Employee;
```
If `Salary` is NULL, it will be replaced with `0`.

---

## 🪙 DUAL Table

### 📌 Purpose:
`DUAL` is a special one-row, one-column table used for **selecting a pseudo value** or performing calculations.

#### 🧪 Examples:
```sql
SELECT 1 + 1 FROM DUAL;

SELECT SYSDATE FROM DUAL;

SELECT 'Gayathri' AS Name FROM DUAL;
```

---

## ⚙️ FUNCTION in SQL

### 📌 Definition:
Functions are built-in operations that perform calculations and return results.

### 🔠 Types:
- **Single row functions** – operate on one row and return one value
- **Aggregate functions** – operate on multiple rows

### 🧪 Examples:
```sql
-- Single Row
SELECT UPPER('hello') FROM DUAL;         -- Output: HELLO
SELECT LENGTH('SQL') FROM DUAL;          -- Output: 3

-- Aggregate
SELECT MAX(Salary) FROM Employee;
SELECT COUNT(*) FROM Employee;
```

---

## 🧾 Summary Table

| Category | Commands                                   |
|----------|--------------------------------------------|
| DDL      | CREATE, ALTER, DROP, TRUNCATE, RENAME      |
| DML      | INSERT, UPDATE, DELETE                     |
| DCL      | GRANT, REVOKE                              |
| TCL      | COMMIT, ROLLBACK, SAVEPOINT                |
| Others   | NVL, DUAL table, Built-in FUNCTIONS         |

---
