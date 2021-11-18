USE bikelbs4;

DELIMITER $$
CREATE TRIGGER add_mehrwertsteuer
BEFORe UPDATE
ON artikel
FOR EACH ROW
BEGIN
    SET NEW.Mehrwertsteuer = NEW.Netto * 0.2;
END $$
Delimiter ;

DELIMITER $$
CREATE TRIGGER add_mehrwertsteuer_insert
BEFORE INSERT
ON artikel
FOR EACH ROW
BEGIN
    SET NEW.Mehrwertsteuer = NEW.Netto * 0.2;
END $$
Delimiter ;

INSERT INTO artikel(Anr, Bezeichnung, Netto, Farbe, Typ)
VALUES(500018, 'Cooles Rad', 125.12, 'Gruen', 'F');

UPDATE artikel
SET Netto = 125.12
WHERE Anr = 500017;

DELIMITER $$
CREATE TRIGGER increment
BEFORE INSERT
ON personal
FOR EACH ROW
BEGIN
	SET NEW.Persnr = (Select Persnr + 1 FROM personal ORDER BY Persnr desc LIMIT 1);
END $$
Delimiter ;

INSERT INTO personal(Vorname, Nachname, GebDatum, adresse_id)
VALUES('Testuser', 'TESTUSER', '2000-10-10', 13);
