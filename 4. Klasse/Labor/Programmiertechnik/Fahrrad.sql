-- Das erstellen der Datenbank und das Befüllen werde ich in diesem Dokument nicht erklären, weil man die Codes einfach nur aus Moodle einfügen und ausführen musste.
Use fahrrad;

-- Führen Sie für jede Entität eine Abfrage aus und erfassen Sie wie viele Einträge es gibt
Select count(*)
From fahrraeder;
Select count(*)
From hersteller;
Select count(*)
From kunden;
Select count(*)
From land;
Select count(*)
From vermietungen;
Select count(*)
From wohnorte;

-- Führen Sie für jedes Datenbankelement eine Abfrage aus wobei Sie die Verknüpfungen berücksichtigen
Select Fahrradnr
From fahrraeder;
Select Herstellername
From hersteller;
Select Name
From kunden;
Select Countrycode
From land;
Select Mietdatum
From vermietungen;
Select Ort
From wohnorte;

-- Fügen Sie ihre Daten mithilfe eines SQL Befehls in die Datenbank ein
Insert Into kunden(Kundennr, Name, Vorname, Strasse)
Values(400, 'Adlgasser', 'Valentin', 'Teststrasse 12');

-- Abfrage aller Kunden, die noch kein Fahrrad ausgeliehen haben
Select *
From kunden
Where Kundennr not in (Select Kundennr From vermietungen);

-- Abfrage der 10 Kunden, welche am öftesten Fahrräder ausleihen
Select kunden.Kundennr
	,kunden.Name
    ,kunden.Vorname
    ,kunden.Strasse
    ,kunden.Ortnr
From kunden
	LEFT OUTER JOIN (SELECT COUNT(mietnr) AS Mietanzahl
					,Kundennr 
					FROM fahrrad.vermietungen
					GROUP BY Kundennr
					ORDER BY Count(Mietnr) desc) AS mieter on kunden.Kundennr = mieter.Kundennr
ORDER BY mieter.Mietanzahl desc
LIMIT 10;

-- Abfrage von allen, noch nie ausgeliehenen, Fahrrädern
Select *
From fahrraeder
Where Fahrradnr NOT IN (Select Fahrradnr From  vermietungen);

-- Abfrage von allen Fahrrädern + Gesamte Ausleihezeit
Select fahrraeder.Fahrradnr
	,fahrraeder.Bezeichnung
    ,fahrraeder.Rahmennummer
    ,fahrraeder.Tagesmietpreis
    ,fahrraeder.Wert
    ,fahrraeder.Kaufdatum
    ,fahrraeder.Herstellernr
    ,miet.Leihdauer
From fahrraeder
	LEFT OUTER JOIN (SELECT DATEDIFF(bis, von) AS Leihdauer
					,Fahrradnr
                    From vermietungen
                    GROUP BY Fahrradnr) AS miet on fahrraeder.Fahrradnr = miet.Fahrradnr;

-- Abfrage Kaufpreis - Mieteinnahmen
Select fahrraeder.Fahrradnr
	,fahrraeder.Bezeichnung
    ,fahrraeder.Rahmennummer
    ,fahrraeder.Tagesmietpreis
    ,fahrraeder.Wert
    ,fahrraeder.Kaufdatum
    ,fahrraeder.Herstellernr
    ,fahrraeder.Wert - (fahrraeder.Tagesmietpreis * miet.Leihdauer) AS 'Wert - Leiheinnahmen'
From fahrraeder
	LEFT OUTER JOIN (SELECT DATEDIFF(bis, von) AS Leihdauer
					,Fahrradnr
                    From vermietungen
                    GROUP BY Fahrradnr) AS miet on fahrraeder.Fahrradnr = miet.Fahrradnr;

-- Abfrage die den Zeitraum der Fahrradvermietung zeigt
Select vermietungen.von
	,vermietungen.bis
    ,fahrraeder.Bezeichnung
From vermietungen
	LEFT OUTER JOIN fahrraeder on vermietungen.Fahrradnr = fahrraeder.Fahrradnr;
    
-- Abfrage, wie lange noch bis Fahrräder abbezahlt sind
Select fahrraeder.Bezeichnung
    ,ROUND((fahrraeder.Wert - (fahrraeder.Tagesmietpreis * miet.Leihdauer))/(Tagesmietpreis * 0.85)) AS 'Tage bis abbezahlt'
From fahrraeder
	LEFT OUTER JOIN (SELECT DATEDIFF(bis, von) AS Leihdauer
					,Fahrradnr
                    From vermietungen
                    GROUP BY Fahrradnr) AS miet on fahrraeder.Fahrradnr = miet.Fahrradnr;

-- Abfrage, Vermiettungstage bist Fahrrad abbezahlt
Select Bezeichnung
	,ROUND(Wert/Tagesmietpreis) AS Tage
From fahrraeder
