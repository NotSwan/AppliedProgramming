import sqlite3 as sql

conn = sql.connect("assignment3.db")
conn.execute("De")

conn.commit()
conn.close()