


# 📘  DBMS 

## 📌 1. TABLE, COLUMN, ROW, DATASET, RECORD SET

```

TABLE:
A table is a database object used to store data in a structured format using rows and columns.
Think of it like an Excel sheet with headers and data.

Example:
Table: Students
+----+--------+-----+
\| ID | Name   | Age |
+----+--------+-----+
\| 1  | Alice  | 20  |
\| 2  | Bob    | 21  |

COLUMN:
Each column in a table represents an attribute of the entity.
In the above table: ID, Name, and Age are columns.

ROW:
Each row is a record (data entry) for the entity.
Example: (1, 'Alice', 20)

DATASET:
A dataset is a collection of data, often returned as output from a SQL query or API.
It may contain multiple tables or result sets.

RECORD SET:
A record set is the result of a query — a group of rows (records) retrieved from a table.

Example Query:
SELECT \* FROM Students;
Output → Record Set:
1, 'Alice', 20
2, 'Bob', 21

```

---

## 🗂️ 2. DATABASE OBJECTS

```

Database objects are elements used to store or manipulate data in a DBMS.

TYPES OF OBJECTS:

• TABLE:
Stores data in rows and columns.
Example:
CREATE TABLE Employee (ID INT, Name VARCHAR(100));

• VIEW:
A virtual table based on SELECT query result.
Example:
CREATE VIEW Active\_Employees AS SELECT \* FROM Employee WHERE Status = 'Active';

• INDEX:
Speeds up search operations by indexing columns.
Example:
CREATE INDEX idx\_name ON Employee(Name);

• SEQUENCE:
Generates sequential numbers, often used for auto-incrementing IDs.
Example:
CREATE SEQUENCE emp\_seq START WITH 1 INCREMENT BY 1;

• SYNONYM:
Alias for another database object (rarely used).
Example:
CREATE SYNONYM EmpSyn FOR Employee;

• STORED PROCEDURE:
Precompiled SQL block for tasks like inserting/updating.
Example:
CREATE PROCEDURE AddEmp(IN name VARCHAR(50)) BEGIN INSERT INTO Employee(Name) VALUES(name); END;

• FUNCTION:
Returns a value. Can be used inside SQL expressions.
Example:
CREATE FUNCTION getTax(salary INT) RETURNS INT BEGIN RETURN salary \* 0.1; END;

• TRIGGER:
Automatically fires on INSERT, UPDATE, DELETE.
Example:
CREATE TRIGGER log\_update BEFORE UPDATE ON Employee FOR EACH ROW INSERT INTO logs VALUES(NOW(), 'updated');

```

---

## 🧱 3. SCHEMA

```

SCHEMA:
A schema is a logical container that holds related database objects (tables, views, procedures).

Purpose:

* Organizes objects into groups.
* Provides separation for different users/applications.

Example:
CREATE SCHEMA College;

Then create objects under it:
CREATE TABLE College.Student (ID INT, Name VARCHAR(100));

```

---

## 🧠 4. LEVELS OF DBMS ARCHITECTURE

```

1. INTERNAL LEVEL (Physical):

   * How data is physically stored on disk (indexes, files, blocks).

2. CONCEPTUAL LEVEL (Logical):

   * Logical structure of the entire database for all users.
   * Tables, relationships, constraints.

3. EXTERNAL LEVEL (View/User):

   * Customized views for each user (subset of data).

Why levels?

* Abstraction: Users don’t need to know how data is physically stored.
* Security: Hide unnecessary data using views.

```

---

## 🏛️ 5. DBMS ARCHITECTURE TYPES

```

1. ONE-TIER:

   * User interacts directly with database (no layer in between).
   * Used for local/standalone apps.

2. TWO-TIER:

   * Client ↔️ Server.
   * Application runs on client and communicates with DB server.

3. THREE-TIER:

   * Client ↔️ Application Server ↔️ DB Server.
   * Used in enterprise web applications (MVC architecture).

```

---

## 🧬 6. DATA MODELS & CLASSIFICATION

```

DATA MODEL:
A way to represent data, its relationships, and constraints.

Types of Data Models:

1. HIERARCHICAL:

   * Tree-like structure (parent-child).
   * Example: XML

2. NETWORK:

   * Graph structure with multiple parent-child links (complex).
   * Example: CODASYL DBs.

3. RELATIONAL:

   * Data stored in tables with rows and columns.
   * Uses primary keys and foreign keys.
   * Example: MySQL, PostgreSQL

4. OBJECT-ORIENTED:

   * Stores objects (data + behavior).
   * Example: db4o, ObjectDB

CLASSIFICATION:

• Conceptual Data Model:

* High-level, shows entities and relationships (e.g., ER Diagram).

• Logical Data Model:

* Adds structure — tables, columns, data types.

• Physical Data Model:

* Specifies file storage, indexing, performance settings.

```

---

## 🔄 7. ER DIAGRAM + RELATIONSHIPS + CARDINALITY

```

ER DIAGRAM:

* Visual representation of entities and relationships.

ENTITIES:

* Object or thing (e.g., Student, Course)

ATTRIBUTES:

* Properties of entities (e.g., Student has Name, Age)

RELATIONSHIPS:

* How entities are related (e.g., Student ENROLLS in Course)

CARDINALITY:
Defines number of entity instances:
1:1 → One-to-One
1\:N → One-to-Many
M\:N → Many-to-Many

Example:
Student(StuID, Name)
Course(CourseID, Title)
Enroll(StuID, CourseID)

Each student can enroll in many courses → 1\:N
Each course can have many students → N:1
→ M\:N Relationship

```

---

## 🧹 8. NORMALIZATION (1NF to 3NF)

```

Normalization:
The process of organizing data to avoid redundancy and improve integrity.

👉 1NF (First Normal Form):

* Atomic values (no repeating groups).
* All attributes contain only single values.

Example:
Before:
Student(ID, Name, Courses)
→ Courses = "Math, Physics"

After 1NF:
Split courses into multiple rows.

👉 2NF (Second Normal Form):

* Must be in 1NF.
* No partial dependency (non-key attribute depends on full key).

👉 3NF (Third Normal Form):

* Must be in 2NF.
* No transitive dependency (non-key attribute depends on another non-key).

Example:

Before:
Table: Orders(OrderID, CustomerName, CustomerCity)

Problem:
CustomerCity depends on CustomerName, not OrderID.

After 3NF:
Separate tables:
Customer(CustomerID, Name, City)
Orders(OrderID, CustomerID)

```

---

## ✅ Summary

```

✔ Tables hold data in row-column format.
✔ DBMS objects include tables, views, indexes, triggers, etc.
✔ Schema groups database objects.
✔ DBMS architecture includes 1-tier, 2-tier, and 3-tier setups.
✔ ER diagrams model real-world entities and relationships.
✔ Normalization avoids redundancy and keeps data clean.


