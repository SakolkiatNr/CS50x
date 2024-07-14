# Using SQL in Python
import csv
from cs50 import SQL

# Open database
db = SQL("sqlite:///favorites.db")

# Prompt user for favorite
favorite = input("Favorite: ")

# Search for title
rows = db.execute("SELECT COUNT(*) AS n
                   FROM favorites
                   WHERE problem LIKE ?", favorite)


