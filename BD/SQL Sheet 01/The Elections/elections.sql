.mode columns
.headers on
PRAGMA foreign_keys = ON;

DROP TABLE IF EXISTS Districts;
CREATE TABLE Districts (
    Code TINYINT,
    Name TEXT NOT NULL,
    Region CHAR(1) DEFAULT 'C',
    CONSTRAINT CodePK PRIMARY KEY (Code),
    CONSTRAINT CodeValue CHECK (Code BETWEEN 1 AND 140),
    CONSTRAINT RegionLetter CHECK (Region IN ('C', 'M', 'A'))
);

DROP TABLE IF EXISTS Municipalities;
CREATE TABLE Municipalities (
    Code INT,
    Name TEXT NOT NULL,
    District TINYINT,
    FOREIGN KEY (District) REFERENCES Districts(Code) ON DELETE SET NULL ON UPDATE CASCADE
);

INSERT INTO Districts VALUES (13, "Porto", 'C');
SELECT * FROM Districts;
.print ' '
.print ' '

INSERT INTO Municipalities VALUES (1308, "Matosinhos", 13);
SELECT * FROM Municipalities;
.print ' '
.print ' '

UPDATE Districts SET Code = 14 WHERE Code = 13;
SELECT * FROM Districts;
.print ' '
.print ' '
SELECT * FROM Municipalities;
.print ' '
.print ' '
