-- to create a database
CREATE DATABASE record_company;

-- we need to specify which database to use
USE record_company;

-- to create a table
CREATE table bands (
	id INT NOT NULL AUTO_INCREMENT,
	name VARCHAR(255) NOT NULL,
    -- primary key tells SQL about which column is supposed to be first
    PRIMARY KEY(id)
);
CREATE TABLE albums (
	-- id here is a variable, to use as "S. No."
	id INT NOT NULL AUTO_INCREMENT,
    name VARCHAR(255) NOT NULL,
    release_year INT,
    band_id INT NOT NULL ,
    PRIMARY KEY (id),
    -- foreign key is used when we need to refrence a column from another table
    foreign key (band_id) REFERENCES bands(id)
);

-- for inserting data into a table, the () tells which column to insert the data into
INSERT INTO bands (name)
VALUES ("AC/DC");

-- if we want to add multiple entries at once in a table
INSERT INTO bands (name)
VALUES ("Dhinka CHika"), ("Queen"), ("Sherlock");

-- SELECT function is used to display the result kinda like print in python
-- the LIMIT function tells it how many colums to display
-- the * indicaes to select everything
SELECT * FROM bands LIMIT 2;

-- To display a specific column from a table
SELECT name FROM bands;

-- If we want to change the title of a column we use the "AS" function
SELECT id AS "S.No", name AS "Band Name"
FROM bands;

-- If we want to order a table on the basis of a specific characteristic, we use "ORDER BY" func
-- DESC and ASC stand for Descending and Ascending, if not specified it will revert to default as ASC
SELECT * FROM bands ORDER BY name DESC;

SELECT * FROM bands ORDER BY name ASC;

-- If we want to insert multiple entries in multiple columns at once
INSERT INTO albums (name, release_year, band_id)
VALUES  ('Back In Black', 1989, 1), 
		('Chika Dhinka', 2012,2),
        ('Bohemian Rhapsody', 1969, 3),
        ('Industry Baby', NULL, 3),
        ('Magic Man', 2019, 4);
SELECT * FROM albums;

-- if we don't want any value to be repeated, we use DISTINCT func
SELECT DISTINCT release_year FROM albums;

-- to update a record we use the update function 
UPDATE albums
SET release_year=1982
-- If we don't do this where statement, all the records will be set to 1982
WHERE id = 1;

-- when we need to put a filter in the data shown
SELECT * FROM albums
WHERE release_year< 2000;

-- if we wanna filter on the basis that a particular string we use LIKE function, 
-- the "%" represent a value that there can be any number and type of characters before and after the sttring we r searching for
SELECT * FROM albums
WHERE name LIKE '%ust%';

-- When we want to have 2 filters
SELECT * FROM albums
WHERE name LIKE '%ust%' OR band_id= 3;
-- we can also have AND func

-- when we wanna give a range to a filter, we use BETWEEN func
SELECT * FROM albums
WHERE release_year BETWEEN 2000 and 2018;

-- When we wanna filter out the null values, we can also make is "IS NULL" to see all the entries which are not yet given
SELECT * FROM albums
WHERE release_year IS NOT NULL;

-- If we wanna remove a piece of data, lets say a band with no record release year entry
DELETE FROM albums -- if we just run this line, it will delete every data in the table (not the table, just the data)
WHERE id=8; -- 8 because it is the one with no entries in the release year column
SELECT * FROM albums;

-- when we wanna merge two tables, the condition "ON bands.id = albums.band_id",  states to join the table when this condition is true
SELECT * FROM bands
JOIN albums ON bands.id = albums.band_id; -- we can also write "INNER JOIN" in place of "JOIN and the result will be the exact same

-- INNER JOIN: returns rows when there is a match in both tables. 
-- LEFT JOIN: returns all rows from the left table, even if there are no matches in the right table.
-- RIGHT JOIN: returns all rows from the right table, even if there are no matches in the left table
SELECT * FROM bands
LEFT JOIN albums ON bands.id = albums.band_id;

-- if we want to average a column
SELECT AVG(release_year) FROM albums;

-- if we want to add all the entries in a column
SELECT SUM(release_year) FROM albums;

-- if we want to count how many albums are in a table by one band
-- An aggregate function performs a calculation on a set of values, and returns a single value
-- "GROUP BY" function collects all the entries with same id and puts them together
SELECT band_id, COUNT(band_id) FROM albums
GROUP BY band_id; -- this one just give a two column result with the band_id and number of albums, but we need more information here.

-- Hence, we do the following to give a table with name of the band as well.
SELECT b.name AS band_name, COUNT(a.id) AS Number_of_Albums
FROM bands AS b
LEFT JOIN albums AS a ON b.id=a.band_id -- we are using LEFT JOIN so that we can also see the bands with no albums as well
GROUP BY b.id;

-- but what if we want to filter the bands who only have 1 or like 2 albums? We can't use WHERE because WHERE function happens before the GROUP BY
-- which will filter before and several entries would be missed. Hence, we use the HAVING function, which is exactly like WHERE function but happens
-- after the GROUP BY.
SELECT b.name AS band_name, COUNT(a.id) AS Number_of_Albums
FROM bands AS b
LEFT JOIN albums AS a ON b.id=a.band_id -- we are using LEFT JOIN so that we can also see the bands with no albums as well
GROUP BY b.id
HAVING Number_of_Albums = 1; -- we can also use OR here to have multiple number filter

-- we can also use WHERE function with HAVING function, but not alone, for in cases when we need to have more type of filters, Eg:
SELECT b.name AS band_name, COUNT(a.id) AS Number_of_Albums
FROM bands AS b
LEFT JOIN albums AS a ON b.id=a.band_id 
WHERE b.name = "Queen"
GROUP BY b.id
HAVING Number_of_Albums = 2;
