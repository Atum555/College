PRAGMA foreign_keys = on;

DROP Table IF EXISTS WorkerRepair;
DROP Table IF EXISTS Employee;
DROP Table IF EXISTS Specialty;
DROP Table IF EXISTS PartModel;
DROP Table IF EXISTS RepairPart;
DROP Table IF EXISTS Part;
DROP Table IF EXISTS Repair;
DROP Table IF EXISTS Car;
DROP Table IF EXISTS Client;
DROP Table IF EXISTS PostalCode;
DROP Table IF EXISTS Model;
DROP Table IF EXISTS Brand;

CREATE TABLE Brand (
brandId INTEGER PRIMARY KEY,
name TEXT UNIQUE NOT NULL);

CREATE TABLE Model (
modelId INTEGER PRIMARY KEY,
name TEXT NOT NULL,
brandId INTEGER REFERENCES Brand(brandId));

CREATE TABLE PostalCode (
postalCode1 TEXT PRIMARY KEY,
municipality TEXT);

CREATE TABLE Client (
clientId INTEGER PRIMARY KEY,
name TEXT NOT NULL,
address TEXT,
postalCode1 TEXT REFERENCES PostalCode(postalCode1),
postalCode2 TEXT,
phoneNumber TEXT);

CREATE TABLE Car (
idCar INTEGER PRIMARY KEY,
licensePlate TEXT UNIQUE,
modelId INTEGER REFERENCES Model(modelId),
clientId INTEGER REFERENCES Client(clientId));

CREATE TABLE Repair (
repairId INTEGER PRIMARY KEY,
startDate DATE,
endDate DATE,
clientId INTEGER REFERENCES Client(clientId),
idCar INTEGER REFERENCES Car(idCar),
CONSTRAINT Repair_Date_CHK CHECK (endDate>=startDate));

CREATE TABLE Part (
partId INTEGER PRIMARY KEY,
code TEXT UNIQUE,
designation TEXT,
unitCost REAL CHECK (unitCost >= 0),
availableQuantity INTEGER CHECK (availableQuantity >= 0));

CREATE TABLE RepairPart (
repairId INTEGER REFERENCES Repair(repairId),
partId INTEGER REFERENCES Part(partId),
quantity INTEGER CHECK (quantity>= 0),
CONSTRAINT RepairPart_PK PRIMARY KEY (repairId, partId));

CREATE TABLE PartModel (
partId INTEGER REFERENCES Part(partId),
modelId INTEGER REFERENCES Model(modelId),
CONSTRAINT PartModel_PK PRIMARY KEY (partId, modelId));

CREATE TABLE Specialty (
specialyId INTEGER PRIMARY KEY,
name TEXT NOT NULL,
hourlyRate REAL CHECK (hourlyRate >= 0));

CREATE TABLE Employee (
employeeId INTEGER PRIMARY KEY,
name TEXT NOT NULL,
address TEXT,
postalCode1 TEXT REFERENCES PostalCode(postalCode1),
postalCode2 TEXT,
phoneNumber TEXT,
specialyId INTEGER REFERENCES Specialty(specialyId));

CREATE TABLE WorkerRepair (
employeeId INTEGER REFERENCES Employee(employeeId),
repairId INTEGER REFERENCES Repair(repairId),
numHours INTEGER CHECK (numHours >= 0),
CONSTRAINT WorkerRepair_PK PRIMARY KEY (employeeId, repairId));

INSERT INTO PostalCode (postalCode1, municipality) VALUES ('4200','Porto');
INSERT INTO PostalCode (postalCode1, municipality) VALUES ('4400','Vila Nova de Gaia');
INSERT INTO PostalCode (postalCode1, municipality) VALUES ('4450','Matosinhos');

INSERT INTO Client (name, address, postalCode1, postalCode2, phoneNumber)
	VALUES ('Alberto Sousa', 'Rua Brito e Cunha, 125','4450','086','932853425');
INSERT INTO Client (name, address, postalCode1, postalCode2, phoneNumber)
	VALUES ('Maria Francisca Pereira Nobre','Avenida Meneres, 201','4450','191','933278005');
INSERT INTO Client (name, address, postalCode1, postalCode2, phoneNumber)
	VALUES ('Rodrigo Meireles de Aguiar','Rua da Cunha, 310 1º Dir','4200','250','928604666');
INSERT INTO Client (name, address, postalCode1, postalCode2, phoneNumber)
	VALUES ('Adão Lopes Sá','Rua Domingos de Matos, 200 3º Esq','4400','120','963670913');

INSERT INTO Brand (name) VALUES ('Renault');
INSERT INTO Brand (name) VALUES ('Volvo');

INSERT INTO Model (name, brandId)
	VALUES ('Clio 1.9D', 1);
INSERT INTO Model (name, brandId)
	VALUES ('V50 Momentum', 2);
INSERT INTO Model (name, brandId)
	VALUES ('C30 Drive', 2);

INSERT INTO Car (licensePlate, modelId, clientId)
	VALUES ('2490CV', 1, 4);
INSERT INTO Car (licensePlate, modelId, clientId)
	VALUES ('36DH79', 2, 2);
INSERT INTO Car (licensePlate, modelId, clientId)
	VALUES ('1127XY', 3, 3);
INSERT INTO Car (licensePlate, modelId, clientId)
	VALUES ('78AB27', 3, 2);
INSERT INTO Car (licensePlate, modelId, clientId)
	VALUES ('16IU02', 3, 4);

INSERT INTO Repair (startDate, endDate, clientId, idCar)
	VALUES ('2010-09-17', '2010-09-20', 1, 3);
INSERT INTO Repair (startDate, endDate, clientId, idCar)
	VALUES ('2010-09-15', '2010-09-16', 4, 1);
INSERT INTO Repair (startDate, endDate, clientId, idCar)
	VALUES ('2009-09-18', '2009-09-27', 4, 5);

INSERT INTO Part (code, designation, unitCost, availableQuantity)
	VALUES ('37XX98', NULL, 3, 100);
INSERT INTO Part (code, designation, unitCost, availableQuantity)
	VALUES ('75VBO98', NULL, 25, 10);

INSERT INTO PartModel (partId, modelId) VALUES (1, 1);
INSERT INTO PartModel (partId, modelId) VALUES (2, 3);

INSERT INTO RepairPart (repairId, partId, quantity) VALUES (2, 1, 8);
INSERT INTO RepairPart (repairId, partId, quantity) VALUES (3, 2, 2);

INSERT INTO Specialty(name, hourlyRate)
	VALUES ('Electricista', 15);
INSERT INTO Specialty(name, hourlyRate)
	VALUES ('Mecânico', 12);
INSERT INTO Specialty(name, hourlyRate)
	VALUES ('Chapeiro', 10);

INSERT INTO Employee(name, address, postalCode1, postalCode2, phoneNumber, specialyId)
	VALUES ('Abel Sousa', 'Rua da Preciosa, 317-1º Esq', 4200, 137, '226903271', 1);
INSERT INTO Employee(name, address, postalCode1, postalCode2, phoneNumber, specialyId)
	VALUES ('Mário Teixeira', 'Rua Seca, 17', 4400, 210, '227519090', 2);
INSERT INTO Employee(name, address, postalCode1, postalCode2, phoneNumber, specialyId)
	VALUES ('Rogério Silva', 'Rua dos Caldeireiros, 312, 3ºF', 4400, 112, '227403728', 2);
INSERT INTO Employee(name, address, postalCode1, postalCode2, phoneNumber, specialyId)
	VALUES ('Luís Pereira', 'Rua Teixeira de Pascoaes, 117, 2º D', 4450, 117, '225901707', 3);

INSERT INTO WorkerRepair (employeeId, repairId, numHours) VALUES (1,1,1);
INSERT INTO WorkerRepair (employeeId, repairId, numHours) VALUES (4,1,4);
INSERT INTO WorkerRepair (employeeId, repairId, numHours) VALUES (1,2,1);
INSERT INTO WorkerRepair (employeeId, repairId, numHours) VALUES (2,2,6);
INSERT INTO WorkerRepair (employeeId, repairId, numHours) VALUES (4,2,2);
INSERT INTO WorkerRepair (employeeId, repairId, numHours) VALUES (1,3,1);

DROP TRIGGER IF EXISTS TRIGGER_A;
CREATE TRIGGER TRIGGER_A
BEFORE INSERT ON RepairPart
BEGIN
    UPDATE Part
    SET availableQuantity = availableQuantity - NEW.quantity
	WHERE Part.partId = NEW.partID;
END;

DROP TRIGGER IF EXISTS TRIGGER_B;
CREATE TRIGGER TRIGGER_B
AFTER INSERT ON Repair
WHEN NEW.clientID is NULL
BEGIN
	UPDATE Repair
	SET clientID = (SELECT clientID FROM Car WHERE idCar = NEW.idCar)
	WHERE repairId = NEW.repairId;
END;

DROP TRIGGER IF EXISTS TRIGGER_C;
CREATE TRIGGER TRIGGER_C
AFTER INSERT ON RepairPart
WHEN (
	NEW.partId NOT IN (
		SELECT PM.partId
		FROM Repair AS R
		JOIN Car as C ON C.idCar = R.idCar
		JOIN PartModel as PM ON C.modelId = PM.modelId
		WHERE R.repairId = NEW.repairId
		) 
	OR NEW.quantity > (SELECT availableQuantity FROM Part WHERE Part.partId = NEW.partId)
	)
BEGIN
	SELECT RAISE(ABORT, 'Rebentou, input invalido');
END;

DROP VIEW IF EXISTS VIEW_D;
CREATE VIEW VIEW_D AS
SELECT B.name AS BrandName, M.name AS ModelName
FROM Model AS M
JOIN Brand AS B USING(brandId);

DROP TRIGGER IF EXISTS TRIGGER_D;
CREATE TRIGGER TRIGGER_D
INSTEAD OF INSERT ON VIEW_D
BEGIN
	INSERT OR IGNORE INTO Brand(name) VALUES (NEW.BrandName);
	INSERT INTO Model(name, brandId) VALUES (NEW.ModelName, (SELECT brandId FROM Brand WHERE name = NEW.BrandName));
END;
