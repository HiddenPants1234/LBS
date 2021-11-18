Select kunden.name
	,adresse.Straße
    ,adresse.PLZ
    ,adresse.Ort
From kunden
Left Outer Join adresse on kunden.AdressID = adresse.AdressID
Order By kunden.name;

Select kunden.Name
	,artikel.Bezeichnung
	,sum(artikel.preis * bestellung.Stück) AS Bestellsumme
From bestellung
Left Outer Join kunden on bestellung.KundenNr = kunden.KundenNr
Left Outer Join artikel on bestellung.ArtikelNr = artikel.ArtikelNr
Group By bestellung.BestellungID;

Select kunden.Name
	,adresse.Straße
    ,adresse.PLZ
    ,adresse.Ort
From kunden
Left Outer Join adresse on kunden.AdressID = adresse.AdressID
Where adresse.Ort LIKE "a%" 
	OR adresse.Ort LIKE "A%";
    
Select *
From kunden
Where Name like "%s%";

Select *
From artikel
Where Preis > 10;

Select min(Stück) as 'Kleinste Bestellung'
	,max(Stück) as 'Größte Bestellung'
    ,avg(Stück) as 'Durchschnittliche Bestellung'
From bestellung;

Select count(distinct Name) As 'Anzahl von Namen'
From kunden;

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

  
  
  
