use bikelbs4;

-- Diese View kann nicht für Updates verwendet werden, weil mehrere Tabellen gejoint werden
Create View VAuftrag AS
Select auftrag.AuftrNr
	,auftrag.Datum
    ,concat(kunde.vorname, " ", kunde.Nachname) AS Kundenname
    ,concat(personal.Vorname, " ", personal.Nachname) AS Bearbeitername
    ,COUNT(AuftrNr) AS Auftragssumme
From auftrag
	LEFT OUTER JOIN personal ON auftrag.Persnr = personal.Persnr
    LEFT OUTER JOIN kunde ON auftrag.Kundnr = kunde.Kundnr
Group by auftrag.AuftrNr, auftrag.Datum, Kundenname, Bearbeitername;

Create View VPersonal AS
Select personal.Persnr
	,personal.Vorname
    ,personal.Nachname
    ,personal.GebDatum
    ,personal.Vorgesetzt
    ,personal.BerufsBez
    ,personal.adresse_id
    ,adresse.Strasse
    ,adresse.Hausnummer
    ,adresse.Ort_plz
    ,ort.Ort
From personal
	LEFT OUTER JOIN adresse on personal.adresse_id = adresse.id
	LEFT OUTER JOIN ort on adresse.Ort_plz = ort.plz
Where personal.Vorgesetzt IS NOT NULL;

-- Jede sicht ist änderbar, man kann eine Sicht immer anpassen, sofern man die richtigen Rechte hat
Create View VAuftragsposten AS
Select *
	,gesamtpreis / anzahl AS Einzelpreis
From auftragsposten