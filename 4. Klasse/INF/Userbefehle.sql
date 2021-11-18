create user 'valentin'@'localhost';

create schema if not exists Projekt Default character set latin1;
use Projekt;

Create table Projektverwaltung (
	Projekt_ID int(6) unsigned auto_increment primary key,
    Projekt_Name varchar(45) not null,
    Mitarbeiter varchar(45) not null,
    Beschreibung varchar(100));
    
INSERT INTO Projektverwaltung(Projekt_Name, Mitarbeiter, Beschreibung)
VALUES('Projekt_1', 'Valentin', 'Ein Projekt');

GRANT SELECT ON Projekt.Projektverwaltung TO 'valentin'@'localhost';

INSERT INTO Projektverwaltung(Projekt_Name, Mitarbeiter, Beschreibung)
VALUES('Projekt_2', 'Valentintin', 'Zwei Projekt');

Delete From Projektverwaltung
Where Projekt_ID = 2;

-- Zum löschen und einfügen von Daten brauchen User INSERT und DELETE Rechte

DROP USER 'valentin'@'localhost';

Select user
From mysql.user