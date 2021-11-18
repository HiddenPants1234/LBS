INSERT INTO bahnhof(City, BahnhofName)
	VALUES('Salzburg', 'Bahnhof Salzburg'),
		('Wien', 'Westbahnhof'),
        ('Linz', 'Hauptbahnhof');
INSERT INTO bahnsteig(BahnsteigName, idBahnhof)
	VALUES('Bahnsteig 1', 1),
		('Bahnsteig 2', 1),
        ('Bahnsteig 1', 2);
INSERT INTO Ankunft(DatumUhrzeit, idZug, idBahnsteig)
	VALUES(NOW(), 1, 1),
		(NOW(), 2, 2),
        (NOW(), 3, 3);
INSERT INTO Abfahrt(DatumUhrzeit, idZug, idBahnsteig)
	VALUES(NOW(), 1, 1),
		(NOW(), 2, 2),
        (NOW(), 3, 3);
INSERT INTO zug(ZugName, ZugTyp, idAnkunft, idAbfahrt)
	VALUES('Rex 123456', 'REx', 1, 1),
		('InterCity 123456', 'ICE', 2, 2),
        ('EuroCity 123456', 'ICE', 3, 3)


