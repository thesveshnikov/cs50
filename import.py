import csv
from cs50 import SQL

db = SQL("sqlite:///favorites.db")

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        language = row["language"].strip().upper()
        db.execute("INSERT INTO favorites (language) VALUES (?)", language)
