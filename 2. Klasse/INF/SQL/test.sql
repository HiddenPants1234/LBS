DELIMITER //
Create Procedure GetBestellungAndKunde ()
Begin
Select kunden.Name
	,artikel.Bezeichnung
	,sum(artikel.preis * bestellung.Stück) AS Bestellsumme
From bestellung
Left Outer Join kunden on bestellung.KundenNr = kunden.KundenNr
Left Outer Join artikel on bestellung.ArtikelNr = artikel.ArtikelNr
Group By bestellung.BestellungID;
END //
DELIMITER ;

DELIMITER //
Create Procedure GetKundeByPLZ (IN Postleitzahl int )
Begin
Select kunden.Name
From kunden
Left Outer Join 
END //
DELIMITER ;