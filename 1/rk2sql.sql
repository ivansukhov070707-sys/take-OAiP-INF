-- 1. УДАЛИМ СТАРЫЕ ТАБЛИЦЫ ЕСЛИ ЕСТЬ
DROP TABLE IF EXISTS grades CASCADE;
DROP TABLE IF EXISTS subjects CASCADE;
DROP TABLE IF EXISTS students CASCADE;

-- 2. СОЗДАЕМ ТАБЛИЦЫ
CREATE TABLE students (
    student_id SERIAL PRIMARY KEY,
    full_name VARCHAR(100) NOT NULL,
    group_number VARCHAR(20) NOT NULL
);

CREATE TABLE subjects (
    subject_id SERIAL PRIMARY KEY,
    subject_name VARCHAR(100) NOT NULL
);

CREATE TABLE grades (
    grade_id SERIAL PRIMARY KEY,
    student_id INT REFERENCES students(student_id),
    subject_id INT REFERENCES subjects(subject_id),
    grade INT CHECK (grade >= 2 AND grade <= 5)
);

-- 3. ДОБАВЛЯЕМ ДАННЫЕ (ПРОСТЫЕ)
-- Сначала студенты
INSERT INTO students (full_name, group_number) VALUES
('Иванов Иван', 'ИУ1-11Б'),
('Петров Петр', 'ИУ1-11Б'),
('Сидорова Мария', 'ИУ1-11Б');

-- Затем предметы
INSERT INTO subjects (subject_name) VALUES
('Математика'),
('Информатика'),
('Физика');

-- Потом оценки
INSERT INTO grades (student_id, subject_id, grade) VALUES
(1, 1, 5),
(1, 2, 4),
(2, 1, 4),
(2, 2, 3),
(3, 1, 5),
(3, 2, 5);

-- 4. СОЗДАЕМ ИНДЕКС
CREATE INDEX idx_students_group ON students(group_number);

-- 5. СОЗДАЕМ ПРЕДСТАВЛЕНИЕ
DROP VIEW IF EXISTS student_avg_grades;
CREATE VIEW student_avg_grades AS
SELECT 
    s.student_id,
    s.full_name,
    s.group_number,
    ROUND(AVG(g.grade)::numeric, 2) as average_grade
FROM students s
LEFT JOIN grades g ON s.student_id = g.student_id
GROUP BY s.student_id, s.full_name, s.group_number;

-- 6. ПРОСТЫЕ ЗАПРОСЫ (БЕЗ СЛОЖНЫХ ТРАНЗАКЦИЙ)

-- 1) Одногруппники
SELECT full_name FROM students WHERE group_number = 'ИТ-101';

-- 2) Средний балл через представление
SELECT * FROM student_avg_grades;

-- 3) Средний балл по информатике
SELECT 
    s.subject_name,
    ROUND(AVG(g.grade)::numeric, 2) as avg_grade
FROM subjects s
JOIN grades g ON s.subject_id = g.subject_id
WHERE s.subject_name = 'Информатика'
GROUP BY s.subject_id;

-- 4) Все студенты и их оценки
SELECT 
    st.full_name,
    su.subject_name,
    g.grade
FROM grades g
JOIN students st ON g.student_id = st.student_id
JOIN subjects su ON g.subject_id = su.subject_id
ORDER BY st.full_name;

-- 7. ПРОСТАЯ ТРАНЗАКЦИЯ (работает всегда)
BEGIN;
    -- Добавляем нового студента
    INSERT INTO students (full_name, group_number) 
    VALUES ('Новиков Сергей', 'ИТ-101');
    
    -- Добавляем ему оценки
    INSERT INTO grades (student_id, subject_id, grade)
    VALUES 
    (4, 1, 4),  -- Предполагаем что student_id = 4
    (4, 2, 5),
    (4, 3, 4);
COMMIT;

-- 8. ПРОСТОЙ UPDATE (без транзакции)
UPDATE grades SET grade = 5 
WHERE student_id = 1 AND subject_id = 2;

-- 9. ПРОВЕРКА РЕЗУЛЬТАТОВ
SELECT '=== ВСЕ СТУДЕНТЫ ===' as info;
SELECT * FROM students;

SELECT '=== ВСЕ ОЦЕНКИ ===' as info;
SELECT * FROM grades;

SELECT '=== СРЕДНИЕ БАЛЛЫ ===' as info;
SELECT * FROM student_avg_grades ORDER BY average_grade DESC;